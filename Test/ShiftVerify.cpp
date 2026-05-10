// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// ShiftVerify - exercises every code path in the shift validators.
//
// Two layers of coverage:
//
//   1. Named regression cases for the specific bugs the shift_fix branch
//      was created to address:
//        - SAFEINT_NOTHROW on shift operators that can throw (verified by
//          observing that SafeIntException actually propagates out of every
//          shift form instead of std::terminate firing).
//        - Mixed-width free-overload bug (uint32_t lhs << SafeInt<uint64_t>
//          bits) where the bit-count check was using the wrong type's width.
//        - Signed left-shift undefined behavior: negative lhs, positive lhs
//          that overflows into the sign bit, and the canonical 1 << 31.
//
//   2. A generated sweep that hits every branch in both ShiftHelper
//      specializations, across boundary bit counts and lhs values, for
//      both << and >> in all six call forms (member raw, member SafeInt,
//      member-assign raw, member-assign SafeInt, free raw lhs, free raw
//      lhs assign).

#include "TestMain.h"
#include "TestCase.h"

// This file deliberately depends on C++ exceptions being the configured
// SafeInt error handler.  Without that, the throw-validation cases would
// silently no-op and the SAFEINT_NOTHROW->SAFEINT_CPP_THROW fix could
// regress without detection.
#if SAFEINT_EXCEPTION_HANDLER_CPP != 1
#error "ShiftVerify requires SAFEINT_EXCEPTION_HANDLER_CPP=1 to validate throw decorations on shift operators."
#endif

// Likewise, SAFEINT_REMOVE_NOTHROW would defeat the point of testing the
// throw decorations -- the operators would carry no throw spec at all,
// so a regression to noexcept would not be detectable here.
#if defined SAFEINT_REMOVE_NOTHROW
#error "ShiftVerify validates that throw decorations on shift operators are correct; do not define SAFEINT_REMOVE_NOTHROW."
#endif

// Test code sweeps both signed and unsigned T through the same templates,
// which intentionally leaves dead-code branches whose compile-time-constant
// conditionals MSVC /W4 flags as C4127.  Likewise, boundary value generation
// produces (T)-1 for unsigned T, triggering C4146.  Both are expected
// consequences of using one template body to test both signed and unsigned
// instantiations.
#if defined(_MSC_VER)
#pragma warning(disable: 4127)  // conditional expression is constant
#pragma warning(disable: 4146)  // unary minus operator applied to unsigned type
#endif

namespace shift_verify
{

static int g_errors = 0;

static void report_failure(const char* what)
{
    ++g_errors;
    std::cerr << "ShiftVerify FAIL: " << what << std::endl;
}

// Helper: run a shift expression that is expected to either succeed with a
// specific result, or throw SafeIntException.  Returns true if the observed
// behavior matches the expectation.
template <typename Expr>
static bool check_shift(Expr expr, bool expect_throw, const char* label)
{
    bool threw = false;
    try
    {
        expr();
    }
    catch (const SafeIntException&)
    {
        threw = true;
    }
    catch (...)
    {
        // Any other exception type indicates the throw decoration is wrong
        // (something escaped that should not have).
        report_failure(label);
        return false;
    }

    if (threw != expect_throw)
    {
        report_failure(label);
        return false;
    }
    return true;
}

//=============================================================================
// Named regression cases.
//=============================================================================

static void NamedRegressionCases()
{
    std::cout << "  Named regression cases" << std::endl;

    // --- Signed left shift UB: 1 << 31 places 1 in the sign position.
    check_shift([] {
        SafeInt<std::int32_t> a = 1;
        std::int32_t r = a << 31;
        (void)r;
    }, true, "int32_t(1) << 31 should throw");

    // --- Signed left shift UB: negative lhs (any bits).
    check_shift([] {
        SafeInt<std::int32_t> a = -1;
        std::int32_t r = a << 1;
        (void)r;
    }, true, "int32_t(-1) << 1 should throw");

    // --- Signed left shift UB: positive lhs whose top set bit overflows.
    check_shift([] {
        SafeInt<std::int32_t> a = 0x40000000;
        std::int32_t r = a << 1;
        (void)r;
    }, true, "int32_t(0x40000000) << 1 should throw");

    // --- Boundary accept (signed): 0x3FFFFFFF << 1 == 0x7FFFFFFE, fits.
    {
        bool ok = false;
        try
        {
            SafeInt<std::int32_t> a = 0x3FFFFFFF;
            std::int32_t r = a << 1;
            ok = (r == 0x7FFFFFFE);
        }
        catch (...) {}
        if (!ok) report_failure("int32_t(0x3FFFFFFF) << 1 should accept and equal 0x7FFFFFFE");
    }

    // --- Did NOT over-restrict: (uint32_t)1 << 31 is well-defined and equals
    // 0x80000000.  This case must not throw.
    {
        bool ok = false;
        try
        {
            SafeInt<std::uint32_t> a = 1;
            std::uint32_t r = a << 31;
            ok = (r == 0x80000000u);
        }
        catch (...) {}
        if (!ok) report_failure("uint32_t(1) << 31 should accept and equal 0x80000000");
    }

    // --- Mixed-width free overload regression: lhs=uint32_t, bits=SafeInt<uint64_t>.
    // Shift count of 40 exceeds bitCount<uint32_t>=32, must throw.
    check_shift([] {
        std::uint32_t lhs = 1;
        SafeInt<std::uint64_t> bits = 40;
        auto r = lhs << bits;
        (void)r;
    }, true, "uint32_t(1) << SafeInt<uint64_t>(40) should throw");

    // --- Mixed-width free overload, valid shift: lhs=uint32_t, bits=SafeInt<uint64_t>(8).
    // 8 < 32, valid, result must equal 0x100.
    {
        bool ok = false;
        try
        {
            std::uint32_t lhs = 1;
            SafeInt<std::uint64_t> bits = 8;
            SafeInt<std::uint32_t, SafeIntDefaultExceptionHandler> r = lhs << bits;
            ok = ((std::uint32_t)r == 0x100u);
        }
        catch (...) {}
        if (!ok) report_failure("uint32_t(1) << SafeInt<uint64_t>(8) should accept and equal 0x100");
    }

    // --- Throw-escape coverage: every shift form must let SafeIntException
    // propagate.  If any of these were still annotated noexcept, std::terminate
    // would fire and the test process would die -- visible signal.
    check_shift([] {
        SafeInt<std::int32_t> a = 1;
        SafeInt<std::int32_t> r = a << 31;
        (void)r;
    }, true, "operator<<(U) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 1;
        SafeInt<std::int32_t> b = 31;
        SafeInt<std::int32_t> r = a << b;
        (void)r;
    }, true, "operator<<(SafeInt<U>) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 1;
        a <<= 31;
    }, true, "operator<<=(U) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 1;
        SafeInt<std::int32_t> b = 31;
        a <<= b;
    }, true, "operator<<=(SafeInt<U>) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 100;
        SafeInt<std::int32_t> r = a >> 32;
        (void)r;
    }, true, "operator>>(U) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 100;
        SafeInt<std::int32_t> b = 32;
        SafeInt<std::int32_t> r = a >> b;
        (void)r;
    }, true, "operator>>(SafeInt<U>) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 100;
        a >>= 32;
    }, true, "operator>>=(U) throw escape");

    check_shift([] {
        SafeInt<std::int32_t> a = 100;
        SafeInt<std::int32_t> b = 32;
        a >>= b;
    }, true, "operator>>=(SafeInt<U>) throw escape");

    check_shift([] {
        std::int32_t lhs = 1;
        SafeInt<std::int32_t> bits = 31;
        auto r = lhs << bits;
        (void)r;
    }, true, "free operator<<(U, SafeInt<T>) throw escape");

    check_shift([] {
        std::int32_t lhs = 100;
        SafeInt<std::int32_t> bits = 32;
        auto r = lhs >> bits;
        (void)r;
    }, true, "free operator>>(U, SafeInt<T>) throw escape");
}

//=============================================================================
// Generated sweep.
//
// Independent oracle: compute the shift in a wide unsigned type, then
// independently decide whether the result fits in T and whether the input
// was UB.  The oracle's logic does NOT share code with ShiftHelper; that's
// the point.
//=============================================================================

// Promote any integer to uint64_t for the oracle's arithmetic, preserving
// the value (sign-extending negatives so the bit pattern is preserved on
// the high side and we can detect "would touch sign bit" cases below).
template <typename T>
static std::uint64_t to_u64(T v)
{
    // Two-step cast: through the same-width signed/unsigned of T to preserve
    // the bit pattern, then widen.  For unsigned T this is just a widen.
    return (std::uint64_t)(typename std::make_unsigned<T>::type)v;
}

// Oracle for left shift: returns true if the shift is well-defined AND the
// result is representable in T.  This independently re-derives the rules,
// matching the C++17 standard's stricter interpretation that SafeInt targets.
template <typename T, typename U>
static bool oracle_lshift_valid(T lhs, U bits)
{
    // Negative bit count: undefined.
    if (std::numeric_limits<U>::is_signed && bits < 0) return false;
    // Bit count >= width: undefined.
    if ((std::uint64_t)bits >= safeint_internal::int_traits<T>::bitCount) return false;

    if (std::numeric_limits<T>::is_signed)
    {
        // Negative signed lhs: undefined pre-C++20.
        if (lhs < 0) return false;
        // Bit count >= width-1 with non-zero lhs would touch the sign bit.
        // (Note: lhs == 0 with bits == width-1 is technically defined, but
        // the validator caps at width-1 unconditionally for signed; the
        // oracle matches that intentional choice -- see ShiftVerify state-of-
        // work doc.)
        if ((std::uint64_t)bits >= safeint_internal::int_traits<T>::bitCount - 1) return false;
        // Non-negative signed lhs: result must fit in signed T.
        std::uint64_t bound = (std::uint64_t)std::numeric_limits<T>::max() >> bits;
        if ((std::uint64_t)lhs > bound) return false;
    }
    return true;
}

// Oracle for right shift: returns true if well-defined.  Right shift does
// not depend on the lhs value for well-definedness on any supported target.
template <typename T, typename U>
static bool oracle_rshift_valid(T /*lhs*/, U bits)
{
    if (std::numeric_limits<U>::is_signed && bits < 0) return false;
    if ((std::uint64_t)bits >= safeint_internal::int_traits<T>::bitCount) return false;
    return true;
}

// For each (T, lhs, bits) tuple where the shift is valid, compute the
// expected result the same way the oracle reasons about it: cast to
// unsigned T, do the shift, cast back.  This matches what SafeInt's
// operator does internally and is well-defined in C++.
template <typename T, typename U>
static T expected_lshift(T lhs, U bits)
{
    typedef typename std::make_unsigned<T>::type UT;
    return (T)((UT)lhs << bits);
}

template <typename T, typename U>
static T expected_rshift(T lhs, U bits)
{
    return (T)(lhs >> bits);
}

// Run all six << forms for one (T, U, lhs, bits) tuple and verify each
// matches the oracle.
template <typename T, typename U>
static void check_one_lshift(T lhs, U bits, const char* tu_label)
{
    bool valid = oracle_lshift_valid<T, U>(lhs, bits);
    T expected = valid ? expected_lshift<T, U>(lhs, bits) : T(0);

    // Form 1: SafeInt<T>(lhs) << bits  (member, raw U)
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); got = a << bits; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " <<(U)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << " threw=" << threw
                      << " valid=" << valid << " got=" << to_hex(got)
                      << " expected=" << to_hex(expected) << std::endl;
            ++g_errors;
        }
    }

    // Form 2: SafeInt<T>(lhs) << SafeInt<U>(bits)  (member, SafeInt U)
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); SafeInt<U> b(bits); got = a << b; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " <<(SafeInt<U>)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }

    // Form 3: a <<= bits  (member-assign, raw U)
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); a <<= bits; got = (T)a; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " <<=(U)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }

    // Form 4: a <<= SafeInt<U>(bits)  (member-assign, SafeInt U)
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); SafeInt<U> b(bits); a <<= b; got = (T)a; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " <<=(SafeInt<U>)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }

    // Form 5: T(lhs) << SafeInt<U>(bits)  (free overload, raw lhs)
    // The validator for this overload runs over (T = lhs type, U = bits type).
    // The validity check matches our oracle for the same (T, U).
    {
        bool threw = false; T got = 0;
        try { SafeInt<U> b(bits); SafeInt<T> r = lhs << b; got = (T)r; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " free <<] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }

    // Form 6: T& <<= SafeInt<U>(bits)  (free overload, raw lhs assign)
    {
        bool threw = false; T got = 0;
        try { T x = lhs; SafeInt<U> b(bits); x <<= b; got = x; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " free <<=] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
}

template <typename T, typename U>
static void check_one_rshift(T lhs, U bits, const char* tu_label)
{
    bool valid = oracle_rshift_valid<T, U>(lhs, bits);
    T expected = valid ? expected_rshift<T, U>(lhs, bits) : T(0);

    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); got = a >> bits; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " >>(U)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); SafeInt<U> b(bits); got = a >> b; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " >>(SafeInt<U>)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); a >>= bits; got = (T)a; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " >>=(U)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
    {
        bool threw = false; T got = 0;
        try { SafeInt<T> a(lhs); SafeInt<U> b(bits); a >>= b; got = (T)a; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " >>=(SafeInt<U>)] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
    {
        bool threw = false; T got = 0;
        try { SafeInt<U> b(bits); SafeInt<T> r = lhs >> b; got = (T)r; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " free >>] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
    {
        bool threw = false; T got = 0;
        try { T x = lhs; SafeInt<U> b(bits); x >>= b; got = x; }
        catch (const SafeIntException&) { threw = true; }
        if (threw == valid || (valid && got != expected))
        {
            std::cerr << "ShiftVerify FAIL [" << tu_label << " free >>=] lhs=" << to_hex(lhs)
                      << " bits=" << (long long)bits << std::endl;
            ++g_errors;
        }
    }
}

// Boundary lhs values for one type T.  Eight distinct values that cover
// zero, near-zero, the just-fits / just-overflows boundary for left shift
// by 1, the type bounds, and -1 for signed types.
template <typename T>
static void boundary_lhs_values(T values[8])
{
    typedef typename std::make_unsigned<T>::type UT;
    UT umax = (UT)std::numeric_limits<T>::max();
    values[0] = (T)0;
    values[1] = (T)1;
    values[2] = (T)(umax >> 1);     // For signed: 0x3FFF... (boundary accept << 1)
    values[3] = (T)((umax >> 1) + 1); // For signed: 0x4000... (boundary reject << 1)
    values[4] = std::numeric_limits<T>::max();
    values[5] = std::numeric_limits<T>::min();
    values[6] = (T)-1;
    values[7] = (T)((T)1 << (safeint_internal::int_traits<T>::bitCount - 2)); // mid bit set
}

// Boundary bit-count values for one (T, U) pair.  Up to seven values:
// negative (only when U is signed), zero, one, width-2, width-1, width,
// width+1.  Returns the count actually filled.
template <typename T, typename U>
static int boundary_bits_values(U values[7])
{
    int count = 0;
    int width = (int)safeint_internal::int_traits<T>::bitCount;
    if (std::numeric_limits<U>::is_signed) values[count++] = (U)-1;
    values[count++] = (U)0;
    values[count++] = (U)1;
    values[count++] = (U)(width - 2);
    values[count++] = (U)(width - 1);
    values[count++] = (U)(width);
    // Don't add width+1 if U can't represent it (e.g. U=int8_t and T=int64_t,
    // then width=64 already overflows int8_t -- but the cast above will have
    // wrapped; check before adding the +1.)
    if ((int)(U)(width + 1) == width + 1) values[count++] = (U)(width + 1);
    return count;
}

template <typename T, typename U>
static void SweepShift(const char* tu_label)
{
    T lhs_values[8];
    boundary_lhs_values<T>(lhs_values);

    U bits_values[7];
    int bits_count = boundary_bits_values<T, U>(bits_values);

    for (size_t i = 0; i < 8; ++i)
    {
        for (int j = 0; j < bits_count; ++j)
        {
            check_one_lshift<T, U>(lhs_values[i], bits_values[j], tu_label);
            check_one_rshift<T, U>(lhs_values[i], bits_values[j], tu_label);
        }
    }
}

//=============================================================================
// Entry point.
//=============================================================================

void ShiftVerify()
{
    std::cout << "Verifying Shift:" << std::endl;
    g_errors = 0;

    NamedRegressionCases();

    std::cout << "  Generated sweep" << std::endl;

    // Same-width sweep across all eight integer types.
    SweepShift<std::int8_t,   std::int8_t>("int8/int8");
    SweepShift<std::int16_t,  std::int16_t>("int16/int16");
    SweepShift<std::int32_t,  std::int32_t>("int32/int32");
    SweepShift<std::int64_t,  std::int64_t>("int64/int64");
    SweepShift<std::uint8_t,  std::uint8_t>("uint8/uint8");
    SweepShift<std::uint16_t, std::uint16_t>("uint16/uint16");
    SweepShift<std::uint32_t, std::uint32_t>("uint32/uint32");
    SweepShift<std::uint64_t, std::uint64_t>("uint64/uint64");

    // Mixed-width and mixed-signedness sweeps on representative T's, to
    // exercise the free-overload regression and the signed-U branch of
    // bits_not_negative.
    SweepShift<std::int32_t,  std::uint64_t>("int32/uint64");
    SweepShift<std::int32_t,  std::int8_t>("int32/int8");
    SweepShift<std::uint32_t, std::uint64_t>("uint32/uint64");
    SweepShift<std::uint32_t, std::int8_t>("uint32/int8");

    if (g_errors == 0)
        std::cout << "  All shift checks passed." << std::endl;
    else
        std::cerr << "  " << g_errors << " shift check(s) failed." << std::endl;
}

} // namespace shift_verify

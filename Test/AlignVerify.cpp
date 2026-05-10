// Copyright (c) David LeBlanc. All rights reserved.
// Licensed under the MIT License.

// AlignVerify - exercises the SafeInt<T,E>::Align<bits>() member.
//
// Align is a small, niche operation: round a non-negative value up to the
// next multiple of 2^bits, throwing on overflow or negative input.  It has
// three observable behaviors:
//
//   1. Zero in -> zero out (early return).
//   2. Negative signed input -> throw.
//   3. Otherwise -> round up; throw if the rounded value exceeds max(T).
//
// The implementation has two ShiftHelper-style specializations (signed and
// unsigned) for align_addmask, and a static_assert guard on the bits value.
// We test each behavior with a handful of explicit cases per integer width.
//
// IMPORTANT: To validate the signed-overflow fix in align_addmask, build
// this file with UBSan (gcc/clang: -fsanitize=undefined).  The original
// bug was that (m_int + AlignValue) was signed-overflow UB near max(T);
// current compilers happen to wrap predictably and the post-mask check
// catches the result, so the functional test passes either way.  Only
// UBSan can distinguish "well-defined unsigned wrap" (correct) from
// "undefined-but-happens-to-do-the-right-thing" (regression).

#include "TestMain.h"
#include "TestCase.h"

#if SAFEINT_EXCEPTION_HANDLER_CPP != 1
#error "AlignVerify requires SAFEINT_EXCEPTION_HANDLER_CPP=1."
#endif
#if defined SAFEINT_REMOVE_NOTHROW
#error "AlignVerify validates throw decorations; do not define SAFEINT_REMOVE_NOTHROW."
#endif

namespace align_verify
{

static int g_errors = 0;

// expect_value: value that .Align<Bits>() should return on success.
// expect_throw: true if Align should throw SafeIntException.
// (At most one of these is meaningful: when expect_throw is true,
// expect_value is ignored.)
template <typename T, int Bits>
static void check(T lhs, T expect_value, bool expect_throw, const char* label)
{
    bool threw = false;
    T got = 0;
    try
    {
        SafeInt<T> a = lhs;
        a.template Align<(typename SafeInt<T>::alignBits)Bits>();
        got = (T)a;
    }
    catch (const SafeIntException&)
    {
        threw = true;
    }
    catch (...)
    {
        std::cerr << "AlignVerify FAIL [" << label << "] unexpected exception type" << std::endl;
        ++g_errors;
        return;
    }

    if (threw != expect_throw)
    {
        std::cerr << "AlignVerify FAIL [" << label << "] threw=" << threw
                  << " expected_throw=" << expect_throw << std::endl;
        ++g_errors;
        return;
    }
    if (!expect_throw && got != expect_value)
    {
        std::cerr << "AlignVerify FAIL [" << label << "] got=" << to_hex(got)
                  << " expected=" << to_hex(expect_value) << std::endl;
        ++g_errors;
    }
}

void AlignVerify()
{
    std::cout << "Verifying Align:" << std::endl;
    g_errors = 0;

    // ---- Behavior 1: zero in -> zero out (early return). ----
    check<std::int32_t,  4>( 0,  0, false, "i32(0).Align<align16>");
    check<std::uint32_t, 4>( 0,  0, false, "u32(0).Align<align16>");
    check<std::int8_t,   1>( 0,  0, false, "i8(0).Align<align2>");
    check<std::uint64_t, 8>( 0,  0, false, "u64(0).Align<align256>");

    // ---- Behavior 2: negative signed input -> throw. ----
    // Always rejected, regardless of bits.  Since the post-mask check also
    // catches negative results, a passing test does not by itself prove the
    // explicit reject path runs -- but it does prove that no negative input
    // ever produces a non-throwing result.
    check<std::int32_t, 1>(-1, 0, true, "i32(-1).Align<align2>");
    check<std::int32_t, 4>(-1, 0, true, "i32(-1).Align<align16>");
    check<std::int32_t, 4>(std::numeric_limits<std::int32_t>::min(), 0, true, "i32(min).Align<align16>");
    check<std::int8_t,  1>(-1,   0, true, "i8(-1).Align<align2>");
    check<std::int8_t,  1>(-100, 0, true, "i8(-100).Align<align2>");
    check<std::int64_t, 6>(-1,   0, true, "i64(-1).Align<align64>");

    // ---- Behavior 3a: positive input that fits, rounded up correctly. ----
    // Already-aligned values pass through unchanged.
    check<std::uint32_t, 2>( 4,    4,    false, "u32(4).Align<align4>");
    check<std::uint32_t, 4>( 0x10, 0x10, false, "u32(16).Align<align16>");
    check<std::int32_t,  4>( 0x10, 0x10, false, "i32(16).Align<align16>");
    // Not-aligned values round up.
    check<std::uint32_t, 2>(  1,    4, false, "u32(1).Align<align4>");
    check<std::uint32_t, 2>(  3,    4, false, "u32(3).Align<align4>");
    check<std::uint32_t, 2>(  5,    8, false, "u32(5).Align<align4>");
    check<std::uint32_t, 4>(  7,   16, false, "u32(7).Align<align16>");
    check<std::uint32_t, 4>(0x101, 0x110, false, "u32(0x101).Align<align16>");
    check<std::int8_t,   1>(  1,    2, false, "i8(1).Align<align2>");
    check<std::int8_t,   2>(  5,    8, false, "i8(5).Align<align4>");

    // ---- Behavior 3b: positive input near max, fits exactly. ----
    // Largest aligned value that's representable.
    check<std::uint32_t, 2>(0xFFFFFFFC, 0xFFFFFFFC, false, "u32(max&~3).Align<align4>");
    check<std::int32_t,  2>(0x7FFFFFFC, 0x7FFFFFFC, false, "i32(0x7FFFFFFC).Align<align4>");
    check<std::uint8_t,  2>(0xFC,       0xFC,       false, "u8(0xFC).Align<align4>");
    check<std::int8_t,   2>(0x7C,       0x7C,       false, "i8(0x7C).Align<align4>");

    // ---- Behavior 3c: positive input near max, rounded up overflows. ----
    // Unsigned: post-mask check catches the wrap-to-zero.
    check<std::uint8_t,  2>(0xFD,       0, true, "u8(0xFD).Align<align4>");
    check<std::uint8_t,  2>(0xFF,       0, true, "u8(0xFF).Align<align4>");
    check<std::uint32_t, 2>(0xFFFFFFFD, 0, true, "u32(0xFFFFFFFD).Align<align4>");
    check<std::uint32_t, 2>(0xFFFFFFFF, 0, true, "u32(max).Align<align4>");
    check<std::uint64_t, 4>(0xFFFFFFFFFFFFFFFFull, 0, true, "u64(max).Align<align16>");
    // Signed: align_addmask helper does the addition in unsigned, then the
    // post-mask check sees a negative value (high bit set) and throws.
    // This is the case that was UB before the unsigned-helper fix.
    check<std::int32_t, 2>(0x7FFFFFFD, 0, true, "i32(max-2).Align<align4>");
    check<std::int32_t, 2>(0x7FFFFFFF, 0, true, "i32(max).Align<align4>");
    check<std::int8_t,  2>(0x7D,       0, true, "i8(125).Align<align4>");
    check<std::int8_t,  2>(0x7F,       0, true, "i8(max).Align<align4>");
    check<std::int64_t, 4>(std::numeric_limits<std::int64_t>::max(), 0, true, "i64(max).Align<align16>");

    // ---- Convenience wrappers (Align2..Align256) delegate to Align<>. ----
    {
        bool ok = false;
        try
        {
            SafeInt<std::uint32_t> a = 13;
            a.Align8();
            ok = ((std::uint32_t)a == 16u);
        }
        catch (...) {}
        if (!ok) { std::cerr << "AlignVerify FAIL: u32(13).Align8() expected 16" << std::endl; ++g_errors; }
    }
    {
        bool ok = false;
        try
        {
            SafeInt<std::uint32_t> a = 0xFFFFFFFD;
            a.Align4();
            ok = false;  // should have thrown
        }
        catch (const SafeIntException&) { ok = true; }
        catch (...) {}
        if (!ok) { std::cerr << "AlignVerify FAIL: u32(max-2).Align4() should throw" << std::endl; ++g_errors; }
    }

    if (g_errors == 0)
        std::cout << "  All align checks passed." << std::endl;
    else
        std::cerr << "  " << g_errors << " align check(s) failed." << std::endl;
}

} // namespace align_verify

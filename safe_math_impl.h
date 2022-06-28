// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

/*-----------------------------------------------------------------------------------------------------------
c_safe_math
Version 1.0 - 6/21/22

This header implements a set of functions that check for integer overflows in C code.
It is based on code and logic from SafeInt.hpp, but ported to C.

Portions copied from SafeInt.hpp are Licensed under the MIT License,
and are originally copyrighted to Microsoft.
*/

#ifndef C_SAFE_MATH_IMPL
#define C_SAFE_MATH_IMPL

#ifdef __cplusplus
extern "C"
{
#endif

    // It is a bit tricky to sort out what compiler we are actually using,
    // do this once here, and avoid cluttering the code
#define VISUAL_STUDIO_COMPILER 0
#define CLANG_COMPILER 1
#define GCC_COMPILER 2
#define UNKNOWN_COMPILER -1

// Clang will sometimes pretend to be Visual Studio
// and does pretend to be gcc. Check it first, as nothing else pretends to be clang
#if defined __clang__
#define SAFEINT_COMPILER CLANG_COMPILER
#elif defined __GNUC__
#define SAFEINT_COMPILER GCC_COMPILER
#elif defined _MSC_VER
#define SAFEINT_COMPILER VISUAL_STUDIO_COMPILER
#else
#define SAFEINT_COMPILER UNKNOWN_COMPILER
#endif

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

// Figure out if we should use intrinsics
// If the user has already decided, let that override
#define SAFEINT_MULTIPLY_MATH        0 // no intrinsics, no built in, no 128-bit
#define SAFEINT_MULTIPLY_INTRINSICS  1
#define SAFEINT_MULTIPLY_BUILTIN     2 // gcc, clang
#define SAFEINT_MULTIPLY_INT128      3 // Best case

// We might have 128-bit int support, check for that, as it should work best
#if !defined SAFEINT_HAS_INT128

#if defined __SIZEOF_INT128__ && __SIZEOF_INT128__ == 16
#define SAFEINT_HAS_INT128 1
#else
#define SAFEINT_HAS_INT128 0
#endif

#endif

#if SAFEINT_HAS_INT128
#define SAFEINT_MULTIPLY_METHOD SAFEINT_MULTIPLY_INT128
#else

#if !defined SAFEINT_USE_INTRINSICS
// If it is the Visual Studio compiler, then it has to be 64-bit, and not ARM64EC
#if SAFEINT_COMPILER == VISUAL_STUDIO_COMPILER
#if defined _M_AMD64 && !defined _M_ARM64EC
#include <intrin.h>
#define SAFEINT_MULTIPLY_METHOD SAFEINT_MULTIPLY_INTRINSICS
#else
#define SAFEINT_MULTIPLY_METHOD SAFEINT_MULTIPLY_MATH
#endif

#else // Not VISUAL_STUDIO_COMPILER

    // Else for gcc and clang, we can use builtin functions
#if SAFEINT_COMPILER == CLANG_COMPILER || SAFEINT_COMPILER == GCC_COMPILER
#define SAFEINT_MULTIPLY_METHOD SAFEINT_MULTIPLY_BUILTIN
#else
#define SAFEINT_MULTIPLY_METHOD SAFEINT_MULTIPLY_MATH
#endif
#endif

#endif // SAFEINT_USE_INTRINSICS
#endif // SAFEINT_HAS_INT128

// TODO This needs to be replaceable
#include <stdlib.h>

void safe_math_fail(const char* msg)
{
    const char* not_used = msg;
    not_used = (const char*)0;
    abort();
}

#if !defined UINT64_MAX

#define INT8_MIN         (-127i8 - 1)
#define INT16_MIN        (-32767i16 - 1)
#define INT32_MIN        (-2147483647i32 - 1)
#define INT64_MIN        (-9223372036854775807i64 - 1)
#define INT8_MAX         127i8
#define INT16_MAX        32767i16
#define INT32_MAX        2147483647i32
#define INT64_MAX        9223372036854775807i64
#define UINT8_MAX        0xffui8
#define UINT16_MAX       0xffffui16
#define UINT32_MAX       0xffffffffui32
#define UINT64_MAX       0xffffffffffffffffui64

#endif

// Utility functions

// Purpose of this is to negate an int in a way
// where the compiler won't remove it if the input is a 
// compile time constant MIN_INT
inline int32_t negate32(int32_t in) { return (int32_t)(~(uint32_t)in + 1); }
inline int64_t negate64(int64_t in) { return (int64_t)(~(uint64_t)in + 1); }

inline uint32_t safe_abs32(int32_t in)
{
    if (in < 0)
        return ~(uint32_t)in + 1;

    return (uint32_t)in;
}

inline uint64_t safe_abs64(int64_t in)
{
    if (in < 0)
        return ~(uint64_t)in + 1;

    return (uint64_t)in;
}

// Checked casting functions
// 0 if the cast is safe, non-zero if unsafe
inline int check_cast_int8_int32(int32_t in) { return (in < INT8_MIN || in > INT8_MAX); }
inline int check_cast_int8_uint32(uint32_t in) { return in > INT8_MAX; }
inline int check_cast_int8_int64(int64_t in) { return in < INT8_MIN || in > INT8_MAX; }
inline int check_cast_int8_uint64(uint64_t in) { return (in > INT8_MAX); }
inline int check_cast_int16_int32(int32_t in) { return in < INT16_MIN || in > INT16_MAX; }
inline int check_cast_int16_uint32(uint32_t in) { return (in > INT16_MAX); }
inline int check_cast_int16_int64(int64_t in) { return (in < INT16_MIN || in > INT16_MAX); }
inline int check_cast_int16_uint64(uint64_t in) { return (in > INT16_MAX); }
inline int check_cast_int32_uint32(uint32_t in) { return (in > INT32_MAX); }
inline int check_cast_int32_int64(int64_t in) { return (in < INT32_MIN || in > INT32_MAX); }
inline int check_cast_int32_uint64(uint64_t in) { return (in > INT32_MAX); }
inline int check_cast_int64_uint64(uint64_t in) { return (in > INT64_MAX); }
inline int check_cast_uint8_int32(int32_t in) { return (in < 0 || in > UINT8_MAX); }
inline int check_cast_uint8_uint32(uint32_t in) { return (in > UINT8_MAX); }
inline int check_cast_uint8_int64(int64_t in) { return (in < 0 || in > UINT8_MAX); }
inline int check_cast_uint8_uint64(uint64_t in) { return (in > UINT8_MAX); }
inline int check_cast_uint16_int32(int32_t in) { return (in < 0 || in > UINT16_MAX); }
inline int check_cast_uint16_uint32(uint32_t in) { return (in > UINT16_MAX); }
inline int check_cast_uint16_int64(int64_t in) { return (in < 0 || in > UINT16_MAX); }
inline int check_cast_uint16_uint64(uint64_t in) { return (in > UINT16_MAX); }
inline int check_cast_uint32_int32(int32_t in) { return (in < 0); }
inline int check_cast_uint32_int64(int64_t in) { return (in < 0 || in > UINT32_MAX); }
inline int check_cast_uint32_uint64(uint64_t in) { return (in > UINT32_MAX); }
inline int check_cast_uint64_int64(int64_t in) { return (in < 0); }

inline int8_t safe_cast_int8_int32(int32_t in)
{
    if (!check_cast_int8_int32(in))
        safe_math_fail("safe_math_fail safe_cast_int8_int32");

    return (int8_t)in;
}

inline int8_t safe_cast_int8_uint32(uint32_t in)
{
    if (check_cast_int8_uint32(in))
        safe_math_fail("safe_math_fail safe_cast_int8_uint32");

    return (int8_t)in;
}

inline int8_t safe_cast_int8_int64(int64_t in)
{
    if (check_cast_int8_int64(in))
        safe_math_fail("safe_math_fail safe_cast_int8_int64");

    return (int8_t)in;
}

inline int8_t safe_cast_int8_uint64(uint64_t in)
{
    if (check_cast_int8_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_int8_uint64");

    return (int8_t)in;
}

inline int16_t safe_cast_int16_int32(int32_t in)
{
    if (check_cast_int16_int32(in))
        safe_math_fail("safe_math_fail safe_cast_int16_int32");

    return (int16_t)in;
}

inline int16_t safe_cast_int16_uint32(uint32_t in)
{
    if (check_cast_int16_uint32(in))
        safe_math_fail("safe_math_fail safe_cast_int16_uint32");

    return (int16_t)in;
}

inline int16_t safe_cast_int16_int64(int64_t in)
{
    if (check_cast_int16_int64(in))
        safe_math_fail("safe_math_fail safe_cast_int16_int64");

    return (int16_t)in;
}

inline int16_t safe_cast_int16_uint64(uint64_t in)
{
    if (in > INT16_MAX)
        safe_math_fail("safe_math_fail safe_cast_int16_uint64");

    return (int16_t)in;
}

inline int32_t safe_cast_int32_uint32(uint32_t in)
{
    if (check_cast_int32_uint32(in))
        safe_math_fail("safe_math_fail safe_cast_int32_uint32");

    return (int32_t)in;
}

inline int32_t safe_cast_int32_int64(int64_t in)
{
    if (check_cast_int32_int64(in))
        safe_math_fail("safe_math_fail safe_cast_int32_int64");

    return (int32_t)in;
}

inline int32_t safe_cast_int32_uint64(uint64_t in)
{
    if (check_cast_int32_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_int32_uint64");

    return (int32_t)in;
}

inline int64_t safe_cast_int64_uint64(uint64_t in)
{
    if (check_cast_int64_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_int64_uint64");

    return (int64_t)in;
}

inline uint8_t safe_cast_uint8_int32(int32_t in)
{
    if (check_cast_uint8_int32(in))
        safe_math_fail("safe_math_fail safe_cast_uint8_int32");

    return (uint8_t)in;
}

inline uint8_t safe_cast_uint8_uint32(uint32_t in)
{
    if (check_cast_uint8_uint32(in))
        safe_math_fail("safe_math_fail safe_cast_uint8_uint32");

    return (uint8_t)in;
}

inline uint8_t safe_cast_uint8_int64(int64_t in)
{
    if (check_cast_uint8_int64(in))
        safe_math_fail("safe_math_fail safe_cast_uint8_int64");

    return (uint8_t)in;
}

inline uint8_t safe_cast_uint8_uint64(uint64_t in)
{
    if (check_cast_uint8_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_uint8_uint64");

    return (uint8_t)in;
}

inline uint16_t safe_cast_uint16_int32(int32_t in)
{
    if (check_cast_uint16_int32(in))
        safe_math_fail("safe_math_fail safe_cast_uint16_int32");

    return (uint16_t)in;
}

inline uint16_t safe_cast_uint16_uint32(uint32_t in)
{
    if (check_cast_uint16_uint32(in))
        safe_math_fail("safe_math_fail safe_cast_uint16_uint32");

    return (uint16_t)in;
}

inline uint16_t safe_cast_uint16_int64(int64_t in)
{
    if (check_cast_uint16_int64(in))
        safe_math_fail("safe_math_fail safe_cast_uint16_int64");

    return (uint16_t)in;
}

inline uint16_t safe_cast_uint16_uint64(uint64_t in)
{
    if (check_cast_uint16_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_int16_uint64");

    return (uint16_t)in;
}

inline uint32_t safe_cast_uint32_int32(int32_t in)
{
    if (check_cast_uint32_int32(in))
        safe_math_fail("safe_math_fail safe_cast_uint32_int32");

    return (uint32_t)in;
}

inline uint32_t safe_cast_uint32_int64(int64_t in)
{
    if (check_cast_uint32_int64(in))
        safe_math_fail("safe_math_fail safe_cast_int32_int64");

    return (uint32_t)in;
}

inline uint32_t safe_cast_uint32_uint64(uint64_t in)
{
    if (check_cast_uint32_uint64(in))
        safe_math_fail("safe_math_fail safe_cast_uint32_uint64");

    return (uint32_t)in;
}

inline uint64_t safe_cast_uint64_int64(int64_t in)
{
    if (check_cast_uint64_int64(in))
        safe_math_fail("safe_math_fail safe_cast_int64_uint64");

    return (uint64_t)in;
}

// Addition
/*
    For addition and multiplication, there will be checks for the following matrix:
    - int32
    - uint32
    - int64
    - uint64

    If you want to add smaller types, then do it inside the appropriate safe_cast function,
    or if adding one of the above and a smaller type, pass it into one that takes a larger
    size of the same type, for example, uint16 -> uint32.
*/

inline int32_t safe_add_int32_int32(int32_t a, int32_t b)
{
    return safe_cast_int32_int64((int64_t)a + b);
}

inline int32_t safe_add_int32_uint32(int32_t a, uint32_t b)
{
    return safe_cast_int32_int64((int64_t)a + b);
}

inline int32_t safe_add_int32_int64(int32_t a, int64_t b)
{
    int64_t tmp = (int64_t)((uint64_t)a + (uint64_t)b);
    
    if (a >= 0)
    {
        // mixed sign cannot overflow
        if (b >= 0 && tmp < a)
            safe_math_fail("safe_math_fail safe_add_int32_int64");
    }
    else
    {
        // lhs negative
        if (b < 0 && tmp > a)
            safe_math_fail("safe_math_fail safe_add_int32_int64");
    }

    return safe_cast_int32_int64(tmp);
}

inline int32_t safe_add_int32_uint64(int32_t a, uint64_t b)
{
    if ((uint32_t)(b >> 32) == 0)
    {
        // Now it just happens to work out that the standard behavior does what we want
        // Adding explicit casts to show exactly what's happening here
        uint32_t tmp = (uint32_t)a + (uint32_t)b;

        if ((int32_t)tmp >= a)
        {
            return (int32_t)tmp;
        }
    }

    safe_math_fail("safe_math_fail safe_add_int32_uint64");
}

inline uint32_t safe_add_uint32_int32(uint32_t a, int32_t b)
{
    return safe_cast_uint32_int64((int64_t)a + b);
}

inline uint32_t safe_add_uint32_uint32(uint32_t a, uint32_t b)
{
    uint32_t tmp = a + b;
    
    if (tmp < a)
    {
        safe_math_fail("safe_math_fail safe_add_uint32_uint32");
    }

    return tmp;
}

inline uint32_t safe_add_uint32_int64(uint32_t a, int64_t b)
{
    if (b < 0)
    {
        if (a >= safe_abs64(b)) //negation is safe, since rhs is 64-bit
        {
            return (uint32_t)(a + b);
        }
    }
    else
    {
        // now we know that rhs can be safely cast into an std::uint64_t
        uint64_t tmp = (uint64_t)a + (uint64_t)b;

        // special case - rhs cannot be larger than 0x7fffffffffffffff, lhs cannot be larger than 0xffffffff
        // it is not possible for the operation above to overflow, so just check max
        return safe_cast_uint32_uint64(tmp);
    }

    safe_math_fail("safe_math_fail safe_add_uint32_int64");
}

inline uint32_t safe_add_uint32_uint64(uint32_t a, uint64_t b)
{
    uint64_t tmp = (uint64_t)a + b;
    
    if (tmp < a)
    {
        safe_math_fail("safe_math_fail safe_add_uint32_uint64");
    }

    return (uint32_t)tmp;
}

inline int64_t safe_add_int64_int32(int64_t a, int32_t b)
{
    int64_t tmp = (int64_t)((uint64_t)a + (uint64_t)b);

    if (a >= 0)
    {
        // mixed sign cannot overflow
        if (b >= 0 && tmp < a)
            safe_math_fail("safe_math_fail safe_add_int64_int32");
    }
    else
    {
        // lhs negative
        if (b < 0 && tmp > a)
            safe_math_fail("safe_math_fail safe_add_int64_int32");
    }

    return tmp;
}

inline int64_t safe_add_int64_uint32(int64_t a, uint32_t b)
{
    uint64_t tmp = (uint64_t)a + (uint64_t)b;

    if ((int64_t)tmp >= a)
    {
        return (int64_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_add_int64_uint32");
}

inline int64_t safe_add_int64_int64(int64_t a, int64_t b)
{
    int64_t tmp = (int64_t)((uint64_t)a + (uint64_t)b);

    if (a >= 0)
    {
        // mixed sign cannot overflow
        if (b >= 0 && tmp < a)
            safe_math_fail("safe_math_fail safe_add_int64_int64");
    }
    else
    {
        // lhs negative
        if (b < 0 && tmp > a)
            safe_math_fail("safe_math_fail safe_add_int64_int64");
    }

    return tmp;
}

inline int64_t safe_add_int64_uint64(int64_t a, uint64_t b)
{
    uint64_t tmp = (uint64_t)a + b;

    if ((int64_t)tmp >= a)
    {
        return (int64_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_add_int64_uint64");
}

inline uint64_t safe_add_uint64_int32(uint64_t a, int32_t b)
{
    uint64_t tmp = 0;

    if (b < 0)
    {
        // So we're effectively subtracting
        tmp = safe_abs32(b);

        if (tmp <= a)
        {
            return a - tmp;
        }
    }
    else
    {
        // now we know that rhs can be safely cast into an std::uint64_t
        tmp = (uint64_t)a + (uint64_t)b;

        // We added and it did not become smaller
        if (tmp >= a)
        {
            return tmp;
        }
    }

    safe_math_fail("safe_math_fail safe_add_uint64_int32");
}

inline uint64_t safe_add_uint64_uint32(uint64_t a, uint32_t b)
{
    uint64_t tmp = (uint64_t)a + (uint64_t)b;

    // We added and it didn't get smaller
    if (tmp >= a)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_add_uint64_uint32");
}

inline uint64_t safe_add_uint64_int64(uint64_t a, int64_t b)
{
    uint64_t tmp = 0;

    if (b < 0)
    {
        // So we're effectively subtracting
        tmp = safe_abs64(b);

        if (tmp <= a)
        {
            return a - tmp;
        }
    }
    else
    {
        // now we know that rhs can be safely cast into an std::uint64_t
        tmp = (uint64_t)a + (uint64_t)b;

        // We added and it did not become smaller
        if (tmp >= a)
        {
            return tmp;
        }
    }

    safe_math_fail("safe_math_fail safe_add_uint64_int64");
}

inline uint64_t safe_add_uint64_uint64(uint64_t a, uint64_t b)
{
    uint64_t tmp = a + b;

    if(tmp < a)
        safe_math_fail("safe_math_fail safe_add_uint64_uint64");

    return tmp;
}

// As we're working in C, use defines
// It would be nice to use an enum, but the compiler 
// will complain that it isn't a proper C++ enum
#define SAFE_INT_MUL_FAIL 0
#define SAFE_INT_MUL_SUCCESS 1

// Multiplication primatives
#if SAFEINT_MULTIPLY_METHOD == SAFEINT_MULTIPLY_INT128

inline int MultiplyUint64(uint64_t a, uint64_t b, uint64_t* pRet)
{
    unsigned __int128 tmp = (unsigned __int128)a * (unsigned __int128)b;

    if ((tmp >> 64) == 0)
    {
        *pRet = (uint64_t)tmp;
        return SAFE_INT_MUL_SUCCESS;
    }

    return SAFE_INT_MUL_FAIL;
}

inline int MultiplyInt64(int64_t a, int64_t b, int64_t* pRet)
{
    __int128 tmp = (__int128)a * (__int128)b;
    *pRet = (int64_t)tmp;
    int64_t tmp_high = (int64_t)((unsigned __int128)tmp >> 64);

    // If only one input is negative, result must be negative, or zero
    if ((a ^ b) < 0)
    {
        if ((tmp_high == -1 && *pRet < 0) ||
            (tmp_high == 0 && *pRet == 0))
        {
            return SAFE_INT_MUL_SUCCESS;
        }
    }
    else
    {
        if (tmp_high == 0 && (uint64_t)*pRet <= (uint64_t)INT64_MAX)
        {
            return SAFE_INT_MUL_SUCCESS;
        }
    }

    return SAFE_INT_MUL_FAIL;
}

#elif SAFEINT_MULTIPLY_METHOD == SAFEINT_MULTIPLY_INTRINSICS // Implies Visual Studio compiler

// As usual, unsigned is easy
inline int MultiplyUint64(uint64_t a, uint64_t b, uint64_t * pRet)
{
    uint64_t ulHigh = 0;
    *pRet = _umul128(a, b, &ulHigh);
    return ulHigh == 0 ? SAFE_INT_MUL_SUCCESS : SAFE_INT_MUL_FAIL;
}

// Signed, is not so easy
inline int MultiplyInt64(int64_t a, int64_t b, int64_t* pRet)
{
    int64_t llHigh = 0;
    *pRet = _mul128(a, b, &llHigh);

    // Now we need to figure out what we expect
    // If llHigh is 0, then treat *pRet as unsigned
    // If llHigh is < 0, then treat *pRet as signed

    if ((a ^ b) < 0)
    {
        // Negative (or zero) result expected
        if (llHigh == -1 && *pRet < 0 ||
            llHigh == 0 && *pRet == 0)
        {
            // Everything is within range
            return SAFE_INT_MUL_SUCCESS;
        }
    }
    else
    {
        // Result should be positive
        // Check for overflow
        if (llHigh == 0 && (uint64_t)*pRet <= (uint64_t)INT64_MAX)
            return SAFE_INT_MUL_SUCCESS;
    }
    return SAFE_INT_MUL_FAIL;
}
#elif SAFEINT_MULTIPLY_METHOD == SAFEINT_MULTIPLY_BUILTIN // Implies gcc or clang

inline int MultiplyUint64(uint64_t a, uint64_t b, uint64_t* pRet)
{
    return !__builtin_umulll_overflow(a, b, (unsigned long long*)pRet) ? SAFE_INT_MUL_SUCCESS : SAFE_INT_MUL_FAIL;
}

inline int MultiplyInt64(int64_t a, int64_t b, int64_t* pRet)
{
    return !__builtin_smulll_overflow(a, b, (long long*)pRet) ? SAFE_INT_MUL_SUCCESS : SAFE_INT_MUL_FAIL;
}

#elif SAFEINT_MULTIPLY_METHOD == SAFEINT_MULTIPLY_MATH // Just going to have to do the math...

inline int MultiplyUint64(uint64_t a, uint64_t b, uint64_t* pRet)
{
    uint32_t a_high = a >> 32;
    uint32_t a_low = (uint32_t)a;
    uint32_t b_high = b >> 32;
    uint32_t b_low = (uint32_t)b;
    uint64_t tmp = 0;
    uint64_t tmp2 = 0;

    /*
    * Now we have the equivalent of (a_high * 2^32 + a_low) * (b_high * 2^32 + b_low)
    * Expanding:
    * result = a_high * b_high * 2^64 + a_high * b_low * 2^32 + b_high * a_low * 2^32 + a_low * b_low
    * We now get to short circult some things - if a_high > 0 && b_high > 0, fail
    * and this then implies that only one of the two middle expressions must be evaluated and checked if the result is >= 2^32
    * finally, do the last term, check addition
    */

    if (a_high > 0 && b_high > 0)
    {
        return SAFE_INT_MUL_FAIL;
    }

    if (a_high > 0)
    {
        tmp = (uint64_t)a_high * b_low;
    }
    else
    {
        tmp = (uint64_t)b_high * a_low;
    }

    if (tmp >> 32 != 0)
    {
        return SAFE_INT_MUL_FAIL;
    }

    tmp2 = (uint64_t)a_low * b_low;
    *pRet = (tmp << 32) + tmp2;
    return *pRet >= tmp2 ? SAFE_INT_MUL_SUCCESS : SAFE_INT_MUL_FAIL;
}

inline int MultiplyInt64(int64_t a, int64_t b, int64_t* pRet)
{
    bool aNegative = false;
    bool bNegative = false;

    uint64_t tmp = 0;
    int64_t a1 = a;
    int64_t b1 = b;

    if (a1 < 0)
    {
        aNegative = true;
        a1 = (int64_t)safe_abs64(a1);
    }

    if (b1 < 0)
    {
        bNegative = true;
        b1 = (int64_t)safe_abs64(b);
    }

    if (MultiplyUint64((uint64_t)a1, (uint64_t)b1, &tmp))
    {
        // The unsigned multiplication didn't overflow
        if (aNegative ^ bNegative)
        {
            // Result must be negative
            if (tmp <= (uint64_t)INT64_MIN)
            {
                *pRet = negate64(tmp);
                return SAFE_INT_MUL_SUCCESS;
            }
        }
        else
        {
            // Result must be positive
            if (tmp <= (uint64_t)INT64_MAX)
            {
                *pRet = (int64_t)tmp;
                return SAFE_INT_MUL_SUCCESS;
            }
        }
    }

    return SAFE_INT_MUL_FAIL;
}

#else // Shouldn't happen, go find out what's broken
// If you are aware of intrinsics for some other platform, please file an issue
# error Intrinsics enabled, no available intrinics defined
#endif

inline int32_t safe_mul_int32_int32(int32_t a, int32_t b)
{
    int64_t tmp = (int64_t)a * (int64_t)b;
    return safe_cast_int32_int64(tmp);
}

inline int32_t safe_mul_int32_uint32(int32_t a, uint32_t b)
{
    int64_t tmp = (int64_t)a * (int64_t)b;
    return safe_cast_int32_int64(tmp);
}

inline int32_t safe_mul_int32_int64(int32_t a, int64_t b)
{
    int64_t tmp = 0;

    if (MultiplyInt64((int64_t)a, b, &tmp))
    {
        return safe_cast_int32_int64(tmp);
    }

    safe_math_fail("safe_math_fail safe_mul_int32_int64");
}

inline int32_t safe_mul_int32_uint64(int32_t a, uint64_t b)
{
    uint64_t tmp = 0;
    if (a < 0)
    {
        // Flip sign, use the unsigned function
        uint64_t a2 = safe_abs64(a);
        if (MultiplyUint64(a2, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= (uint64_t)INT32_MAX + 1)
        {
            // Not too big, flip it back
            return (int32_t)(tmp + 1);
        }
    }
    else
    {
        if (MultiplyUint64((uint64_t)a, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= INT32_MAX)
        {
            return (int32_t)tmp;
        }
    }
 
    safe_math_fail("safe_math_fail safe_mul_int32_uint64");
}

inline uint32_t safe_mul_uint32_int32(uint32_t a, int32_t b)
{
    int64_t tmp = (int64_t)a * (int64_t)b;
    return safe_cast_uint32_int64(tmp);
}

inline uint32_t safe_mul_uint32_uint32(uint32_t a, uint32_t b)
{
    uint64_t tmp = (uint64_t)a * (uint64_t)b;
    return safe_cast_uint32_uint64(tmp);
}

inline uint32_t safe_mul_uint32_int64(uint32_t a, int64_t b)
{
    int64_t tmp = 0;

    if (MultiplyInt64((int64_t)a, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= UINT32_MAX)
    {
        return (uint32_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint32_int64");
}

inline uint32_t safe_mul_uint32_uint64(uint32_t a, uint64_t b)
{
    uint64_t tmp = 0;

    if (MultiplyUint64((uint64_t)a, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= UINT32_MAX)
    {
        return (uint32_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint32_uint64");
}

inline int64_t safe_mul_int64_int32(int64_t a, int32_t b)
{
    int64_t tmp = 0;

    if (MultiplyInt64(a, (int64_t)b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_int64_int32");
}

inline int64_t safe_mul_int64_uint32(int64_t a, uint32_t b)
{
    int64_t tmp = 0;

    if (MultiplyInt64(a, (int64_t)b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_int64_uint32");
}

inline int64_t safe_mul_int64_int64(int64_t a, int64_t b)
{
    int64_t tmp = 0;

    if (MultiplyInt64(a, b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_int64_int64");
}

inline int64_t safe_mul_int64_uint64(int64_t a, uint64_t b)
{
    uint64_t tmp = 0;

    if (a < 0)
    {
        uint64_t a2 = safe_abs64(a);

        if (MultiplyUint64(a2, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= (uint64_t)0x8000000000000000)
        {
            return negate64((int64_t)tmp);
        }
    }
    else
    {
        if (MultiplyUint64((uint64_t)a, b, &tmp) == SAFE_INT_MUL_SUCCESS && tmp <= (uint64_t)INT64_MAX)
        {
            return (int64_t)tmp;
        }
    }

    safe_math_fail("safe_math_fail safe_mul_int64_uint64");
}

inline uint64_t safe_mul_uint64_int32(uint64_t a, int32_t b)
{
    uint64_t tmp;

    if (b < 0)
    {
        if (a == 0)
            return 0;

        safe_math_fail("safe_math_fail safe_mul_uint64_int32");
    }
   
    if (MultiplyUint64(a, (uint64_t)b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint64_int32");
}

inline uint64_t safe_mul_uint64_uint32(uint64_t a, uint32_t b)
{
    uint64_t tmp;

    if (MultiplyUint64(a, (uint64_t)b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint64_uint32");
}

inline uint64_t safe_mul_uint64_int64(uint64_t a, int64_t b)
{
    uint64_t tmp;

    if (b < 0)
    {
        if (a == 0)
            return 0;

        safe_math_fail("safe_math_fail safe_mul_uint64_int32");
    }

    if (MultiplyUint64(a, (uint64_t)b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint64_int64");
}

inline uint64_t safe_mul_uint64_uint64(uint64_t a, uint64_t b)
{
    uint64_t tmp;

    if (MultiplyUint64(a, b, &tmp) == SAFE_INT_MUL_SUCCESS)
    {
        return tmp;
    }

    safe_math_fail("safe_math_fail safe_mul_uint64_uint64");
}

inline int32_t safe_div_int32_int32(int32_t a, int32_t b)
{
    if (b != 0 && !(a == INT32_MIN && b == -1))
    {
        return a / b;
    }
    safe_math_fail("safe_math_fail safe_div_int32_int32");
}

inline int32_t safe_div_int32_uint32(int32_t a, uint32_t b)
{
    if (b != 0)
    {
        return (int64_t)a / (int64_t)b;
    }
    safe_math_fail("safe_math_fail safe_div_int32_uint32");
}

inline int32_t safe_div_int32_int64(int32_t a, int64_t b)
{
    if (b != 0 && !(a == INT32_MIN && b == -1))
    {
        return (int32_t)(a / b);
    }
    safe_math_fail("safe_math_fail safe_div_int32_int64");
}

inline int32_t safe_div_int32_uint64(int32_t a, uint64_t b)
{
    if (b == 0)
    {
        safe_math_fail("safe_math_fail safe_div_int32_uint64");
    }

    if (a > 0)
    {
        return (int32_t)((uint64_t)a / b);
    }
    else
    {
        uint64_t a2 = (uint64_t)safe_abs32(a);
        a2 /= b;
        return (int32_t)negate32((int32_t)a2);
    }

    safe_math_fail("safe_math_fail safe_div_int32_uint64");
}

inline uint32_t safe_div_uint32_int32(uint32_t a, int32_t b)
{
    if (b > 0)
    {
        return a / b;
    }
    safe_math_fail("safe_math_fail safe_div_uint32_uint64");
}

inline uint32_t safe_div_uint32_uint32(uint32_t a, uint32_t b)
{
    if (b > 0)
    {
        return (uint32_t)(a / b);
    }
    safe_math_fail("safe_math_fail safe_div_uint32_uint32");
}

inline uint32_t safe_div_uint32_int64(uint32_t a, int64_t b)
{
    if (b > 0)
    {
        return (uint32_t)(a / b);
    }
    safe_math_fail("safe_math_fail safe_div_uint32_uint64");
}

inline uint32_t safe_div_uint32_uint64(uint32_t a, uint64_t b)
{
    if (b > 0)
    {
        return (uint32_t)(a / b);
    }
    safe_math_fail("safe_math_fail safe_div_uint32_uint64");
}

inline int64_t safe_div_int64_int32(int64_t a, int32_t b)
{
    if(b == 0 || (b == -1 && a == INT64_MIN))
        safe_math_fail("safe_math_fail safe_div_int64_int32");

    return a / b;
}

inline int64_t safe_div_int64_uint32(int64_t a, uint32_t b)
{
    if (b == 0)
        safe_math_fail("safe_math_fail safe_div_int64_int32");

    return a / b;
}

inline int64_t safe_div_int64_int64(int64_t a, int64_t b)
{
    if (b == 0 || (b == -1 && a == INT64_MIN))
        safe_math_fail("safe_math_fail safe_div_int64_int32");

    return a / b;
}

inline int64_t safe_div_int64_uint64(int64_t a, uint64_t b)
{
    if (b == 0)
        safe_math_fail("safe_math_fail safe_div_int64_int32");

    return a / b;
}

inline uint64_t safe_div_uint64_int32(uint64_t a, int32_t b)
{
    if (b > 0)
        return a / b;

    safe_math_fail("safe_math_fail safe_div_int64_int32");
}

inline uint64_t safe_div_uint64_uint32(uint64_t a, uint32_t b)
{
    if (b != 0)
        return a / b;

    safe_math_fail("safe_math_fail safe_div_int64_uint32");
}

inline uint64_t safe_div_uint64_int64(uint64_t a, int64_t b)
{
    if (b > 0)
        return a / b;

    safe_math_fail("safe_math_fail safe_div_int64_int64");
}

inline uint64_t safe_div_uint64_uint64(uint64_t a, uint64_t b)
{
    if (b != 0)
        return a / b;

    safe_math_fail("safe_math_fail safe_div_int64_uint32");
}

inline int32_t safe_sub_int32_int32(int32_t a, int32_t b)
{
    int64_t tmp = (int64_t)a - (int64_t)b;
    return safe_cast_int32_int64(tmp);
}

inline int32_t safe_sub_int32_uint32(int32_t a, uint32_t b)
{
    int64_t tmp = (int64_t)a - (int64_t)b;
    return safe_cast_int32_int64(tmp);
}

inline int32_t safe_sub_int32_int64(int32_t a, int64_t b)
{
    // We have 4 fairly complex cases:
    // lhs positive, rhs positive - rhs could be larger than lhs can represent
    // lhs positive, rhs negative - additive case - check tmp >= lhs and tmp > max int
    // lhs negative, rhs positive - check tmp <= lhs and tmp < min int
    // lhs negative, rhs negative - addition cannot internally overflow, check against max

    int64_t tmp = (int64_t)((uint64_t)a - (uint64_t)b);

    if (a >= 0)
    {
        // first case
        if (b >= 0)
        {
            if (tmp >= INT32_MIN)
            {
                return (int32_t)tmp;
            }
        }
        else
        {
            // second case
            if (tmp >= a && tmp <= INT32_MAX)
            {
                return (int32_t)tmp;
            }
        }
    }
    else
    {
        // lhs < 0
        // third case
        if (b >= 0)
        {
            if (tmp <= a && tmp >= INT32_MIN)
            {
                return (int32_t)tmp;
            }
        }
        else
        {
            // fourth case
            if (tmp <= INT32_MAX)
            {
                return (int32_t)tmp;
            }
        }
    }

    safe_math_fail("safe_math_fail safe_sub_int32_int64");
}

inline int32_t safe_sub_int32_uint64(int32_t a, uint64_t b)
{
    // We need the absolute value of INT32_MIN
    // This will give it to us without extraneous compiler warnings
    const uint64_t AbsMinInt32 = (uint64_t)INT32_MAX + 1;

    if (a < 0)
    {
        if (b <= AbsMinInt32 - safe_abs32(a))
        {
            return (int32_t)(a - b);
        }
    }
    else
    {
        if (b <= AbsMinInt32 + (uint64_t)a)
        {
            return (int32_t)(a - b);
        }
    }

    safe_math_fail("safe_math_fail safe_sub_int32_uint64");

}

inline uint32_t safe_sub_uint32_int32(uint32_t a, int32_t b)
{
    int64_t tmp = (int64_t)a - (int64_t)b;
    return safe_cast_uint32_int64(tmp);
}

inline uint32_t safe_sub_uint32_uint32(uint32_t a, uint32_t b)
{
    if (a >= b)
        return a - b;

    safe_math_fail("safe_math_fail safe_sub_uint32_uint32");
}

inline uint32_t safe_sub_uint32_int64(uint32_t a, int64_t b)
{
    // must first see if rhs is positive or negative
    if (b >= 0)
    {
        if ((uint64_t)b <= a)
        {
            return (uint32_t)(a - (uint32_t)b);
        }
    }
    else
    {
        // we're now effectively adding
        // since lhs is 32-bit, and rhs cannot exceed 2^63
        // this addition cannot overflow
        uint64_t tmp = a + (uint64_t)negate64(b); // negation safe

        // but we could exceed UINT32_MAX
        if (tmp <= UINT32_MAX)
        {
            return (uint32_t)tmp;
        }
    }

    safe_math_fail("safe_math_fail safe_sub_uint32_int64");
}

inline uint32_t safe_sub_uint32_uint64(uint32_t a, uint64_t b)
{
    if (a >= b)
        return (uint32_t)(a - b);

    safe_math_fail("safe_math_fail safe_sub_uint32_uint64");
}

inline int64_t safe_sub_int64_int32(int64_t a, int32_t b)
{
    // we have essentially 4 cases:
    //
    // 1) lhs positive, rhs positive - overflow not possible
    // 2) lhs positive, rhs negative - equivalent to addition - result >= lhs or error
    // 3) lhs negative, rhs positive - check result <= lhs
    // 4) lhs negative, rhs negative - overflow not possible

    int64_t tmp = (int64_t)((uint64_t)a - (uint64_t)b);

    // Note - ideally, we can order these so that true conditionals
    // lead to success, which enables better pipelining
    // It isn't practical here
    if ((a >= 0 && b < 0 && tmp < a) || // condition 2
        (b >= 0 && tmp > a))              // condition 3
    {
        safe_math_fail("safe_math_fail safe_sub_int64_int32");
    }

    return tmp;
}

inline int64_t safe_sub_int64_uint32(int64_t a, uint32_t b)
{
    // lhs is a 64-bit int, rhs unsigned int32 or smaller
    // perform test as unsigned to prevent unwanted optimizations
    uint64_t tmp = (uint64_t)a - (uint64_t)b;

    if ((int64_t)tmp <= a)
    {
        return (int64_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_sub_int64_int64");
}

inline int64_t safe_sub_int64_int64(int64_t a, int64_t b)
{
    // we have essentially 4 cases:
    //
    // 1) lhs positive, rhs positive - overflow not possible
    // 2) lhs positive, rhs negative - equivalent to addition - result >= lhs or error
    // 3) lhs negative, rhs positive - check result <= lhs
    // 4) lhs negative, rhs negative - overflow not possible

    int64_t tmp = (int64_t)((uint64_t)a - (uint64_t)b);

    // Note - ideally, we can order these so that true conditionals
    // lead to success, which enables better pipelining
    // It isn't practical here
    if ((a >= 0 && b < 0 && tmp < a) || // condition 2
        (b >= 0 && tmp > a))              // condition 3
    {
        safe_math_fail("safe_math_fail safe_sub_int64_int64");
    }

    return tmp;
}

inline int64_t safe_sub_int64_uint64(int64_t a, uint64_t b)
{
    // if we subtract, and it gets larger, there's a problem
    // Perform test as unsigned to prevent unwanted optimizations
    uint64_t tmp = (uint64_t)a - b;

    if ((int64_t)tmp <= a)
    {
        return (int64_t)tmp;
    }

    safe_math_fail("safe_math_fail safe_sub_int64_uint64");
}

inline uint64_t safe_sub_uint64_int32(uint64_t a, int32_t b)
{
    // lhs is an uint64_t, rhs signed
    // must first see if rhs is positive or negative
    if (b >= 0)
    {
        if ((uint64_t)b <= a)
        {
            return (uint64_t)(a - (uint64_t)b);
        }
    }
    else
    {
        uint64_t tmp = a;
        // we're now effectively adding
        uint64_t result = a + safe_abs64(b);

        if (result >= tmp)
            return result;
    }

    safe_math_fail("safe_math_fail safe_sub_uint64_int32");
}

inline uint64_t safe_sub_uint64_uint32(uint64_t a, uint32_t b)
{
    uint64_t tmp = a - b;

    if (tmp <= a)
        return tmp;

    safe_math_fail("safe_math_fail safe_sub_uint64_uint32");
}

inline uint64_t safe_sub_uint64_int64(uint64_t a, int64_t b)
{
    uint64_t result = 0;

    // must first see if rhs is positive or negative
    if (b >= 0)
    {
        if ((uint64_t)b <= a)
        {
            return (a - (uint64_t)b);
        }
    }
    else
    {
        // we're now effectively adding
        result = a + safe_abs64(b);

        if (result >= a)
            return result;
    }

    safe_math_fail("safe_math_fail safe_sub_uint64_int64");
}

inline uint64_t safe_sub_uint64_uint64(uint64_t a, uint64_t b)
{
    uint64_t tmp = a - b;

    if (tmp <= a)
        return tmp;

    safe_math_fail("safe_math_fail safe_sub_uint64_uint64");
}

#ifdef __cplusplus
} 
#endif

#endif // C_SAFE_MATH_IMPL
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#if !defined __GNUC__
// relative include path contains '..', specific to this file
#pragma warning( disable: 4464 )
#endif

#include "../SafeInt.hpp"

#if SAFEINT_USE_INTRINSICS

_CONSTEXPR14 std::int16_t CastInt()
{
    const std::int16_t t1 = 2;
    const std::int16_t u1 = -3;
    std::int16_t r1 = 0;
    if (!MultiplicationHelper< std::int16_t, std::int16_t, MultiplicationState_CastInt>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::uint16_t CastUint()
{
    const std::uint16_t t1 = 2;
    const std::uint16_t u1 = 3;
    std::uint16_t r1 = 0;
    if (!MultiplicationHelper< std::uint16_t, std::uint16_t, MultiplicationState_CastUint>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::int32_t CastInt64()
{
    const std::int32_t t1 = 2;
    const std::int32_t u1 = -3;
    std::int32_t r1 = 0;
    if (!MultiplicationHelper< std::int32_t, std::int32_t, MultiplicationState_CastInt64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::uint32_t CastUint64()
{
    const std::uint32_t t1 = 2;
    const std::uint32_t u1 = 3;
    std::uint32_t r1 = 0;
    if (!MultiplicationHelper< std::uint32_t, std::uint32_t, MultiplicationState_CastUint64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::uint64_t Uint64Uint64()
{
    const std::uint64_t t1 = 2;
    const std::uint64_t u1 = 3;
    std::uint64_t r1 = 0;
    if (!MultiplicationHelper< std::uint64_t, std::uint64_t, MultiplicationState_Uint64Uint64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::uint64_t Uint64Uint()
{
    const std::uint64_t t1 = 2;
    const std::uint32_t u1 = 3;
    std::uint64_t r1 = 0;
    if (!MultiplicationHelper< std::uint64_t, std::uint32_t, MultiplicationState_Uint64Uint>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::uint32_t UintUint64()
{
    const std::uint32_t t1 = 2;
    const std::uint64_t u1 = 3;
    std::uint32_t r1 = 0;
    if (!MultiplicationHelper< std::uint32_t, std::uint64_t, MultiplicationState_UintUint64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::uint64_t Uint64Int()
{
    const std::uint64_t t1 = 2;
    const std::int32_t u1 = 3;
    std::uint64_t r1 = 0;
    if (!MultiplicationHelper< std::uint64_t, std::int32_t, MultiplicationState_Uint64Int>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::uint64_t Uint64Int64()
{
    const std::uint64_t t1 = 2;
    const std::int64_t u1 = 3;
    std::uint64_t r1 = 0;
    if (!MultiplicationHelper< std::uint64_t, std::int64_t, MultiplicationState_Uint64Int64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::uint32_t UintInt64()
{
    const std::uint32_t t1 = 2;
    const std::int64_t u1 = 3;
    std::uint32_t r1 = 0;
    if (!MultiplicationHelper< std::uint32_t, std::int64_t, MultiplicationState_UintInt64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::int64_t Int64Uint()
{
    const std::int64_t t1 = 2;
    const std::uint32_t u1 = 3;
    std::int64_t r1 = 0;
    if (!MultiplicationHelper< std::int64_t, std::uint32_t, MultiplicationState_Int64Uint>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::int64_t Int64Int64()
{
    const std::int64_t t1 = 2;
    const std::int64_t u1 = 3;
    std::int64_t r1 = 0;
    if (!MultiplicationHelper< std::int64_t, std::int64_t, MultiplicationState_Int64Int64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::int64_t Int64Int()
{
    const std::int64_t t1 = 2;
    const std::int32_t u1 = 3;
    std::int64_t r1 = 0;
    if (!MultiplicationHelper< std::int64_t, std::int32_t, MultiplicationState_Int64Int>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14 std::int32_t IntUint64()
{
    const std::int32_t t1 = 2;
    const std::uint64_t u1 = 3;
    std::int32_t r1 = 0;
    if (!MultiplicationHelper< std::int32_t, std::uint64_t, MultiplicationState_IntUint64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::int64_t Int64Uint64()
{
    const std::int64_t t1 = 2;
    const std::uint64_t u1 = 3;
    std::int64_t r1 = 0;

    if (!MultiplicationHelper< std::int64_t, std::uint64_t, MultiplicationState_Int64Uint64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

_CONSTEXPR14_MULTIPLY std::int32_t IntInt64()
{
    const std::int32_t t1 = 2;
    const std::int64_t u1 = 3;
    std::int32_t r1 = 0;
    if (!MultiplicationHelper< std::int32_t, std::int64_t, MultiplicationState_IntInt64>::Multiply(t1, u1, r1))
        return 0;

    return r1;
}

void IntrinsicConstExpr()
{
    // Need to ensure that nothing that calls an intrinsic is marked constexpr, and everything that doesn't call an intrinsic is marked
    static constexpr std::int16_t test1 = CastInt();
    static constexpr std::uint16_t test2 = CastUint();
    static constexpr std::int32_t test3 = CastInt64();
    static constexpr std::uint32_t test4 = CastUint64();
    static _CONSTEXPR14_MULTIPLY std::uint64_t test5 = Uint64Uint64();
    static _CONSTEXPR14_MULTIPLY std::uint64_t test6 = Uint64Uint();
    static constexpr std::uint32_t test7 = UintUint64();
    static _CONSTEXPR14_MULTIPLY std::uint64_t test8 = Uint64Int();
    static _CONSTEXPR14_MULTIPLY std::uint64_t test9 = Uint64Int64();
    static constexpr std::uint32_t test10 = UintInt64();
    static _CONSTEXPR14_MULTIPLY std::int64_t test11 = Int64Uint();
    static _CONSTEXPR14_MULTIPLY std::int64_t test12 = Int64Int64();
    static _CONSTEXPR14_MULTIPLY std::int64_t test13 = Int64Int();
    static constexpr std::int32_t test14 = IntUint64();
    static _CONSTEXPR14_MULTIPLY std::int64_t test15 = Int64Uint64();
    static _CONSTEXPR14_MULTIPLY std::int32_t test16 = IntInt64();
}

#else
void IntrinsicConstExpr(){}
#endif
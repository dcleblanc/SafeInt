// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include <iostream>
#define SAFEINT_USE_INTRINSICS 0

#include "../../../SafeInt.hpp"

/*
Use this to check specific scenarios
*/

#include <string>

int main(int argc, char** argv)
{
    std::uint32_t lhs = 1;            // U = std::uint32_t
    SafeInt<std::uint64_t> bits = 40; // T = std::uint64_t

    auto foo = lhs << bits;

    return 0;
}
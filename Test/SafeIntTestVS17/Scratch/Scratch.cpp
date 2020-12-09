// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include <iostream>
//#define SAFEINT_USE_INTRINSICS 0

#include "../../../SafeInt.hpp"

/*
Use this to check specific scenarios
*/

int main(int argc, char** argv)
{
    SafeInt<uint64_t> z = 0x180000000ull;
    uint64_t y = 2 * argc;
    z *= y;
    return 0;
}
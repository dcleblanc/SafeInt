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
    std::string s = "12345678";

    SafeInt<uint64_t> a = 1;
    int64_t b = 2;

    return a - b;
}
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include <iostream>
#define SAFEINT_USE_INTRINSICS 0

#include "../../../SafeInt.hpp"

/*
Use this to check specific scenarios
*/

unsigned long long Foo(unsigned long long a, unsigned long long b)
{
    SafeInt<unsigned long long> x = SafeInt<unsigned long long>(a) * b;
    return x;
}
int main(int argc, char** argv)
{
    unsigned long long a = argc;
    unsigned long long b = 23;

    unsigned long long x = Foo(a, b);
    if (x > 300)
        printf("Foo\n");

    return 0;
}
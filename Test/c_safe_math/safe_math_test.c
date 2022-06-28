// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

#if defined _MSC_VER
#pragma warning(disable:4464)
#pragma warning(disable:4555)
#endif

#include <stdio.h>
#include "../../safe_math.h"

int main(int argc, char* argv[])
{
	argc;
	argv;

#if defined _CRT_SECURE_INVALID_PARAMETER
	printf("Has _CRT_SECURE_INVALID_PARAMETER\n");
#endif

	printf("SAFEINT_MULTIPLY_METHOD = %d\n", SAFEINT_MULTIPLY_METHOD);

	return 0;
}
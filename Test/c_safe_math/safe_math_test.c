// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

#if defined _MSC_VER
#pragma warning(disable:4464)
#pragma warning(disable:4555)
#pragma warning(disable:5045)
#endif

#include <stdio.h>
//#include "../../safe_math.h"

void add_test(void);
void mult_test(void);
void div_test(void);

int main(int argc, char* argv[])
{
	argc;
	argv;

	add_test();
	mult_test();
	div_test();

	return 0;
}
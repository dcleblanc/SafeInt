// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

#if defined _MSC_VER
#pragma warning(disable:4464)
#pragma warning(disable:4555)
#pragma warning(disable:5045)
#endif

#include <stdio.h>

void add_test(void);
void mult_test(void);
void div_test(void);
void sub_test(void);

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	add_test();
	mult_test();
	div_test();
	sub_test();

	return 0;
}
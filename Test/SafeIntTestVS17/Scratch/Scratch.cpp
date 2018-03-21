#include "../../../SafeInt.hpp"
#include <stdio.h>

/*
Use this to check specific scenarios
*/

int main(int, char**)
{
	__int64 a = 2;
	unsigned long b = 3;
	__int64 ret;

	bool f = SafeAdd(a, b, ret);

	return 0;
}
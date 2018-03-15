#include "../../../SafeInt.hpp"
#include <stdio.h>

/*
Use this to check specific scenarios
*/

constexpr int Foo()
{
	return SafeInt<char>(255) * 5;
}

int main(int, char**)
{
	static const int x = Foo();
	printf("%d", x);
	return 0;
}
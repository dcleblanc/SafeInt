#include "../../../SafeInt.hpp"
#include <stdio.h>

/*
Use this to check specific scenarios
*/

template <typename T, typename U>
_CONSTEXPR14 U LShiftOperator2()
{
	// Have to explicitly force this operator
	// to be used
	U lhs = 3;
	SafeInt<T> s(2);

	SafeInt<U> r = operator <<(lhs, s);
	return r;
}

int main(int, char**)
{
	LShiftOperator2<char, int>();

	return 0;
}
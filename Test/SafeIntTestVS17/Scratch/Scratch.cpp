#include "../../../SafeInt.hpp"

/*
Use this to check specific scenarios
*/
template <typename T, typename U>
void ModulusFriendTest()
{
	U u = 3;
	SafeInt<T> st(1);
	T t = u % st;
}

int main(int, char**)
{
	ModulusFriendTest<long long, long long>();
	return 0;
}
#if !defined __GNUC__
#pragma warning( disable: 4571 4820 4514 4987 4710 4309 4986 4548)
// relative include path contains '..'
// (function) selected for automatic inline expansion
#pragma warning( disable: 4464 4711 )
#endif

#include <iostream>
#include "../SafeInt.hpp"

enum class Foo
{
	Foo1 = 0,
	Foo2
};

void CompileMe()
{
	SafeInt<char> c;
	SafeInt<unsigned char> uc;
	SafeInt<signed char> sc;
	SafeInt<unsigned short> us;
	SafeInt<signed short> ss;
	SafeInt<unsigned int> ui;
	SafeInt<signed int> si;
	SafeInt<unsigned long> ul;
	SafeInt<signed long> sl;
	SafeInt<unsigned long long> ull;
	SafeInt<signed long long> sll;
	
	// Test some initialization
	SafeInt<int> i(Foo::Foo1);

}

int main(int, char**)
{
  std::cout << "It compiles!\n";
  return 0;
}

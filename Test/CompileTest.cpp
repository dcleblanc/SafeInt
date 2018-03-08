#if !defined __GNUC__
#pragma warning( disable: 4571 4820 4514 4987 4710 4309 4986 4548)
// relative include path contains '..'
// (function) selected for automatic inline expansion
#pragma warning( disable: 4464 4711 )
#else
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include <iostream>
#include "../SafeInt.hpp"

enum class Foo
{
	Foo1 = 0,
	Foo2
};

template <typename T, typename U>
void CompiledMixedType()
{
	// Mixed constructors
	U u = 0;
	SafeInt<T> st(u);
	SafeInt<U> su(u);
	SafeInt<T> st2(su);
}

template <typename T>
void CompileType()
{
	// Test constructors
	SafeInt<T> s;
	SafeInt<T> i(Foo::Foo1);
	T t = 0;
	SafeInt<T> st(t);
	SafeInt<T> b(false);

	// Mixed operations
	CompiledMixedType<T, char>();
	CompiledMixedType<T, signed char>();
	CompiledMixedType<T, unsigned char>();
	CompiledMixedType<T, short>();
	CompiledMixedType<T, unsigned short>();
	CompiledMixedType<T, int>();
	CompiledMixedType<T, unsigned int>();
	CompiledMixedType<T, long>();
	CompiledMixedType<T, unsigned long>();
	CompiledMixedType<T, long long>();
	CompiledMixedType<T, unsigned long long>();
}

void CompileMe()
{
	CompileType<char>();
	CompileType<unsigned char>();
	CompileType<signed char>();

	CompileType<unsigned short>();
	CompileType<signed short>();
	CompileType<unsigned int>();
	CompileType<signed int>();
	CompileType<unsigned long>();
	CompileType<signed long>();
	CompileType<unsigned long long>();
	CompileType<signed long long>();
}

int main(int, char**)
{
  std::cout << "It compiles!\n";
  return 0;
}

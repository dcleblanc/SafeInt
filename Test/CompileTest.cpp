// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#if !defined __GNUC__
#pragma warning( disable: 4571 4820 4514 4987 4710 4309 4986 4548 4189)
// relative include path contains '..'
// (function) selected for automatic inline expansion
#pragma warning( disable: 4464 4711 )
#else
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include "../SafeInt.hpp"

void ConstExpr();

enum class Foo
{
	Foo1 = 0,
	Foo2
};

template <typename T, typename U>
void ModulusFriendTest()
{
	U u = 3;
	SafeInt<T> st(1);
	T t = u % st;
}

template <typename T, typename U>
void CompiledMixedType()
{
	// Mixed constructors
	U u = 0;
	T t = 0;
	bool b = false;
	SafeInt<T> st(u);
	SafeInt<U> su(u);
	SafeInt<T> st2(su);

	// Shut up the compiler
	b = !b;

	// Assignment
	st = t;
	st = u;
	st = su;
	st = st2;

	// Casting
	U u2 = (U)st;

	// Multiplication
	t = st * u;
	t = st * st2;
	t = u * st;
	st *= u;
	st *= su;

	// Modulus, modulus assignment
	u = 1;
	st = 1;
	su = 1;
	// For some reason, this is annoying the VS17 link time code generation
//	t = u % st;

	t = st % u;
	st2 = 1;
	t = st % st2;
	st %= u;
	st %= su;

	// Division
	u = 1;
	st2 = 1;
	st = 1;
	t = st / u;
	t = st / st2;
	t = u / st;
	st /= u;
	st /= su;

	// Addition
	t = st + u;
	t = st + st2;
	t = u + st;
	st += u;
	st += su;

	// Subtraction
	st = 0;
	u = 0;
	st2 = 0;
	t = st - u;
	t = st - st2;
	t = u - st;
	st -= u;

	st = 1;
	su = 1;
	st -= su;

	// Shift operators
	u = 1;
	su = 1;
	// Left
	t = st << u;
	t = st << su;
	t = t << su;

	st <<= u;
	st <<= su;

	// Right
	t = st >> u;
	t = st >> su;
	t = t >> su;

	st >>= u;
	st >>= su;

	// Binary operations
	// And
	t = st & st2;
	t = st & u;
	t = t & su;

	st &= st2;
	st &= u;
	st &= su;

	// Or
	t = st | st2;
	t = st | u;
	t = t | su;

	st |= st2;
	st |= u;
	st |= su;

	// Xor
	t = st ^ st2;
	t = st ^ u;
	t = t ^ su;

	st ^= st2;
	st ^= u;
	st ^= su;

	// Comparisons
	// Less than
	b = st < su;
	b = st < u;
	b = u < st;
	b = st < su;

	// Less than or equal
	b = st <= su;
	b = st <= u;
	b = u <= st;
	b = st <= su;

	// Greater than
	b = st > su;
	b = st > u;
	b = u > st;
	b = st > su;

	// Greater than or equal
	b = st >= su;
	b = st >= u;
	b = u >= st;
	b = st >= su;

	// Equals
	b = st == su;
	b = st == u;
	b = u == st;
	b = st == su;
}

template <typename T>
void CompileSigned()
{
	SafeInt<T> st;
	T t = -st;
}

template <typename T>
void CompileType()
{
	// Test constructors
	SafeInt<T> s;
	SafeInt<T> i(Foo::Foo1);
	T t = 0;
	SafeInt<T> st(t);
	SafeInt<T> sb(false);

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

	// This is making trouble for the compiler
	ModulusFriendTest<T, char>();
	ModulusFriendTest<T, signed char>();
	ModulusFriendTest<T, unsigned char>();
	ModulusFriendTest<T, short>();
	ModulusFriendTest<T, unsigned short>();
	ModulusFriendTest<T, int>();
	ModulusFriendTest<T, unsigned int>();
	ModulusFriendTest<T, long>();
	ModulusFriendTest<T, unsigned long>();
	ModulusFriendTest<T, long long>();
	ModulusFriendTest<T, unsigned long long>();
	
	// Special case casts
	bool b = (bool)s;
	wchar_t w = (wchar_t)s;
	size_t size = (size_t)s;
	float f = (float)s;
	double d = (double)s;
	long double ld = (long double)s;

	// Pointer operations
	T* p1 = s.Ptr();
	const T* p2 = s.Ptr();
	const T& r = s.Ref();
	T* p3 = &s;
	const T* p4 = &s;

	// Unary operators
	bool b2 = !st;
	t = +st;

	st++;
	++st;
	st--;
	--st;
	t = ~st;

	// Get compile time coverage of negation
	T x = 1;
	T result;

	SafeNegation(x, result);

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

	CompileSigned<signed char>();
	CompileSigned<signed short>();
	CompileSigned<signed int>();
	CompileSigned<signed long>();
	CompileSigned<signed long long>();

}

/*
	Need to add tests for the miscellaneous helper functions
	Min, Max, Align, Swap
	Also need the pointer functions
*/
int main(int, char**)
{
	CompileMe();
	void ConstExpr();
	return 0;
}

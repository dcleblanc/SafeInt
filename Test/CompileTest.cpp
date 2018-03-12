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

	// Modulus, modulus assignment
	u = 1;
	t = st % u;
	st2 = 1;
	t = st % st2;
	t = u % st;

	st %= u;
	st %= su;

	// Multiplication
	t = st * u;
	t = st * st2;
	t = u * st;
	st *= u;
	st *= su;

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
	t = st - u;
	t = st - st2;
	t = u - st;
	st -= u;
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

	CompileSigned<signed char>();
	CompileSigned<signed short>();
	CompileSigned<signed int>();
	CompileSigned<signed long>();
	CompileSigned<signed long long>();

}

namespace TestConstExpr
{
	template <typename T, typename U>
	_CONSTEXPR11 bool LessThanTest()
	{
		return
			(U)2 < SafeInt<T>(3) &&
			SafeInt<T>(4) < (U)5 &&
			SafeInt<T>(6) < SafeInt<U>(7);
	}

	template <typename T, typename U>
	_CONSTEXPR11 bool GreaterThanTest()
	{
		return
			(U)2 > SafeInt<T>(3) &&
			SafeInt<T>(4) > (U)5 &&
			SafeInt<T>(6) > SafeInt<U>(7);
	}

	template <typename T, typename U>
	_CONSTEXPR11 bool LessThanEqualTest()
	{
		return
			(U)2 <= SafeInt<T>(3) &&
			SafeInt<T>(4) <= (U)5 &&
			SafeInt<T>(6) <= SafeInt<U>(7);
	}

	template <typename T, typename U>
	_CONSTEXPR11 bool GreaterThanEqualTest()
	{
		return
			(U)2 >= SafeInt<T>(3) &&
			SafeInt<T>(4) >= (U)5 &&
			SafeInt<T>(6) >= SafeInt<U>(7);
	}

	template <typename T, typename U>
	_CONSTEXPR11 bool EqualTest()
	{
		return
			(U)2 == SafeInt<T>(3) &&
			SafeInt<T>(4) == (U)5 &&
			SafeInt<T>(6) == SafeInt<U>(7) &&
			true == SafeInt<T>(1) &&
			false == SafeInt<T>(0);
	}

	template <typename T, typename U>
	_CONSTEXPR11 bool NotEqualTest()
	{
		return
			(U)2 != SafeInt<T>(3) &&
			SafeInt<T>(4) != (U)5 &&
			SafeInt<T>(6) != SafeInt<U>(7) &&
			true != SafeInt<T>(1) &&
			false != SafeInt<T>(0);
	}

	template <typename T, typename U>
	void ComparisonTestTU()
	{
		static bool b1 = LessThanTest<T, U>();
		static bool b2 = LessThanEqualTest<T, U>();
		static bool b3 = GreaterThanTest<T, U>();
		static bool b4 = GreaterThanEqualTest<T, U>();
		static bool b5 = EqualTest<T, U>();
		static bool b6 = NotEqualTest<T, U>();
	}

	template <typename T> void ComparisonTestT()
	{
		ComparisonTestTU<T, char>();
		ComparisonTestTU<T, signed char>();
		ComparisonTestTU<T, unsigned char>();
		ComparisonTestTU<T, signed short>();
		ComparisonTestTU<T, unsigned short>();
		ComparisonTestTU<T, signed int>();
		ComparisonTestTU<T, unsigned int>();
		ComparisonTestTU<T, signed long>();
		ComparisonTestTU<T, unsigned long>();
		ComparisonTestTU<T, signed long long>();
		ComparisonTestTU<T, unsigned long long>();
	}

	template <typename T>
	_CONSTEXPR11 T ConstConstructor()
	{
		// Constructors, also add in the useless unary + operator
		return SafeInt<T>() + SafeInt<T>(1) + SafeInt<T>(false) + (+SafeInt<T>(3));
	}

	template <typename T>
	_CONSTEXPR11 bool ConstBool()
	{
		return (bool)SafeInt<T>(2) && !SafeInt<T>(0);
	}

	template <typename T>
	void ConstTestT()
	{
		static const T t = ConstConstructor<T>();
		static const bool b = ConstBool<T>();
	}

	void ConstExprTest()
	{
		ConstTestT<char>();
		ConstTestT<signed char>();
		ConstTestT<unsigned char>();
		ConstTestT<signed short>();
		ConstTestT<unsigned short>();
		ConstTestT<signed int>();
		ConstTestT<unsigned int>();
		ConstTestT<signed long>();
		ConstTestT<unsigned long>();
		ConstTestT<signed long long>();
		ConstTestT<unsigned long long>();

		// Catch the SafePtrDiff function, since it is marked. Can't think of a scenario for this being constexpr, though.
		const char* p1 = (char*)1;
		const char* p2 = nullptr;

		static const SafeInt<ptrdiff_t> pt = SafePtrDiff(p1, p2);

		// Now the comparison test ComparisonTestT
		ComparisonTestT<char>();
		ComparisonTestT<signed char>();
		ComparisonTestT<unsigned char>();
		ComparisonTestT<signed short>();
		ComparisonTestT<unsigned short>();
		ComparisonTestT<signed int>();
		ComparisonTestT<unsigned int>();
		ComparisonTestT<signed long>();
		ComparisonTestT<unsigned long>();
		ComparisonTestT<signed long long>();
		ComparisonTestT<unsigned long long>();

	}

}

/*
	Need to add tests for the miscellaneous helper functions
	Min, Max, Align, Swap
	Also need the pointer functions
*/
int main(int, char**)
{
	CompileMe();
	TestConstExpr::ConstExprTest();
	std::cout << "It compiles!\n";
	return 0;
}

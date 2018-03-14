#if !defined __GNUC__
// relative include path contains '..', specific to this file
#pragma warning( disable: 4464 )

#else
// #pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include "../SafeInt.hpp"

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

	_CONSTEXPR14 int ConstAdditionTest()
	{
		return (SafeInt<int>(3) + 4) + SafeInt<int>(5);
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

		static const int i = ConstAdditionTest();

	}

}

void ConstExpr()
{
	TestConstExpr::ConstExprTest();
}
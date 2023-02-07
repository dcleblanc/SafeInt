// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

#if defined _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4365) // signed/unsigned mismatch in iostream
#endif

#include <exception>
#include <assert.h>
#include <iostream>
#include <string>
#include <cstdint>

#if defined _MSC_VER
#pragma warning(pop)
#pragma warning(disable: 4514 5045 4464 4820)
#endif


#if defined __clang__ || defined __GNUC__
#define NORETURN __attribute__((noreturn))
#elif defined _MSC_VER
#define NORETURN __declspec(noreturn)
#else
#define NORETURN
#endif

// This has to be done in C++ so we can catch exceptions, not abort
NORETURN inline void safe_math_fail(const char* msg)
{
	throw std::runtime_error(msg);
}

#define SAFE_MATH_FAIL_DEFINED
#include "../../safe_math.h"
#include "../TestCase.h"

// Suppress warnings in test files
#if defined _MSC_VER
#pragma warning(disable: 4838)
#endif

template <typename T, typename U>
struct check_test
{
	template<typename F>
	bool operator()(F f, T t, U u, T* ret)
	{
		return f(t, u, ret);
	}
};

template <typename T, typename U>
struct safe_test
{
	template<typename F>
	T operator()(F f, T t, U u)
	{
		return f(t, u);
	}
};

template <typename T, typename U, typename F1, typename F2, int op>
void test_base(const char* type_str, F1 fcn1, F2 fcn2)
{
	TestVector< T, U, op > tests;
	TestCase<T, U, op > test = tests.GetNext();

	while (!tests.Done())
	{
		T ret;

		// err_msg(std::string(OpName::op_name(op)) + "_test_" + type_str + " enter: ", test.x, test.y, test.fExpected);

		check_test<T, U> ct;
		bool result = ct.operator()(fcn1, test.x, test.y, &ret);

		if (!!result != test.fExpected)
		{
			std::string msg = std::string("Failure in ") + OpName::op_name(op) + "_test_" + type_str;
			// err_msg(msg, test.x, test.y, test.fExpected);
			throw std::runtime_error(msg.c_str());
		}

		bool actual;
		try
		{
			safe_test<T, U> st;
			ret = st.operator()(fcn2, test.x, test.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test.fExpected)
		{
			std::string msg = std::string("Failure in ") + OpName::op_name(op) + "_test_" + type_str;
			// err_msg(msg, test.x, test.y, test.fExpected);
			throw std::runtime_error(msg.c_str());
		}

		// err_msg(std::string(OpName::op_name(op)) + "_test_" + type_str + " completed: ", test.x, test.y, test.fExpected);
		test = tests.GetNext();
	}
}

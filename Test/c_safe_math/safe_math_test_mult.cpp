#include "safe_math_test.h"
#include "../MultVerify.h"
#include <string>

using namespace mult_verify;

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

template <typename T, typename U, typename F1, typename F2>
void mult_test_base(const char* type_str, F1 fcn1, F2 fcn2)
{
	MultTestCase< T, U> tests;
	MultTest<T, U> test = tests.GetNext();

	while (!tests.Done())
	{
		T ret;

		check_test<T, U> ct;
		bool result = ct.operator()(fcn1, test.x, test.y, &ret);

		if (!!result != test.fExpected)
		{
			std::string msg = std::string("Failure in mult_test_") + type_str;

			assert(false);
			throw std::exception(msg.c_str());
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
			std::string msg = std::string("Failure in mult_test_") + type_str;

			assert(false);
			throw std::exception(msg.c_str());
		}

		test = tests.GetNext();
	}
}

void mult_test_uint64_uint64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint64_t);

	mult_test_base<std::uint64_t, std::uint64_t, test_fcn, check_fcn>("uint64_uint64", &check_mul_uint64_uint64, &safe_mul_uint64_uint64);
}

void mult_test_uint64_uint32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint32_t);

	mult_test_base<std::uint64_t, std::uint32_t, test_fcn, check_fcn>("uint64_uint32", &check_mul_uint64_uint32, &safe_mul_uint64_uint32);
}

void mult_test_uint64_int64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int64_t);

	mult_test_base<std::uint64_t, std::int64_t, test_fcn, check_fcn>("uint64_int64", &check_mul_uint64_int64, &safe_mul_uint64_int64);
}

void mult_test_uint64_int32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int32_t);

	mult_test_base<std::uint64_t, std::int32_t, test_fcn, check_fcn>("uint64_int32", &check_mul_uint64_int32, &safe_mul_uint64_int32);
}

void mult_test_int64_uint64()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint64_t);

	mult_test_base<std::int64_t, std::uint64_t, test_fcn, check_fcn>("int64_uint64", &check_mul_int64_uint64, &safe_mul_int64_uint64);
}

void mult_test_int64_uint32()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint32_t);

	mult_test_base<std::int64_t, std::uint32_t, test_fcn, check_fcn>("int64_uint32", &check_mul_int64_uint32, &safe_mul_int64_uint32);
}

void mult_test_int64_int64()
{
	typedef bool (*test_fcn)(std::int64_t, std::int64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int64_t);

	mult_test_base<std::int64_t, std::int64_t, test_fcn, check_fcn>("int64_int64", &check_mul_int64_int64, &safe_mul_int64_int64);
}

void mult_test_int64_int32()
{
	typedef bool (*test_fcn)(std::int64_t, std::int32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int32_t);

	mult_test_base<std::int64_t, std::int32_t, test_fcn, check_fcn>("int64_int32", &check_mul_int64_int32, &safe_mul_int64_int32);
}

void mult_test_uint32_uint64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint64_t);

	mult_test_base<std::uint32_t, std::uint64_t, test_fcn, check_fcn>("uint32_uint64", &check_mul_uint32_uint64, &safe_mul_uint32_uint64);
}

void mult_test_uint32_uint32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint32_t);

	mult_test_base<std::uint32_t, std::uint32_t, test_fcn, check_fcn>("uint32_uint32", &check_mul_uint32_uint32, &safe_mul_uint32_uint32);
}

void mult_test_uint32_int64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int64_t);

	mult_test_base<std::uint32_t, std::int64_t, test_fcn, check_fcn>("uint32_int64", &check_mul_uint32_int64, &safe_mul_uint32_int64);
}

void mult_test_uint32_int32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int32_t);

	mult_test_base<std::uint32_t, std::int32_t, test_fcn, check_fcn>("uint32_int32", &check_mul_uint32_int32, &safe_mul_uint32_int32);
}

void mult_test_int32_uint64()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint64_t);

	mult_test_base<std::int32_t, std::uint64_t, test_fcn, check_fcn>("int32_uint64", &check_mul_int32_uint64, &safe_mul_int32_uint64);
}

void mult_test_int32_uint32()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint32_t);

	mult_test_base<std::int32_t, std::uint32_t, test_fcn, check_fcn>("int32_uint32", &check_mul_int32_uint32, &safe_mul_int32_uint32);
}

void mult_test_int32_int64()
{
	typedef bool (*test_fcn)(std::int32_t, std::int64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int64_t);

	mult_test_base<std::int32_t, std::int64_t, test_fcn, check_fcn>("int32_int64", &check_mul_int32_int64, &safe_mul_int32_int64);
}

void mult_test_int32_int32()
{
	typedef bool (*test_fcn)(std::int32_t, std::int32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int32_t);

	mult_test_base<std::int32_t, std::int32_t, test_fcn, check_fcn>("int32_int32", &check_mul_int32_int32, &safe_mul_int32_int32);
}

extern "C" void mult_test()
{
	try
	{
		mult_test_uint64_uint64();
		mult_test_uint64_uint32();
		mult_test_uint64_int64();
		mult_test_uint64_int32();

		mult_test_int64_uint64();
		mult_test_int64_uint32();
		mult_test_int64_int64();
		mult_test_int64_int32();

		mult_test_uint32_uint64();
		mult_test_uint32_uint32();
		mult_test_uint32_int64();
		mult_test_uint32_int32();

		mult_test_int32_uint64();
		mult_test_int32_uint32();
		mult_test_int32_int64();
		mult_test_int32_int32();

		std::cout << "Multiplication tests completed" << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "Multiplication tests failed - " << err.what() << std::endl;
	}

	return;
}
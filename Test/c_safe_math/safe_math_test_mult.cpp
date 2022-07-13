// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net
#if defined _MSC_VER
// Inline expansion warnings
#pragma warning(disable:4710 4711)
#endif

#include "safe_math_test.h"
#include "../TestCase.h"

void mult_test_uint64_uint64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint64_t);

	test_base<std::uint64_t, std::uint64_t, test_fcn, check_fcn, OpType::Mult>("uint64_uint64", &check_mul_uint64_uint64, &safe_mul_uint64_uint64);
}

void mult_test_uint64_uint32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint32_t);

	test_base<std::uint64_t, std::uint32_t, test_fcn, check_fcn, OpType::Mult>("uint64_uint32", &check_mul_uint64_uint32, &safe_mul_uint64_uint32);
}

void mult_test_uint64_int64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int64_t);

	test_base<std::uint64_t, std::int64_t, test_fcn, check_fcn, OpType::Mult>("uint64_int64", &check_mul_uint64_int64, &safe_mul_uint64_int64);
}

void mult_test_uint64_int32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int32_t);

	test_base<std::uint64_t, std::int32_t, test_fcn, check_fcn, OpType::Mult>("uint64_int32", &check_mul_uint64_int32, &safe_mul_uint64_int32);
}

void mult_test_int64_uint64()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint64_t);

	test_base<std::int64_t, std::uint64_t, test_fcn, check_fcn, OpType::Mult>("int64_uint64", &check_mul_int64_uint64, &safe_mul_int64_uint64);
}

void mult_test_int64_uint32()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint32_t);

	test_base<std::int64_t, std::uint32_t, test_fcn, check_fcn, OpType::Mult>("int64_uint32", &check_mul_int64_uint32, &safe_mul_int64_uint32);
}

void mult_test_int64_int64()
{
	typedef bool (*test_fcn)(std::int64_t, std::int64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int64_t);

	test_base<std::int64_t, std::int64_t, test_fcn, check_fcn, OpType::Mult>("int64_int64", &check_mul_int64_int64, &safe_mul_int64_int64);
}

void mult_test_int64_int32()
{
	typedef bool (*test_fcn)(std::int64_t, std::int32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int32_t);

	test_base<std::int64_t, std::int32_t, test_fcn, check_fcn, OpType::Mult>("int64_int32", &check_mul_int64_int32, &safe_mul_int64_int32);
}

void mult_test_uint32_uint64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint64_t);

	test_base<std::uint32_t, std::uint64_t, test_fcn, check_fcn, OpType::Mult>("uint32_uint64", &check_mul_uint32_uint64, &safe_mul_uint32_uint64);
}

void mult_test_uint32_uint32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint32_t);

	test_base<std::uint32_t, std::uint32_t, test_fcn, check_fcn, OpType::Mult>("uint32_uint32", &check_mul_uint32_uint32, &safe_mul_uint32_uint32);
}

void mult_test_uint32_int64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int64_t);

	test_base<std::uint32_t, std::int64_t, test_fcn, check_fcn, OpType::Mult>("uint32_int64", &check_mul_uint32_int64, &safe_mul_uint32_int64);
}

void mult_test_uint32_int32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int32_t);

	test_base<std::uint32_t, std::int32_t, test_fcn, check_fcn, OpType::Mult>("uint32_int32", &check_mul_uint32_int32, &safe_mul_uint32_int32);
}

void mult_test_int32_uint64()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint64_t);

	test_base<std::int32_t, std::uint64_t, test_fcn, check_fcn, OpType::Mult>("int32_uint64", &check_mul_int32_uint64, &safe_mul_int32_uint64);
}

void mult_test_int32_uint32()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint32_t);

	test_base<std::int32_t, std::uint32_t, test_fcn, check_fcn, OpType::Mult>("int32_uint32", &check_mul_int32_uint32, &safe_mul_int32_uint32);
}

void mult_test_int32_int64()
{
	typedef bool (*test_fcn)(std::int32_t, std::int64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int64_t);

	test_base<std::int32_t, std::int64_t, test_fcn, check_fcn, OpType::Mult>("int32_int64", &check_mul_int32_int64, &safe_mul_int32_int64);
}

void mult_test_int32_int32()
{
	typedef bool (*test_fcn)(std::int32_t, std::int32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int32_t);

	test_base<std::int32_t, std::int32_t, test_fcn, check_fcn, OpType::Mult>("int32_int32", &check_mul_int32_int32, &safe_mul_int32_int32);
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
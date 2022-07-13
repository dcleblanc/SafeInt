// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net
#if defined _MSC_VER
// Inline expansion warnings
#pragma warning(disable:4710 4711)
#endif

#include "safe_math_test.h"
#include "../TestCase.h"

void add_test_uint64_uint64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint64_t);

	test_base<std::uint64_t, std::uint64_t, test_fcn, check_fcn, OpType::Add>("uint64_uint64", &check_add_uint64_uint64, &safe_add_uint64_uint64);
}

void add_test_uint64_uint32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint32_t);

	test_base<std::uint64_t, std::uint32_t, test_fcn, check_fcn, OpType::Add>("uint64_uint32", &check_add_uint64_uint32, &safe_add_uint64_uint32);
}

void add_test_uint64_int64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int64_t);

	test_base<std::uint64_t, std::int64_t, test_fcn, check_fcn, OpType::Add>("uint64_int64", &check_add_uint64_int64, &safe_add_uint64_int64);
}

void add_test_uint64_int32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int32_t);

	test_base<std::uint64_t, std::int32_t, test_fcn, check_fcn, OpType::Add>("uint64_int32", &check_add_uint64_int32, &safe_add_uint64_int32);
}

void add_test_int64_uint64()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint64_t);

	test_base<std::int64_t, std::uint64_t, test_fcn, check_fcn, OpType::Add>("int64_uint64", &check_add_int64_uint64, &safe_add_int64_uint64);
}

void add_test_int64_uint32()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint32_t);

	test_base<std::int64_t, std::uint32_t, test_fcn, check_fcn, OpType::Add>("int64_uint32", &check_add_int64_uint32, &safe_add_int64_uint32);
}

void add_test_int64_int64()
{
	typedef bool (*test_fcn)(std::int64_t, std::int64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int64_t);

	test_base<std::int64_t, std::int64_t, test_fcn, check_fcn, OpType::Add>("int64_int64", &check_add_int64_int64, &safe_add_int64_int64);
}

void add_test_int64_int32()
{
	typedef bool (*test_fcn)(std::int64_t, std::int32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int32_t);

	test_base<std::int64_t, std::int32_t, test_fcn, check_fcn, OpType::Add>("int64_int32", &check_add_int64_int32, &safe_add_int64_int32);
}

void add_test_uint32_uint64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint64_t);

	test_base<std::uint32_t, std::uint64_t, test_fcn, check_fcn, OpType::Add>("uint32_uint64", &check_add_uint32_uint64, &safe_add_uint32_uint64);
}

void add_test_uint32_uint32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint32_t);

	test_base<std::uint32_t, std::uint32_t, test_fcn, check_fcn, OpType::Add>("uint32_uint32", &check_add_uint32_uint32, &safe_add_uint32_uint32);
}

void add_test_uint32_int64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int64_t);

	test_base<std::uint32_t, std::int64_t, test_fcn, check_fcn, OpType::Add>("uint32_int64", &check_add_uint32_int64, &safe_add_uint32_int64);
}

void add_test_uint32_int32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int32_t);

	test_base<std::uint32_t, std::int32_t, test_fcn, check_fcn, OpType::Add>("uint32_int32", &check_add_uint32_int32, &safe_add_uint32_int32);
}

void add_test_int32_uint64()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint64_t);

	test_base<std::int32_t, std::uint64_t, test_fcn, check_fcn, OpType::Add>("int32_uint64", &check_add_int32_uint64, &safe_add_int32_uint64);
}

void add_test_int32_uint32()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint32_t);

	test_base<std::int32_t, std::uint32_t, test_fcn, check_fcn, OpType::Add>("int32_uint32", &check_add_int32_uint32, &safe_add_int32_uint32);
}

void add_test_int32_int64()
{
	typedef bool (*test_fcn)(std::int32_t, std::int64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int64_t);

	test_base<std::int32_t, std::int64_t, test_fcn, check_fcn, OpType::Add>("int32_int64", &check_add_int32_int64, &safe_add_int32_int64);
}

void add_test_int32_int32()
{
	typedef bool (*test_fcn)(std::int32_t, std::int32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int32_t);

	test_base<std::int32_t, std::int32_t, test_fcn, check_fcn, OpType::Add>("int32_int32", &check_add_int32_int32, &safe_add_int32_int32);
}

extern "C" void add_test()
{
	try
	{
		add_test_uint64_uint64();
		add_test_uint64_uint32();
		add_test_uint64_int64();
		add_test_uint64_int32();

		add_test_int64_uint64();
		add_test_int64_uint32();
		add_test_int64_int64();
		add_test_int64_int32();

		add_test_uint32_uint64();
		add_test_uint32_uint32();
		add_test_uint32_int64();
		add_test_uint32_int32();

		add_test_int32_uint64();
		add_test_int32_uint32();
		add_test_int32_int64();
		add_test_int32_int32();

		std::cout << "Addition tests completed" << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "Addition tests failed - " << err.what() << std::endl;
	}

	return;
}
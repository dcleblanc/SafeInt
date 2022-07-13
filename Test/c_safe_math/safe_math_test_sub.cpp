// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net
#if defined _MSC_VER
// Inline expansion warnings
#pragma warning(disable:4710 4711)
#endif

#include "safe_math_test.h"
#include "../TestCase.h"

void sub_test_uint64_uint64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint64_t);

	test_base<std::uint64_t, std::uint64_t, test_fcn, check_fcn, OpType::Sub>("uint64_uint64", &check_sub_uint64_uint64, &safe_sub_uint64_uint64);
}

void sub_test_uint64_uint32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::uint32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::uint32_t);

	test_base<std::uint64_t, std::uint32_t, test_fcn, check_fcn, OpType::Sub>("uint64_uint32", &check_sub_uint64_uint32, &safe_sub_uint64_uint32);
}

void sub_test_uint64_int64()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int64_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int64_t);

	test_base<std::uint64_t, std::int64_t, test_fcn, check_fcn, OpType::Sub>("uint64_int64", &check_sub_uint64_int64, &safe_sub_uint64_int64);
}

void sub_test_uint64_int32()
{
	typedef bool (*test_fcn)(std::uint64_t, std::int32_t, std::uint64_t*);
	typedef std::uint64_t(*check_fcn)(std::uint64_t, std::int32_t);

	test_base<std::uint64_t, std::int32_t, test_fcn, check_fcn, OpType::Sub>("uint64_int32", &check_sub_uint64_int32, &safe_sub_uint64_int32);
}

void sub_test_int64_uint64()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint64_t);

	test_base<std::int64_t, std::uint64_t, test_fcn, check_fcn, OpType::Sub>("int64_uint64", &check_sub_int64_uint64, &safe_sub_int64_uint64);
}

void sub_test_int64_uint32()
{
	typedef bool (*test_fcn)(std::int64_t, std::uint32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::uint32_t);

	test_base<std::int64_t, std::uint32_t, test_fcn, check_fcn, OpType::Sub>("int64_uint32", &check_sub_int64_uint32, &safe_sub_int64_uint32);
}

void sub_test_int64_int64()
{
	typedef bool (*test_fcn)(std::int64_t, std::int64_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int64_t);

	test_base<std::int64_t, std::int64_t, test_fcn, check_fcn, OpType::Sub>("int64_int64", &check_sub_int64_int64, &safe_sub_int64_int64);
}

void sub_test_int64_int32()
{
	typedef bool (*test_fcn)(std::int64_t, std::int32_t, std::int64_t*);
	typedef std::int64_t(*check_fcn)(std::int64_t, std::int32_t);

	test_base<std::int64_t, std::int32_t, test_fcn, check_fcn, OpType::Sub>("int64_int32", &check_sub_int64_int32, &safe_sub_int64_int32);
}

void sub_test_uint32_uint64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint64_t);

	test_base<std::uint32_t, std::uint64_t, test_fcn, check_fcn, OpType::Sub>("uint32_uint64", &check_sub_uint32_uint64, &safe_sub_uint32_uint64);
}

void sub_test_uint32_uint32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::uint32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::uint32_t);

	test_base<std::uint32_t, std::uint32_t, test_fcn, check_fcn, OpType::Sub>("uint32_uint32", &check_sub_uint32_uint32, &safe_sub_uint32_uint32);
}

void sub_test_uint32_int64()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int64_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int64_t);

	test_base<std::uint32_t, std::int64_t, test_fcn, check_fcn, OpType::Sub>("uint32_int64", &check_sub_uint32_int64, &safe_sub_uint32_int64);
}

void sub_test_uint32_int32()
{
	typedef bool (*test_fcn)(std::uint32_t, std::int32_t, std::uint32_t*);
	typedef std::uint32_t(*check_fcn)(std::uint32_t, std::int32_t);

	test_base<std::uint32_t, std::int32_t, test_fcn, check_fcn, OpType::Sub>("uint32_int32", &check_sub_uint32_int32, &safe_sub_uint32_int32);
}

void sub_test_int32_uint64()
{
	typedef bool (*test_fcn)(std::int32_t, std::uint64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint64_t);

	test_base<std::int32_t, std::uint64_t, test_fcn, check_fcn, OpType::Sub>("int32_uint64", &check_sub_int32_uint64, &safe_sub_int32_uint64);
}

void sub_test_int32_uint32()
{
	trace t(false);
	typedef bool (*test_fcn)(std::int32_t, std::uint32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::uint32_t);

	test_base<std::int32_t, std::uint32_t, test_fcn, check_fcn, OpType::Sub>("int32_uint32", &check_sub_int32_uint32, &safe_sub_int32_uint32);
	t.trace_msg("completed sub_test_int32_uint64");
}

void sub_test_int32_int64()
{
	typedef bool (*test_fcn)(std::int32_t, std::int64_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int64_t);

	test_base<std::int32_t, std::int64_t, test_fcn, check_fcn, OpType::Sub>("int32_int64", &check_sub_int32_int64, &safe_sub_int32_int64);
}

void sub_test_int32_int32()
{
	typedef bool (*test_fcn)(std::int32_t, std::int32_t, std::int32_t*);
	typedef std::int32_t(*check_fcn)(std::int32_t, std::int32_t);

	test_base<std::int32_t, std::int32_t, test_fcn, check_fcn, OpType::Sub>("int32_int32", &check_sub_int32_int32, &safe_sub_int32_int32);
}

extern "C" void sub_test()
{
	try
	{
		sub_test_uint64_uint64();
		sub_test_uint64_uint32();
		sub_test_uint64_int64();
		sub_test_uint64_int32();

		sub_test_int64_uint64();
		sub_test_int64_uint32();
		sub_test_int64_int64();
		sub_test_int64_int32();

		sub_test_uint32_uint64();
		sub_test_uint32_uint32();
		sub_test_uint32_int64();
		sub_test_uint32_int32();

		sub_test_int32_uint64();
		sub_test_int32_uint32();
		sub_test_int32_int64();
		sub_test_int32_int32();

		std::cout << "Subtraction tests completed" << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "Subtraction tests failed - " << err.what() << std::endl;
	}

	return;
}
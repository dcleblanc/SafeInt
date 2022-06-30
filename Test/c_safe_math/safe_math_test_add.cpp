#include "safe_math_test.h"

struct add_test_uint64_uint64
{
	uint64_t x;
	uint64_t y;
	bool fExpected;
};

static const struct add_test_uint64_uint64 uint64_uint64[] =
{
	{ 0x0000000000000000, 0x0000000000000000, true},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000000, true},
	{ 0x000000007ffffffe, 0x0000000000000000, true},
	{ 0x000000007fffffff, 0x0000000000000000, true},
	{ 0x0000000080000000, 0x0000000000000000, true},
	{ 0x0000000080000001, 0x0000000000000000, true},
	{ 0x00000000fffffffe, 0x0000000000000000, true},
	{ 0x00000000ffffffff, 0x0000000000000000, true},
	{ 0x0000000100000000, 0x0000000000000000, true},
	{ 0x0000000200000000, 0x0000000000000000, true},
	{ 0x7ffffffffffffffe, 0x0000000000000000, true},
	{ 0x7fffffffffffffff, 0x0000000000000000, true},
	{ 0x8000000000000000, 0x0000000000000000, true},
	{ 0x8000000000000001, 0x0000000000000000, true},
	{ 0xfffffffffffffffe, 0x0000000000000000, true},
	{ 0xffffffffffffffff, 0x0000000000000000, true},

	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000001, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x0000000000000001, true},
	{ 0x000000007fffffff, 0x0000000000000001, true},
	{ 0x0000000080000000, 0x0000000000000001, true},
	{ 0x0000000080000001, 0x0000000000000001, true},
	{ 0x00000000fffffffe, 0x0000000000000001, true},
	{ 0x00000000ffffffff, 0x0000000000000001, true},
	{ 0x0000000100000000, 0x0000000000000001, true},
	{ 0x0000000200000000, 0x0000000000000001, true},
	{ 0x7ffffffffffffffe, 0x0000000000000001, true},
	{ 0x7fffffffffffffff, 0x0000000000000001, true},
	{ 0x8000000000000000, 0x0000000000000001, true},
	{ 0x8000000000000001, 0x0000000000000001, true},
	{ 0xfffffffffffffffe, 0x0000000000000001, true},
	{ 0xffffffffffffffff, 0x0000000000000001, false},

	{ 0x0000000000000000, 0x0000000000000002, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000002, true},
	{ 0x000000007ffffffe, 0x0000000000000002, true},
	{ 0x000000007fffffff, 0x0000000000000002, true},
	{ 0x0000000080000000, 0x0000000000000002, true},
	{ 0x0000000080000001, 0x0000000000000002, true},
	{ 0x00000000fffffffe, 0x0000000000000002, true},
	{ 0x00000000ffffffff, 0x0000000000000002, true},
	{ 0x0000000100000000, 0x0000000000000002, true},
	{ 0x0000000200000000, 0x0000000000000002, true},
	{ 0x7ffffffffffffffe, 0x0000000000000002, true},
	{ 0x7fffffffffffffff, 0x0000000000000002, true},
	{ 0x8000000000000000, 0x0000000000000002, true},
	{ 0x8000000000000001, 0x0000000000000002, true},
	{ 0xfffffffffffffffe, 0x0000000000000002, false},
	{ 0xffffffffffffffff, 0x0000000000000002, false},

	{ 0x0000000000000000, 0x000000007ffffffe, true},
	{ 0x0000000000000001, 0x000000007ffffffe, true},
	{ 0x0000000000000002, 0x000000007ffffffe, true},
	{ 0x000000007ffffffe, 0x000000007ffffffe, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007ffffffe, true},
	{ 0x0000000080000001, 0x000000007ffffffe, true},
	{ 0x00000000fffffffe, 0x000000007ffffffe, true},
	{ 0x00000000ffffffff, 0x000000007ffffffe, true},
	{ 0x0000000100000000, 0x000000007ffffffe, true},
	{ 0x0000000200000000, 0x000000007ffffffe, true},
	{ 0x7ffffffffffffffe, 0x000000007ffffffe, true},
	{ 0x7fffffffffffffff, 0x000000007ffffffe, true},
	{ 0x8000000000000000, 0x000000007ffffffe, true},
	{ 0x8000000000000001, 0x000000007ffffffe, true},
	{ 0xfffffffffffffffe, 0x000000007ffffffe, false},
	{ 0xffffffffffffffff, 0x000000007ffffffe, false},

	{ 0x0000000000000000, 0x000000007fffffff, true},
	{ 0x0000000000000001, 0x000000007fffffff, true},
	{ 0x0000000000000002, 0x000000007fffffff, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x000000007fffffff, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x000000007fffffff, true},
	{ 0x00000000fffffffe, 0x000000007fffffff, true},
	{ 0x00000000ffffffff, 0x000000007fffffff, true},
	{ 0x0000000100000000, 0x000000007fffffff, true},
	{ 0x0000000200000000, 0x000000007fffffff, true},
	{ 0x7ffffffffffffffe, 0x000000007fffffff, true},
	{ 0x7fffffffffffffff, 0x000000007fffffff, true},
	{ 0x8000000000000000, 0x000000007fffffff, true},
	{ 0x8000000000000001, 0x000000007fffffff, true},
	{ 0xfffffffffffffffe, 0x000000007fffffff, false},
	{ 0xffffffffffffffff, 0x000000007fffffff, false},

	{ 0x0000000000000000, 0x0000000080000000, true},
	{ 0x0000000000000001, 0x0000000080000000, true},
	{ 0x0000000000000002, 0x0000000080000000, true},
	{ 0x000000007ffffffe, 0x0000000080000000, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000000, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x0000000080000000, true},
	{ 0x00000000ffffffff, 0x0000000080000000, true},
	{ 0x0000000100000000, 0x0000000080000000, true},
	{ 0x0000000200000000, 0x0000000080000000, true},
	{ 0x7ffffffffffffffe, 0x0000000080000000, true},
	{ 0x7fffffffffffffff, 0x0000000080000000, true},
	{ 0x8000000000000000, 0x0000000080000000, true},
	{ 0x8000000000000001, 0x0000000080000000, true},
	{ 0xfffffffffffffffe, 0x0000000080000000, false},
	{ 0xffffffffffffffff, 0x0000000080000000, false},

	{ 0x0000000000000000, 0x0000000080000001, true},
	{ 0x0000000000000001, 0x0000000080000001, true},
	{ 0x0000000000000002, 0x0000000080000001, true},
	{ 0x000000007ffffffe, 0x0000000080000001, true},
	{ 0x000000007fffffff, 0x0000000080000001, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000001, true},
	{ 0x00000000fffffffe, 0x0000000080000001, true},
	{ 0x00000000ffffffff, 0x0000000080000001, true},
	{ 0x0000000100000000, 0x0000000080000001, true},
	{ 0x0000000200000000, 0x0000000080000001, true},
	{ 0x7ffffffffffffffe, 0x0000000080000001, true},
	{ 0x7fffffffffffffff, 0x0000000080000001, true},
	{ 0x8000000000000000, 0x0000000080000001, true},
	{ 0x8000000000000001, 0x0000000080000001, true},
	{ 0xfffffffffffffffe, 0x0000000080000001, false},
	{ 0xffffffffffffffff, 0x0000000080000001, false},

	{ 0x0000000000000000, 0x00000000fffffffe, true},
	{ 0x0000000000000001, 0x00000000fffffffe, true},
	{ 0x0000000000000002, 0x00000000fffffffe, true},
	{ 0x000000007ffffffe, 0x00000000fffffffe, true},
	{ 0x000000007fffffff, 0x00000000fffffffe, true},
	{ 0x0000000080000000, 0x00000000fffffffe, true},
	{ 0x0000000080000001, 0x00000000fffffffe, true},
	{ 0x00000000fffffffe, 0x00000000fffffffe, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000fffffffe, true},
	{ 0x0000000200000000, 0x00000000fffffffe, true},
	{ 0x7ffffffffffffffe, 0x00000000fffffffe, true},
	{ 0x7fffffffffffffff, 0x00000000fffffffe, true},
	{ 0x8000000000000000, 0x00000000fffffffe, true},
	{ 0x8000000000000001, 0x00000000fffffffe, true},
	{ 0xfffffffffffffffe, 0x00000000fffffffe, false},
	{ 0xffffffffffffffff, 0x00000000fffffffe, false},

	{ 0x0000000000000000, 0x00000000ffffffff, true},
	{ 0x0000000000000001, 0x00000000ffffffff, true},
	{ 0x0000000000000002, 0x00000000ffffffff, true},
	{ 0x000000007ffffffe, 0x00000000ffffffff, true},
	{ 0x000000007fffffff, 0x00000000ffffffff, true},
	{ 0x0000000080000000, 0x00000000ffffffff, true},
	{ 0x0000000080000001, 0x00000000ffffffff, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x00000000ffffffff, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000000ffffffff, true},
	{ 0x7ffffffffffffffe, 0x00000000ffffffff, true},
	{ 0x7fffffffffffffff, 0x00000000ffffffff, true},
	{ 0x8000000000000000, 0x00000000ffffffff, true},
	{ 0x8000000000000001, 0x00000000ffffffff, true},
	{ 0xfffffffffffffffe, 0x00000000ffffffff, false},
	{ 0xffffffffffffffff, 0x00000000ffffffff, false},

	{ 0x0000000000000000, 0x0000000100000000, true},
	{ 0x0000000000000001, 0x0000000100000000, true},
	{ 0x0000000000000002, 0x0000000100000000, true},
	{ 0x000000007ffffffe, 0x0000000100000000, true},
	{ 0x000000007fffffff, 0x0000000100000000, true},
	{ 0x0000000080000000, 0x0000000100000000, true},
	{ 0x0000000080000001, 0x0000000100000000, true},
	{ 0x00000000fffffffe, 0x0000000100000000, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000000, true},
	{ 0x0000000200000000, 0x0000000100000000, true},
	{ 0x7ffffffffffffffe, 0x0000000100000000, true},
	{ 0x7fffffffffffffff, 0x0000000100000000, true},
	{ 0x8000000000000000, 0x0000000100000000, true},
	{ 0x8000000000000001, 0x0000000100000000, true},
	{ 0xfffffffffffffffe, 0x0000000100000000, false},
	{ 0xffffffffffffffff, 0x0000000100000000, false},

	{ 0x0000000000000000, 0x0000000200000000, true},
	{ 0x0000000000000001, 0x0000000200000000, true},
	{ 0x0000000000000002, 0x0000000200000000, true},
	{ 0x000000007ffffffe, 0x0000000200000000, true},
	{ 0x000000007fffffff, 0x0000000200000000, true},
	{ 0x0000000080000000, 0x0000000200000000, true},
	{ 0x0000000080000001, 0x0000000200000000, true},
	{ 0x00000000fffffffe, 0x0000000200000000, true},
	{ 0x00000000ffffffff, 0x0000000200000000, true},
	{ 0x0000000100000000, 0x0000000200000000, true},
	{ 0x0000000200000000, 0x0000000200000000, true},
	{ 0x7ffffffffffffffe, 0x0000000200000000, true},
	{ 0x7fffffffffffffff, 0x0000000200000000, true},
	{ 0x8000000000000000, 0x0000000200000000, true},
	{ 0x8000000000000001, 0x0000000200000000, true},
	{ 0xfffffffffffffffe, 0x0000000200000000, false},
	{ 0xffffffffffffffff, 0x0000000200000000, false},

	{ 0x0000000000000000, 0x7ffffffffffffffe, true},
	{ 0x0000000000000001, 0x7ffffffffffffffe, true},
	{ 0x0000000000000002, 0x7ffffffffffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffffffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffffffffffe, true},
	{ 0x0000000080000000, 0x7ffffffffffffffe, true},
	{ 0x0000000080000001, 0x7ffffffffffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffffffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffffffffffe, true},
	{ 0x0000000100000000, 0x7ffffffffffffffe, true},
	{ 0x0000000200000000, 0x7ffffffffffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffe, true},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
	{ 0x8000000000000000, 0x7ffffffffffffffe, true},
	{ 0x8000000000000001, 0x7ffffffffffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffffffffffe, false},
	{ 0xffffffffffffffff, 0x7ffffffffffffffe, false},

	{ 0x0000000000000000, 0x7fffffffffffffff, true},
	{ 0x0000000000000001, 0x7fffffffffffffff, true},
	{ 0x0000000000000002, 0x7fffffffffffffff, true},
	{ 0x000000007ffffffe, 0x7fffffffffffffff, true},
	{ 0x000000007fffffff, 0x7fffffffffffffff, true},
	{ 0x0000000080000000, 0x7fffffffffffffff, true},
	{ 0x0000000080000001, 0x7fffffffffffffff, true},
	{ 0x00000000fffffffe, 0x7fffffffffffffff, true},
	{ 0x00000000ffffffff, 0x7fffffffffffffff, true},
	{ 0x0000000100000000, 0x7fffffffffffffff, true},
	{ 0x0000000200000000, 0x7fffffffffffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0x7fffffffffffffff, 0x7fffffffffffffff, true},
	{ 0x8000000000000000, 0x7fffffffffffffff, true},
	{ 0x8000000000000001, 0x7fffffffffffffff, false},
	{ 0xfffffffffffffffe, 0x7fffffffffffffff, false},
	{ 0xffffffffffffffff, 0x7fffffffffffffff, false},

	{ 0x0000000000000000, 0x8000000000000000, true},
	{ 0x0000000000000001, 0x8000000000000000, true},
	{ 0x0000000000000002, 0x8000000000000000, true},
	{ 0x000000007ffffffe, 0x8000000000000000, true},
	{ 0x000000007fffffff, 0x8000000000000000, true},
	{ 0x0000000080000000, 0x8000000000000000, true},
	{ 0x0000000080000001, 0x8000000000000000, true},
	{ 0x00000000fffffffe, 0x8000000000000000, true},
	{ 0x00000000ffffffff, 0x8000000000000000, true},
	{ 0x0000000100000000, 0x8000000000000000, true},
	{ 0x0000000200000000, 0x8000000000000000, true},
	{ 0x7ffffffffffffffe, 0x8000000000000000, true},
	{ 0x7fffffffffffffff, 0x8000000000000000, true},
	{ 0x8000000000000000, 0x8000000000000000, false},
	{ 0x8000000000000001, 0x8000000000000000, false},
	{ 0xfffffffffffffffe, 0x8000000000000000, false},
	{ 0xffffffffffffffff, 0x8000000000000000, false},

	{ 0x0000000000000000, 0x8000000000000001, true},
	{ 0x0000000000000001, 0x8000000000000001, true},
	{ 0x0000000000000002, 0x8000000000000001, true},
	{ 0x000000007ffffffe, 0x8000000000000001, true},
	{ 0x000000007fffffff, 0x8000000000000001, true},
	{ 0x0000000080000000, 0x8000000000000001, true},
	{ 0x0000000080000001, 0x8000000000000001, true},
	{ 0x00000000fffffffe, 0x8000000000000001, true},
	{ 0x00000000ffffffff, 0x8000000000000001, true},
	{ 0x0000000100000000, 0x8000000000000001, true},
	{ 0x0000000200000000, 0x8000000000000001, true},
	{ 0x7ffffffffffffffe, 0x8000000000000001, true},
	{ 0x7fffffffffffffff, 0x8000000000000001, false},
	{ 0x8000000000000000, 0x8000000000000001, false},
	{ 0x8000000000000001, 0x8000000000000001, false},
	{ 0xfffffffffffffffe, 0x8000000000000001, false},
	{ 0xffffffffffffffff, 0x8000000000000001, false},

	{ 0x0000000000000000, 0xfffffffffffffffe, true},
	{ 0x0000000000000001, 0xfffffffffffffffe, true},
	{ 0x0000000000000002, 0xfffffffffffffffe, false},
	{ 0x000000007ffffffe, 0xfffffffffffffffe, false},
	{ 0x000000007fffffff, 0xfffffffffffffffe, false},
	{ 0x0000000080000000, 0xfffffffffffffffe, false},
	{ 0x0000000080000001, 0xfffffffffffffffe, false},
	{ 0x00000000fffffffe, 0xfffffffffffffffe, false},
	{ 0x00000000ffffffff, 0xfffffffffffffffe, false},
	{ 0x0000000100000000, 0xfffffffffffffffe, false},
	{ 0x0000000200000000, 0xfffffffffffffffe, false},
	{ 0x7ffffffffffffffe, 0xfffffffffffffffe, false},
	{ 0x7fffffffffffffff, 0xfffffffffffffffe, false},
	{ 0x8000000000000000, 0xfffffffffffffffe, false},
	{ 0x8000000000000001, 0xfffffffffffffffe, false},
	{ 0xfffffffffffffffe, 0xfffffffffffffffe, false},
	{ 0xffffffffffffffff, 0xfffffffffffffffe, false},

	{ 0x0000000000000000, 0xffffffffffffffff, true},
	{ 0x0000000000000001, 0xffffffffffffffff, false},
	{ 0x0000000000000002, 0xffffffffffffffff, false},
	{ 0x000000007ffffffe, 0xffffffffffffffff, false},
	{ 0x000000007fffffff, 0xffffffffffffffff, false},
	{ 0x0000000080000000, 0xffffffffffffffff, false},
	{ 0x0000000080000001, 0xffffffffffffffff, false},
	{ 0x00000000fffffffe, 0xffffffffffffffff, false},
	{ 0x00000000ffffffff, 0xffffffffffffffff, false},
	{ 0x0000000100000000, 0xffffffffffffffff, false},
	{ 0x0000000200000000, 0xffffffffffffffff, false},
	{ 0x7ffffffffffffffe, 0xffffffffffffffff, false},
	{ 0x7fffffffffffffff, 0xffffffffffffffff, false},
	{ 0x8000000000000000, 0xffffffffffffffff, false},
	{ 0x8000000000000001, 0xffffffffffffffff, false},
	{ 0xfffffffffffffffe, 0xffffffffffffffff, false},
	{ 0xffffffffffffffff, 0xffffffffffffffff, false},
};

void add_test_uint64_uint64()
{
	 
	for (size_t i = 0; i < sizeof(uint64_uint64) / sizeof(struct add_test_uint64_uint64); ++i)
	{
		const struct add_test_uint64_uint64& test_val = uint64_uint64[i];
		uint64_t ret;

		bool result = check_add_uint64_uint64(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

		bool actual;
		try
		{
			ret = safe_add_uint64_uint64(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

	}
}

struct add_test_uint64_uint32
{
	uint64_t x;
	uint32_t y;
	bool fExpected;
};

static const struct add_test_uint64_uint32 uint64_uint32[] =
{
	{ 0x0000000000000000, 0x00000000, true},
	{ 0x0000000000000001, 0x00000000, true},
	{ 0x0000000000000002, 0x00000000, true},
	{ 0x000000007ffffffe, 0x00000000, true},
	{ 0x000000007fffffff, 0x00000000, true},
	{ 0x0000000080000000, 0x00000000, true},
	{ 0x0000000080000001, 0x00000000, true},
	{ 0x00000000fffffffe, 0x00000000, true},
	{ 0x00000000ffffffff, 0x00000000, true},
	{ 0x0000000100000000, 0x00000000, true},
	{ 0x0000000200000000, 0x00000000, true},
	{ 0x7ffffffffffffffe, 0x00000000, true},
	{ 0x7fffffffffffffff, 0x00000000, true},
	{ 0x8000000000000000, 0x00000000, true},
	{ 0x8000000000000001, 0x00000000, true},
	{ 0xfffffffffffffffe, 0x00000000, true},
	{ 0xffffffffffffffff, 0x00000000, true},

	{ 0x0000000000000000, 0x00000001, true},
	{ 0x0000000000000001, 0x00000001, true},
	{ 0x0000000000000002, 0x00000001, true},
	{ 0x000000007ffffffe, 0x00000001, true},
	{ 0x000000007fffffff, 0x00000001, true},
	{ 0x0000000080000000, 0x00000001, true},
	{ 0x0000000080000001, 0x00000001, true},
	{ 0x00000000fffffffe, 0x00000001, true},
	{ 0x00000000ffffffff, 0x00000001, true},
	{ 0x0000000100000000, 0x00000001, true},
	{ 0x0000000200000000, 0x00000001, true},
	{ 0x7ffffffffffffffe, 0x00000001, true},
	{ 0x7fffffffffffffff, 0x00000001, true},
	{ 0x8000000000000000, 0x00000001, true},
	{ 0x8000000000000001, 0x00000001, true},
	{ 0xfffffffffffffffe, 0x00000001, true},
	{ 0xffffffffffffffff, 0x00000001, false},

	{ 0x0000000000000000, 0x00000002, true},
	{ 0x0000000000000001, 0x00000002, true},
	{ 0x0000000000000002, 0x00000002, true},
	{ 0x000000007ffffffe, 0x00000002, true},
	{ 0x000000007fffffff, 0x00000002, true},
	{ 0x0000000080000000, 0x00000002, true},
	{ 0x0000000080000001, 0x00000002, true},
	{ 0x00000000fffffffe, 0x00000002, true},
	{ 0x00000000ffffffff, 0x00000002, true},
	{ 0x0000000100000000, 0x00000002, true},
	{ 0x0000000200000000, 0x00000002, true},
	{ 0x7ffffffffffffffe, 0x00000002, true},
	{ 0x7fffffffffffffff, 0x00000002, true},
	{ 0x8000000000000000, 0x00000002, true},
	{ 0x8000000000000001, 0x00000002, true},
	{ 0xfffffffffffffffe, 0x00000002, false},
	{ 0xffffffffffffffff, 0x00000002, false},

	{ 0x0000000000000000, 0x7ffffffe, true},
	{ 0x0000000000000001, 0x7ffffffe, true},
	{ 0x0000000000000002, 0x7ffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffe, true},
	{ 0x0000000080000000, 0x7ffffffe, true},
	{ 0x0000000080000001, 0x7ffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffe, true},
	{ 0x0000000100000000, 0x7ffffffe, true},
	{ 0x0000000200000000, 0x7ffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffe, true},
	{ 0x7fffffffffffffff, 0x7ffffffe, true},
	{ 0x8000000000000000, 0x7ffffffe, true},
	{ 0x8000000000000001, 0x7ffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffe, false},
	{ 0xffffffffffffffff, 0x7ffffffe, false},

	{ 0x0000000000000000, 0x7fffffff, true},
	{ 0x0000000000000001, 0x7fffffff, true},
	{ 0x0000000000000002, 0x7fffffff, true},
	{ 0x000000007ffffffe, 0x7fffffff, true},
	{ 0x000000007fffffff, 0x7fffffff, true},
	{ 0x0000000080000000, 0x7fffffff, true},
	{ 0x0000000080000001, 0x7fffffff, true},
	{ 0x00000000fffffffe, 0x7fffffff, true},
	{ 0x00000000ffffffff, 0x7fffffff, true},
	{ 0x0000000100000000, 0x7fffffff, true},
	{ 0x0000000200000000, 0x7fffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffff, true},
	{ 0x7fffffffffffffff, 0x7fffffff, true},
	{ 0x8000000000000000, 0x7fffffff, true},
	{ 0x8000000000000001, 0x7fffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffff, false},
	{ 0xffffffffffffffff, 0x7fffffff, false},

	{ 0x0000000000000000, 0x80000000, true},
	{ 0x0000000000000001, 0x80000000, true},
	{ 0x0000000000000002, 0x80000000, true},
	{ 0x000000007ffffffe, 0x80000000, true},
	{ 0x000000007fffffff, 0x80000000, true},
	{ 0x0000000080000000, 0x80000000, true},
	{ 0x0000000080000001, 0x80000000, true},
	{ 0x00000000fffffffe, 0x80000000, true},
	{ 0x00000000ffffffff, 0x80000000, true},
	{ 0x0000000100000000, 0x80000000, true},
	{ 0x0000000200000000, 0x80000000, true},
	{ 0x7ffffffffffffffe, 0x80000000, true},
	{ 0x7fffffffffffffff, 0x80000000, true},
	{ 0x8000000000000000, 0x80000000, true},
	{ 0x8000000000000001, 0x80000000, true},
	{ 0xfffffffffffffffe, 0x80000000, false},
	{ 0xffffffffffffffff, 0x80000000, false},

	{ 0x0000000000000000, 0x80000001, true},
	{ 0x0000000000000001, 0x80000001, true},
	{ 0x0000000000000002, 0x80000001, true},
	{ 0x000000007ffffffe, 0x80000001, true},
	{ 0x000000007fffffff, 0x80000001, true},
	{ 0x0000000080000000, 0x80000001, true},
	{ 0x0000000080000001, 0x80000001, true},
	{ 0x00000000fffffffe, 0x80000001, true},
	{ 0x00000000ffffffff, 0x80000001, true},
	{ 0x0000000100000000, 0x80000001, true},
	{ 0x0000000200000000, 0x80000001, true},
	{ 0x7ffffffffffffffe, 0x80000001, true},
	{ 0x7fffffffffffffff, 0x80000001, true},
	{ 0x8000000000000000, 0x80000001, true},
	{ 0x8000000000000001, 0x80000001, true},
	{ 0xfffffffffffffffe, 0x80000001, false},
	{ 0xffffffffffffffff, 0x80000001, false},

	{ 0x0000000000000000, 0xfffffffe, true},
	{ 0x0000000000000001, 0xfffffffe, true},
	{ 0x0000000000000002, 0xfffffffe, true},
	{ 0x000000007ffffffe, 0xfffffffe, true},
	{ 0x000000007fffffff, 0xfffffffe, true},
	{ 0x0000000080000000, 0xfffffffe, true},
	{ 0x0000000080000001, 0xfffffffe, true},
	{ 0x00000000fffffffe, 0xfffffffe, true},
	{ 0x00000000ffffffff, 0xfffffffe, true},
	{ 0x0000000100000000, 0xfffffffe, true},
	{ 0x0000000200000000, 0xfffffffe, true},
	{ 0x7ffffffffffffffe, 0xfffffffe, true},
	{ 0x7fffffffffffffff, 0xfffffffe, true},
	{ 0x8000000000000000, 0xfffffffe, true},
	{ 0x8000000000000001, 0xfffffffe, true},
	{ 0xfffffffffffffffe, 0xfffffffe, false},
	{ 0xffffffffffffffff, 0xfffffffe, false},

	{ 0x0000000000000000, 0xffffffff, true},
	{ 0x0000000000000001, 0xffffffff, true},
	{ 0x0000000000000002, 0xffffffff, true},
	{ 0x000000007ffffffe, 0xffffffff, true},
	{ 0x000000007fffffff, 0xffffffff, true},
	{ 0x0000000080000000, 0xffffffff, true},
	{ 0x0000000080000001, 0xffffffff, true},
	{ 0x00000000fffffffe, 0xffffffff, true},
	{ 0x00000000ffffffff, 0xffffffff, true},
	{ 0x0000000100000000, 0xffffffff, true},
	{ 0x0000000200000000, 0xffffffff, true},
	{ 0x7ffffffffffffffe, 0xffffffff, true},
	{ 0x7fffffffffffffff, 0xffffffff, true},
	{ 0x8000000000000000, 0xffffffff, true},
	{ 0x8000000000000001, 0xffffffff, true},
	{ 0xfffffffffffffffe, 0xffffffff, false},
	{ 0xffffffffffffffff, 0xffffffff, false},
};

void add_test_uint64_uint32()
{

	for (size_t i = 0; i < sizeof(uint64_uint32) / sizeof(struct add_test_uint64_uint32); ++i)
	{
		const struct add_test_uint64_uint32& test_val = uint64_uint32[i];
		uint64_t ret;

		bool result = check_add_uint64_uint32(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

		bool actual;
		try
		{
			ret = safe_add_uint64_uint32(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint32");
		}

	}
}

struct add_test_uint64_int64
{
	uint64_t x;
	int64_t y;
	bool fExpected;
};

static const struct add_test_uint64_int64 uint64_int64[] =
{
	{ 0x0000000000000000, 0x0000000000000000, true},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000000, true},
	{ 0x000000007ffffffe, 0x0000000000000000, true},
	{ 0x000000007fffffff, 0x0000000000000000, true},
	{ 0x0000000080000000, 0x0000000000000000, true},
	{ 0x0000000080000001, 0x0000000000000000, true},
	{ 0x00000000fffffffe, 0x0000000000000000, true},
	{ 0x00000000ffffffff, 0x0000000000000000, true},
	{ 0x0000000100000000, 0x0000000000000000, true},
	{ 0x0000000200000000, 0x0000000000000000, true},
	{ 0x7ffffffffffffffe, 0x0000000000000000, true},
	{ 0x7fffffffffffffff, 0x0000000000000000, true},
	{ 0x8000000000000000, 0x0000000000000000, true},
	{ 0x8000000000000001, 0x0000000000000000, true},
	{ 0xfffffffffffffffe, 0x0000000000000000, true},
	{ 0xffffffffffffffff, 0x0000000000000000, true},

	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000001, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x0000000000000001, true},
	{ 0x000000007fffffff, 0x0000000000000001, true},
	{ 0x0000000080000000, 0x0000000000000001, true},
	{ 0x0000000080000001, 0x0000000000000001, true},
	{ 0x00000000fffffffe, 0x0000000000000001, true},
	{ 0x00000000ffffffff, 0x0000000000000001, true},
	{ 0x0000000100000000, 0x0000000000000001, true},
	{ 0x0000000200000000, 0x0000000000000001, true},
	{ 0x7ffffffffffffffe, 0x0000000000000001, true},
	{ 0x7fffffffffffffff, 0x0000000000000001, true},
	{ 0x8000000000000000, 0x0000000000000001, true},
	{ 0x8000000000000001, 0x0000000000000001, true},
	{ 0xfffffffffffffffe, 0x0000000000000001, true},
	{ 0xffffffffffffffff, 0x0000000000000001, false},

	{ 0x0000000000000000, 0x0000000000000002, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000002, true},
	{ 0x000000007ffffffe, 0x0000000000000002, true},
	{ 0x000000007fffffff, 0x0000000000000002, true},
	{ 0x0000000080000000, 0x0000000000000002, true},
	{ 0x0000000080000001, 0x0000000000000002, true},
	{ 0x00000000fffffffe, 0x0000000000000002, true},
	{ 0x00000000ffffffff, 0x0000000000000002, true},
	{ 0x0000000100000000, 0x0000000000000002, true},
	{ 0x0000000200000000, 0x0000000000000002, true},
	{ 0x7ffffffffffffffe, 0x0000000000000002, true},
	{ 0x7fffffffffffffff, 0x0000000000000002, true},
	{ 0x8000000000000000, 0x0000000000000002, true},
	{ 0x8000000000000001, 0x0000000000000002, true},
	{ 0xfffffffffffffffe, 0x0000000000000002, false},
	{ 0xffffffffffffffff, 0x0000000000000002, false},

	{ 0x0000000000000000, 0x000000007ffffffe, true},
	{ 0x0000000000000001, 0x000000007ffffffe, true},
	{ 0x0000000000000002, 0x000000007ffffffe, true},
	{ 0x000000007ffffffe, 0x000000007ffffffe, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007ffffffe, true},
	{ 0x0000000080000001, 0x000000007ffffffe, true},
	{ 0x00000000fffffffe, 0x000000007ffffffe, true},
	{ 0x00000000ffffffff, 0x000000007ffffffe, true},
	{ 0x0000000100000000, 0x000000007ffffffe, true},
	{ 0x0000000200000000, 0x000000007ffffffe, true},
	{ 0x7ffffffffffffffe, 0x000000007ffffffe, true},
	{ 0x7fffffffffffffff, 0x000000007ffffffe, true},
	{ 0x8000000000000000, 0x000000007ffffffe, true},
	{ 0x8000000000000001, 0x000000007ffffffe, true},
	{ 0xfffffffffffffffe, 0x000000007ffffffe, false},
	{ 0xffffffffffffffff, 0x000000007ffffffe, false},

	{ 0x0000000000000000, 0x000000007fffffff, true},
	{ 0x0000000000000001, 0x000000007fffffff, true},
	{ 0x0000000000000002, 0x000000007fffffff, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x000000007fffffff, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x000000007fffffff, true},
	{ 0x00000000fffffffe, 0x000000007fffffff, true},
	{ 0x00000000ffffffff, 0x000000007fffffff, true},
	{ 0x0000000100000000, 0x000000007fffffff, true},
	{ 0x0000000200000000, 0x000000007fffffff, true},
	{ 0x7ffffffffffffffe, 0x000000007fffffff, true},
	{ 0x7fffffffffffffff, 0x000000007fffffff, true},
	{ 0x8000000000000000, 0x000000007fffffff, true},
	{ 0x8000000000000001, 0x000000007fffffff, true},
	{ 0xfffffffffffffffe, 0x000000007fffffff, false},
	{ 0xffffffffffffffff, 0x000000007fffffff, false},

	{ 0x0000000000000000, 0x0000000080000000, true},
	{ 0x0000000000000001, 0x0000000080000000, true},
	{ 0x0000000000000002, 0x0000000080000000, true},
	{ 0x000000007ffffffe, 0x0000000080000000, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000000, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x0000000080000000, true},
	{ 0x00000000ffffffff, 0x0000000080000000, true},
	{ 0x0000000100000000, 0x0000000080000000, true},
	{ 0x0000000200000000, 0x0000000080000000, true},
	{ 0x7ffffffffffffffe, 0x0000000080000000, true},
	{ 0x7fffffffffffffff, 0x0000000080000000, true},
	{ 0x8000000000000000, 0x0000000080000000, true},
	{ 0x8000000000000001, 0x0000000080000000, true},
	{ 0xfffffffffffffffe, 0x0000000080000000, false},
	{ 0xffffffffffffffff, 0x0000000080000000, false},

	{ 0x0000000000000000, 0x0000000080000001, true},
	{ 0x0000000000000001, 0x0000000080000001, true},
	{ 0x0000000000000002, 0x0000000080000001, true},
	{ 0x000000007ffffffe, 0x0000000080000001, true},
	{ 0x000000007fffffff, 0x0000000080000001, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000001, true},
	{ 0x00000000fffffffe, 0x0000000080000001, true},
	{ 0x00000000ffffffff, 0x0000000080000001, true},
	{ 0x0000000100000000, 0x0000000080000001, true},
	{ 0x0000000200000000, 0x0000000080000001, true},
	{ 0x7ffffffffffffffe, 0x0000000080000001, true},
	{ 0x7fffffffffffffff, 0x0000000080000001, true},
	{ 0x8000000000000000, 0x0000000080000001, true},
	{ 0x8000000000000001, 0x0000000080000001, true},
	{ 0xfffffffffffffffe, 0x0000000080000001, false},
	{ 0xffffffffffffffff, 0x0000000080000001, false},

	{ 0x0000000000000000, 0x00000000fffffffe, true},
	{ 0x0000000000000001, 0x00000000fffffffe, true},
	{ 0x0000000000000002, 0x00000000fffffffe, true},
	{ 0x000000007ffffffe, 0x00000000fffffffe, true},
	{ 0x000000007fffffff, 0x00000000fffffffe, true},
	{ 0x0000000080000000, 0x00000000fffffffe, true},
	{ 0x0000000080000001, 0x00000000fffffffe, true},
	{ 0x00000000fffffffe, 0x00000000fffffffe, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000fffffffe, true},
	{ 0x0000000200000000, 0x00000000fffffffe, true},
	{ 0x7ffffffffffffffe, 0x00000000fffffffe, true},
	{ 0x7fffffffffffffff, 0x00000000fffffffe, true},
	{ 0x8000000000000000, 0x00000000fffffffe, true},
	{ 0x8000000000000001, 0x00000000fffffffe, true},
	{ 0xfffffffffffffffe, 0x00000000fffffffe, false},
	{ 0xffffffffffffffff, 0x00000000fffffffe, false},

	{ 0x0000000000000000, 0x00000000ffffffff, true},
	{ 0x0000000000000001, 0x00000000ffffffff, true},
	{ 0x0000000000000002, 0x00000000ffffffff, true},
	{ 0x000000007ffffffe, 0x00000000ffffffff, true},
	{ 0x000000007fffffff, 0x00000000ffffffff, true},
	{ 0x0000000080000000, 0x00000000ffffffff, true},
	{ 0x0000000080000001, 0x00000000ffffffff, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x00000000ffffffff, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000000ffffffff, true},
	{ 0x7ffffffffffffffe, 0x00000000ffffffff, true},
	{ 0x7fffffffffffffff, 0x00000000ffffffff, true},
	{ 0x8000000000000000, 0x00000000ffffffff, true},
	{ 0x8000000000000001, 0x00000000ffffffff, true},
	{ 0xfffffffffffffffe, 0x00000000ffffffff, false},
	{ 0xffffffffffffffff, 0x00000000ffffffff, false},

	{ 0x0000000000000000, 0x0000000100000000, true},
	{ 0x0000000000000001, 0x0000000100000000, true},
	{ 0x0000000000000002, 0x0000000100000000, true},
	{ 0x000000007ffffffe, 0x0000000100000000, true},
	{ 0x000000007fffffff, 0x0000000100000000, true},
	{ 0x0000000080000000, 0x0000000100000000, true},
	{ 0x0000000080000001, 0x0000000100000000, true},
	{ 0x00000000fffffffe, 0x0000000100000000, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000000, true},
	{ 0x0000000200000000, 0x0000000100000000, true},
	{ 0x7ffffffffffffffe, 0x0000000100000000, true},
	{ 0x7fffffffffffffff, 0x0000000100000000, true},
	{ 0x8000000000000000, 0x0000000100000000, true},
	{ 0x8000000000000001, 0x0000000100000000, true},
	{ 0xfffffffffffffffe, 0x0000000100000000, false},
	{ 0xffffffffffffffff, 0x0000000100000000, false},

	{ 0x0000000000000000, 0x0000000200000000, true},
	{ 0x0000000000000001, 0x0000000200000000, true},
	{ 0x0000000000000002, 0x0000000200000000, true},
	{ 0x000000007ffffffe, 0x0000000200000000, true},
	{ 0x000000007fffffff, 0x0000000200000000, true},
	{ 0x0000000080000000, 0x0000000200000000, true},
	{ 0x0000000080000001, 0x0000000200000000, true},
	{ 0x00000000fffffffe, 0x0000000200000000, true},
	{ 0x00000000ffffffff, 0x0000000200000000, true},
	{ 0x0000000100000000, 0x0000000200000000, true},
	{ 0x0000000200000000, 0x0000000200000000, true},
	{ 0x7ffffffffffffffe, 0x0000000200000000, true},
	{ 0x7fffffffffffffff, 0x0000000200000000, true},
	{ 0x8000000000000000, 0x0000000200000000, true},
	{ 0x8000000000000001, 0x0000000200000000, true},
	{ 0xfffffffffffffffe, 0x0000000200000000, false},
	{ 0xffffffffffffffff, 0x0000000200000000, false},

	{ 0x0000000000000000, 0x7ffffffffffffffe, true},
	{ 0x0000000000000001, 0x7ffffffffffffffe, true},
	{ 0x0000000000000002, 0x7ffffffffffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffffffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffffffffffe, true},
	{ 0x0000000080000000, 0x7ffffffffffffffe, true},
	{ 0x0000000080000001, 0x7ffffffffffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffffffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffffffffffe, true},
	{ 0x0000000100000000, 0x7ffffffffffffffe, true},
	{ 0x0000000200000000, 0x7ffffffffffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffe, true},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
	{ 0x8000000000000000, 0x7ffffffffffffffe, true},
	{ 0x8000000000000001, 0x7ffffffffffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffffffffffe, false},
	{ 0xffffffffffffffff, 0x7ffffffffffffffe, false},

	{ 0x0000000000000000, 0x7fffffffffffffff, true},
	{ 0x0000000000000001, 0x7fffffffffffffff, true},
	{ 0x0000000000000002, 0x7fffffffffffffff, true},
	{ 0x000000007ffffffe, 0x7fffffffffffffff, true},
	{ 0x000000007fffffff, 0x7fffffffffffffff, true},
	{ 0x0000000080000000, 0x7fffffffffffffff, true},
	{ 0x0000000080000001, 0x7fffffffffffffff, true},
	{ 0x00000000fffffffe, 0x7fffffffffffffff, true},
	{ 0x00000000ffffffff, 0x7fffffffffffffff, true},
	{ 0x0000000100000000, 0x7fffffffffffffff, true},
	{ 0x0000000200000000, 0x7fffffffffffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0x7fffffffffffffff, 0x7fffffffffffffff, true},
	{ 0x8000000000000000, 0x7fffffffffffffff, true},
	{ 0x8000000000000001, 0x7fffffffffffffff, false},
	{ 0xfffffffffffffffe, 0x7fffffffffffffff, false},
	{ 0xffffffffffffffff, 0x7fffffffffffffff, false},

	{ 0x0000000000000000, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000000000001, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000000000002, (std::int64_t)0x8000000000000000, false},
	{ 0x000000007ffffffe, (std::int64_t)0x8000000000000000, false},
	{ 0x000000007fffffff, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000080000000, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000080000001, (std::int64_t)0x8000000000000000, false},
	{ 0x00000000fffffffe, (std::int64_t)0x8000000000000000, false},
	{ 0x00000000ffffffff, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000100000000, (std::int64_t)0x8000000000000000, false},
	{ 0x0000000200000000, (std::int64_t)0x8000000000000000, false},
	{ 0x7ffffffffffffffe, (std::int64_t)0x8000000000000000, false},
	{ 0x7fffffffffffffff, (std::int64_t)0x8000000000000000, false},
	{ 0x8000000000000000, (std::int64_t)0x8000000000000000, true},
	{ 0x8000000000000001, (std::int64_t)0x8000000000000000, true},
	{ 0xfffffffffffffffe, (std::int64_t)0x8000000000000000, true},
	{ 0xffffffffffffffff, (std::int64_t)0x8000000000000000, true},

	{ 0x0000000000000000, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000000000001, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000000000002, (std::int64_t)0x8000000000000001, false},
	{ 0x000000007ffffffe, (std::int64_t)0x8000000000000001, false},
	{ 0x000000007fffffff, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000080000000, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000080000001, (std::int64_t)0x8000000000000001, false},
	{ 0x00000000fffffffe, (std::int64_t)0x8000000000000001, false},
	{ 0x00000000ffffffff, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000100000000, (std::int64_t)0x8000000000000001, false},
	{ 0x0000000200000000, (std::int64_t)0x8000000000000001, false},
	{ 0x7ffffffffffffffe, (std::int64_t)0x8000000000000001, false},
	{ 0x7fffffffffffffff, (std::int64_t)0x8000000000000001, true},
	{ 0x8000000000000000, (std::int64_t)0x8000000000000001, true},
	{ 0x8000000000000001, (std::int64_t)0x8000000000000001, true},
	{ 0xfffffffffffffffe, (std::int64_t)0x8000000000000001, true},
	{ 0xffffffffffffffff, (std::int64_t)0x8000000000000001, true},

	{ 0x0000000000000000, (std::int64_t)0xfffffffffffffffe, false},
	{ 0x0000000000000001, (std::int64_t)0xfffffffffffffffe, false},
	{ 0x0000000000000002, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x000000007ffffffe, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x000000007fffffff, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x0000000080000000, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x0000000080000001, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x00000000fffffffe, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x00000000ffffffff, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x0000000100000000, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x0000000200000000, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x7ffffffffffffffe, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x7fffffffffffffff, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x8000000000000000, (std::int64_t)0xfffffffffffffffe, true},
	{ 0x8000000000000001, (std::int64_t)0xfffffffffffffffe, true},
	{ 0xfffffffffffffffe, (std::int64_t)0xfffffffffffffffe, true},
	{ 0xffffffffffffffff, (std::int64_t)0xfffffffffffffffe, true},

	{ 0x0000000000000000, (std::int64_t)0xffffffffffffffff, false},
	{ 0x0000000000000001, (std::int64_t)0xffffffffffffffff, true},
	{ 0x0000000000000002, (std::int64_t)0xffffffffffffffff, true},
	{ 0x000000007ffffffe, (std::int64_t)0xffffffffffffffff, true},
	{ 0x000000007fffffff, (std::int64_t)0xffffffffffffffff, true},
	{ 0x0000000080000000, (std::int64_t)0xffffffffffffffff, true},
	{ 0x0000000080000001, (std::int64_t)0xffffffffffffffff, true},
	{ 0x00000000fffffffe, (std::int64_t)0xffffffffffffffff, true},
	{ 0x00000000ffffffff, (std::int64_t)0xffffffffffffffff, true},
	{ 0x0000000100000000, (std::int64_t)0xffffffffffffffff, true},
	{ 0x0000000200000000, (std::int64_t)0xffffffffffffffff, true},
	{ 0x7ffffffffffffffe, (std::int64_t)0xffffffffffffffff, true},
	{ 0x7fffffffffffffff, (std::int64_t)0xffffffffffffffff, true},
	{ 0x8000000000000000, (std::int64_t)0xffffffffffffffff, true},
	{ 0x8000000000000001, (std::int64_t)0xffffffffffffffff, true},
	{ 0xfffffffffffffffe, (std::int64_t)0xffffffffffffffff, true},
	{ 0xffffffffffffffff, (std::int64_t)0xffffffffffffffff, true},
};

void add_test_uint64_int64()
{

	for (size_t i = 0; i < sizeof(uint64_int64) / sizeof(struct add_test_uint64_int64); ++i)
	{
		const struct add_test_uint64_int64& test_val = uint64_int64[i];
		uint64_t ret;

		bool result = check_add_uint64_int64(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

		bool actual;
		try
		{
			ret = safe_add_uint64_int64(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_int64");
		}

	}
}

struct add_test_uint64_int32
{
	uint64_t x;
	int32_t y;
	bool fExpected;
};

static const struct add_test_uint64_int32 uint64_int32[] =
{
	{ 0x0000000000000000, 0x00000000, true},
	{ 0x0000000000000001, 0x00000000, true},
	{ 0x0000000000000002, 0x00000000, true},
	{ 0x000000007ffffffe, 0x00000000, true},
	{ 0x000000007fffffff, 0x00000000, true},
	{ 0x0000000080000000, 0x00000000, true},
	{ 0x0000000080000001, 0x00000000, true},
	{ 0x00000000fffffffe, 0x00000000, true},
	{ 0x00000000ffffffff, 0x00000000, true},
	{ 0x0000000100000000, 0x00000000, true},
	{ 0x0000000200000000, 0x00000000, true},
	{ 0x7ffffffffffffffe, 0x00000000, true},
	{ 0x7fffffffffffffff, 0x00000000, true},
	{ 0x8000000000000000, 0x00000000, true},
	{ 0x8000000000000001, 0x00000000, true},
	{ 0xfffffffffffffffe, 0x00000000, true},
	{ 0xffffffffffffffff, 0x00000000, true},

	{ 0x0000000000000000, 0x00000001, true},
	{ 0x0000000000000001, 0x00000001, true},
	{ 0x0000000000000002, 0x00000001, true},
	{ 0x000000007ffffffe, 0x00000001, true},
	{ 0x000000007fffffff, 0x00000001, true},
	{ 0x0000000080000000, 0x00000001, true},
	{ 0x0000000080000001, 0x00000001, true},
	{ 0x00000000fffffffe, 0x00000001, true},
	{ 0x00000000ffffffff, 0x00000001, true},
	{ 0x0000000100000000, 0x00000001, true},
	{ 0x0000000200000000, 0x00000001, true},
	{ 0x7ffffffffffffffe, 0x00000001, true},
	{ 0x7fffffffffffffff, 0x00000001, true},
	{ 0x8000000000000000, 0x00000001, true},
	{ 0x8000000000000001, 0x00000001, true},
	{ 0xfffffffffffffffe, 0x00000001, true},
	{ 0xffffffffffffffff, 0x00000001, false},

	{ 0x0000000000000000, 0x00000002, true},
	{ 0x0000000000000001, 0x00000002, true},
	{ 0x0000000000000002, 0x00000002, true},
	{ 0x000000007ffffffe, 0x00000002, true},
	{ 0x000000007fffffff, 0x00000002, true},
	{ 0x0000000080000000, 0x00000002, true},
	{ 0x0000000080000001, 0x00000002, true},
	{ 0x00000000fffffffe, 0x00000002, true},
	{ 0x00000000ffffffff, 0x00000002, true},
	{ 0x0000000100000000, 0x00000002, true},
	{ 0x0000000200000000, 0x00000002, true},
	{ 0x7ffffffffffffffe, 0x00000002, true},
	{ 0x7fffffffffffffff, 0x00000002, true},
	{ 0x8000000000000000, 0x00000002, true},
	{ 0x8000000000000001, 0x00000002, true},
	{ 0xfffffffffffffffe, 0x00000002, false},
	{ 0xffffffffffffffff, 0x00000002, false},

	{ 0x0000000000000000, 0x7ffffffe, true},
	{ 0x0000000000000001, 0x7ffffffe, true},
	{ 0x0000000000000002, 0x7ffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffe, true},
	{ 0x0000000080000000, 0x7ffffffe, true},
	{ 0x0000000080000001, 0x7ffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffe, true},
	{ 0x0000000100000000, 0x7ffffffe, true},
	{ 0x0000000200000000, 0x7ffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffe, true},
	{ 0x7fffffffffffffff, 0x7ffffffe, true},
	{ 0x8000000000000000, 0x7ffffffe, true},
	{ 0x8000000000000001, 0x7ffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffe, false},
	{ 0xffffffffffffffff, 0x7ffffffe, false},

	{ 0x0000000000000000, 0x7fffffff, true},
	{ 0x0000000000000001, 0x7fffffff, true},
	{ 0x0000000000000002, 0x7fffffff, true},
	{ 0x000000007ffffffe, 0x7fffffff, true},
	{ 0x000000007fffffff, 0x7fffffff, true},
	{ 0x0000000080000000, 0x7fffffff, true},
	{ 0x0000000080000001, 0x7fffffff, true},
	{ 0x00000000fffffffe, 0x7fffffff, true},
	{ 0x00000000ffffffff, 0x7fffffff, true},
	{ 0x0000000100000000, 0x7fffffff, true},
	{ 0x0000000200000000, 0x7fffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffff, true},
	{ 0x7fffffffffffffff, 0x7fffffff, true},
	{ 0x8000000000000000, 0x7fffffff, true},
	{ 0x8000000000000001, 0x7fffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffff, false},
	{ 0xffffffffffffffff, 0x7fffffff, false},

	{ 0x0000000000000000, (std::int32_t)0x80000000, false},
	{ 0x0000000000000001, (std::int32_t)0x80000000, false},
	{ 0x0000000000000002, (std::int32_t)0x80000000, false},
	{ 0x000000007ffffffe, (std::int32_t)0x80000000, false},
	{ 0x000000007fffffff, (std::int32_t)0x80000000, false},
	{ 0x0000000080000000, (std::int32_t)0x80000000, true},
	{ 0x0000000080000001, (std::int32_t)0x80000000, true},
	{ 0x00000000fffffffe, (std::int32_t)0x80000000, true},
	{ 0x00000000ffffffff, (std::int32_t)0x80000000, true},
	{ 0x0000000100000000, (std::int32_t)0x80000000, true},
	{ 0x0000000200000000, (std::int32_t)0x80000000, true},
	{ 0x7ffffffffffffffe, (std::int32_t)0x80000000, true},
	{ 0x7fffffffffffffff, (std::int32_t)0x80000000, true},
	{ 0x8000000000000000, (std::int32_t)0x80000000, true},
	{ 0x8000000000000001, (std::int32_t)0x80000000, true},
	{ 0xfffffffffffffffe, (std::int32_t)0x80000000, true},
	{ 0xffffffffffffffff, (std::int32_t)0x80000000, true},

	{ 0x0000000000000000, (std::int32_t)0x80000001, false},
	{ 0x0000000000000001, (std::int32_t)0x80000001, false},
	{ 0x0000000000000002, (std::int32_t)0x80000001, false},
	{ 0x000000007ffffffe, (std::int32_t)0x80000001, false},
	{ 0x000000007fffffff, (std::int32_t)0x80000001, true},
	{ 0x0000000080000000, (std::int32_t)0x80000001, true},
	{ 0x0000000080000001, (std::int32_t)0x80000001, true},
	{ 0x00000000fffffffe, (std::int32_t)0x80000001, true},
	{ 0x00000000ffffffff, (std::int32_t)0x80000001, true},
	{ 0x0000000100000000, (std::int32_t)0x80000001, true},
	{ 0x0000000200000000, (std::int32_t)0x80000001, true},
	{ 0x7ffffffffffffffe, (std::int32_t)0x80000001, true},
	{ 0x7fffffffffffffff, (std::int32_t)0x80000001, true},
	{ 0x8000000000000000, (std::int32_t)0x80000001, true},
	{ 0x8000000000000001, (std::int32_t)0x80000001, true},
	{ 0xfffffffffffffffe, (std::int32_t)0x80000001, true},
	{ 0xffffffffffffffff, (std::int32_t)0x80000001, true},

	{ 0x0000000000000000, (std::int32_t)0xfffffffe, false},
	{ 0x0000000000000001, (std::int32_t)0xfffffffe, false},
	{ 0x0000000000000002, (std::int32_t)0xfffffffe, true},
	{ 0x000000007ffffffe, (std::int32_t)0xfffffffe, true},
	{ 0x000000007fffffff, (std::int32_t)0xfffffffe, true},
	{ 0x0000000080000000, (std::int32_t)0xfffffffe, true},
	{ 0x0000000080000001, (std::int32_t)0xfffffffe, true},
	{ 0x00000000fffffffe, (std::int32_t)0xfffffffe, true},
	{ 0x00000000ffffffff, (std::int32_t)0xfffffffe, true},
	{ 0x0000000100000000, (std::int32_t)0xfffffffe, true},
	{ 0x0000000200000000, (std::int32_t)0xfffffffe, true},
	{ 0x7ffffffffffffffe, (std::int32_t)0xfffffffe, true},
	{ 0x7fffffffffffffff, (std::int32_t)0xfffffffe, true},
	{ 0x8000000000000000, (std::int32_t)0xfffffffe, true},
	{ 0x8000000000000001, (std::int32_t)0xfffffffe, true},
	{ 0xfffffffffffffffe, (std::int32_t)0xfffffffe, true},
	{ 0xffffffffffffffff, (std::int32_t)0xfffffffe, true},

	{ 0x0000000000000000, (std::int32_t)0xffffffff, false},
	{ 0x0000000000000001, (std::int32_t)0xffffffff, true},
	{ 0x0000000000000002, (std::int32_t)0xffffffff, true},
	{ 0x000000007ffffffe, (std::int32_t)0xffffffff, true},
	{ 0x000000007fffffff, (std::int32_t)0xffffffff, true},
	{ 0x0000000080000000, (std::int32_t)0xffffffff, true},
	{ 0x0000000080000001, (std::int32_t)0xffffffff, true},
	{ 0x00000000fffffffe, (std::int32_t)0xffffffff, true},
	{ 0x00000000ffffffff, (std::int32_t)0xffffffff, true},
	{ 0x0000000100000000, (std::int32_t)0xffffffff, true},
	{ 0x0000000200000000, (std::int32_t)0xffffffff, true},
	{ 0x7ffffffffffffffe, (std::int32_t)0xffffffff, true},
	{ 0x7fffffffffffffff, (std::int32_t)0xffffffff, true},
	{ 0x8000000000000000, (std::int32_t)0xffffffff, true},
	{ 0x8000000000000001, (std::int32_t)0xffffffff, true},
	{ 0xfffffffffffffffe, (std::int32_t)0xffffffff, true},
	{ 0xffffffffffffffff, (std::int32_t)0xffffffff, true},
};

void add_test_uint64_int32()
{

	for (size_t i = 0; i < sizeof(uint64_int32) / sizeof(struct add_test_uint64_int32); ++i)
	{
		const struct add_test_uint64_int32& test_val = uint64_int32[i];
		uint64_t ret;

		bool result = check_add_uint64_int32(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

		bool actual;
		try
		{
			ret = safe_add_uint64_int32(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_int64");
		}
	}
}

struct add_test_int64_uint64
{
	int64_t x;
	uint64_t y;
	bool fExpected;
};

static const struct add_test_int64_uint64 int64_uint64[] =
{
	{ 0x0000000000000000, 0x0000000000000000, true},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000000, true},
	{ 0x000000007ffffffe, 0x0000000000000000, true},
	{ 0x000000007fffffff, 0x0000000000000000, true},
	{ 0x0000000080000000, 0x0000000000000000, true},
	{ 0x0000000080000001, 0x0000000000000000, true},
	{ 0x00000000fffffffe, 0x0000000000000000, true},
	{ 0x00000000ffffffff, 0x0000000000000000, true},
	{ 0x0000000100000000, 0x0000000000000000, true},
	{ 0x0000000200000000, 0x0000000000000000, true},
	{ 0x7ffffffffffffffe, 0x0000000000000000, true},
	{ 0x7fffffffffffffff, 0x0000000000000000, true},
	{ 0x8000000000000000, 0x0000000000000000, true},
	{ 0x8000000000000001, 0x0000000000000000, true},
	{ 0xfffffffffffffffe, 0x0000000000000000, true},
	{ 0xffffffffffffffff, 0x0000000000000000, true},

	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000001, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x0000000000000001, true},
	{ 0x000000007fffffff, 0x0000000000000001, true},
	{ 0x0000000080000000, 0x0000000000000001, true},
	{ 0x0000000080000001, 0x0000000000000001, true},
	{ 0x00000000fffffffe, 0x0000000000000001, true},
	{ 0x00000000ffffffff, 0x0000000000000001, true},
	{ 0x0000000100000000, 0x0000000000000001, true},
	{ 0x0000000200000000, 0x0000000000000001, true},
	{ 0x7ffffffffffffffe, 0x0000000000000001, true},
	{ 0x7fffffffffffffff, 0x0000000000000001, false},
	{ 0x8000000000000000, 0x0000000000000001, true},
	{ 0x8000000000000001, 0x0000000000000001, true},
	{ 0xfffffffffffffffe, 0x0000000000000001, true},
	{ 0xffffffffffffffff, 0x0000000000000001, true},

	{ 0x0000000000000000, 0x0000000000000002, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000002, true},
	{ 0x000000007ffffffe, 0x0000000000000002, true},
	{ 0x000000007fffffff, 0x0000000000000002, true},
	{ 0x0000000080000000, 0x0000000000000002, true},
	{ 0x0000000080000001, 0x0000000000000002, true},
	{ 0x00000000fffffffe, 0x0000000000000002, true},
	{ 0x00000000ffffffff, 0x0000000000000002, true},
	{ 0x0000000100000000, 0x0000000000000002, true},
	{ 0x0000000200000000, 0x0000000000000002, true},
	{ 0x7ffffffffffffffe, 0x0000000000000002, false},
	{ 0x7fffffffffffffff, 0x0000000000000002, false},
	{ 0x8000000000000000, 0x0000000000000002, true},
	{ 0x8000000000000001, 0x0000000000000002, true},
	{ 0xfffffffffffffffe, 0x0000000000000002, true},
	{ 0xffffffffffffffff, 0x0000000000000002, true},

	{ 0x0000000000000000, 0x000000007ffffffe, true},
	{ 0x0000000000000001, 0x000000007ffffffe, true},
	{ 0x0000000000000002, 0x000000007ffffffe, true},
	{ 0x000000007ffffffe, 0x000000007ffffffe, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007ffffffe, true},
	{ 0x0000000080000001, 0x000000007ffffffe, true},
	{ 0x00000000fffffffe, 0x000000007ffffffe, true},
	{ 0x00000000ffffffff, 0x000000007ffffffe, true},
	{ 0x0000000100000000, 0x000000007ffffffe, true},
	{ 0x0000000200000000, 0x000000007ffffffe, true},
	{ 0x7ffffffffffffffe, 0x000000007ffffffe, false},
	{ 0x7fffffffffffffff, 0x000000007ffffffe, false},
	{ 0x8000000000000000, 0x000000007ffffffe, true},
	{ 0x8000000000000001, 0x000000007ffffffe, true},
	{ 0xfffffffffffffffe, 0x000000007ffffffe, true},
	{ 0xffffffffffffffff, 0x000000007ffffffe, true},

	{ 0x0000000000000000, 0x000000007fffffff, true},
	{ 0x0000000000000001, 0x000000007fffffff, true},
	{ 0x0000000000000002, 0x000000007fffffff, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x000000007fffffff, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x000000007fffffff, true},
	{ 0x00000000fffffffe, 0x000000007fffffff, true},
	{ 0x00000000ffffffff, 0x000000007fffffff, true},
	{ 0x0000000100000000, 0x000000007fffffff, true},
	{ 0x0000000200000000, 0x000000007fffffff, true},
	{ 0x7ffffffffffffffe, 0x000000007fffffff, false},
	{ 0x7fffffffffffffff, 0x000000007fffffff, false},
	{ 0x8000000000000000, 0x000000007fffffff, true},
	{ 0x8000000000000001, 0x000000007fffffff, true},
	{ 0xfffffffffffffffe, 0x000000007fffffff, true},
	{ 0xffffffffffffffff, 0x000000007fffffff, true},

	{ 0x0000000000000000, 0x0000000080000000, true},
	{ 0x0000000000000001, 0x0000000080000000, true},
	{ 0x0000000000000002, 0x0000000080000000, true},
	{ 0x000000007ffffffe, 0x0000000080000000, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000000, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x0000000080000000, true},
	{ 0x00000000ffffffff, 0x0000000080000000, true},
	{ 0x0000000100000000, 0x0000000080000000, true},
	{ 0x0000000200000000, 0x0000000080000000, true},
	{ 0x7ffffffffffffffe, 0x0000000080000000, false},
	{ 0x7fffffffffffffff, 0x0000000080000000, false},
	{ 0x8000000000000000, 0x0000000080000000, true},
	{ 0x8000000000000001, 0x0000000080000000, true},
	{ 0xfffffffffffffffe, 0x0000000080000000, true},
	{ 0xffffffffffffffff, 0x0000000080000000, true},

	{ 0x0000000000000000, 0x0000000080000001, true},
	{ 0x0000000000000001, 0x0000000080000001, true},
	{ 0x0000000000000002, 0x0000000080000001, true},
	{ 0x000000007ffffffe, 0x0000000080000001, true},
	{ 0x000000007fffffff, 0x0000000080000001, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000001, true},
	{ 0x00000000fffffffe, 0x0000000080000001, true},
	{ 0x00000000ffffffff, 0x0000000080000001, true},
	{ 0x0000000100000000, 0x0000000080000001, true},
	{ 0x0000000200000000, 0x0000000080000001, true},
	{ 0x7ffffffffffffffe, 0x0000000080000001, false},
	{ 0x7fffffffffffffff, 0x0000000080000001, false},
	{ 0x8000000000000000, 0x0000000080000001, true},
	{ 0x8000000000000001, 0x0000000080000001, true},
	{ 0xfffffffffffffffe, 0x0000000080000001, true},
	{ 0xffffffffffffffff, 0x0000000080000001, true},

	{ 0x0000000000000000, 0x00000000fffffffe, true},
	{ 0x0000000000000001, 0x00000000fffffffe, true},
	{ 0x0000000000000002, 0x00000000fffffffe, true},
	{ 0x000000007ffffffe, 0x00000000fffffffe, true},
	{ 0x000000007fffffff, 0x00000000fffffffe, true},
	{ 0x0000000080000000, 0x00000000fffffffe, true},
	{ 0x0000000080000001, 0x00000000fffffffe, true},
	{ 0x00000000fffffffe, 0x00000000fffffffe, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000fffffffe, true},
	{ 0x0000000200000000, 0x00000000fffffffe, true},
	{ 0x7ffffffffffffffe, 0x00000000fffffffe, false},
	{ 0x7fffffffffffffff, 0x00000000fffffffe, false},
	{ 0x8000000000000000, 0x00000000fffffffe, true},
	{ 0x8000000000000001, 0x00000000fffffffe, true},
	{ 0xfffffffffffffffe, 0x00000000fffffffe, true},
	{ 0xffffffffffffffff, 0x00000000fffffffe, true},

	{ 0x0000000000000000, 0x00000000ffffffff, true},
	{ 0x0000000000000001, 0x00000000ffffffff, true},
	{ 0x0000000000000002, 0x00000000ffffffff, true},
	{ 0x000000007ffffffe, 0x00000000ffffffff, true},
	{ 0x000000007fffffff, 0x00000000ffffffff, true},
	{ 0x0000000080000000, 0x00000000ffffffff, true},
	{ 0x0000000080000001, 0x00000000ffffffff, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x00000000ffffffff, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000000ffffffff, true},
	{ 0x7ffffffffffffffe, 0x00000000ffffffff, false},
	{ 0x7fffffffffffffff, 0x00000000ffffffff, false},
	{ 0x8000000000000000, 0x00000000ffffffff, true},
	{ 0x8000000000000001, 0x00000000ffffffff, true},
	{ 0xfffffffffffffffe, 0x00000000ffffffff, true},
	{ 0xffffffffffffffff, 0x00000000ffffffff, true},

	{ 0x0000000000000000, 0x0000000100000000, true},
	{ 0x0000000000000001, 0x0000000100000000, true},
	{ 0x0000000000000002, 0x0000000100000000, true},
	{ 0x000000007ffffffe, 0x0000000100000000, true},
	{ 0x000000007fffffff, 0x0000000100000000, true},
	{ 0x0000000080000000, 0x0000000100000000, true},
	{ 0x0000000080000001, 0x0000000100000000, true},
	{ 0x00000000fffffffe, 0x0000000100000000, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000000, true},
	{ 0x0000000200000000, 0x0000000100000000, true},
	{ 0x7ffffffffffffffe, 0x0000000100000000, false},
	{ 0x7fffffffffffffff, 0x0000000100000000, false},
	{ 0x8000000000000000, 0x0000000100000000, true},
	{ 0x8000000000000001, 0x0000000100000000, true},
	{ 0xfffffffffffffffe, 0x0000000100000000, true},
	{ 0xffffffffffffffff, 0x0000000100000000, true},

	{ 0x0000000000000000, 0x0000000200000000, true},
	{ 0x0000000000000001, 0x0000000200000000, true},
	{ 0x0000000000000002, 0x0000000200000000, true},
	{ 0x000000007ffffffe, 0x0000000200000000, true},
	{ 0x000000007fffffff, 0x0000000200000000, true},
	{ 0x0000000080000000, 0x0000000200000000, true},
	{ 0x0000000080000001, 0x0000000200000000, true},
	{ 0x00000000fffffffe, 0x0000000200000000, true},
	{ 0x00000000ffffffff, 0x0000000200000000, true},
	{ 0x0000000100000000, 0x0000000200000000, true},
	{ 0x0000000200000000, 0x0000000200000000, true},
	{ 0x7ffffffffffffffe, 0x0000000200000000, false},
	{ 0x7fffffffffffffff, 0x0000000200000000, false},
	{ 0x8000000000000000, 0x0000000200000000, true},
	{ 0x8000000000000001, 0x0000000200000000, true},
	{ 0xfffffffffffffffe, 0x0000000200000000, true},
	{ 0xffffffffffffffff, 0x0000000200000000, true},

	{ 0x0000000000000000, 0x7ffffffffffffffe, true},
	{ 0x0000000000000001, 0x7ffffffffffffffe, true},
	{ 0x0000000000000002, 0x7ffffffffffffffe, false},
	{ 0x000000007ffffffe, 0x7ffffffffffffffe, false},
	{ 0x000000007fffffff, 0x7ffffffffffffffe, false},
	{ 0x0000000080000000, 0x7ffffffffffffffe, false},
	{ 0x0000000080000001, 0x7ffffffffffffffe, false},
	{ 0x00000000fffffffe, 0x7ffffffffffffffe, false},
	{ 0x00000000ffffffff, 0x7ffffffffffffffe, false},
	{ 0x0000000100000000, 0x7ffffffffffffffe, false},
	{ 0x0000000200000000, 0x7ffffffffffffffe, false},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffe, false},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, false},
	{ 0x8000000000000000, 0x7ffffffffffffffe, true},
	{ 0x8000000000000001, 0x7ffffffffffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
	{ 0xffffffffffffffff, 0x7ffffffffffffffe, true},

	{ 0x0000000000000000, 0x7fffffffffffffff, true},
	{ 0x0000000000000001, 0x7fffffffffffffff, false},
	{ 0x0000000000000002, 0x7fffffffffffffff, false},
	{ 0x000000007ffffffe, 0x7fffffffffffffff, false},
	{ 0x000000007fffffff, 0x7fffffffffffffff, false},
	{ 0x0000000080000000, 0x7fffffffffffffff, false},
	{ 0x0000000080000001, 0x7fffffffffffffff, false},
	{ 0x00000000fffffffe, 0x7fffffffffffffff, false},
	{ 0x00000000ffffffff, 0x7fffffffffffffff, false},
	{ 0x0000000100000000, 0x7fffffffffffffff, false},
	{ 0x0000000200000000, 0x7fffffffffffffff, false},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, false},
	{ 0x7fffffffffffffff, 0x7fffffffffffffff, false},
	{ 0x8000000000000000, 0x7fffffffffffffff, true},
	{ 0x8000000000000001, 0x7fffffffffffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0xffffffffffffffff, 0x7fffffffffffffff, true},

	{ 0x0000000000000000, 0x8000000000000000, false},
	{ 0x0000000000000001, 0x8000000000000000, false},
	{ 0x0000000000000002, 0x8000000000000000, false},
	{ 0x000000007ffffffe, 0x8000000000000000, false},
	{ 0x000000007fffffff, 0x8000000000000000, false},
	{ 0x0000000080000000, 0x8000000000000000, false},
	{ 0x0000000080000001, 0x8000000000000000, false},
	{ 0x00000000fffffffe, 0x8000000000000000, false},
	{ 0x00000000ffffffff, 0x8000000000000000, false},
	{ 0x0000000100000000, 0x8000000000000000, false},
	{ 0x0000000200000000, 0x8000000000000000, false},
	{ 0x7ffffffffffffffe, 0x8000000000000000, false},
	{ 0x7fffffffffffffff, 0x8000000000000000, false},
	{ 0x8000000000000000, 0x8000000000000000, true},
	{ 0x8000000000000001, 0x8000000000000000, true},
	{ 0xfffffffffffffffe, 0x8000000000000000, true},
	{ 0xffffffffffffffff, 0x8000000000000000, true},

	{ 0x0000000000000000, 0x8000000000000001, false},
	{ 0x0000000000000001, 0x8000000000000001, false},
	{ 0x0000000000000002, 0x8000000000000001, false},
	{ 0x000000007ffffffe, 0x8000000000000001, false},
	{ 0x000000007fffffff, 0x8000000000000001, false},
	{ 0x0000000080000000, 0x8000000000000001, false},
	{ 0x0000000080000001, 0x8000000000000001, false},
	{ 0x00000000fffffffe, 0x8000000000000001, false},
	{ 0x00000000ffffffff, 0x8000000000000001, false},
	{ 0x0000000100000000, 0x8000000000000001, false},
	{ 0x0000000200000000, 0x8000000000000001, false},
	{ 0x7ffffffffffffffe, 0x8000000000000001, false},
	{ 0x7fffffffffffffff, 0x8000000000000001, false},
	{ 0x8000000000000000, 0x8000000000000001, true},
	{ 0x8000000000000001, 0x8000000000000001, true},
	{ 0xfffffffffffffffe, 0x8000000000000001, true},
	{ 0xffffffffffffffff, 0x8000000000000001, false},

	{ 0x0000000000000000, 0xfffffffffffffffe, false},
	{ 0x0000000000000001, 0xfffffffffffffffe, false},
	{ 0x0000000000000002, 0xfffffffffffffffe, false},
	{ 0x000000007ffffffe, 0xfffffffffffffffe, false},
	{ 0x000000007fffffff, 0xfffffffffffffffe, false},
	{ 0x0000000080000000, 0xfffffffffffffffe, false},
	{ 0x0000000080000001, 0xfffffffffffffffe, false},
	{ 0x00000000fffffffe, 0xfffffffffffffffe, false},
	{ 0x00000000ffffffff, 0xfffffffffffffffe, false},
	{ 0x0000000100000000, 0xfffffffffffffffe, false},
	{ 0x0000000200000000, 0xfffffffffffffffe, false},
	{ 0x7ffffffffffffffe, 0xfffffffffffffffe, false},
	{ 0x7fffffffffffffff, 0xfffffffffffffffe, false},
	{ 0x8000000000000000, 0xfffffffffffffffe, true},
	{ 0x8000000000000001, 0xfffffffffffffffe, true},
	{ 0xfffffffffffffffe, 0xfffffffffffffffe, false},
	{ 0xffffffffffffffff, 0xfffffffffffffffe, false},

	{ 0x0000000000000000, 0xffffffffffffffff, false},
	{ 0x0000000000000001, 0xffffffffffffffff, false},
	{ 0x0000000000000002, 0xffffffffffffffff, false},
	{ 0x000000007ffffffe, 0xffffffffffffffff, false},
	{ 0x000000007fffffff, 0xffffffffffffffff, false},
	{ 0x0000000080000000, 0xffffffffffffffff, false},
	{ 0x0000000080000001, 0xffffffffffffffff, false},
	{ 0x00000000fffffffe, 0xffffffffffffffff, false},
	{ 0x00000000ffffffff, 0xffffffffffffffff, false},
	{ 0x0000000100000000, 0xffffffffffffffff, false},
	{ 0x0000000200000000, 0xffffffffffffffff, false},
	{ 0x7ffffffffffffffe, 0xffffffffffffffff, false},
	{ 0x7fffffffffffffff, 0xffffffffffffffff, false},
	{ 0x8000000000000000, 0xffffffffffffffff, true},
	{ 0x8000000000000001, 0xffffffffffffffff, false},
	{ 0xfffffffffffffffe, 0xffffffffffffffff, false},
	{ 0xffffffffffffffff, 0xffffffffffffffff, false},
};

void add_test_int64_uint64()
{

	for (size_t i = 0; i < sizeof(int64_uint64) / sizeof(struct add_test_int64_uint64); ++i)
	{
		const struct add_test_int64_uint64& test_val = int64_uint64[i];
		int64_t ret;

		bool result = check_add_int64_uint64(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_uint64");
		}

		bool actual;
		try
		{
			ret = safe_add_int64_uint64(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_uint64_int64");
		}
	}
}

struct add_test_int64_uint32
{
	int64_t x;
	uint32_t y;
	bool fExpected;
};

static const struct add_test_int64_uint32 int64_uint32[] =
{
	{ 0x0000000000000000, 0x00000000, true},
	{ 0x0000000000000001, 0x00000000, true},
	{ 0x0000000000000002, 0x00000000, true},
	{ 0x000000007ffffffe, 0x00000000, true},
	{ 0x000000007fffffff, 0x00000000, true},
	{ 0x0000000080000000, 0x00000000, true},
	{ 0x0000000080000001, 0x00000000, true},
	{ 0x00000000fffffffe, 0x00000000, true},
	{ 0x00000000ffffffff, 0x00000000, true},
	{ 0x0000000100000000, 0x00000000, true},
	{ 0x0000000200000000, 0x00000000, true},
	{ 0x7ffffffffffffffe, 0x00000000, true},
	{ 0x7fffffffffffffff, 0x00000000, true},
	{ 0x8000000000000000, 0x00000000, true},
	{ 0x8000000000000001, 0x00000000, true},
	{ 0xfffffffffffffffe, 0x00000000, true},
	{ 0xffffffffffffffff, 0x00000000, true},

	{ 0x0000000000000000, 0x00000001, true},
	{ 0x0000000000000001, 0x00000001, true},
	{ 0x0000000000000002, 0x00000001, true},
	{ 0x000000007ffffffe, 0x00000001, true},
	{ 0x000000007fffffff, 0x00000001, true},
	{ 0x0000000080000000, 0x00000001, true},
	{ 0x0000000080000001, 0x00000001, true},
	{ 0x00000000fffffffe, 0x00000001, true},
	{ 0x00000000ffffffff, 0x00000001, true},
	{ 0x0000000100000000, 0x00000001, true},
	{ 0x0000000200000000, 0x00000001, true},
	{ 0x7ffffffffffffffe, 0x00000001, true},
	{ 0x7fffffffffffffff, 0x00000001, false},
	{ 0x8000000000000000, 0x00000001, true},
	{ 0x8000000000000001, 0x00000001, true},
	{ 0xfffffffffffffffe, 0x00000001, true},
	{ 0xffffffffffffffff, 0x00000001, true},

	{ 0x0000000000000000, 0x00000002, true},
	{ 0x0000000000000001, 0x00000002, true},
	{ 0x0000000000000002, 0x00000002, true},
	{ 0x000000007ffffffe, 0x00000002, true},
	{ 0x000000007fffffff, 0x00000002, true},
	{ 0x0000000080000000, 0x00000002, true},
	{ 0x0000000080000001, 0x00000002, true},
	{ 0x00000000fffffffe, 0x00000002, true},
	{ 0x00000000ffffffff, 0x00000002, true},
	{ 0x0000000100000000, 0x00000002, true},
	{ 0x0000000200000000, 0x00000002, true},
	{ 0x7ffffffffffffffe, 0x00000002, false},
	{ 0x7fffffffffffffff, 0x00000002, false},
	{ 0x8000000000000000, 0x00000002, true},
	{ 0x8000000000000001, 0x00000002, true},
	{ 0xfffffffffffffffe, 0x00000002, true},
	{ 0xffffffffffffffff, 0x00000002, true},

	{ 0x0000000000000000, 0x7ffffffe, true},
	{ 0x0000000000000001, 0x7ffffffe, true},
	{ 0x0000000000000002, 0x7ffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffe, true},
	{ 0x0000000080000000, 0x7ffffffe, true},
	{ 0x0000000080000001, 0x7ffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffe, true},
	{ 0x0000000100000000, 0x7ffffffe, true},
	{ 0x0000000200000000, 0x7ffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffe, false},
	{ 0x7fffffffffffffff, 0x7ffffffe, false},
	{ 0x8000000000000000, 0x7ffffffe, true},
	{ 0x8000000000000001, 0x7ffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffe, true},
	{ 0xffffffffffffffff, 0x7ffffffe, true},

	{ 0x0000000000000000, 0x7fffffff, true},
	{ 0x0000000000000001, 0x7fffffff, true},
	{ 0x0000000000000002, 0x7fffffff, true},
	{ 0x000000007ffffffe, 0x7fffffff, true},
	{ 0x000000007fffffff, 0x7fffffff, true},
	{ 0x0000000080000000, 0x7fffffff, true},
	{ 0x0000000080000001, 0x7fffffff, true},
	{ 0x00000000fffffffe, 0x7fffffff, true},
	{ 0x00000000ffffffff, 0x7fffffff, true},
	{ 0x0000000100000000, 0x7fffffff, true},
	{ 0x0000000200000000, 0x7fffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffff, false},
	{ 0x7fffffffffffffff, 0x7fffffff, false},
	{ 0x8000000000000000, 0x7fffffff, true},
	{ 0x8000000000000001, 0x7fffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffff, true},
	{ 0xffffffffffffffff, 0x7fffffff, true},

	{ 0x0000000000000000, 0x80000000, true},
	{ 0x0000000000000001, 0x80000000, true},
	{ 0x0000000000000002, 0x80000000, true},
	{ 0x000000007ffffffe, 0x80000000, true},
	{ 0x000000007fffffff, 0x80000000, true},
	{ 0x0000000080000000, 0x80000000, true},
	{ 0x0000000080000001, 0x80000000, true},
	{ 0x00000000fffffffe, 0x80000000, true},
	{ 0x00000000ffffffff, 0x80000000, true},
	{ 0x0000000100000000, 0x80000000, true},
	{ 0x0000000200000000, 0x80000000, true},
	{ 0x7ffffffffffffffe, 0x80000000, false},
	{ 0x7fffffffffffffff, 0x80000000, false},
	{ 0x8000000000000000, 0x80000000, true},
	{ 0x8000000000000001, 0x80000000, true},
	{ 0xfffffffffffffffe, 0x80000000, true},
	{ 0xffffffffffffffff, 0x80000000, true},

	{ 0x0000000000000000, 0x80000001, true},
	{ 0x0000000000000001, 0x80000001, true},
	{ 0x0000000000000002, 0x80000001, true},
	{ 0x000000007ffffffe, 0x80000001, true},
	{ 0x000000007fffffff, 0x80000001, true},
	{ 0x0000000080000000, 0x80000001, true},
	{ 0x0000000080000001, 0x80000001, true},
	{ 0x00000000fffffffe, 0x80000001, true},
	{ 0x00000000ffffffff, 0x80000001, true},
	{ 0x0000000100000000, 0x80000001, true},
	{ 0x0000000200000000, 0x80000001, true},
	{ 0x7ffffffffffffffe, 0x80000001, false},
	{ 0x7fffffffffffffff, 0x80000001, false},
	{ 0x8000000000000000, 0x80000001, true},
	{ 0x8000000000000001, 0x80000001, true},
	{ 0xfffffffffffffffe, 0x80000001, true},
	{ 0xffffffffffffffff, 0x80000001, true},

	{ 0x0000000000000000, 0xfffffffe, true},
	{ 0x0000000000000001, 0xfffffffe, true},
	{ 0x0000000000000002, 0xfffffffe, true},
	{ 0x000000007ffffffe, 0xfffffffe, true},
	{ 0x000000007fffffff, 0xfffffffe, true},
	{ 0x0000000080000000, 0xfffffffe, true},
	{ 0x0000000080000001, 0xfffffffe, true},
	{ 0x00000000fffffffe, 0xfffffffe, true},
	{ 0x00000000ffffffff, 0xfffffffe, true},
	{ 0x0000000100000000, 0xfffffffe, true},
	{ 0x0000000200000000, 0xfffffffe, true},
	{ 0x7ffffffffffffffe, 0xfffffffe, false},
	{ 0x7fffffffffffffff, 0xfffffffe, false},
	{ 0x8000000000000000, 0xfffffffe, true},
	{ 0x8000000000000001, 0xfffffffe, true},
	{ 0xfffffffffffffffe, 0xfffffffe, true},
	{ 0xffffffffffffffff, 0xfffffffe, true},

	{ 0x0000000000000000, 0xffffffff, true},
	{ 0x0000000000000001, 0xffffffff, true},
	{ 0x0000000000000002, 0xffffffff, true},
	{ 0x000000007ffffffe, 0xffffffff, true},
	{ 0x000000007fffffff, 0xffffffff, true},
	{ 0x0000000080000000, 0xffffffff, true},
	{ 0x0000000080000001, 0xffffffff, true},
	{ 0x00000000fffffffe, 0xffffffff, true},
	{ 0x00000000ffffffff, 0xffffffff, true},
	{ 0x0000000100000000, 0xffffffff, true},
	{ 0x0000000200000000, 0xffffffff, true},
	{ 0x7ffffffffffffffe, 0xffffffff, false},
	{ 0x7fffffffffffffff, 0xffffffff, false},
	{ 0x8000000000000000, 0xffffffff, true},
	{ 0x8000000000000001, 0xffffffff, true},
	{ 0xfffffffffffffffe, 0xffffffff, true},
	{ 0xffffffffffffffff, 0xffffffff, true},
};

void add_test_int64_uint32()
{

	for (size_t i = 0; i < sizeof(int64_uint32) / sizeof(struct add_test_int64_uint32); ++i)
	{
		const struct add_test_int64_uint32& test_val = int64_uint32[i];
		int64_t ret;

		bool result = check_add_int64_uint32(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_uint32");
		}

		bool actual;
		try
		{
			ret = safe_add_int64_uint32(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_uint32");
		}
	}
}

struct add_test_int64_int64
{
	int64_t x;
	int64_t y;
	bool fExpected;
};

static const struct add_test_int64_int64 int64_int64[] =
{
	{ 0x0000000000000000, 0x0000000000000000, true},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000000, true},
	{ 0x000000007ffffffe, 0x0000000000000000, true},
	{ 0x000000007fffffff, 0x0000000000000000, true},
	{ 0x0000000080000000, 0x0000000000000000, true},
	{ 0x0000000080000001, 0x0000000000000000, true},
	{ 0x00000000fffffffe, 0x0000000000000000, true},
	{ 0x00000000ffffffff, 0x0000000000000000, true},
	{ 0x0000000100000000, 0x0000000000000000, true},
	{ 0x0000000200000000, 0x0000000000000000, true},
	{ 0x7ffffffffffffffe, 0x0000000000000000, true},
	{ 0x7fffffffffffffff, 0x0000000000000000, true},
	{ 0x8000000000000000, 0x0000000000000000, true},
	{ 0x8000000000000001, 0x0000000000000000, true},
	{ 0xfffffffffffffffe, 0x0000000000000000, true},
	{ 0xffffffffffffffff, 0x0000000000000000, true},

	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000001, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x0000000000000001, true},
	{ 0x000000007fffffff, 0x0000000000000001, true},
	{ 0x0000000080000000, 0x0000000000000001, true},
	{ 0x0000000080000001, 0x0000000000000001, true},
	{ 0x00000000fffffffe, 0x0000000000000001, true},
	{ 0x00000000ffffffff, 0x0000000000000001, true},
	{ 0x0000000100000000, 0x0000000000000001, true},
	{ 0x0000000200000000, 0x0000000000000001, true},
	{ 0x7ffffffffffffffe, 0x0000000000000001, true},
	{ 0x7fffffffffffffff, 0x0000000000000001, false},
	{ 0x8000000000000000, 0x0000000000000001, true},
	{ 0x8000000000000001, 0x0000000000000001, true},
	{ 0xfffffffffffffffe, 0x0000000000000001, true},
	{ 0xffffffffffffffff, 0x0000000000000001, true},

	{ 0x0000000000000000, 0x0000000000000002, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000002, true},
	{ 0x000000007ffffffe, 0x0000000000000002, true},
	{ 0x000000007fffffff, 0x0000000000000002, true},
	{ 0x0000000080000000, 0x0000000000000002, true},
	{ 0x0000000080000001, 0x0000000000000002, true},
	{ 0x00000000fffffffe, 0x0000000000000002, true},
	{ 0x00000000ffffffff, 0x0000000000000002, true},
	{ 0x0000000100000000, 0x0000000000000002, true},
	{ 0x0000000200000000, 0x0000000000000002, true},
	{ 0x7ffffffffffffffe, 0x0000000000000002, false},
	{ 0x7fffffffffffffff, 0x0000000000000002, false},
	{ 0x8000000000000000, 0x0000000000000002, true},
	{ 0x8000000000000001, 0x0000000000000002, true},
	{ 0xfffffffffffffffe, 0x0000000000000002, true},
	{ 0xffffffffffffffff, 0x0000000000000002, true},

	{ 0x0000000000000000, 0x000000007ffffffe, true},
	{ 0x0000000000000001, 0x000000007ffffffe, true},
	{ 0x0000000000000002, 0x000000007ffffffe, true},
	{ 0x000000007ffffffe, 0x000000007ffffffe, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007ffffffe, true},
	{ 0x0000000080000001, 0x000000007ffffffe, true},
	{ 0x00000000fffffffe, 0x000000007ffffffe, true},
	{ 0x00000000ffffffff, 0x000000007ffffffe, true},
	{ 0x0000000100000000, 0x000000007ffffffe, true},
	{ 0x0000000200000000, 0x000000007ffffffe, true},
	{ 0x7ffffffffffffffe, 0x000000007ffffffe, false},
	{ 0x7fffffffffffffff, 0x000000007ffffffe, false},
	{ 0x8000000000000000, 0x000000007ffffffe, true},
	{ 0x8000000000000001, 0x000000007ffffffe, true},
	{ 0xfffffffffffffffe, 0x000000007ffffffe, true},
	{ 0xffffffffffffffff, 0x000000007ffffffe, true},

	{ 0x0000000000000000, 0x000000007fffffff, true},
	{ 0x0000000000000001, 0x000000007fffffff, true},
	{ 0x0000000000000002, 0x000000007fffffff, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x000000007fffffff, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x000000007fffffff, true},
	{ 0x00000000fffffffe, 0x000000007fffffff, true},
	{ 0x00000000ffffffff, 0x000000007fffffff, true},
	{ 0x0000000100000000, 0x000000007fffffff, true},
	{ 0x0000000200000000, 0x000000007fffffff, true},
	{ 0x7ffffffffffffffe, 0x000000007fffffff, false},
	{ 0x7fffffffffffffff, 0x000000007fffffff, false},
	{ 0x8000000000000000, 0x000000007fffffff, true},
	{ 0x8000000000000001, 0x000000007fffffff, true},
	{ 0xfffffffffffffffe, 0x000000007fffffff, true},
	{ 0xffffffffffffffff, 0x000000007fffffff, true},

	{ 0x0000000000000000, 0x0000000080000000, true},
	{ 0x0000000000000001, 0x0000000080000000, true},
	{ 0x0000000000000002, 0x0000000080000000, true},
	{ 0x000000007ffffffe, 0x0000000080000000, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000000, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x0000000080000000, true},
	{ 0x00000000ffffffff, 0x0000000080000000, true},
	{ 0x0000000100000000, 0x0000000080000000, true},
	{ 0x0000000200000000, 0x0000000080000000, true},
	{ 0x7ffffffffffffffe, 0x0000000080000000, false},
	{ 0x7fffffffffffffff, 0x0000000080000000, false},
	{ 0x8000000000000000, 0x0000000080000000, true},
	{ 0x8000000000000001, 0x0000000080000000, true},
	{ 0xfffffffffffffffe, 0x0000000080000000, true},
	{ 0xffffffffffffffff, 0x0000000080000000, true},

	{ 0x0000000000000000, 0x0000000080000001, true},
	{ 0x0000000000000001, 0x0000000080000001, true},
	{ 0x0000000000000002, 0x0000000080000001, true},
	{ 0x000000007ffffffe, 0x0000000080000001, true},
	{ 0x000000007fffffff, 0x0000000080000001, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000001, true},
	{ 0x00000000fffffffe, 0x0000000080000001, true},
	{ 0x00000000ffffffff, 0x0000000080000001, true},
	{ 0x0000000100000000, 0x0000000080000001, true},
	{ 0x0000000200000000, 0x0000000080000001, true},
	{ 0x7ffffffffffffffe, 0x0000000080000001, false},
	{ 0x7fffffffffffffff, 0x0000000080000001, false},
	{ 0x8000000000000000, 0x0000000080000001, true},
	{ 0x8000000000000001, 0x0000000080000001, true},
	{ 0xfffffffffffffffe, 0x0000000080000001, true},
	{ 0xffffffffffffffff, 0x0000000080000001, true},

	{ 0x0000000000000000, 0x00000000fffffffe, true},
	{ 0x0000000000000001, 0x00000000fffffffe, true},
	{ 0x0000000000000002, 0x00000000fffffffe, true},
	{ 0x000000007ffffffe, 0x00000000fffffffe, true},
	{ 0x000000007fffffff, 0x00000000fffffffe, true},
	{ 0x0000000080000000, 0x00000000fffffffe, true},
	{ 0x0000000080000001, 0x00000000fffffffe, true},
	{ 0x00000000fffffffe, 0x00000000fffffffe, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000fffffffe, true},
	{ 0x0000000200000000, 0x00000000fffffffe, true},
	{ 0x7ffffffffffffffe, 0x00000000fffffffe, false},
	{ 0x7fffffffffffffff, 0x00000000fffffffe, false},
	{ 0x8000000000000000, 0x00000000fffffffe, true},
	{ 0x8000000000000001, 0x00000000fffffffe, true},
	{ 0xfffffffffffffffe, 0x00000000fffffffe, true},
	{ 0xffffffffffffffff, 0x00000000fffffffe, true},

	{ 0x0000000000000000, 0x00000000ffffffff, true},
	{ 0x0000000000000001, 0x00000000ffffffff, true},
	{ 0x0000000000000002, 0x00000000ffffffff, true},
	{ 0x000000007ffffffe, 0x00000000ffffffff, true},
	{ 0x000000007fffffff, 0x00000000ffffffff, true},
	{ 0x0000000080000000, 0x00000000ffffffff, true},
	{ 0x0000000080000001, 0x00000000ffffffff, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x00000000ffffffff, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000000ffffffff, true},
	{ 0x7ffffffffffffffe, 0x00000000ffffffff, false},
	{ 0x7fffffffffffffff, 0x00000000ffffffff, false},
	{ 0x8000000000000000, 0x00000000ffffffff, true},
	{ 0x8000000000000001, 0x00000000ffffffff, true},
	{ 0xfffffffffffffffe, 0x00000000ffffffff, true},
	{ 0xffffffffffffffff, 0x00000000ffffffff, true},

	{ 0x0000000000000000, 0x0000000100000000, true},
	{ 0x0000000000000001, 0x0000000100000000, true},
	{ 0x0000000000000002, 0x0000000100000000, true},
	{ 0x000000007ffffffe, 0x0000000100000000, true},
	{ 0x000000007fffffff, 0x0000000100000000, true},
	{ 0x0000000080000000, 0x0000000100000000, true},
	{ 0x0000000080000001, 0x0000000100000000, true},
	{ 0x00000000fffffffe, 0x0000000100000000, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000000, true},
	{ 0x0000000200000000, 0x0000000100000000, true},
	{ 0x7ffffffffffffffe, 0x0000000100000000, false},
	{ 0x7fffffffffffffff, 0x0000000100000000, false},
	{ 0x8000000000000000, 0x0000000100000000, true},
	{ 0x8000000000000001, 0x0000000100000000, true},
	{ 0xfffffffffffffffe, 0x0000000100000000, true},
	{ 0xffffffffffffffff, 0x0000000100000000, true},

	{ 0x0000000000000000, 0x0000000200000000, true},
	{ 0x0000000000000001, 0x0000000200000000, true},
	{ 0x0000000000000002, 0x0000000200000000, true},
	{ 0x000000007ffffffe, 0x0000000200000000, true},
	{ 0x000000007fffffff, 0x0000000200000000, true},
	{ 0x0000000080000000, 0x0000000200000000, true},
	{ 0x0000000080000001, 0x0000000200000000, true},
	{ 0x00000000fffffffe, 0x0000000200000000, true},
	{ 0x00000000ffffffff, 0x0000000200000000, true},
	{ 0x0000000100000000, 0x0000000200000000, true},
	{ 0x0000000200000000, 0x0000000200000000, true},
	{ 0x7ffffffffffffffe, 0x0000000200000000, false},
	{ 0x7fffffffffffffff, 0x0000000200000000, false},
	{ 0x8000000000000000, 0x0000000200000000, true},
	{ 0x8000000000000001, 0x0000000200000000, true},
	{ 0xfffffffffffffffe, 0x0000000200000000, true},
	{ 0xffffffffffffffff, 0x0000000200000000, true},

	{ 0x0000000000000000, 0x7ffffffffffffffe, true},
	{ 0x0000000000000001, 0x7ffffffffffffffe, true},
	{ 0x0000000000000002, 0x7ffffffffffffffe, false},
	{ 0x000000007ffffffe, 0x7ffffffffffffffe, false},
	{ 0x000000007fffffff, 0x7ffffffffffffffe, false},
	{ 0x0000000080000000, 0x7ffffffffffffffe, false},
	{ 0x0000000080000001, 0x7ffffffffffffffe, false},
	{ 0x00000000fffffffe, 0x7ffffffffffffffe, false},
	{ 0x00000000ffffffff, 0x7ffffffffffffffe, false},
	{ 0x0000000100000000, 0x7ffffffffffffffe, false},
	{ 0x0000000200000000, 0x7ffffffffffffffe, false},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffe, false},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, false},
	{ 0x8000000000000000, 0x7ffffffffffffffe, true},
	{ 0x8000000000000001, 0x7ffffffffffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
	{ 0xffffffffffffffff, 0x7ffffffffffffffe, true},

	{ 0x0000000000000000, 0x7fffffffffffffff, true},
	{ 0x0000000000000001, 0x7fffffffffffffff, false},
	{ 0x0000000000000002, 0x7fffffffffffffff, false},
	{ 0x000000007ffffffe, 0x7fffffffffffffff, false},
	{ 0x000000007fffffff, 0x7fffffffffffffff, false},
	{ 0x0000000080000000, 0x7fffffffffffffff, false},
	{ 0x0000000080000001, 0x7fffffffffffffff, false},
	{ 0x00000000fffffffe, 0x7fffffffffffffff, false},
	{ 0x00000000ffffffff, 0x7fffffffffffffff, false},
	{ 0x0000000100000000, 0x7fffffffffffffff, false},
	{ 0x0000000200000000, 0x7fffffffffffffff, false},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, false},
	{ 0x7fffffffffffffff, 0x7fffffffffffffff, false},
	{ 0x8000000000000000, 0x7fffffffffffffff, true},
	{ 0x8000000000000001, 0x7fffffffffffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0xffffffffffffffff, 0x7fffffffffffffff, true},

	{ 0x0000000000000000, 0x8000000000000000, true},
	{ 0x0000000000000001, 0x8000000000000000, true},
	{ 0x0000000000000002, 0x8000000000000000, true},
	{ 0x000000007ffffffe, 0x8000000000000000, true},
	{ 0x000000007fffffff, 0x8000000000000000, true},
	{ 0x0000000080000000, 0x8000000000000000, true},
	{ 0x0000000080000001, 0x8000000000000000, true},
	{ 0x00000000fffffffe, 0x8000000000000000, true},
	{ 0x00000000ffffffff, 0x8000000000000000, true},
	{ 0x0000000100000000, 0x8000000000000000, true},
	{ 0x0000000200000000, 0x8000000000000000, true},
	{ 0x7ffffffffffffffe, 0x8000000000000000, true},
	{ 0x7fffffffffffffff, 0x8000000000000000, true},
	{ 0x8000000000000000, 0x8000000000000000, false},
	{ 0x8000000000000001, 0x8000000000000000, false},
	{ 0xfffffffffffffffe, 0x8000000000000000, false},
	{ 0xffffffffffffffff, 0x8000000000000000, false},

	{ 0x0000000000000000, 0x8000000000000001, true},
	{ 0x0000000000000001, 0x8000000000000001, true},
	{ 0x0000000000000002, 0x8000000000000001, true},
	{ 0x000000007ffffffe, 0x8000000000000001, true},
	{ 0x000000007fffffff, 0x8000000000000001, true},
	{ 0x0000000080000000, 0x8000000000000001, true},
	{ 0x0000000080000001, 0x8000000000000001, true},
	{ 0x00000000fffffffe, 0x8000000000000001, true},
	{ 0x00000000ffffffff, 0x8000000000000001, true},
	{ 0x0000000100000000, 0x8000000000000001, true},
	{ 0x0000000200000000, 0x8000000000000001, true},
	{ 0x7ffffffffffffffe, 0x8000000000000001, true},
	{ 0x7fffffffffffffff, 0x8000000000000001, true},
	{ 0x8000000000000000, 0x8000000000000001, false},
	{ 0x8000000000000001, 0x8000000000000001, false},
	{ 0xfffffffffffffffe, 0x8000000000000001, false},
	{ 0xffffffffffffffff, 0x8000000000000001, true},

	{ 0x0000000000000000, 0xfffffffffffffffe, true},
	{ 0x0000000000000001, 0xfffffffffffffffe, true},
	{ 0x0000000000000002, 0xfffffffffffffffe, true},
	{ 0x000000007ffffffe, 0xfffffffffffffffe, true},
	{ 0x000000007fffffff, 0xfffffffffffffffe, true},
	{ 0x0000000080000000, 0xfffffffffffffffe, true},
	{ 0x0000000080000001, 0xfffffffffffffffe, true},
	{ 0x00000000fffffffe, 0xfffffffffffffffe, true},
	{ 0x00000000ffffffff, 0xfffffffffffffffe, true},
	{ 0x0000000100000000, 0xfffffffffffffffe, true},
	{ 0x0000000200000000, 0xfffffffffffffffe, true},
	{ 0x7ffffffffffffffe, 0xfffffffffffffffe, true},
	{ 0x7fffffffffffffff, 0xfffffffffffffffe, true},
	{ 0x8000000000000000, 0xfffffffffffffffe, false},
	{ 0x8000000000000001, 0xfffffffffffffffe, false},
	{ 0xfffffffffffffffe, 0xfffffffffffffffe, true},
	{ 0xffffffffffffffff, 0xfffffffffffffffe, true},

	{ 0x0000000000000000, 0xffffffffffffffff, true},
	{ 0x0000000000000001, 0xffffffffffffffff, true},
	{ 0x0000000000000002, 0xffffffffffffffff, true},
	{ 0x000000007ffffffe, 0xffffffffffffffff, true},
	{ 0x000000007fffffff, 0xffffffffffffffff, true},
	{ 0x0000000080000000, 0xffffffffffffffff, true},
	{ 0x0000000080000001, 0xffffffffffffffff, true},
	{ 0x00000000fffffffe, 0xffffffffffffffff, true},
	{ 0x00000000ffffffff, 0xffffffffffffffff, true},
	{ 0x0000000100000000, 0xffffffffffffffff, true},
	{ 0x0000000200000000, 0xffffffffffffffff, true},
	{ 0x7ffffffffffffffe, 0xffffffffffffffff, true},
	{ 0x7fffffffffffffff, 0xffffffffffffffff, true},
	{ 0x8000000000000000, 0xffffffffffffffff, false},
	{ 0x8000000000000001, 0xffffffffffffffff, true},
	{ 0xfffffffffffffffe, 0xffffffffffffffff, true},
	{ 0xffffffffffffffff, 0xffffffffffffffff, true},
};

void add_test_int64_int64()
{

	for (size_t i = 0; i < sizeof(int64_int64) / sizeof(struct add_test_int64_int64); ++i)
	{
		const struct add_test_int64_int64& test_val = int64_int64[i];
		int64_t ret;

		bool result = check_add_int64_int64(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_uint32");
		}

		bool actual;
		try
		{
			ret = safe_add_int64_int64(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_int64");
		}
	}
}

struct add_test_int64_int32
{
	int64_t x;
	int32_t y;
	bool fExpected;
};

static const struct add_test_int64_int32 int64_int32[] =
{
	{ 0x0000000000000000, 0x00000000, true},
	{ 0x0000000000000001, 0x00000000, true},
	{ 0x0000000000000002, 0x00000000, true},
	{ 0x000000007ffffffe, 0x00000000, true},
	{ 0x000000007fffffff, 0x00000000, true},
	{ 0x0000000080000000, 0x00000000, true},
	{ 0x0000000080000001, 0x00000000, true},
	{ 0x00000000fffffffe, 0x00000000, true},
	{ 0x00000000ffffffff, 0x00000000, true},
	{ 0x0000000100000000, 0x00000000, true},
	{ 0x0000000200000000, 0x00000000, true},
	{ 0x7ffffffffffffffe, 0x00000000, true},
	{ 0x7fffffffffffffff, 0x00000000, true},
	{ 0x8000000000000000, 0x00000000, true},
	{ 0x8000000000000001, 0x00000000, true},
	{ 0xfffffffffffffffe, 0x00000000, true},
	{ 0xffffffffffffffff, 0x00000000, true},

	{ 0x0000000000000000, 0x00000001, true},
	{ 0x0000000000000001, 0x00000001, true},
	{ 0x0000000000000002, 0x00000001, true},
	{ 0x000000007ffffffe, 0x00000001, true},
	{ 0x000000007fffffff, 0x00000001, true},
	{ 0x0000000080000000, 0x00000001, true},
	{ 0x0000000080000001, 0x00000001, true},
	{ 0x00000000fffffffe, 0x00000001, true},
	{ 0x00000000ffffffff, 0x00000001, true},
	{ 0x0000000100000000, 0x00000001, true},
	{ 0x0000000200000000, 0x00000001, true},
	{ 0x7ffffffffffffffe, 0x00000001, true},
	{ 0x7fffffffffffffff, 0x00000001, false},
	{ 0x8000000000000000, 0x00000001, true},
	{ 0x8000000000000001, 0x00000001, true},
	{ 0xfffffffffffffffe, 0x00000001, true},
	{ 0xffffffffffffffff, 0x00000001, true},

	{ 0x0000000000000000, 0x00000002, true},
	{ 0x0000000000000001, 0x00000002, true},
	{ 0x0000000000000002, 0x00000002, true},
	{ 0x000000007ffffffe, 0x00000002, true},
	{ 0x000000007fffffff, 0x00000002, true},
	{ 0x0000000080000000, 0x00000002, true},
	{ 0x0000000080000001, 0x00000002, true},
	{ 0x00000000fffffffe, 0x00000002, true},
	{ 0x00000000ffffffff, 0x00000002, true},
	{ 0x0000000100000000, 0x00000002, true},
	{ 0x0000000200000000, 0x00000002, true},
	{ 0x7ffffffffffffffe, 0x00000002, false},
	{ 0x7fffffffffffffff, 0x00000002, false},
	{ 0x8000000000000000, 0x00000002, true},
	{ 0x8000000000000001, 0x00000002, true},
	{ 0xfffffffffffffffe, 0x00000002, true},
	{ 0xffffffffffffffff, 0x00000002, true},

	{ 0x0000000000000000, 0x7ffffffe, true},
	{ 0x0000000000000001, 0x7ffffffe, true},
	{ 0x0000000000000002, 0x7ffffffe, true},
	{ 0x000000007ffffffe, 0x7ffffffe, true},
	{ 0x000000007fffffff, 0x7ffffffe, true},
	{ 0x0000000080000000, 0x7ffffffe, true},
	{ 0x0000000080000001, 0x7ffffffe, true},
	{ 0x00000000fffffffe, 0x7ffffffe, true},
	{ 0x00000000ffffffff, 0x7ffffffe, true},
	{ 0x0000000100000000, 0x7ffffffe, true},
	{ 0x0000000200000000, 0x7ffffffe, true},
	{ 0x7ffffffffffffffe, 0x7ffffffe, false},
	{ 0x7fffffffffffffff, 0x7ffffffe, false},
	{ 0x8000000000000000, 0x7ffffffe, true},
	{ 0x8000000000000001, 0x7ffffffe, true},
	{ 0xfffffffffffffffe, 0x7ffffffe, true},
	{ 0xffffffffffffffff, 0x7ffffffe, true},

	{ 0x0000000000000000, 0x7fffffff, true},
	{ 0x0000000000000001, 0x7fffffff, true},
	{ 0x0000000000000002, 0x7fffffff, true},
	{ 0x000000007ffffffe, 0x7fffffff, true},
	{ 0x000000007fffffff, 0x7fffffff, true},
	{ 0x0000000080000000, 0x7fffffff, true},
	{ 0x0000000080000001, 0x7fffffff, true},
	{ 0x00000000fffffffe, 0x7fffffff, true},
	{ 0x00000000ffffffff, 0x7fffffff, true},
	{ 0x0000000100000000, 0x7fffffff, true},
	{ 0x0000000200000000, 0x7fffffff, true},
	{ 0x7ffffffffffffffe, 0x7fffffff, false},
	{ 0x7fffffffffffffff, 0x7fffffff, false},
	{ 0x8000000000000000, 0x7fffffff, true},
	{ 0x8000000000000001, 0x7fffffff, true},
	{ 0xfffffffffffffffe, 0x7fffffff, true},
	{ 0xffffffffffffffff, 0x7fffffff, true},

	{ 0x0000000000000000, 0x80000000, true},
	{ 0x0000000000000001, 0x80000000, true},
	{ 0x0000000000000002, 0x80000000, true},
	{ 0x000000007ffffffe, 0x80000000, true},
	{ 0x000000007fffffff, 0x80000000, true},
	{ 0x0000000080000000, 0x80000000, true},
	{ 0x0000000080000001, 0x80000000, true},
	{ 0x00000000fffffffe, 0x80000000, true},
	{ 0x00000000ffffffff, 0x80000000, true},
	{ 0x0000000100000000, 0x80000000, true},
	{ 0x0000000200000000, 0x80000000, true},
	{ 0x7ffffffffffffffe, 0x80000000, true},
	{ 0x7fffffffffffffff, 0x80000000, true},
	{ 0x8000000000000000, 0x80000000, false},
	{ 0x8000000000000001, 0x80000000, false},
	{ 0xfffffffffffffffe, 0x80000000, true},
	{ 0xffffffffffffffff, 0x80000000, true},

	{ 0x0000000000000000, 0x80000001, true},
	{ 0x0000000000000001, 0x80000001, true},
	{ 0x0000000000000002, 0x80000001, true},
	{ 0x000000007ffffffe, 0x80000001, true},
	{ 0x000000007fffffff, 0x80000001, true},
	{ 0x0000000080000000, 0x80000001, true},
	{ 0x0000000080000001, 0x80000001, true},
	{ 0x00000000fffffffe, 0x80000001, true},
	{ 0x00000000ffffffff, 0x80000001, true},
	{ 0x0000000100000000, 0x80000001, true},
	{ 0x0000000200000000, 0x80000001, true},
	{ 0x7ffffffffffffffe, 0x80000001, true},
	{ 0x7fffffffffffffff, 0x80000001, true},
	{ 0x8000000000000000, 0x80000001, false},
	{ 0x8000000000000001, 0x80000001, false},
	{ 0xfffffffffffffffe, 0x80000001, true},
	{ 0xffffffffffffffff, 0x80000001, true},

	{ 0x0000000000000000, 0xfffffffe, true},
	{ 0x0000000000000001, 0xfffffffe, true},
	{ 0x0000000000000002, 0xfffffffe, true},
	{ 0x000000007ffffffe, 0xfffffffe, true},
	{ 0x000000007fffffff, 0xfffffffe, true},
	{ 0x0000000080000000, 0xfffffffe, true},
	{ 0x0000000080000001, 0xfffffffe, true},
	{ 0x00000000fffffffe, 0xfffffffe, true},
	{ 0x00000000ffffffff, 0xfffffffe, true},
	{ 0x0000000100000000, 0xfffffffe, true},
	{ 0x0000000200000000, 0xfffffffe, true},
	{ 0x7ffffffffffffffe, 0xfffffffe, true},
	{ 0x7fffffffffffffff, 0xfffffffe, true},
	{ 0x8000000000000000, 0xfffffffe, false},
	{ 0x8000000000000001, 0xfffffffe, false},
	{ 0xfffffffffffffffe, 0xfffffffe, true},
	{ 0xffffffffffffffff, 0xfffffffe, true},

	{ 0x0000000000000000, 0xffffffff, true},
	{ 0x0000000000000001, 0xffffffff, true},
	{ 0x0000000000000002, 0xffffffff, true},
	{ 0x000000007ffffffe, 0xffffffff, true},
	{ 0x000000007fffffff, 0xffffffff, true},
	{ 0x0000000080000000, 0xffffffff, true},
	{ 0x0000000080000001, 0xffffffff, true},
	{ 0x00000000fffffffe, 0xffffffff, true},
	{ 0x00000000ffffffff, 0xffffffff, true},
	{ 0x0000000100000000, 0xffffffff, true},
	{ 0x0000000200000000, 0xffffffff, true},
	{ 0x7ffffffffffffffe, 0xffffffff, true},
	{ 0x7fffffffffffffff, 0xffffffff, true},
	{ 0x8000000000000000, 0xffffffff, false},
	{ 0x8000000000000001, 0xffffffff, true},
	{ 0xfffffffffffffffe, 0xffffffff, true},
	{ 0xffffffffffffffff, 0xffffffff, true},
};

void add_test_int64_int32()
{

	for (size_t i = 0; i < sizeof(int64_int32) / sizeof(struct add_test_int64_int32); ++i)
	{
		const struct add_test_int64_int32& test_val = int64_int32[i];
		int64_t ret;

		bool result = check_add_int64_int32(test_val.x, test_val.y, &ret);

		if (!!result != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_uint32");
		}

		bool actual;
		try
		{
			ret = safe_add_int64_int32(test_val.x, test_val.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test_val.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int64_int64");
		}
	}
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

		std::cout << "Addition tests completed" << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "Addition tests failed - " << err.what() << std::endl;
	}
	
	return;
}
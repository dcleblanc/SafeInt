#include "safe_math_test.h"
#include "../MultVerify.h"

using namespace mult_verify;

void mult_test_uint64_uint64()
{
	MultTestCase< std::uint64_t, std::uint64_t> tests;
	MultTest<std::uint64_t, std::uint64_t> test = tests.GetNext();

	while (!tests.Done())
	{
		uint64_t ret;

		bool result = check_mul_uint64_uint64(test.x, test.y, &ret);

		if (!!result != test.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int32_int32");
		}

		bool actual;
		try
		{
			ret = safe_mul_uint64_uint64(test.x, test.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test.fExpected)
		{
			assert(false);
			throw std::exception("Failure in add_test_int32_int32");
		}
		
		test = tests.GetNext();
	}
}

void mult_test_uint64_uint32()
{
	MultTestCase< std::uint64_t, std::uint32_t> tests;
	MultTest<std::uint64_t, std::uint32_t> test = tests.GetNext();

	while (!tests.Done())
	{
		uint64_t ret;

		bool result = check_mul_uint64_uint32(test.x, test.y, &ret);

		if (!!result != test.fExpected)
		{
			assert(false);
			throw std::exception("Failure in mul_test_uint64_uint32");
		}

		bool actual;
		try
		{
			ret = safe_mul_uint64_uint32(test.x, test.y);
			actual = true;
		}
		catch (...)
		{
			actual = false;
		}

		if (actual != test.fExpected)
		{
			assert(false);
			throw std::exception("Failure in mul_test_uint64_uint64");
		}

		test = tests.GetNext();
	}

}

extern "C" void mult_test()
{
	try
	{
		mult_test_uint64_uint64();
		mult_test_uint64_uint32();
		/*		mult_test_uint64_int64();
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
		*/
		std::cout << "Multiplication tests completed" << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "Multiplication tests failed - " << err.what() << std::endl;
	}

	return;
}
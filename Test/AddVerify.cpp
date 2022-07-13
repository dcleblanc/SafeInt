// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"

template <typename T, typename U>
void AddVerifyBase(const char* types)
{
	TestVector< T, U, OpType::Add > tests;
	TestCase< T, U, OpType::Add > test = tests.GetNext();

	while (!tests.Done())
	{
		T ret;
		if (SafeAdd(test.x, test.y, ret) != test.fExpected)
		{
			std::string msg = std::string("Error in case ") + types + ": ";
			err_msg(msg.c_str(), test.x, test.y, test.fExpected);
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<T> si(test.x);
			si += test.y;
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			std::string msg = std::string("Error in case ") + types + " throw (1): ";
			err_msg(msg.c_str(), test.x, test.y, test.fExpected);
		}

		// Also need to test the version that assigns back out
		// to a plain int, as it has different logic
		fSuccess = true;
		try
		{
			T x(test.x);
			x += SafeInt<U>(test.y);
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			std::string msg = std::string("Error in case ") + types + " throw (2): ";
			err_msg(msg.c_str(), test.x, test.y, test.fExpected);
		}

		test = tests.GetNext();
	}
}

namespace add_verify
{

void AddVerify()
{
    std::cout << "Verifying Addition:" << std::endl;

    // Unsigned int64, unsigned cases
	AddVerifyBase<std::uint64_t, std::uint64_t>("uint64_uint64");
	AddVerifyBase<std::uint64_t, std::uint32_t>("uint64_uint32");
	AddVerifyBase<std::uint64_t, std::uint16_t>("uint64_uint16");
	AddVerifyBase<std::uint64_t, std::uint8_t>("uint64_uint8");

    // Unsigned int64, signed cases
	AddVerifyBase<std::uint64_t, std::int64_t>("uint64_int64");
	AddVerifyBase<std::uint64_t, std::int32_t>("uint64_int32");
	AddVerifyBase<std::uint64_t, std::int16_t>("uint64_int16");
	AddVerifyBase<std::uint64_t, std::int8_t>("uint64_int8");

	// Signed int64, unsigned cases
	AddVerifyBase<std::int64_t, std::uint64_t>("int64_uint64");
	AddVerifyBase<std::int64_t, std::uint32_t>("int64_uint32");
	AddVerifyBase<std::int64_t, std::uint16_t>("int64_uint16");
	AddVerifyBase<std::int64_t, std::uint16_t>("int64_uint8");

    // Signed int64, signed cases
	AddVerifyBase<std::int64_t, std::int64_t>("int64_int64");
	AddVerifyBase<std::int64_t, std::int32_t>("int64_int32");
	AddVerifyBase<std::int64_t, std::int16_t>("int64_int16");
	AddVerifyBase<std::int64_t, std::int8_t>("int64_int8");

	// Unsigned int32, unsigned cases
	AddVerifyBase<std::uint32_t, std::uint64_t>("uint32_uint64");
	AddVerifyBase<std::uint32_t, std::uint32_t>("uint32_uint32");
	// TBD - 16, 8-bit

	// Unsigned int32, signed cases
	AddVerifyBase<std::uint32_t, std::int64_t>("uint32_int64");
	AddVerifyBase<std::uint32_t, std::int32_t>("uint32_int32");
	// TBD - 16, 8-bit

	// Signed int32, unsigned cases
	AddVerifyBase<std::int32_t, std::uint64_t>("int32_uint64");
	AddVerifyBase<std::int32_t, std::uint32_t>("int32_uint32");
	// TBD - 16, 8-bit

	// Signed int32, signed cases
	AddVerifyBase<std::int32_t, std::int64_t>("int32_int64");
	AddVerifyBase<std::int32_t, std::int32_t>("int32_int32");
	// TBD - 16, 8-bit

	// Unsigned int8, unsigned cases
	AddVerifyBase<std::uint8_t, std::uint64_t>("uint8_t_uint64");
	AddVerifyBase<std::uint8_t, std::uint32_t>("uint8_t_uint32");
	AddVerifyBase<std::uint8_t, std::uint16_t>("uint8_t_uint16");
	AddVerifyBase<std::uint8_t, std::uint8_t>("uint8_t_uint8");

    // Unsigned int8, signed cases
	AddVerifyBase<std::uint8_t, std::int64_t>("uint8_t_int64");
	AddVerifyBase<std::uint8_t, std::int32_t>("uint8_t_int32");
	AddVerifyBase<std::uint8_t, std::int16_t>("uint8_t_int16");
	AddVerifyBase<std::uint8_t, std::int8_t>("uint8_t_int8");

	// Signed int8, unsigned cases
	AddVerifyBase<std::int8_t, std::uint64_t>("int8_t_uint64");
	AddVerifyBase<std::int8_t, std::uint32_t>("int8_t_uint32");
	AddVerifyBase<std::int8_t, std::uint16_t>("int8_t_uint16");
	AddVerifyBase<std::int8_t, std::uint8_t>("int8_t_uint8");

    // Signed int8, signed cases
	AddVerifyBase<std::int8_t, std::int64_t>("int8_t_int64");
	AddVerifyBase<std::int8_t, std::int32_t>("int8_t_int32");
	AddVerifyBase<std::int8_t, std::int16_t>("int8_t_int16");
	AddVerifyBase<std::int8_t, std::int8_t>("int8_t_int8");
}

}
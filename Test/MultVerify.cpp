// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"

namespace mult_verify
{

void MultVerifyUint64Uint64()
{
	TestVector< std::uint64_t, std::uint64_t, OpType::Mult > tests;
	TestCase<std::uint64_t, std::uint64_t, OpType::Mult > test = tests.GetNext();

	while( !tests.Done() )
	{
		std::uint64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint64_uint64: ", test.x, test.y, test.fExpected );
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint64_uint64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyUint64Uint()
{
	TestVector< std::uint64_t, std::uint32_t, OpType::Mult > tests;
	TestCase<std::uint64_t, std::uint32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint64_uint32: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint64_uint32 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyUintUint64()
{
	TestVector< std::uint32_t, std::uint64_t, OpType::Mult > tests;
	TestCase<std::uint32_t, std::uint64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint32_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint32_uint64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint32_uint64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyUint32Uint32()
{
	TestVector< std::uint32_t, std::uint32_t, OpType::Mult > tests;
	TestCase<std::uint32_t, std::uint32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint32_t ret;
		if (SafeMultiply(test.x, test.y, ret) != test.fExpected)
		{
			//assert(false);
			err_msg("Error in case uint32_uint32: ", test.x, test.y, test.fExpected);
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(test.x);
			si *= test.y;
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			err_msg("Error in case uint32_uint32 throw: ", test.x, test.y, test.fExpected);
		}

		test = tests.GetNext();
	}
}

void MultVerifyUintInt64()
{
	TestVector< std::uint32_t, std::int64_t, OpType::Mult > tests;
	TestCase<std::uint32_t, std::int64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint32_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint32_int64: ", test.x, test.y, test.fExpected ); 
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint32_int64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyUint32Int32()
{
	TestVector< std::uint32_t, std::int32_t, OpType::Mult > tests;
	TestCase<std::uint32_t, std::int32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint32_t ret;
		if (SafeMultiply(test.x, test.y, ret) != test.fExpected)
		{
			//assert(false);
			err_msg("Error in case uint32_int32: ", test.x, test.y, test.fExpected);
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(test.x);
			si *= test.y;
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			err_msg("Error in case uint32_int32 throw: ", test.x, test.y, test.fExpected);
		}

		test = tests.GetNext();
	}
}

void MultVerifyUint64Int64()
{
	TestVector< std::uint64_t, std::uint32_t, OpType::Mult > tests;
	TestCase<std::uint64_t, std::uint32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint64_int64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint64_int64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyUint64Int()
{
	TestVector< std::uint64_t, std::int32_t, OpType::Mult > tests;
	TestCase<std::uint64_t, std::int32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::uint64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint64_int32: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case uint64_int32 throw: ", test.x, test.y, test.fExpected );
		}
		test = tests.GetNext();
	}
}

void MultVerifyInt64Int64()
{
	TestVector< std::int64_t, std::int64_t, OpType::Mult > tests;
	TestCase<std::int64_t, std::int64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int64_int64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int64_int64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt64Uint64()
{
	TestVector< std::int64_t, std::uint64_t, OpType::Mult > tests;
	TestCase<std::int64_t, std::uint64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int64_uint64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int64_uint64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt64Int()
{
	TestVector< std::int64_t, std::int64_t, OpType::Mult > tests;
	TestCase<std::int64_t, std::int64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int64_int32: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int64_int32 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}


void MultVerifyInt64Uint32()
{
	TestVector< std::int64_t, std::int32_t, OpType::Mult > tests;
	TestCase<std::int64_t, std::int32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int64_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int64_uint32: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int64_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int64_uint32 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt32Int64()
{
	TestVector< std::int32_t, std::int64_t, OpType::Mult > tests;
	TestCase<std::int32_t, std::int64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int32_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int_int64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int32_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int_int64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt32Int32()
{
	TestVector< std::int32_t, std::int32_t, OpType::Mult > tests;
	TestCase<std::int32_t, std::int32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int32_t ret;
		if (SafeMultiply(test.x, test.y, ret) != test.fExpected)
		{
			//assert(false);
			err_msg("Error in case int32_int32: ", test.x, test.y, test.fExpected);
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int32_t> si(test.x);
			si *= test.y;
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			err_msg("Error in case int32_int32 throw: ", test.x, test.y, test.fExpected);
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt32Uint64()
{
	TestVector< std::int32_t, std::uint64_t, OpType::Mult > tests;
	TestCase<std::int32_t, std::uint64_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int32_t ret;
		if( SafeMultiply(test.x, test.y, ret) != test.fExpected )
		{
			//assert(false);
			err_msg( "Error in case int_uint64: ", test.x, test.y, test.fExpected );
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int32_t> si(test.x);
			si *= test.y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != test.fExpected )
		{
			err_msg( "Error in case int_uint64 throw: ", test.x, test.y, test.fExpected );
		}

		test = tests.GetNext();
	}
}

void MultVerifyInt32Uint32()
{
	TestVector< std::int32_t, std::uint32_t, OpType::Mult > tests;
	TestCase<std::int32_t, std::uint32_t, OpType::Mult > test = tests.GetNext();

	while (!tests.Done())
	{
		std::int32_t ret;
		if (SafeMultiply(test.x, test.y, ret) != test.fExpected)
		{
			//assert(false);
			err_msg("Error in case int_uint32: ", test.x, test.y, test.fExpected);
		}

		bool fSuccess = true;
		try
		{
			SafeInt<std::int32_t> si(test.x);
			si *= test.y;
		}
		catch (...)
		{
			fSuccess = false;
		}

		if (fSuccess != test.fExpected)
		{
			err_msg("Error in case int_uint32 throw: ", test.x, test.y, test.fExpected);
		}

		test = tests.GetNext();
	}
}

static const TestCase< std::uint8_t, std::uint8_t, OpType::Mult > uint8_uint8[] =
{
	{ 0,	0, true },
	{ 1,	0, true },
	{ 2,	0, true },
	{ 4,	0, true },
	{ 0x10,	0, true },
	{ 0x20,	0, true },
	{ 0x7f,	0, true },
	{ 0x80,	0, true },
	{ 0xc0,	0, true },
	{ 0xe0,	0, true },
	{ 0xff,	0, true },

	{ 0,	1, true },
	{ 1,	1, true },
	{ 2,	1, true },
	{ 4,	1, true },
	{ 0x10,	1, true },
	{ 0x20,	1, true },
	{ 0x7f,	1, true },
	{ 0x80,	1, true },
	{ 0xc0,	1, true },
	{ 0xe0,	1, true },
	{ 0xff,	1, true },

	{ 0,	2, true },
	{ 1,	2, true },
	{ 2,	2, true },
	{ 4,	2, true },
	{ 0x10,	2, true },
	{ 0x20,	2, true },
	{ 0x7f,	2, true },
	{ 0x80,	2, false },
	{ 0xc0,	2, false },
	{ 0xe0,	2, false },
	{ 0xff,	2, false },

	{ 0,	4, true },
	{ 1,	4, true },
	{ 2,	4, true },
	{ 4,	4, true },
	{ 0x10,	4, true },
	{ 0x20,	4, true },
	{ 0x3f,	4, true },
	{ 0x40,	4, false },
	{ 0x7f,	4, false },
	{ 0x80,	4, false },
	{ 0xc0,	4, false },
	{ 0xe0,	4, false },
	{ 0xff,	4, false },

	{ 0,	0x10, true },
	{ 1,	0x10, true },
	{ 2,	0x10, true },
	{ 4,	0x10, true },
	{ 0x0f,	0x10, true },
	{ 0x10,	0x10, false },
	{ 0x20,	0x10, false },
	{ 0x7f,	0x10, false },
	{ 0x80,	0x10, false },
	{ 0xc0,	0x10, false },
	{ 0xe0,	0x10, false },
	{ 0xff,	0x10, false },

	{ 0,	0x20, true },
	{ 1,	0x20, true },
	{ 2,	0x20, true },
	{ 4,	0x20, true },
	{ 7,	0x20, true },
	{ 0x10,	0x20, false },
	{ 0x20,	0x20, false },
	{ 0x7f,	0x20, false },
	{ 0x80,	0x20, false },
	{ 0xc0,	0x20, false },
	{ 0xe0,	0x20, false },
	{ 0xff,	0x20, false },

	{ 0,	0x7f, true },
	{ 1,	0x7f, true },
	{ 2,	0x7f, true },
	{ 4,	0x7f, false },
	{ 0x10,	0x7f, false },
	{ 0x20,	0x7f, false },
	{ 0x7f,	0x7f, false },
	{ 0x80,	0x7f, false },
	{ 0xc0,	0x7f, false },
	{ 0xe0,	0x7f, false },
	{ 0xff,	0x7f, false },

	{ 0,	0x40, true },
	{ 1,	0x40, true },
	{ 2,	0x40, true },
	{ 3,	0x40, true },
	{ 4,	0x40, false },
	{ 0x10,	0x40, false },
	{ 0x20,	0x40, false },
	{ 0x7f,	0x40, false },
	{ 0x80,	0x40, false },
	{ 0xc0,	0x40, false },
	{ 0xe0,	0x40, false },
	{ 0xff,	0x40, false },

	{ 0,	0x80, true },
	{ 1,	0x80, true },
	{ 2,	0x80, false },
	{ 4,	0x80, false },
	{ 0x10,	0x80, false },
	{ 0x20,	0x80, false },
	{ 0x7f,	0x80, false },
	{ 0x80,	0x80, false },
	{ 0xc0,	0x80, false },
	{ 0xe0,	0x80, false },
	{ 0xff,	0x80, false },

	{ 0,	0xff, true },
	{ 1,	0xff, true },
	{ 2,	0xff, false },
	{ 4,	0xff, false },
	{ 0x10,	0xff, false },
	{ 0x20,	0xff, false },
	{ 0x7f,	0xff, false },
	{ 0x80,	0xff, false },
	{ 0xc0,	0xff, false },
	{ 0xe0,	0xff, false },
	{ 0xff,	0xff, false },
};

void MultVerifyUint8Uint8()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint8_uint8); ++i )
	{
		std::uint8_t ret;
		if( SafeMultiply(uint8_uint8[i].x, uint8_uint8[i].y, ret) != uint8_uint8[i].fExpected )
		{
			//assert(false);
			err_msg( "Error in case uint8_uint8: ", (unsigned int)uint8_uint8[i].x, (unsigned int)uint8_uint8[i].y, uint8_uint8[i].fExpected );
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint8_t> si(uint8_uint8[i].x);
			si *= uint8_uint8[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint8_uint8[i].fExpected )
		{
			err_msg( "Error in case uint8_uint8 throw: ", (unsigned int)uint8_uint8[i].x, (unsigned int)uint8_uint8[i].y, uint8_uint8[i].fExpected );
		}
	}
}

#if !defined __GNUC__
#pragma warning( disable: 4309 )
#endif

static const TestCase< std::int8_t, std::int8_t, OpType::Mult > int8_int8[] =
{
	{ 0,	0, true },
	{ 1,	0, true },
	{ 2,	0, true },
	{ 4,	0, true },
	{ 0x10,	0, true },
	{ 0x20,	0, true },
	{ 0x7f,	0, true },
	{ 0x80,	0, true },
	{ 0xc0,	0, true },
	{ 0xe0,	0, true },
	{ 0xfe,	0, true },
	{ 0xff,	0, true },

	{ 0,	1, true },
	{ 1,	1, true },
	{ 2,	1, true },
	{ 4,	1, true },
	{ 0x10,	1, true },
	{ 0x20,	1, true },
	{ 0x7f,	1, true },
	{ 0x80,	1, true },
	{ 0xc0,	1, true },
	{ 0xe0,	1, true },
	{ 0xfe,	1, true },
	{ 0xff,	1, true },

	{ 0,	2, true },
	{ 1,	2, true },
	{ 2,	2, true },
	{ 4,	2, true },
	{ 0x10,	2, true },
	{ 0x20,	2, true },
	{ 0x3f,	2, true },
	{ 0x40,	2, false },
	{ 0x7f,	2, false },
	{ 0x80,	2, false },
	{ 0xc0,	2, true },
	{ 0xe0,	2, true },
	{ 0xfe,	2, true },
	{ 0xff,	2, true },

	{ 0,	4, true },
	{ 1,	4, true },
	{ 2,	4, true },
	{ 4,	4, true },
	{ 0x10,	4, true },
	{ 0x1f,	4, true },
	{ 0x20,	4, false },
	{ 0x7f,	4, false },
	{ 0x80,	4, false },
	{ 0xc0,	4, false },
	{ 0xdf,	4, false },
	{ 0xe0,	4, true },
	{ 0xfe,	4, true },
	{ 0xff,	4, true },

	{ 0,	0x10, true },
	{ 1,	0x10, true },
	{ 2,	0x10, true },
	{ 4,	0x10, true },
	{ 7,	0x10, true },
	{ 8,	0x10, false },
	{ 0x10,	0x10, false },
	{ 0x20,	0x10, false },
	{ 0x7f,	0x10, false },
	{ 0x80,	0x10, false },
	{ 0xc0,	0x10, false },
	{ 0xe0,	0x10, false },
	{ 0xf7,	0x10, false },
	{ 0xf8,	0x10, true },
	{ 0xfe,	0x10, true },
	{ 0xff,	0x10, true },

	{ 0,	0x20, true },
	{ 1,	0x20, true },
	{ 2,	0x20, true },
	{ 3,	0x20, true },
	{ 4,	0x20, false },
	{ 0x10,	0x20, false },
	{ 0x20,	0x20, false },
	{ 0x7f,	0x20, false },
	{ 0x80,	0x20, false },
	{ 0xc0,	0x20, false },
	{ 0xe0,	0x20, false },
	{ 0xfb,	0x20, false },
	{ 0xfc,	0x20, true },
	{ 0xfe,	0x20, true },
	{ 0xff,	0x20, true },

	{ 0,	0x40, true },
	{ 1,	0x40, true },
	{ 2,	0x40, false },
	{ 3,	0x40, false },
	{ 4,	0x40, false },
	{ 0x10,	0x40, false },
	{ 0x20,	0x40, false },
	{ 0x7f,	0x40, false },
	{ 0x80,	0x40, false },
	{ 0xc0,	0x40, false },
	{ 0xe0,	0x40, false },
	{ 0xfd,	0x40, false },
	{ 0xfe,	0x40, true },
	{ 0xff,	0x40, true },

	{ 0,	0x7f, true },
	{ 1,	0x7f, true },
	{ 2,	0x7f, false },
	{ 4,	0x7f, false },
	{ 0x10,	0x7f, false },
	{ 0x20,	0x7f, false },
	{ 0x7f,	0x7f, false },
	{ 0x80,	0x7f, false },
	{ 0xc0,	0x7f, false },
	{ 0xe0,	0x7f, false },
	{ 0xfe,	0x7f, false },
	{ 0xff,	0x7f, true },

	{ 0,	0x80, true },
	{ 1,	0x80, true },
	{ 2,	0x80, false },
	{ 3,	0x80, false },
	{ 4,	0x80, false },
	{ 0x10,	0x80, false },
	{ 0x20,	0x80, false },
	{ 0x7f,	0x80, false },
	{ 0x80,	0x80, false },
	{ 0xc0,	0x80, false },
	{ 0xe0,	0x80, false },
	{ 0xfe,	0x80, false },
	{ 0xff,	0x80, false },

	{ 0,	0xfe, true },
	{ 1,	0xfe, true },
	{ 2,	0xfe, true },
	{ 4,	0xfe, true },
	{ 0x10,	0xfe, true },
	{ 0x20,	0xfe, true },
	{ 0x40,	0xfe, true },
	{ 0x41,	0xfe, false },
	{ 0x7f,	0xfe, false },
	{ 0x80,	0xfe, false },
	{ 0xc0,	0xfe, false },
	{ 0xdf,	0xfe, true },
	{ 0xe0,	0xfe, true },
	{ 0xff,	0xfe, true },

	{ 0,	0xff, true },
	{ 1,	0xff, true },
	{ 2,	0xff, true },
	{ 4,	0xff, true },
	{ 0x10,	0xff, true },
	{ 0x20,	0xff, true },
	{ 0x7f,	0xff, true },
	{ 0x80,	0xff, false },
	{ 0xc0,	0xff, true },
	{ 0xe0,	0xff, true },
	{ 0xff,	0xff, true },
};

#if !defined __GNUC__
#pragma warning( default: 4309 )
#endif

void MultVerifyInt8Int8()
{
	size_t i;

	for( i = 0; i < COUNTOF(int8_int8); ++i )
	{
		std::int8_t ret;
		if( SafeMultiply(int8_int8[i].x, int8_int8[i].y, ret) != int8_int8[i].fExpected )
		{
			//assert(false);
			err_msg( "Error in case int8_int8: ", (unsigned int)int8_int8[i].x, (unsigned int)int8_int8[i].y, int8_int8[i].fExpected );
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<std::int8_t> si(int8_int8[i].x);
			si *= int8_int8[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int8_int8[i].fExpected )
		{
			err_msg( "Error in case int8_int8 throw: ", (unsigned int)int8_int8[i].x, (unsigned int)int8_int8[i].y, int8_int8[i].fExpected );
		}
	}
}

void MultVerify()
{
	std::cout << "Verifying Multiplication:" << std::endl;

	MultVerifyUint64Uint64();
	MultVerifyUint64Uint();
	MultVerifyUint64Int64();
	MultVerifyUint64Int();

	MultVerifyUintUint64();
	MultVerifyUint32Uint32();
	MultVerifyUintInt64();
	MultVerifyUint32Int32();

	MultVerifyInt64Int64();
	MultVerifyInt64Uint64();
	MultVerifyInt64Int();
	MultVerifyInt64Uint32();

	MultVerifyInt32Uint64();
	MultVerifyInt32Uint32();
	MultVerifyInt32Int64();
	MultVerifyInt32Int32();

	// TBD 16 and 8-bit complete
	MultVerifyInt8Int8();
	MultVerifyUint8Uint8();
}

}
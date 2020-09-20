// Copyright (c) OWASP Project (https://www.owasp.org), 2011. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"

namespace incdec_verify
{

template <typename T>
struct IncTest
{
	T x;			// value
	T y;			// value++
	bool fExpected;	// false = overflow
};

template <typename T>
struct DecTest
{
	T x;			// value
	T y;			// value++
	bool fExpected;	// false = overflow
};

static const IncTest< std::uint8_t > inc_uint8[] =
{
	{ 0x00, 0x01, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x03, true},
	{ 0x7e, 0x7f, true},
	{ 0x7f, 0x80, true},
	{ 0x80, 0x81, true},
	{ 0x81, 0x82, true},
	{ 0xfe, 0xff, true},
	{ 0xff, 0x00, false},
};

void PreIncTestUint8()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint8_t> si(inc_uint8[i].x);
			SafeInt<std::uint8_t> vv = ++si;

			if(vv != inc_uint8[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint8[i].fExpected )
		{
			err_msg( "Error in case inc_uint8 throw (1): ", inc_uint8[i].x, inc_uint8[i].fExpected );
		}
	}
}

void PostIncTestUint8()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint8_t> si(inc_uint8[i].x);
			SafeInt<std::uint8_t> vv = si++;

			if(vv != inc_uint8[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint8[i].fExpected )
		{
			err_msg( "Error in case inc_uint8 throw (2): ", inc_uint8[i].x, inc_uint8[i].fExpected );
		}
	}
}

static const IncTest< std::uint16_t > inc_uint16[] =
{
	{ 0x0000, 0x0001, true},
	{ 0x0001, 0x0002, true},
	{ 0x0002, 0x0003, true},
	{ 0x7ffe, 0x7fff, true},
	{ 0x7fff, 0x8000, true},
	{ 0x8000, 0x8001, true},
	{ 0x8001, 0x8002, true},
	{ 0xfffe, 0xffff, true},
	{ 0xffff, 0x0000, false},
};

void PreIncTestUint16()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint16_t> si(inc_uint16[i].x);
			SafeInt<std::uint16_t> vv = ++si;

			if(vv != inc_uint16[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint16[i].fExpected )
		{
			err_msg( "Error in case inc_uint16 throw (1): ", inc_uint16[i].x, inc_uint16[i].fExpected );
		}
	}
}

void PostIncTestUint16()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint16_t> si(inc_uint16[i].x);
			SafeInt<std::uint16_t> vv = si++;

			if(vv != inc_uint16[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint16[i].fExpected )
		{
			err_msg( "Error in case inc_uint16 throw (2): ", inc_uint16[i].x, inc_uint16[i].fExpected );
		}
	}
}

static const IncTest< std::uint32_t > inc_uint32[] =
{
	{ 0x00000000, 0x00000001, true},
	{ 0x00000001, 0x00000002, true},
	{ 0x00000002, 0x00000003, true},
	{ 0x7ffffffe, 0x7fffffff, true},
	{ 0x7fffffff, 0x80000000, true},
	{ 0x80000000, 0x80000001, true},
	{ 0x80000001, 0x80000002, true},
	{ 0xfffffffe, 0xffffffff, true},
	{ 0xffffffff, 0x00000000, false},
};

void PreIncTestUint32()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(inc_uint32[i].x);
			SafeInt<std::uint32_t> vv = ++si;

			if(vv != inc_uint32[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint32[i].fExpected )
		{
			err_msg( "Error in case inc_uint32 throw (1): ", inc_uint32[i].x, inc_uint32[i].fExpected );
		}
	}
}

void PostIncTestUint32()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(inc_uint32[i].x);
			SafeInt<std::uint32_t> vv = si++;

			if(vv != inc_uint32[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint32[i].fExpected )
		{
			err_msg( "Error in case inc_uint32 throw (2): ", inc_uint32[i].x, inc_uint32[i].fExpected );
		}
	}
}

static const IncTest< std::uint64_t > inc_uint64[] =
{
	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000003, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000002, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000001, true},
	{ 0x0000000200000000, 0x0000000200000001, true},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0x7fffffffffffffff, 0x8000000000000000, true},
	{ 0x8000000000000000, 0x8000000000000001, true},
	{ 0x8000000000000001, 0x8000000000000002, true},
	{ 0xfffffffffffffffe, 0xffffffffffffffff, true},
	{ 0xffffffffffffffff, 0x0000000000000000, false},
};

void PreIncTestUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(inc_uint64[i].x);
			SafeInt<std::uint64_t> vv = ++si;

			if(vv != inc_uint64[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint64[i].fExpected )
		{
			err_msg( "Error in case inc_uint64 throw (1): ",
			inc_uint64[i].x,
			inc_uint64[i].fExpected );
		}
	}
}

void PostIncTestUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_uint64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(inc_uint64[i].x);
			SafeInt<std::uint64_t> vv = si++;

			if(vv != inc_uint64[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_uint64[i].fExpected )
		{
			err_msg( "Error in case inc_uint64 throw (2): ",
			inc_uint64[i].x,
			inc_uint64[i].fExpected );
		}
	}
}

static const IncTest< std::int8_t > inc_int8[] =
{
	{ 0x00, 0x01, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x03, true},
	{ 0x7e, 0x7f, true},
	{ 0x7f, 0x80, false},
	{ 0x80, 0x81, true},
	{ 0x81, 0x82, true},
	{ 0xfe, 0xff, true},
	{ 0xff, 0x00, true},
};

void PreIncTestInt8()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int8_t > si(inc_int8[i].x);
			SafeInt< std::int8_t > vv = ++si;

			if(vv != inc_int8[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int8[i].fExpected )
		{
			err_msg( "Error in case inc_int8 throw (1): ", inc_int8[i].x, inc_int8[i].fExpected );
		}
	}
}

void PostIncTestInt8()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int8_t > si(inc_int8[i].x);
			SafeInt< std::int8_t > vv = si++;

			if(vv != inc_int8[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int8[i].fExpected )
		{
			err_msg( "Error in case inc_int8 throw (2): ", inc_int8[i].x, inc_int8[i].fExpected );
		}
	}
}

static const IncTest< std::int16_t > inc_int16[] =
{
	{ 0x0000, 0x0001, true},
	{ 0x0001, 0x0002, true},
	{ 0x0002, 0x0003, true},
	{ 0x7ffe, 0x7fff, true},
	{ 0x7fff, 0x8000, false},
	{ 0x8000, 0x8001, true},
	{ 0x8001, 0x8002, true},
	{ 0xfffe, 0xffff, true},
	{ 0xffff, 0x0000, true},
};

void PreIncTestInt16()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int16_t > si(inc_int16[i].x);
			SafeInt< std::int16_t > vv = ++si;

			if(vv != inc_int16[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int16[i].fExpected )
		{
			err_msg( "Error in case inc_int16 throw (1): ", inc_int16[i].x, inc_int16[i].fExpected );
		}
	}
}

void PostIncTestInt16()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int16_t > si(inc_int16[i].x);
			SafeInt< std::int16_t > vv = si++;

			if(vv != inc_int16[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int16[i].fExpected )
		{
			err_msg( "Error in case inc_int16 throw (2): ", inc_int16[i].x, inc_int16[i].fExpected );
		}
	}
}

static const IncTest< std::int32_t > inc_int32[] =
{
	{ 0x00000000, 0x00000001, true},
	{ 0x00000001, 0x00000002, true},
	{ 0x00000002, 0x00000003, true},
	{ 0x7ffffffe, 0x7fffffff, true},
	{ 0x7fffffff, 0x80000000, false},
	{ 0x80000000, 0x80000001, true},
	{ 0x80000001, 0x80000002, true},
	{ 0xfffffffe, 0xffffffff, true},
	{ 0xffffffff, 0x00000000, true},
};

void PreIncTestInt32()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int32_t > si(inc_int32[i].x);
			SafeInt< std::int32_t > vv = ++si;

			if(vv != inc_int32[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int32[i].fExpected )
		{
			err_msg( "Error in case inc_int32 throw (1): ", inc_int32[i].x, inc_int32[i].fExpected );
		}
	}
}

void PostIncTestInt32()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int32_t > si(inc_int32[i].x);
			SafeInt< std::int32_t > vv = si++;

			if(vv != inc_int32[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int32[i].fExpected )
		{
			err_msg( "Error in case inc_int32 throw (2): ", inc_int32[i].x, inc_int32[i].fExpected );
		}
	}
}

static const IncTest< std::int64_t > inc_int64[] =
{
	{ 0x0000000000000000, 0x0000000000000001, true},
	{ 0x0000000000000001, 0x0000000000000002, true},
	{ 0x0000000000000002, 0x0000000000000003, true},
	{ 0x000000007ffffffe, 0x000000007fffffff, true},
	{ 0x000000007fffffff, 0x0000000080000000, true},
	{ 0x0000000080000000, 0x0000000080000001, true},
	{ 0x0000000080000001, 0x0000000080000002, true},
	{ 0x00000000fffffffe, 0x00000000ffffffff, true},
	{ 0x00000000ffffffff, 0x0000000100000000, true},
	{ 0x0000000100000000, 0x0000000100000001, true},
	{ 0x0000000200000000, 0x0000000200000001, true},
	{ 0x7ffffffffffffffe, 0x7fffffffffffffff, true},
	{ 0x7fffffffffffffff, 0x8000000000000000, false},
	{ 0x8000000000000000, 0x8000000000000001, true},
	{ 0x8000000000000001, 0x8000000000000002, true},
	{ 0xfffffffffffffffe, 0xffffffffffffffff, true},
	{ 0xffffffffffffffff, 0x0000000000000000, true},
};

void PreIncTestInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int64_t > si(inc_int64[i].x);
			SafeInt< std::int64_t > vv = ++si;

			if(vv != inc_int64[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int64[i].fExpected )
		{
			err_msg( "Error in case inc_int64 throw (1): ", inc_int64[i].x, inc_int64[i].fExpected );
		}
	}
}

void PostIncTestInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(inc_int64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int64_t > si(inc_int64[i].x);
			SafeInt< std::int64_t > vv = si++;

			if(vv != inc_int64[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != inc_int64[i].fExpected )
		{
			err_msg( "Error in case inc_int64 throw (2): ", inc_int64[i].x, inc_int64[i].fExpected );
		}
	}
}

static const DecTest< std::uint8_t > dec_uint8[] =
{
	{ 0x00, 0xff, false},
	{ 0x01, 0x00, true},
	{ 0x02, 0x01, true},
	{ 0x7e, 0x7d, true},
	{ 0x7f, 0x7e, true},
	{ 0x80, 0x7f, true},
	{ 0x81, 0x80, true},
	{ 0xfe, 0xfd, true},
	{ 0xff, 0xfe, true},
};

void PreDecTestUint8()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint8_t> si(dec_uint8[i].x);
			SafeInt<std::uint8_t> vv = --si;

			if(vv != dec_uint8[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint8[i].fExpected )
		{
			err_msg( "Error in case dec_uint8 throw (1): ", dec_uint8[i].x, dec_uint8[i].fExpected );
		}
	}
}

void PostDecTestUint8()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint8_t> si(dec_uint8[i].x);
			SafeInt<std::uint8_t> vv = si--;

			if(vv != dec_uint8[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint8[i].fExpected )
		{
			err_msg( "Error in case dec_uint8 throw (2): ", dec_uint8[i].x, dec_uint8[i].fExpected );
		}
	}
}

static const DecTest< std::uint16_t > dec_uint16[] =
{
	{ 0x0000, 0xffff, false},
	{ 0x0001, 0x0000, true},
	{ 0x0002, 0x0001, true},
	{ 0x7ffe, 0x7ffd, true},
	{ 0x7fff, 0x7ffe, true},
	{ 0x8000, 0x7fff, true},
	{ 0x8001, 0x8000, true},
	{ 0xfffe, 0xfffd, true},
	{ 0xffff, 0xfffe, true},
};

void PreDecTestUint16()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint16_t> si(dec_uint16[i].x);
			SafeInt<std::uint16_t> vv = --si;

			if(vv != dec_uint16[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint16[i].fExpected )
		{
			err_msg( "Error in case dec_uint16 throw (1): ", dec_uint16[i].x, dec_uint16[i].fExpected );
		}
	}
}

void PostDecTestUint16()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint16_t> si(dec_uint16[i].x);
			SafeInt<std::uint16_t> vv = si--;

			if(vv != dec_uint16[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint16[i].fExpected )
		{
			err_msg( "Error in case dec_uint16 throw (2): ", dec_uint16[i].x, dec_uint16[i].fExpected );
		}
	}
}

static const DecTest< std::uint32_t > dec_uint32[] =
{
	{ 0x00000000, 0xffffffff, false},
	{ 0x00000001, 0x00000000, true},
	{ 0x00000002, 0x00000001, true},
	{ 0x7ffffffe, 0x7ffffffd, true},
	{ 0x7fffffff, 0x7ffffffe, true},
	{ 0x80000000, 0x7fffffff, true},
	{ 0x80000001, 0x80000000, true},
	{ 0xfffffffe, 0xfffffffd, true},
	{ 0xffffffff, 0xfffffffe, true},
};

void PreDecTestUint32()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(dec_uint32[i].x);
			SafeInt<std::uint32_t> vv = --si;

			if(vv != dec_uint32[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint32[i].fExpected )
		{
			err_msg( "Error in case dec_uint32 throw (1): ", dec_uint32[i].x, dec_uint32[i].fExpected );
		}
	}
}

void PostDecTestUint32()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint32_t> si(dec_uint32[i].x);
			SafeInt<std::uint32_t> vv = si--;

			if(vv != dec_uint32[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint32[i].fExpected )
		{
			err_msg( "Error in case dec_uint32 throw (2): ", dec_uint32[i].x, dec_uint32[i].fExpected );
		}
	}
}

static const DecTest< std::uint64_t > dec_uint64[] =
{
	{ 0x0000000000000000, 0xffffffffffffffff, false},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x000000007ffffffd, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x00000000fffffffd, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000001ffffffff, true},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffd, true},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
	{ 0x8000000000000000, 0x7fffffffffffffff, true},
	{ 0x8000000000000001, 0x8000000000000000, true},
	{ 0xfffffffffffffffe, 0xfffffffffffffffd, true},
	{ 0xffffffffffffffff, 0xfffffffffffffffe, true},
};

void PreDecTestUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(dec_uint64[i].x);
			SafeInt<std::uint64_t> vv = --si;

			if(vv != dec_uint64[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint64[i].fExpected )
		{
			err_msg( "Error in case dec_uint64 throw (1): ",
			dec_uint64[i].x,
			dec_uint64[i].fExpected );
		}
	}
}

void PostDecTestUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_uint64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt<std::uint64_t> si(dec_uint64[i].x);
			SafeInt<std::uint64_t> vv = si--;

			if(vv != dec_uint64[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_uint64[i].fExpected )
		{
			err_msg( "Error in case dec_uint64 throw (2): ",
			dec_uint64[i].x,
			dec_uint64[i].fExpected );
		}
	}
}

static const DecTest< std::int8_t > dec_int8[] =
{
	{ 0x00, 0xff, true},
	{ 0x01, 0x00, true},
	{ 0x02, 0x01, true},
	{ 0x7e, 0x7d, true},
	{ 0x7f, 0x7e, true},
	{ 0x80, 0x7f, false},
	{ 0x81, 0x80, true},
	{ 0xfe, 0xfd, true},
	{ 0xff, 0xfe, true},
};

void PreDecTestInt8()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int8_t > si(dec_int8[i].x);
			SafeInt< std::int8_t > vv = --si;

			if(vv != dec_int8[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int8[i].fExpected )
		{
			err_msg( "Error in case dec_int8 throw (1): ", dec_int8[i].x, dec_int8[i].fExpected );
		}
	}
}

void PostDecTestInt8()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int8); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int8_t > si(dec_int8[i].x);
			SafeInt< std::int8_t > vv = si--;

			if(vv != dec_int8[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int8[i].fExpected )
		{
			err_msg( "Error in case dec_int8 throw (2): ", dec_int8[i].x, dec_int8[i].fExpected );
		}
	}
}

static const DecTest< std::int16_t > dec_int16[] =
{
	{ 0x0000, 0xffff, true},
	{ 0x0001, 0x0000, true},
	{ 0x0002, 0x0001, true},
	{ 0x7ffe, 0x7ffd, true},
	{ 0x7fff, 0x7ffe, true},
	{ 0x8000, 0x7fff, false},
	{ 0x8001, 0x8000, true},
	{ 0xfffe, 0xfffd, true},
	{ 0xffff, 0xfffe, true},
};

void PreDecTestInt16()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int16_t > si(dec_int16[i].x);
			SafeInt< std::int16_t > vv = --si;

			if(vv != dec_int16[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int16[i].fExpected )
		{
			err_msg( "Error in case dec_int16 throw (1): ", dec_int16[i].x, dec_int16[i].fExpected );
		}
	}
}

void PostDecTestInt16()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int16); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int16_t > si(dec_int16[i].x);
			SafeInt< std::int16_t > vv = si--;

			if(vv != dec_int16[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int16[i].fExpected )
		{
			err_msg( "Error in case dec_int16 throw (2): ", dec_int16[i].x, dec_int16[i].fExpected );
		}
	}
}

static const DecTest< std::int32_t > dec_int32[] =
{
	{ 0x00000000, 0xffffffff, true},
	{ 0x00000001, 0x00000000, true},
	{ 0x00000002, 0x00000001, true},
	{ 0x7ffffffe, 0x7ffffffd, true},
	{ 0x7fffffff, 0x7ffffffe, true},
	{ 0x80000000, 0x7fffffff, false},
	{ 0x80000001, 0x80000000, true},
	{ 0xfffffffe, 0xfffffffd, true},
	{ 0xffffffff, 0xfffffffe, true},
};

void PreDecTestInt32()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int32_t > si(dec_int32[i].x);
			SafeInt< std::int32_t > vv = --si;

			if(vv != dec_int32[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int32[i].fExpected )
		{
			err_msg( "Error in case dec_int32 throw (1): ", dec_int32[i].x, dec_int32[i].fExpected );
		}
	}
}

void PostDecTestInt32()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int32); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int32_t > si(dec_int32[i].x);
			SafeInt< std::int32_t > vv = si--;

			if(vv != dec_int32[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int32[i].fExpected )
		{
			err_msg( "Error in case dec_int32 throw (2): ", dec_int32[i].x, dec_int32[i].fExpected );
		}
	}
}

static const DecTest< std::int64_t > dec_int64[] =
{
	{ 0x0000000000000000, 0xffffffffffffffff, true},
	{ 0x0000000000000001, 0x0000000000000000, true},
	{ 0x0000000000000002, 0x0000000000000001, true},
	{ 0x000000007ffffffe, 0x000000007ffffffd, true},
	{ 0x000000007fffffff, 0x000000007ffffffe, true},
	{ 0x0000000080000000, 0x000000007fffffff, true},
	{ 0x0000000080000001, 0x0000000080000000, true},
	{ 0x00000000fffffffe, 0x00000000fffffffd, true},
	{ 0x00000000ffffffff, 0x00000000fffffffe, true},
	{ 0x0000000100000000, 0x00000000ffffffff, true},
	{ 0x0000000200000000, 0x00000001ffffffff, true},
	{ 0x7ffffffffffffffe, 0x7ffffffffffffffd, true},
	{ 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
	{ 0x8000000000000000, 0x7fffffffffffffff, false},
	{ 0x8000000000000001, 0x8000000000000000, true},
	{ 0xfffffffffffffffe, 0xfffffffffffffffd, true},
	{ 0xffffffffffffffff, 0xfffffffffffffffe, true},
};

void PreDecTestInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int64_t > si(dec_int64[i].x);
			SafeInt< std::int64_t > vv = --si;

			if(vv != dec_int64[i].y)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int64[i].fExpected )
		{
			err_msg( "Error in case dec_int64 throw (1): ", dec_int64[i].x, dec_int64[i].fExpected );
		}
	}
}

void PostDecTestInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(dec_int64); ++i )
	{
		bool fSuccess = true;
		try
		{
			SafeInt< std::int64_t > si(dec_int64[i].x);
			SafeInt< std::int64_t > vv = si--;

			if(vv != dec_int64[i].x)
			{
				fSuccess = false;
			}
		}
		catch(SafeIntException&)
		{
			fSuccess = false;
		}

		if( fSuccess != dec_int64[i].fExpected )
		{
			err_msg( "Error in case dec_int64 throw (2): ", dec_int64[i].x, dec_int64[i].fExpected );
		}
	}
}

void IncDecVerify()
{
   std::cout << "Verifying Increment-decrement:" << std::endl;
	PreIncTestUint8();
	PostIncTestUint8();
	PreIncTestUint16();
	PostIncTestUint16();
	PreIncTestUint32();
	PostIncTestUint32();
	PreIncTestUint64();
	PostIncTestUint64();

	PreIncTestInt8();
	PostIncTestInt8();
	PreIncTestInt16();
	PostIncTestInt16();
	PreIncTestInt32();
	PostIncTestInt32();
	PreIncTestInt64();
	PostIncTestInt64();

	PostDecTestUint8();
	PreDecTestUint16();
	PostDecTestUint16();
	PreDecTestUint32();
	PostDecTestUint32();
	PreDecTestUint64();
	PostDecTestUint64();

	PreDecTestInt8();
	PostDecTestInt8();
	PreDecTestInt16();
	PostDecTestInt16();
	PreDecTestInt32();
	PostDecTestInt32();
	PreDecTestInt64();
	PostDecTestInt64();
}

}
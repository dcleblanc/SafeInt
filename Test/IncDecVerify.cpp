/*-----------------------------------------------------------------------------------------------------------
This software is licensed under the Microsoft Public License (Ms-PL).
For more information about Microsoft open source licenses, refer to
http://www.microsoft.com/opensource/licenses.mspx

This license governs use of the accompanying software. If you use the software, you accept this license.
If you do not accept the license, do not use the software.

Definitions
The terms "reproduce," "reproduction," "derivative works," and "distribution" have the same meaning here
as under U.S. copyright law. A "contribution" is the original software, or any additions or changes to
the software. A "contributor" is any person that distributes its contribution under this license.
"Licensed patents" are a contributor's patent claims that read directly on its contribution.

Grant of Rights
(A) Copyright Grant- Subject to the terms of this license, including the license conditions and limitations
in section 3, each contributor grants you a non-exclusive, worldwide, royalty-free copyright license to
reproduce its contribution, prepare derivative works of its contribution, and distribute its contribution
or any derivative works that you create.

(B) Patent Grant- Subject to the terms of this license, including the license conditions and limitations in
section 3, each contributor grants you a non-exclusive, worldwide, royalty-free license under its licensed
patents to make, have made, use, sell, offer for sale, import, and/or otherwise dispose of its contribution
in the software or derivative works of the contribution in the software.

Conditions and Limitations
(A) No Trademark License- This license does not grant you rights to use any contributors' name, logo,
or trademarks.
(B) If you bring a patent claim against any contributor over patents that you claim are infringed by the
software, your patent license from such contributor to the software ends automatically.
(C) If you distribute any portion of the software, you must retain all copyright, patent, trademark, and
attribution notices that are present in the software.
(D) If you distribute any portion of the software in source code form, you may do so only under this license
by including a complete copy of this license with your distribution. If you distribute any portion of the
software in compiled or object code form, you may only do so under a license that complies with this license.
(E) The software is licensed "as-is." You bear the risk of using it. The contributors give no express warranties,
guarantees, or conditions. You may have additional consumer rights under your local laws which this license
cannot change. To the extent permitted under your local laws, the contributors exclude the implied warranties
of merchantability, fitness for a particular purpose and non-infringement.


Copyright (c) OWASP Project (https://www.owasp.org), 2011. All rights reserved.
*/

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

static const IncTest< unsigned __int8 > inc_uint8[] =
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
			SafeInt<unsigned __int8> si(inc_uint8[i].x);
			SafeInt<unsigned __int8> vv = ++si;

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
			cerr << "Error in case inc_uint8 throw (1): ";
			cerr << HEX(2) << (0xFF & (int)inc_uint8[i].x) << ", ";
			cerr << "expected = " << inc_uint8[i].fExpected << endl;
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
			SafeInt<unsigned __int8> si(inc_uint8[i].x);
			SafeInt<unsigned __int8> vv = si++;

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
			cerr << "Error in case inc_uint8 throw (2): ";
			cerr << HEX(2) << (0xFF & (int)inc_uint8[i].x) << ", ";
			cerr << "expected = " << inc_uint8[i].fExpected << endl;
		}
	}
}

static const IncTest< unsigned __int16 > inc_uint16[] =
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
			SafeInt<unsigned __int16> si(inc_uint16[i].x);
			SafeInt<unsigned __int16> vv = ++si;

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
			cerr << "Error in case inc_uint16 throw (1): ";
			cerr << HEX(4) << inc_uint16[i].x << ", ";
			cerr << "expected = " << inc_uint16[i].fExpected << endl;
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
			SafeInt<unsigned __int16> si(inc_uint16[i].x);
			SafeInt<unsigned __int16> vv = si++;

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
			cerr << "Error in case inc_uint16 throw (2): ";
			cerr << HEX(4) << inc_uint16[i].x << ", ";
			cerr << "expected = " << inc_uint16[i].fExpected << endl;
		}
	}
}

static const IncTest< unsigned __int32 > inc_uint32[] =
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
			SafeInt<unsigned __int32> si(inc_uint32[i].x);
			SafeInt<unsigned __int32> vv = ++si;

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
			cerr << "Error in case inc_uint32 throw (1): ";
			cerr << HEX(8) << inc_uint32[i].x << ", ";
			cerr << "expected = " << inc_uint32[i].fExpected << endl;
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
			SafeInt<unsigned __int32> si(inc_uint32[i].x);
			SafeInt<unsigned __int32> vv = si++;

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
			cerr << "Error in case inc_uint32 throw (2): ";
			cerr << HEX(8) << inc_uint32[i].x << ", ";
			cerr << "expected = " << inc_uint32[i].fExpected << endl;
		}
	}
}

static const IncTest< unsigned __int64 > inc_uint64[] =
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
			SafeInt<unsigned __int64> si(inc_uint64[i].x);
			SafeInt<unsigned __int64> vv = ++si;

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
			cerr << "Error in case inc_uint64 throw (1): ";
			cerr << HEX(16) << inc_uint64[i].x << ", ";
			cerr << "expected = " << inc_uint64[i].fExpected << endl;
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
			SafeInt<unsigned __int64> si(inc_uint64[i].x);
			SafeInt<unsigned __int64> vv = si++;

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
			cerr << "Error in case inc_uint64 throw (2): ";
			cerr << HEX(16) << inc_uint64[i].x << ", ";
			cerr << "expected = " << inc_uint64[i].fExpected << endl;
		}
	}
}

static const IncTest< __int8 > inc_int8[] =
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
			SafeInt< __int8 > si(inc_int8[i].x);
			SafeInt< __int8 > vv = ++si;

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
			cerr << "Error in case inc_int8 throw (1): ";
			cerr << HEX(2) << (0xFF & (int)inc_int8[i].x) << ", ";
			cerr << "expected = " << inc_int8[i].fExpected << endl;
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
			SafeInt< __int8 > si(inc_int8[i].x);
			SafeInt< __int8 > vv = si++;

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
			cerr << "Error in case inc_int8 throw (2): ";
			cerr << HEX(2) << (0xFF & (int)inc_int8[i].x) << ", ";
			cerr << "expected = " << inc_int8[i].fExpected << endl;
		}
	}
}

static const IncTest< __int16 > inc_int16[] =
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
			SafeInt< __int16 > si(inc_int16[i].x);
			SafeInt< __int16 > vv = ++si;

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
			cerr << "Error in case inc_int16 throw (1): ";
			cerr << HEX(4) << inc_int16[i].x << ", ";
			cerr << "expected = " << inc_int16[i].fExpected << endl;
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
			SafeInt< __int16 > si(inc_int16[i].x);
			SafeInt< __int16 > vv = si++;

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
			cerr << "Error in case inc_int16 throw (2): ";
			cerr << HEX(4) << inc_int16[i].x << ", ";
			cerr << "expected = " << inc_int16[i].fExpected << endl;
		}
	}
}

static const IncTest< __int32 > inc_int32[] =
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
			SafeInt< __int32 > si(inc_int32[i].x);
			SafeInt< __int32 > vv = ++si;

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
			cerr << "Error in case inc_int32 throw (1): ";
			cerr << HEX(8) << inc_int32[i].x << ", ";
			cerr << "expected = " << inc_int32[i].fExpected << endl;
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
			SafeInt< __int32 > si(inc_int32[i].x);
			SafeInt< __int32 > vv = si++;

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
			cerr << "Error in case inc_int32 throw (2): ";
			cerr << HEX(8) << inc_int32[i].x << ", ";
			cerr << "expected = " << inc_int32[i].fExpected << endl;
		}
	}
}

static const IncTest< __int64 > inc_int64[] =
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
			SafeInt< __int64 > si(inc_int64[i].x);
			SafeInt< __int64 > vv = ++si;

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
			cerr << "Error in case inc_int64 throw (1): ";
			cerr << HEX(8) << inc_int64[i].x << ", ";
			cerr << "expected = " << inc_int64[i].fExpected << endl;
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
			SafeInt< __int64 > si(inc_int64[i].x);
			SafeInt< __int64 > vv = si++;

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
			cerr << "Error in case inc_int64 throw (2): ";
			cerr << HEX(8) << inc_int64[i].x << ", ";
			cerr << "expected = " << inc_int64[i].fExpected << endl;
		}
	}
}

static const DecTest< unsigned __int8 > dec_uint8[] =
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
			SafeInt<unsigned __int8> si(dec_uint8[i].x);
			SafeInt<unsigned __int8> vv = --si;

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
			cerr << "Error in case dec_uint8 throw (1): ";
			cerr << HEX(2) << (0xFF & (int)dec_uint8[i].x) << ", ";
			cerr << "expected = " << dec_uint8[i].fExpected << endl;
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
			SafeInt<unsigned __int8> si(dec_uint8[i].x);
			SafeInt<unsigned __int8> vv = si--;

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
			cerr << "Error in case dec_uint8 throw (2): ";
			cerr << HEX(2) << (0xFF & (int)dec_uint8[i].x) << ", ";
			cerr << "expected = " << dec_uint8[i].fExpected << endl;
		}
	}
}

static const DecTest< unsigned __int16 > dec_uint16[] =
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
			SafeInt<unsigned __int16> si(dec_uint16[i].x);
			SafeInt<unsigned __int16> vv = --si;

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
			cerr << "Error in case dec_uint16 throw (1): ";
			cerr << HEX(4) << dec_uint16[i].x << ", ";
			cerr << "expected = " << dec_uint16[i].fExpected << endl;
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
			SafeInt<unsigned __int16> si(dec_uint16[i].x);
			SafeInt<unsigned __int16> vv = si--;

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
			cerr << "Error in case dec_uint16 throw (2): ";
			cerr << HEX(4) << dec_uint16[i].x << ", ";
			cerr << "expected = " << dec_uint16[i].fExpected << endl;
		}
	}
}

static const DecTest< unsigned __int32 > dec_uint32[] =
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
			SafeInt<unsigned __int32> si(dec_uint32[i].x);
			SafeInt<unsigned __int32> vv = --si;

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
			cerr << "Error in case dec_uint32 throw (1): ";
			cerr << HEX(8) << dec_uint32[i].x << ", ";
			cerr << "expected = " << dec_uint32[i].fExpected << endl;
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
			SafeInt<unsigned __int32> si(dec_uint32[i].x);
			SafeInt<unsigned __int32> vv = si--;

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
			cerr << "Error in case dec_uint32 throw (2): ";
			cerr << HEX(8) << dec_uint32[i].x << ", ";
			cerr << "expected = " << dec_uint32[i].fExpected << endl;
		}
	}
}

static const DecTest< unsigned __int64 > dec_uint64[] =
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
			SafeInt<unsigned __int64> si(dec_uint64[i].x);
			SafeInt<unsigned __int64> vv = --si;

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
			cerr << "Error in case dec_uint64 throw (1): ";
			cerr << HEX(16) << dec_uint64[i].x << ", ";
			cerr << "expected = " << dec_uint64[i].fExpected << endl;
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
			SafeInt<unsigned __int64> si(dec_uint64[i].x);
			SafeInt<unsigned __int64> vv = si--;

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
			cerr << "Error in case dec_uint64 throw (2): ";
			cerr << HEX(16) << dec_uint64[i].x << ", ";
			cerr << "expected = " << dec_uint64[i].fExpected << endl;
		}
	}
}

static const DecTest< __int8 > dec_int8[] =
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
			SafeInt< __int8 > si(dec_int8[i].x);
			SafeInt< __int8 > vv = --si;

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
			cerr << "Error in case dec_int8 throw (1): ";
			cerr << HEX(2) << (0xFF & (int)dec_int8[i].x) << ", ";
			cerr << "expected = " << dec_int8[i].fExpected << endl;
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
			SafeInt< __int8 > si(dec_int8[i].x);
			SafeInt< __int8 > vv = si--;

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
			cerr << "Error in case dec_int8 throw (2): ";
			cerr << HEX(2) << (0xFF & (int)dec_int8[i].x) << ", ";
			cerr << "expected = " << dec_int8[i].fExpected << endl;
		}
	}
}

static const DecTest< __int16 > dec_int16[] =
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
			SafeInt< __int16 > si(dec_int16[i].x);
			SafeInt< __int16 > vv = --si;

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
			cerr << "Error in case dec_int16 throw (1): ";
			cerr << HEX(4) << dec_int16[i].x << ", ";
			cerr << "expected = " << dec_int16[i].fExpected << endl;
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
			SafeInt< __int16 > si(dec_int16[i].x);
			SafeInt< __int16 > vv = si--;

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
			cerr << "Error in case dec_int16 throw (2): ";
			cerr << HEX(4) << dec_int16[i].x << ", ";
			cerr << "expected = " << dec_int16[i].fExpected << endl;
		}
	}
}

static const DecTest< __int32 > dec_int32[] =
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
			SafeInt< __int32 > si(dec_int32[i].x);
			SafeInt< __int32 > vv = --si;

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
			cerr << "Error in case dec_int32 throw (1): ";
			cerr << HEX(8) << dec_int32[i].x << ", ";
			cerr << "expected = " << dec_int32[i].fExpected << endl;
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
			SafeInt< __int32 > si(dec_int32[i].x);
			SafeInt< __int32 > vv = si--;

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
			cerr << "Error in case dec_int32 throw (2): ";
			cerr << HEX(8) << dec_int32[i].x << ", ";
			cerr << "expected = " << dec_int32[i].fExpected << endl;
		}
	}
}

static const DecTest< __int64 > dec_int64[] =
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
			SafeInt< __int64 > si(dec_int64[i].x);
			SafeInt< __int64 > vv = --si;

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
			cerr << "Error in case dec_int64 throw (1): ";
			cerr << HEX(16) << dec_int64[i].x << ", ";
			cerr << "expected = " << dec_int64[i].fExpected << endl;
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
			SafeInt< __int64 > si(dec_int64[i].x);
			SafeInt< __int64 > vv = si--;

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
			cerr << "Error in case dec_int64 throw (2): ";
			cerr << HEX(16) << dec_int64[i].x << ", ";
			cerr << "expected = " << dec_int64[i].fExpected << endl;
		}
	}
}

void IncDecVerify()
{
   cout << "Verifying Increment-decrement:" << endl;
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
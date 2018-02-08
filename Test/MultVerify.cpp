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


Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#include "TestMain.h"

/*
* Interesting numbers:
*
*  unsigned __int64
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000000, 0x200000000, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff
*  unsigned __int32
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff
*  signed __int64
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000000, 0x200000000, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff
*/

namespace mult_verify
{

template <typename T, typename U>
struct MultTest
{
	T x;
	U y;
	bool fExpected;
};

static const MultTest< unsigned __int64, unsigned __int64 > uint64_uint64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, true },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, true },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, true },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, true },
	{ 0x100000000,           0xffffffff, true },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, true },
	{ 2,                     0x100000000, true },
	{ 0x7fffffff,            0x100000000, true },
	{ 0x80000000,            0x100000000, true },
	{ 0xffffffff,            0x100000000, true },
	{ 0x100000000,           0x100000000, false },
	{ 0x200000000,           0x100000000, false },
	{ 0x7fffffffffffffff,    0x100000000, false },
	{ 0x8000000000000000,    0x100000000, false },
	{ 0xffffffffffffffff,    0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, true },
	{ 2,                     0x200000000, true },
	{ 0x7fffffff,            0x200000000, true },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0x100000000,           0x200000000, false },
	{ 0x200000000,           0x200000000, false },
	{ 0x7fffffffffffffff,    0x200000000, false },
	{ 0x8000000000000000,    0x200000000, false },
	{ 0xffffffffffffffff,    0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, true },
	{ 2,                     0x7fffffffffffffff, true },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0x100000000,           0x7fffffffffffffff, false },
	{ 0x200000000,           0x7fffffffffffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffffffffffff, false },
	{ 0x8000000000000000,    0x7fffffffffffffff, false },
	{ 0xffffffffffffffff,    0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, true },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0x100000000,           0x8000000000000000, false },
	{ 0x200000000,           0x8000000000000000, false },
	{ 0x7fffffffffffffff,    0x8000000000000000, false },
	{ 0x8000000000000000,    0x8000000000000000, false },
	{ 0xffffffffffffffff,    0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, true },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false },
	{ 0x100000000,           0xffffffffffffffff, false },
	{ 0x200000000,           0xffffffffffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffffffffffff, false },
	{ 0x8000000000000000,    0xffffffffffffffff, false },
	{ 0xffffffffffffffff,    0xffffffffffffffff, false },
	// Special case - force addition overflow case
	{ 0xffffffff,            0x100000002, false }
};

void MultVerifyUint64Uint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint64_uint64); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case uint64_uint64: %I64X, %I64X, expected = %s\n",
			// uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_uint64: ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].y << ", ";
			cerr << "expected = " << uint64_uint64[i].fExpected << endl;
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int64> si(uint64_uint64[i].x);
			si *= uint64_uint64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint64_uint64[i].fExpected )
		{
			// printf("Error in case uint64_uint64 throw: %I64X, %I64X, expected = %s\n",
			// uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_uint64 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].y << ", ";
			cerr << "expected = " << uint64_uint64[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int64, unsigned __int32 > uint64_uint32[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, true },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, true },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, true },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, true },
	{ 0x100000000,           0xffffffff, true },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, false }
};

void MultVerifyUint64Uint()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint64_uint32); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_uint32: ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].y << ", ";
			cerr << "expected = " << uint64_uint32[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int64> si(uint64_uint32[i].x);
			si *= uint64_uint32[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint64_uint32[i].fExpected )
		{
			// printf("Error in case uint64_uint32 throw: %I64X, %I64X, expected = %s\n",
			// uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_uint32 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].y << ", ";
			cerr << "expected = " << uint64_uint32[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int32, unsigned __int64 > uint32_uint64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, false },
	{ 0xffffffff,            2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, false },
	{ 0x80000000,            0x7fffffff, false },
	{ 0xffffffff,            0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, false },
	{ 0x7fffffff,            0x80000000, false },
	{ 0x80000000,            0x80000000, false },
	{ 0xffffffff,            0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, false },
	{ 0x7fffffff,            0xffffffff, false },
	{ 0x80000000,            0xffffffff, false },
	{ 0xffffffff,            0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, false },
	{ 2,                     0x100000000, false },
	{ 0x7fffffff,            0x100000000, false },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, false },
	{ 2,                     0x200000000, false },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, false },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, false },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false }
};

void MultVerifyUintUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint32_uint64); ++i )
	{
		unsigned __int32 ret;
		if( SafeMultiply(uint32_uint64[i].x, uint32_uint64[i].y, ret) != uint32_uint64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// uint32_uint64[i].x, uint32_uint64[i].y, uint32_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint32_uint64: ";
			cerr << hex << setw(16) << setfill('0') << uint32_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint32_uint64[i].y << ", ";
			cerr << "expected = " << uint32_uint64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int32> si(uint32_uint64[i].x);
			si *= uint32_uint64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint32_uint64[i].fExpected )
		{
			// printf("Error in case uint32_uint64 throw: %I64X, %I64X, expected = %s\n",
			// uint32_uint64[i].x, uint32_uint64[i].y, uint32_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint32_uint64 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint32_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint32_uint64[i].y << ", ";
			cerr << "expected = " << uint32_uint64[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int32, __int64 > uint32_int64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, false },
	{ 0xffffffff,            2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, false },
	{ 0x80000000,            0x7fffffff, false },
	{ 0xffffffff,            0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, false },
	{ 0x7fffffff,            0x80000000, false },
	{ 0x80000000,            0x80000000, false },
	{ 0xffffffff,            0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, false },
	{ 0x7fffffff,            0xffffffff, false },
	{ 0x80000000,            0xffffffff, false },
	{ 0xffffffff,            0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, false },
	{ 2,                     0x100000000, false },
	{ 0x7fffffff,            0x100000000, false },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, false },
	{ 2,                     0x200000000, false },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, false },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, false },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false }
};

void MultVerifyUintInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint32_int64); ++i )
	{
		unsigned __int32 ret;
		if( SafeMultiply(uint32_int64[i].x, uint32_int64[i].y, ret) != uint32_int64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// uint32_int64[i].x, uint32_int64[i].y, uint32_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint32_int64: ";
			cerr << hex << setw(16) << setfill('0') << uint32_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint32_int64[i].y << ", ";
			cerr << "expected = " << uint32_int64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int32> si(uint32_int64[i].x);
			si *= uint32_int64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint32_int64[i].fExpected )
		{
			// printf("Error in case uint32_int64 throw: %I64X, %I64X, expected = %s\n",
			// uint32_int64[i].x, uint32_int64[i].y, uint32_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint32_int64 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint32_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint32_int64[i].y << ", ";
			cerr << "expected = " << uint32_int64[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int64, __int64 > uint64_int64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, true },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, true },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, true },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, true },
	{ 0x100000000,           0xffffffff, true },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, true },
	{ 2,                     0x100000000, true },
	{ 0x7fffffff,            0x100000000, true },
	{ 0x80000000,            0x100000000, true },
	{ 0xffffffff,            0x100000000, true },
	{ 0x100000000,           0x100000000, false },
	{ 0x200000000,           0x100000000, false },
	{ 0x7fffffffffffffff,    0x100000000, false },
	{ 0x8000000000000000,    0x100000000, false },
	{ 0xffffffffffffffff,    0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, true },
	{ 2,                     0x200000000, true },
	{ 0x7fffffff,            0x200000000, true },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0x100000000,           0x200000000, false },
	{ 0x200000000,           0x200000000, false },
	{ 0x7fffffffffffffff,    0x200000000, false },
	{ 0x8000000000000000,    0x200000000, false },
	{ 0xffffffffffffffff,    0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, true },
	{ 2,                     0x7fffffffffffffff, true },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0x100000000,           0x7fffffffffffffff, false },
	{ 0x200000000,           0x7fffffffffffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffffffffffff, false },
	{ 0x8000000000000000,    0x7fffffffffffffff, false },
	{ 0xffffffffffffffff,    0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0x100000000,           0x8000000000000000, false },
	{ 0x200000000,           0x8000000000000000, false },
	{ 0x7fffffffffffffff,    0x8000000000000000, false },
	{ 0x8000000000000000,    0x8000000000000000, false },
	{ 0xffffffffffffffff,    0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, false },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false },
	{ 0x100000000,           0xffffffffffffffff, false },
	{ 0x200000000,           0xffffffffffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffffffffffff, false },
	{ 0x8000000000000000,    0xffffffffffffffff, false },
	{ 0xffffffffffffffff,    0xffffffffffffffff, false }
};

void MultVerifyUint64Int64()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint64_int64); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_int64: ";
			cerr << hex << setw(16) << setfill('0') << uint64_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_int64[i].y << ", ";
			cerr << "expected = " << uint64_int64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int64> si(uint64_int64[i].x);
			si *= uint64_int64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint64_int64[i].fExpected )
		{
			// printf("Error in case uint64_int64 throw: %I64X, %I64X, expected = %s\n",
			// uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_int64 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint64_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_int64[i].y << ", ";
			cerr << "expected = " << uint64_int64[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int64, __int32 > uint64_int32[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, true },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, false },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, true },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, false },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, false },
	{ 2,                     0x80000000, false },
	{ 0x7fffffff,            0x80000000, false },
	{ 0x80000000,            0x80000000, false },
	{ 0xffffffff,            0x80000000, false },
	{ 0x100000000,           0x80000000, false },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, false },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, false },
	{ 2,                     0xffffffff, false },
	{ 0x7fffffff,            0xffffffff, false },
	{ 0x80000000,            0xffffffff, false },
	{ 0xffffffff,            0xffffffff, false },
	{ 0x100000000,           0xffffffff, false },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, false }
};

void MultVerifyUint64Int()
{
	size_t i;

	for( i = 0; i < COUNTOF(uint64_int32); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_int32: ";
			cerr << hex << setw(16) << setfill('0') << uint64_int32[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_int32[i].y << ", ";
			cerr << "expected = " << uint64_int32[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int64> si(uint64_int32[i].x);
			si *= uint64_int32[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint64_int32[i].fExpected )
		{
			// printf("Error in case uint64_int32 throw: %I64X, %I64X, expected = %s\n",
			// uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
			cerr << "Error in case uint64_int32 throw: ";
			cerr << hex << setw(16) << setfill('0') << uint64_int32[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << uint64_int32[i].y << ", ";
			cerr << "expected = " << uint64_int32[i].fExpected << endl;
		}
	}
}

static const MultTest< __int64, __int64 > int64_int64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, false },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, false },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, false },
	{ 0x100000000,           0xffffffff, false },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, true },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, true },
	{ 2,                     0x100000000, true },
	{ 0x7fffffff,            0x100000000, true },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0x100000000,           0x100000000, false },
	{ 0x200000000,           0x100000000, false },
	{ 0x7fffffffffffffff,    0x100000000, false },
	{ 0x8000000000000000,    0x100000000, false },
	{ 0xffffffffffffffff,    0x100000000, true },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, true },
	{ 2,                     0x200000000, true },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0x100000000,           0x200000000, false },
	{ 0x200000000,           0x200000000, false },
	{ 0x7fffffffffffffff,    0x200000000, false },
	{ 0x8000000000000000,    0x200000000, false },
	{ 0xffffffffffffffff,    0x200000000, true },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, true },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0x100000000,           0x7fffffffffffffff, false },
	{ 0x200000000,           0x7fffffffffffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffffffffffff, false },
	{ 0x8000000000000000,    0x7fffffffffffffff, false },
	{ 0xffffffffffffffff,    0x7fffffffffffffff, true },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, true },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0x100000000,           0x8000000000000000, false },
	{ 0x200000000,           0x8000000000000000, false },
	{ 0x7fffffffffffffff,    0x8000000000000000, false },
	{ 0x8000000000000000,    0x8000000000000000, false },
	{ 0xffffffffffffffff,    0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, true },
	{ 2,                     0xffffffffffffffff, true },
	{ 0x7fffffff,            0xffffffffffffffff, true },
	{ 0x80000000,            0xffffffffffffffff, true },
	{ 0xffffffff,            0xffffffffffffffff, true },
	{ 0x100000000,           0xffffffffffffffff, true },
	{ 0x200000000,           0xffffffffffffffff, true },
	{ 0x7fffffffffffffff,    0xffffffffffffffff, true },
	{ 0x8000000000000000,    0xffffffffffffffff, false },
	{ 0xffffffffffffffff,    0xffffffffffffffff, true },
	// Special case - force addition overflow case
	{ 0xffffffff,            0x100000002, false }
};

void MultVerifyInt64Int64()
{
	size_t i;

	for( i = 0; i < COUNTOF(int64_int64); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_int64: ";
			cerr << hex << setw(16) << setfill('0') << int64_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_int64[i].y << ", ";
			cerr << "expected = " << int64_int64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int64> si(int64_int64[i].x);
			si *= int64_int64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int64_int64[i].fExpected )
		{
			// printf("Error in case int64_int64 throw: %I64X, %I64X, expected = %s\n",
			// int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_int64 throw: ";
			cerr << hex << setw(16) << setfill('0') << int64_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_int64[i].y << ", ";
			cerr << "expected = " << int64_int64[i].fExpected << endl;
		}
	}
}

static const MultTest< __int64, unsigned __int64 > int64_uint64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, false },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, false },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, false },
	{ 0x100000000,           0xffffffff, false },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, true },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, true },
	{ 2,                     0x100000000, true },
	{ 0x7fffffff,            0x100000000, true },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0x100000000,           0x100000000, false },
	{ 0x200000000,           0x100000000, false },
	{ 0x7fffffffffffffff,    0x100000000, false },
	{ 0x8000000000000000,    0x100000000, false },
	{ 0xffffffffffffffff,    0x100000000, true },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, true },
	{ 2,                     0x200000000, true },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0x100000000,           0x200000000, false },
	{ 0x200000000,           0x200000000, false },
	{ 0x7fffffffffffffff,    0x200000000, false },
	{ 0x8000000000000000,    0x200000000, false },
	{ 0xffffffffffffffff,    0x200000000, true },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, true },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0x100000000,           0x7fffffffffffffff, false },
	{ 0x200000000,           0x7fffffffffffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffffffffffff, false },
	{ 0x8000000000000000,    0x7fffffffffffffff, false },
	{ 0xffffffffffffffff,    0x7fffffffffffffff, true },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0x100000000,           0x8000000000000000, false },
	{ 0x200000000,           0x8000000000000000, false },
	{ 0x7fffffffffffffff,    0x8000000000000000, false },
	{ 0x8000000000000000,    0x8000000000000000, false },
	{ 0xffffffffffffffff,    0x8000000000000000, true },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, false },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false },
	{ 0x100000000,           0xffffffffffffffff, false },
	{ 0x200000000,           0xffffffffffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffffffffffff, false },
	{ 0x8000000000000000,    0xffffffffffffffff, false },
	{ 0xffffffffffffffff,    0xffffffffffffffff, false },
	// Special case - force addition overflow case
	{ 0xffffffff,            0x100000002, false }
};

void MultVerifyInt64Uint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(int64_uint64); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_uint64: ";
			cerr << hex << setw(16) << setfill('0') << int64_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_uint64[i].y << ", ";
			cerr << "expected = " << int64_uint64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int64> si(int64_uint64[i].x);
			si *= int64_uint64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int64_uint64[i].fExpected )
		{
			// printf("Error in case int64_uint64 throw: %I64X, %I64X, expected = %s\n",
			// int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_uint64 throw: ";
			cerr << hex << setw(16) << setfill('0') << int64_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_uint64[i].y << ", ";
			cerr << "expected = " << int64_uint64[i].fExpected << endl;
		}
	}
}

static const MultTest< __int64, __int32 > int64_int[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, false },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, true },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, true },
	{ 0x100000000,           0xffffffff, true },
	{ 0x200000000,           0xffffffff, true },
	{ 0x7fffffffffffffff,    0xffffffff, true },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, true }
};

void MultVerifyInt64Int()
{
	size_t i;

	for( i = 0; i < COUNTOF(int64_int); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_int[i].x, int64_int[i].y, ret) != int64_int[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int64_int[i].x, int64_int[i].y, int64_int[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_int: ";
			cerr << hex << setw(16) << setfill('0') << int64_int[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_int[i].y << ", ";
			cerr << "expected = " << int64_int[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int64> si(int64_int[i].x);
			si *= int64_int[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int64_int[i].fExpected )
		{
			// printf("Error in case int64_int throw: %I64X, %I64X, expected = %s\n",
			// int64_int[i].x, int64_int[i].y, int64_int[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_int throw: ";
			cerr << hex << setw(16) << setfill('0') << int64_int[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_int[i].y << ", ";
			cerr << "expected = " << int64_int[i].fExpected << endl;
		}
	}
}

static const MultTest< __int64, unsigned __int32 > int64_uint[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0x100000000,           0, true },
	{ 0x200000000,           0, true },
	{ 0x7fffffffffffffff,    0, true },
	{ 0x8000000000000000,    0, true },
	{ 0xffffffffffffffff,    0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0x100000000,           1, true },
	{ 0x200000000,           1, true },
	{ 0x7fffffffffffffff,    1, true },
	{ 0x8000000000000000,    1, true },
	{ 0xffffffffffffffff,    1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, true },
	{ 0x80000000,            2, true },
	{ 0xffffffff,            2, true },
	{ 0x100000000,           2, true },
	{ 0x200000000,           2, true },
	{ 0x7fffffffffffffff,    2, false },
	{ 0x8000000000000000,    2, false },
	{ 0xffffffffffffffff,    2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, true },
	{ 0x7fffffff,            0x7fffffff, true },
	{ 0x80000000,            0x7fffffff, true },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0x100000000,           0x7fffffff, true },
	{ 0x200000000,           0x7fffffff, false },
	{ 0x7fffffffffffffff,    0x7fffffff, false },
	{ 0x8000000000000000,    0x7fffffff, false },
	{ 0xffffffffffffffff,    0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, true },
	{ 2,                     0x80000000, true },
	{ 0x7fffffff,            0x80000000, true },
	{ 0x80000000,            0x80000000, true },
	{ 0xffffffff,            0x80000000, true },
	{ 0x100000000,           0x80000000, false },
	{ 0x200000000,           0x80000000, false },
	{ 0x7fffffffffffffff,    0x80000000, false },
	{ 0x8000000000000000,    0x80000000, false },
	{ 0xffffffffffffffff,    0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, true },
	{ 2,                     0xffffffff, true },
	{ 0x7fffffff,            0xffffffff, true },
	{ 0x80000000,            0xffffffff, true },
	{ 0xffffffff,            0xffffffff, false },
	{ 0x100000000,           0xffffffff, false },
	{ 0x200000000,           0xffffffff, false },
	{ 0x7fffffffffffffff,    0xffffffff, false },
	{ 0x8000000000000000,    0xffffffff, false },
	{ 0xffffffffffffffff,    0xffffffff, true }
};

void MultVerifyInt64Uint()
{
	size_t i;

	for( i = 0; i < COUNTOF(int64_uint); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_uint[i].x, int64_uint[i].y, ret) != int64_uint[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int64_uint[i].x, int64_uint[i].y, int64_uint[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_uint: ";
			cerr << hex << setw(16) << setfill('0') << int64_uint[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_uint[i].y << ", ";
			cerr << "expected = " << int64_uint[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int64> si(int64_uint[i].x);
			si *= int64_uint[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int64_uint[i].fExpected )
		{
			// printf("Error in case int64_uint throw: %I64X, %I64X, expected = %s\n",
			// int64_uint[i].x, int64_uint[i].y, int64_uint[i].fExpected ? "true" : "false");
			cerr << "Error in case int64_uint throw: ";
			cerr << hex << setw(16) << setfill('0') << int64_uint[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int64_uint[i].y << ", ";
			cerr << "expected = " << int64_uint[i].fExpected << endl;
		}
	}
}

static const MultTest< __int32, __int64 > int_int64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, false },
	{ 0x80000000,            2, false },
	{ 0xffffffff,            2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, false },
	{ 0x7fffffff,            0x7fffffff, false },
	{ 0x80000000,            0x7fffffff, false },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, false },
	{ 2,                     0x80000000, false },
	{ 0x7fffffff,            0x80000000, false },
	{ 0x80000000,            0x80000000, false },
	{ 0xffffffff,            0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, false },
	{ 2,                     0xffffffff, false },
	{ 0x7fffffff,            0xffffffff, false },
	{ 0x80000000,            0xffffffff, false },
	{ 0xffffffff,            0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, false },
	{ 2,                     0x100000000, false },
	{ 0x7fffffff,            0x100000000, false },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, false },
	{ 2,                     0x200000000, false },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, false },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, true },
	{ 2,                     0xffffffffffffffff, true },
	{ 0x7fffffff,            0xffffffffffffffff, true },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, true },
	// Special case - force addition overflow case
	{ 0xffffffff,            0x100000002, false }
};

void MultVerifyIntInt64()
{
	size_t i;

	for( i = 0; i < COUNTOF(int_int64); ++i )
	{
		__int32 ret;
		if( SafeMultiply(int_int64[i].x, int_int64[i].y, ret) != int_int64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int_int64[i].x, int_int64[i].y, int_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case int_int64: ";
			cerr << hex << setw(16) << setfill('0') << int_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int_int64[i].y << ", ";
			cerr << "expected = " << int_int64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int32> si(int_int64[i].x);
			si *= int_int64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int_int64[i].fExpected )
		{
			// printf("Error in case int_int64 throw: %I64X, %I64X, expected = %s\n",
			// int_int64[i].x, int_int64[i].y, int_int64[i].fExpected ? "true" : "false");
			cerr << "Error in case int_int64 throw: ";
			cerr << hex << setw(16) << setfill('0') << int_int64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int_int64[i].y << ", ";
			cerr << "expected = " << int_int64[i].fExpected << endl;
		}
	}
}

static const MultTest< __int32, unsigned __int64 > int_uint64[] = 
{
	{ 0,                     0, true },
	{ 1,                     0, true },
	{ 2,                     0, true },
	{ 0x7fffffff,            0, true },
	{ 0x80000000,            0, true },
	{ 0xffffffff,            0, true },
	{ 0,                     1, true },
	{ 1,                     1, true },
	{ 2,                     1, true },
	{ 0x7fffffff,            1, true },
	{ 0x80000000,            1, true },
	{ 0xffffffff,            1, true },
	{ 0,                     2, true },
	{ 1,                     2, true },
	{ 2,                     2, true },
	{ 0x7fffffff,            2, false },
	{ 0x80000000,            2, false },
	{ 0xffffffff,            2, true },
	{ 0,                     0x7fffffff, true },
	{ 1,                     0x7fffffff, true },
	{ 2,                     0x7fffffff, false },
	{ 0x7fffffff,            0x7fffffff, false },
	{ 0x80000000,            0x7fffffff, false },
	{ 0xffffffff,            0x7fffffff, true },
	{ 0,                     0x80000000, true },
	{ 1,                     0x80000000, false },
	{ 2,                     0x80000000, false },
	{ 0x7fffffff,            0x80000000, false },
	{ 0x80000000,            0x80000000, false },
	{ 0xffffffff,            0x80000000, true },
	{ 0,                     0xffffffff, true },
	{ 1,                     0xffffffff, false },
	{ 2,                     0xffffffff, false },
	{ 0x7fffffff,            0xffffffff, false },
	{ 0x80000000,            0xffffffff, false },
	{ 0xffffffff,            0xffffffff, false },
	{ 0,                     0x100000000, true },
	{ 1,                     0x100000000, false },
	{ 2,                     0x100000000, false },
	{ 0x7fffffff,            0x100000000, false },
	{ 0x80000000,            0x100000000, false },
	{ 0xffffffff,            0x100000000, false },
	{ 0,                     0x200000000, true },
	{ 1,                     0x200000000, false },
	{ 2,                     0x200000000, false },
	{ 0x7fffffff,            0x200000000, false },
	{ 0x80000000,            0x200000000, false },
	{ 0xffffffff,            0x200000000, false },
	{ 0,                     0x7fffffffffffffff, true },
	{ 1,                     0x7fffffffffffffff, false },
	{ 2,                     0x7fffffffffffffff, false },
	{ 0x7fffffff,            0x7fffffffffffffff, false },
	{ 0x80000000,            0x7fffffffffffffff, false },
	{ 0xffffffff,            0x7fffffffffffffff, false },
	{ 0,                     0x8000000000000000, true },
	{ 1,                     0x8000000000000000, false },
	{ 2,                     0x8000000000000000, false },
	{ 0x7fffffff,            0x8000000000000000, false },
	{ 0x80000000,            0x8000000000000000, false },
	{ 0xffffffff,            0x8000000000000000, false },
	{ 0,                     0xffffffffffffffff, true },
	{ 1,                     0xffffffffffffffff, false },
	{ 2,                     0xffffffffffffffff, false },
	{ 0x7fffffff,            0xffffffffffffffff, false },
	{ 0x80000000,            0xffffffffffffffff, false },
	{ 0xffffffff,            0xffffffffffffffff, false },
	// Special case - force addition overflow case
	{ 0xffffffff,            0x100000002, false }
};

void MultVerifyIntUint64()
{
	size_t i;

	for( i = 0; i < COUNTOF(int_uint64); ++i )
	{
		__int32 ret;
		if( SafeMultiply(int_uint64[i].x, int_uint64[i].y, ret) != int_uint64[i].fExpected )
		{
			//assert(false);
			// printf("Error in case %I64X, %I64X, expected = %s\n",
			// int_uint64[i].x, int_uint64[i].y, int_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case int_uint64: ";
			cerr << hex << setw(16) << setfill('0') << int_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int_uint64[i].y << ", ";
			cerr << "expected = " << int_uint64[i].fExpected << endl;
		}

		bool fSuccess = true;
		try
		{
			SafeInt<signed __int32> si(int_uint64[i].x);
			si *= int_uint64[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int_uint64[i].fExpected )
		{
			// printf("Error in case int_uint64 throw: %I64X, %I64X, expected = %s\n",
			// int_uint64[i].x, int_uint64[i].y, int_uint64[i].fExpected ? "true" : "false");
			cerr << "Error in case int_uint64 throw: ";
			cerr << hex << setw(16) << setfill('0') << int_uint64[i].x << ", ";
			cerr << hex << setw(16) << setfill('0') << int_uint64[i].y << ", ";
			cerr << "expected = " << int_uint64[i].fExpected << endl;
		}
	}
}

static const MultTest< unsigned __int8, unsigned __int8 > uint8_uint8[] = 
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
		unsigned __int8 ret;
		if( SafeMultiply(uint8_uint8[i].x, uint8_uint8[i].y, ret) != uint8_uint8[i].fExpected )
		{
			//assert(false);
			// printf("Error in case uint8_uint8: %02X, %02X, expected = %s\n",
			// uint8_uint8[i].x, uint8_uint8[i].y, uint8_uint8[i].fExpected ? "true" : "false");
			cerr << "Error in case uint8_uint8: ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)uint8_uint8[i].x << ", ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)uint8_uint8[i].y << ", ";
			cerr << "expected = " << uint8_uint8[i].fExpected << endl;
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<unsigned __int8> si(uint8_uint8[i].x);
			si *= uint8_uint8[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != uint8_uint8[i].fExpected )
		{
			// printf("Error in case uint8_uint8 throw: %02X, %02X, expected = %s\n",
			// uint8_uint8[i].x, uint8_uint8[i].y, uint8_uint8[i].fExpected ? "true" : "false");
			cerr << "Error in case uint8_uint8 throw: ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)uint8_uint8[i].x << ", ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)uint8_uint8[i].y << ", ";
			cerr << "expected = " << uint8_uint8[i].fExpected << endl;
		}
	}
}

#if !defined __GNUC__
#pragma warning( disable: 4309 )
#endif

static const MultTest< __int8, __int8 > int8_int8[] = 
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
		__int8 ret;
		if( SafeMultiply(int8_int8[i].x, int8_int8[i].y, ret) != int8_int8[i].fExpected )
		{
			//assert(false);
			// printf("Error in case int8_int8: %02X, %02X, expected = %s\n",
			// int8_int8[i].x, int8_int8[i].y, int8_int8[i].fExpected ? "true" : "false");
			cerr << "Error in case int8_int8: ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)int8_int8[i].x << ", ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)int8_int8[i].y << ", ";
			cerr << "expected = " << int8_int8[i].fExpected << endl;
		}

		// Now test throwing version
		bool fSuccess = true;
		try
		{
			SafeInt<__int8> si(int8_int8[i].x);
			si *= int8_int8[i].y;
		}
		catch(...)
		{
			fSuccess = false;
		}

		if( fSuccess != int8_int8[i].fExpected )
		{
			// printf("Error in case int8_int8 throw: %02X, %02X, expected = %s\n",
			// int8_int8[i].x, int8_int8[i].y, int8_int8[i].fExpected ? "true" : "false");
			cerr << "Error in case int8_int8 throw: ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)int8_int8[i].x << ", ";
			cerr << hex << setw(2) << setfill('0') << (unsigned int)int8_int8[i].y << ", ";
			cerr << "expected = " << int8_int8[i].fExpected << endl;
		}
	}
}

void MultVerify()
{
	cout << "Verifying Multiplication:" << endl;

	MultVerifyUint64Uint64();
	MultVerifyUint64Uint();
	MultVerifyUint64Int64();
	MultVerifyUint64Int();

	MultVerifyUintUint64();
	MultVerifyUintInt64();

	MultVerifyInt64Int64();
	MultVerifyInt64Uint64();
	MultVerifyInt64Int();
	MultVerifyInt64Uint();

	MultVerifyIntInt64();
	MultVerifyIntUint64();

	MultVerifyInt8Int8();
	MultVerifyUint8Uint8();
}

}
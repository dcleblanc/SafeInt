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

#include <stdio.h>
#include <assert.h>
#include "SafeInt3.hpp"

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

template <typename T, typename U>
struct MultTest
{
	T x;
	U y;
	bool fExpected;
};

MultTest< unsigned __int64, unsigned __int64 > uint64_uint64[] = 
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

	for( i = 0; i < sizeof(uint64_uint64)/sizeof(uint64_uint64[0]); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< unsigned __int64, unsigned __int32 > uint64_uint32[] = 
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

	for( i = 0; i < sizeof(uint64_uint32)/sizeof(uint64_uint32[0]); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< unsigned __int32, unsigned __int64 > uint32_uint64[] = 
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

	for( i = 0; i < sizeof(uint32_uint64)/sizeof(uint32_uint64[0]); ++i )
	{
		unsigned __int32 ret;
		if( SafeMultiply(uint32_uint64[i].x, uint32_uint64[i].y, ret) != uint32_uint64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint32_uint64[i].x, uint32_uint64[i].y, uint32_uint64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< unsigned __int32, __int64 > uint32_int64[] = 
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

	for( i = 0; i < sizeof(uint32_int64)/sizeof(uint32_int64[0]); ++i )
	{
		unsigned __int32 ret;
		if( SafeMultiply(uint32_int64[i].x, uint32_int64[i].y, ret) != uint32_int64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint32_int64[i].x, uint32_int64[i].y, uint32_int64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< unsigned __int64, __int64 > uint64_int64[] = 
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

	for( i = 0; i < sizeof(uint64_int64)/sizeof(uint64_int64[0]); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< unsigned __int64, __int32 > uint64_int32[] = 
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

	for( i = 0; i < sizeof(uint64_int32)/sizeof(uint64_int32[0]); ++i )
	{
		unsigned __int64 ret;
		if( SafeMultiply(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int64, __int64 > int64_int64[] = 
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

	for( i = 0; i < sizeof(int64_int64)/sizeof(int64_int64[0]); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int64, unsigned __int64 > int64_uint64[] = 
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

	for( i = 0; i < sizeof(int64_uint64)/sizeof(int64_uint64[0]); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int64, __int32 > int64_int[] = 
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

	for( i = 0; i < sizeof(int64_int)/sizeof(int64_int[0]); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_int[i].x, int64_int[i].y, ret) != int64_int[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int64_int[i].x, int64_int[i].y, int64_int[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int64, unsigned __int32 > int64_uint[] = 
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

	for( i = 0; i < sizeof(int64_uint)/sizeof(int64_uint[0]); ++i )
	{
		__int64 ret;
		if( SafeMultiply(int64_uint[i].x, int64_uint[i].y, ret) != int64_uint[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int64_uint[i].x, int64_uint[i].y, int64_uint[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int32, __int64 > int_int64[] = 
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

	for( i = 0; i < sizeof(int_int64)/sizeof(int_int64[0]); ++i )
	{
		__int32 ret;
		if( SafeMultiply(int_int64[i].x, int_int64[i].y, ret) != int_int64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int_int64[i].x, int_int64[i].y, int_int64[i].fExpected ? "true" : "false");
		}
	}
}

MultTest< __int32, unsigned __int64 > int_uint64[] = 
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

	for( i = 0; i < sizeof(int_uint64)/sizeof(int_uint64[0]); ++i )
	{
		__int32 ret;
		if( SafeMultiply(int_uint64[i].x, int_uint64[i].y, ret) != int_uint64[i].fExpected )
		{
			//assert(false);
			printf("Error in case %I64X, %I64X, expected = %s\n", int_uint64[i].x, int_uint64[i].y, int_uint64[i].fExpected ? "true" : "false");
		}
	}
}

void MultVerify()
{
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

}
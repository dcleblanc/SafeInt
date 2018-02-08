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


Copyright (c) Microsoft Corporation. All rights reserved.
*/
#include "TestMain.h"

namespace sub_verify
{

template <typename T, typename U>
struct SubTest
{
    T x;
    U y;
    bool fExpected;
};

// For the most part, unsigned-unsigned combinations are not going to give us any problems
static const SubTest< unsigned __int64, unsigned __int64 > uint64_uint64[] =
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

    { 0x0000000000000000, 0x0000000000000001, false},
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
    { 0xffffffffffffffff, 0x0000000000000001, true},

    { 0x0000000000000000, 0x0000000000000002, false},
    { 0x0000000000000001, 0x0000000000000002, false},
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
    { 0xfffffffffffffffe, 0x0000000000000002, true},
    { 0xffffffffffffffff, 0x0000000000000002, true},

    { 0x0000000000000000, 0x000000007ffffffe, false},
    { 0x0000000000000001, 0x000000007ffffffe, false},
    { 0x0000000000000002, 0x000000007ffffffe, false},
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
    { 0xfffffffffffffffe, 0x000000007ffffffe, true},
    { 0xffffffffffffffff, 0x000000007ffffffe, true},

    { 0x0000000000000000, 0x000000007fffffff, false},
    { 0x0000000000000001, 0x000000007fffffff, false},
    { 0x0000000000000002, 0x000000007fffffff, false},
    { 0x000000007ffffffe, 0x000000007fffffff, false},
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
    { 0xfffffffffffffffe, 0x000000007fffffff, true},
    { 0xffffffffffffffff, 0x000000007fffffff, true},

    { 0x0000000000000000, 0x0000000080000000, false},
    { 0x0000000000000001, 0x0000000080000000, false},
    { 0x0000000000000002, 0x0000000080000000, false},
    { 0x000000007ffffffe, 0x0000000080000000, false},
    { 0x000000007fffffff, 0x0000000080000000, false},
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
    { 0xfffffffffffffffe, 0x0000000080000000, true},
    { 0xffffffffffffffff, 0x0000000080000000, true},

    { 0x0000000000000000, 0x0000000080000001, false},
    { 0x0000000000000001, 0x0000000080000001, false},
    { 0x0000000000000002, 0x0000000080000001, false},
    { 0x000000007ffffffe, 0x0000000080000001, false},
    { 0x000000007fffffff, 0x0000000080000001, false},
    { 0x0000000080000000, 0x0000000080000001, false},
    { 0x0000000080000001, 0x0000000080000001, true},
    { 0x00000000fffffffe, 0x0000000080000001, true},
    { 0x00000000ffffffff, 0x0000000080000001, true},
    { 0x0000000100000000, 0x0000000080000001, true},
    { 0x0000000200000000, 0x0000000080000001, true},
    { 0x7ffffffffffffffe, 0x0000000080000001, true},
    { 0x7fffffffffffffff, 0x0000000080000001, true},
    { 0x8000000000000000, 0x0000000080000001, true},
    { 0x8000000000000001, 0x0000000080000001, true},
    { 0xfffffffffffffffe, 0x0000000080000001, true},
    { 0xffffffffffffffff, 0x0000000080000001, true},

    { 0x0000000000000000, 0x00000000fffffffe, false},
    { 0x0000000000000001, 0x00000000fffffffe, false},
    { 0x0000000000000002, 0x00000000fffffffe, false},
    { 0x000000007ffffffe, 0x00000000fffffffe, false},
    { 0x000000007fffffff, 0x00000000fffffffe, false},
    { 0x0000000080000000, 0x00000000fffffffe, false},
    { 0x0000000080000001, 0x00000000fffffffe, false},
    { 0x00000000fffffffe, 0x00000000fffffffe, true},
    { 0x00000000ffffffff, 0x00000000fffffffe, true},
    { 0x0000000100000000, 0x00000000fffffffe, true},
    { 0x0000000200000000, 0x00000000fffffffe, true},
    { 0x7ffffffffffffffe, 0x00000000fffffffe, true},
    { 0x7fffffffffffffff, 0x00000000fffffffe, true},
    { 0x8000000000000000, 0x00000000fffffffe, true},
    { 0x8000000000000001, 0x00000000fffffffe, true},
    { 0xfffffffffffffffe, 0x00000000fffffffe, true},
    { 0xffffffffffffffff, 0x00000000fffffffe, true},

    { 0x0000000000000000, 0x00000000ffffffff, false},
    { 0x0000000000000001, 0x00000000ffffffff, false},
    { 0x0000000000000002, 0x00000000ffffffff, false},
    { 0x000000007ffffffe, 0x00000000ffffffff, false},
    { 0x000000007fffffff, 0x00000000ffffffff, false},
    { 0x0000000080000000, 0x00000000ffffffff, false},
    { 0x0000000080000001, 0x00000000ffffffff, false},
    { 0x00000000fffffffe, 0x00000000ffffffff, false},
    { 0x00000000ffffffff, 0x00000000ffffffff, true},
    { 0x0000000100000000, 0x00000000ffffffff, true},
    { 0x0000000200000000, 0x00000000ffffffff, true},
    { 0x7ffffffffffffffe, 0x00000000ffffffff, true},
    { 0x7fffffffffffffff, 0x00000000ffffffff, true},
    { 0x8000000000000000, 0x00000000ffffffff, true},
    { 0x8000000000000001, 0x00000000ffffffff, true},
    { 0xfffffffffffffffe, 0x00000000ffffffff, true},
    { 0xffffffffffffffff, 0x00000000ffffffff, true},

    { 0x0000000000000000, 0x0000000100000000, false},
    { 0x0000000000000001, 0x0000000100000000, false},
    { 0x0000000000000002, 0x0000000100000000, false},
    { 0x000000007ffffffe, 0x0000000100000000, false},
    { 0x000000007fffffff, 0x0000000100000000, false},
    { 0x0000000080000000, 0x0000000100000000, false},
    { 0x0000000080000001, 0x0000000100000000, false},
    { 0x00000000fffffffe, 0x0000000100000000, false},
    { 0x00000000ffffffff, 0x0000000100000000, false},
    { 0x0000000100000000, 0x0000000100000000, true},
    { 0x0000000200000000, 0x0000000100000000, true},
    { 0x7ffffffffffffffe, 0x0000000100000000, true},
    { 0x7fffffffffffffff, 0x0000000100000000, true},
    { 0x8000000000000000, 0x0000000100000000, true},
    { 0x8000000000000001, 0x0000000100000000, true},
    { 0xfffffffffffffffe, 0x0000000100000000, true},
    { 0xffffffffffffffff, 0x0000000100000000, true},

    { 0x0000000000000000, 0x0000000200000000, false},
    { 0x0000000000000001, 0x0000000200000000, false},
    { 0x0000000000000002, 0x0000000200000000, false},
    { 0x000000007ffffffe, 0x0000000200000000, false},
    { 0x000000007fffffff, 0x0000000200000000, false},
    { 0x0000000080000000, 0x0000000200000000, false},
    { 0x0000000080000001, 0x0000000200000000, false},
    { 0x00000000fffffffe, 0x0000000200000000, false},
    { 0x00000000ffffffff, 0x0000000200000000, false},
    { 0x0000000100000000, 0x0000000200000000, false},
    { 0x0000000200000000, 0x0000000200000000, true},
    { 0x7ffffffffffffffe, 0x0000000200000000, true},
    { 0x7fffffffffffffff, 0x0000000200000000, true},
    { 0x8000000000000000, 0x0000000200000000, true},
    { 0x8000000000000001, 0x0000000200000000, true},
    { 0xfffffffffffffffe, 0x0000000200000000, true},
    { 0xffffffffffffffff, 0x0000000200000000, true},

    { 0x0000000000000000, 0x7ffffffffffffffe, false},
    { 0x0000000000000001, 0x7ffffffffffffffe, false},
    { 0x0000000000000002, 0x7ffffffffffffffe, false},
    { 0x000000007ffffffe, 0x7ffffffffffffffe, false},
    { 0x000000007fffffff, 0x7ffffffffffffffe, false},
    { 0x0000000080000000, 0x7ffffffffffffffe, false},
    { 0x0000000080000001, 0x7ffffffffffffffe, false},
    { 0x00000000fffffffe, 0x7ffffffffffffffe, false},
    { 0x00000000ffffffff, 0x7ffffffffffffffe, false},
    { 0x0000000100000000, 0x7ffffffffffffffe, false},
    { 0x0000000200000000, 0x7ffffffffffffffe, false},
    { 0x7ffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
    { 0x8000000000000000, 0x7ffffffffffffffe, true},
    { 0x8000000000000001, 0x7ffffffffffffffe, true},
    { 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffffffffffe, true},

    { 0x0000000000000000, 0x7fffffffffffffff, false},
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
    { 0x7fffffffffffffff, 0x7fffffffffffffff, true},
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
    { 0x8000000000000000, 0x8000000000000001, false},
    { 0x8000000000000001, 0x8000000000000001, true},
    { 0xfffffffffffffffe, 0x8000000000000001, true},
    { 0xffffffffffffffff, 0x8000000000000001, true},

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
    { 0x8000000000000000, 0xfffffffffffffffe, false},
    { 0x8000000000000001, 0xfffffffffffffffe, false},
    { 0xfffffffffffffffe, 0xfffffffffffffffe, true},
    { 0xffffffffffffffff, 0xfffffffffffffffe, true},

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
    { 0x8000000000000000, 0xffffffffffffffff, false},
    { 0x8000000000000001, 0xffffffffffffffff, false},
    { 0xfffffffffffffffe, 0xffffffffffffffff, false},
    { 0xffffffffffffffff, 0xffffffffffffffff, true},
};

void SubVerifyUint64Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint64); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
        {
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
            si -= uint64_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint64[i].fExpected )
        {
            cerr << "Error in case uint64_uint64 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].y << ", ";
            cerr << "expected = " << uint64_uint64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_uint64[i].x);
            x -= SafeInt<unsigned __int64>(uint64_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint64[i].fExpected )
        {
            cerr << "Error in case uint64_uint64 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint64[i].y << ", ";
            cerr << "expected = " << uint64_uint64[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, unsigned __int32 > uint64_uint32[] =
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

    { 0x0000000000000000, 0x00000001, false},
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
    { 0xffffffffffffffff, 0x00000001, true},

    { 0x0000000000000000, 0x00000002, false},
    { 0x0000000000000001, 0x00000002, false},
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
    { 0xfffffffffffffffe, 0x00000002, true},
    { 0xffffffffffffffff, 0x00000002, true},

    { 0x0000000000000000, 0x7ffffffe, false},
    { 0x0000000000000001, 0x7ffffffe, false},
    { 0x0000000000000002, 0x7ffffffe, false},
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
    { 0xfffffffffffffffe, 0x7ffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffe, true},

    { 0x0000000000000000, 0x7fffffff, false},
    { 0x0000000000000001, 0x7fffffff, false},
    { 0x0000000000000002, 0x7fffffff, false},
    { 0x000000007ffffffe, 0x7fffffff, false},
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
    { 0xfffffffffffffffe, 0x7fffffff, true},
    { 0xffffffffffffffff, 0x7fffffff, true},

    { 0x0000000000000000, 0x80000000, false},
    { 0x0000000000000001, 0x80000000, false},
    { 0x0000000000000002, 0x80000000, false},
    { 0x000000007ffffffe, 0x80000000, false},
    { 0x000000007fffffff, 0x80000000, false},
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
    { 0xfffffffffffffffe, 0x80000000, true},
    { 0xffffffffffffffff, 0x80000000, true},

    { 0x0000000000000000, 0x80000001, false},
    { 0x0000000000000001, 0x80000001, false},
    { 0x0000000000000002, 0x80000001, false},
    { 0x000000007ffffffe, 0x80000001, false},
    { 0x000000007fffffff, 0x80000001, false},
    { 0x0000000080000000, 0x80000001, false},
    { 0x0000000080000001, 0x80000001, true},
    { 0x00000000fffffffe, 0x80000001, true},
    { 0x00000000ffffffff, 0x80000001, true},
    { 0x0000000100000000, 0x80000001, true},
    { 0x0000000200000000, 0x80000001, true},
    { 0x7ffffffffffffffe, 0x80000001, true},
    { 0x7fffffffffffffff, 0x80000001, true},
    { 0x8000000000000000, 0x80000001, true},
    { 0x8000000000000001, 0x80000001, true},
    { 0xfffffffffffffffe, 0x80000001, true},
    { 0xffffffffffffffff, 0x80000001, true},

    { 0x0000000000000000, 0xfffffffe, false},
    { 0x0000000000000001, 0xfffffffe, false},
    { 0x0000000000000002, 0xfffffffe, false},
    { 0x000000007ffffffe, 0xfffffffe, false},
    { 0x000000007fffffff, 0xfffffffe, false},
    { 0x0000000080000000, 0xfffffffe, false},
    { 0x0000000080000001, 0xfffffffe, false},
    { 0x00000000fffffffe, 0xfffffffe, true},
    { 0x00000000ffffffff, 0xfffffffe, true},
    { 0x0000000100000000, 0xfffffffe, true},
    { 0x0000000200000000, 0xfffffffe, true},
    { 0x7ffffffffffffffe, 0xfffffffe, true},
    { 0x7fffffffffffffff, 0xfffffffe, true},
    { 0x8000000000000000, 0xfffffffe, true},
    { 0x8000000000000001, 0xfffffffe, true},
    { 0xfffffffffffffffe, 0xfffffffe, true},
    { 0xffffffffffffffff, 0xfffffffe, true},

    { 0x0000000000000000, 0xffffffff, false},
    { 0x0000000000000001, 0xffffffff, false},
    { 0x0000000000000002, 0xffffffff, false},
    { 0x000000007ffffffe, 0xffffffff, false},
    { 0x000000007fffffff, 0xffffffff, false},
    { 0x0000000080000000, 0xffffffff, false},
    { 0x0000000080000001, 0xffffffff, false},
    { 0x00000000fffffffe, 0xffffffff, false},
    { 0x00000000ffffffff, 0xffffffff, true},
    { 0x0000000100000000, 0xffffffff, true},
    { 0x0000000200000000, 0xffffffff, true},
    { 0x7ffffffffffffffe, 0xffffffff, true},
    { 0x7fffffffffffffff, 0xffffffff, true},
    { 0x8000000000000000, 0xffffffff, true},
    { 0x8000000000000001, 0xffffffff, true},
    { 0xfffffffffffffffe, 0xffffffff, true},
    { 0xffffffffffffffff, 0xffffffff, true},
};

void SubVerifyUint64Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint32); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
        {
            cerr << "Error in case uint64_uint32: ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_uint32[i].y << ", ";
            cerr << "expected = " << uint64_uint32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_uint32[i].x);
            si -= uint64_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint32[i].fExpected )
        {
            cerr << "Error in case uint64_uint32 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_uint32[i].y << ", ";
            cerr << "expected = " << uint64_uint32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_uint32[i].x);
            x -= SafeInt<unsigned __int64>(uint64_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint32[i].fExpected )
        {
            cerr << "Error in case uint64_uint32 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_uint32[i].y << ", ";
            cerr << "expected = " << uint64_uint32[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, unsigned __int16 > uint64_uint16[] =
{
    { 0x0000000000000000, 0x0000, true},
    { 0x0000000000000001, 0x0000, true},
    { 0x0000000000000002, 0x0000, true},
    { 0x000000007ffffffe, 0x0000, true},
    { 0x000000007fffffff, 0x0000, true},
    { 0x0000000080000000, 0x0000, true},
    { 0x0000000080000001, 0x0000, true},
    { 0x00000000fffffffe, 0x0000, true},
    { 0x00000000ffffffff, 0x0000, true},
    { 0x0000000100000000, 0x0000, true},
    { 0x0000000200000000, 0x0000, true},
    { 0x7ffffffffffffffe, 0x0000, true},
    { 0x7fffffffffffffff, 0x0000, true},
    { 0x8000000000000000, 0x0000, true},
    { 0x8000000000000001, 0x0000, true},
    { 0xfffffffffffffffe, 0x0000, true},
    { 0xffffffffffffffff, 0x0000, true},

    { 0x0000000000000000, 0x0001, false},
    { 0x0000000000000001, 0x0001, true},
    { 0x0000000000000002, 0x0001, true},
    { 0x000000007ffffffe, 0x0001, true},
    { 0x000000007fffffff, 0x0001, true},
    { 0x0000000080000000, 0x0001, true},
    { 0x0000000080000001, 0x0001, true},
    { 0x00000000fffffffe, 0x0001, true},
    { 0x00000000ffffffff, 0x0001, true},
    { 0x0000000100000000, 0x0001, true},
    { 0x0000000200000000, 0x0001, true},
    { 0x7ffffffffffffffe, 0x0001, true},
    { 0x7fffffffffffffff, 0x0001, true},
    { 0x8000000000000000, 0x0001, true},
    { 0x8000000000000001, 0x0001, true},
    { 0xfffffffffffffffe, 0x0001, true},
    { 0xffffffffffffffff, 0x0001, true},

    { 0x0000000000000000, 0x0002, false},
    { 0x0000000000000001, 0x0002, false},
    { 0x0000000000000002, 0x0002, true},
    { 0x000000007ffffffe, 0x0002, true},
    { 0x000000007fffffff, 0x0002, true},
    { 0x0000000080000000, 0x0002, true},
    { 0x0000000080000001, 0x0002, true},
    { 0x00000000fffffffe, 0x0002, true},
    { 0x00000000ffffffff, 0x0002, true},
    { 0x0000000100000000, 0x0002, true},
    { 0x0000000200000000, 0x0002, true},
    { 0x7ffffffffffffffe, 0x0002, true},
    { 0x7fffffffffffffff, 0x0002, true},
    { 0x8000000000000000, 0x0002, true},
    { 0x8000000000000001, 0x0002, true},
    { 0xfffffffffffffffe, 0x0002, true},
    { 0xffffffffffffffff, 0x0002, true},

    { 0x0000000000000000, 0x7ffe, false},
    { 0x0000000000000001, 0x7ffe, false},
    { 0x0000000000000002, 0x7ffe, false},
    { 0x000000007ffffffe, 0x7ffe, true},
    { 0x000000007fffffff, 0x7ffe, true},
    { 0x0000000080000000, 0x7ffe, true},
    { 0x0000000080000001, 0x7ffe, true},
    { 0x00000000fffffffe, 0x7ffe, true},
    { 0x00000000ffffffff, 0x7ffe, true},
    { 0x0000000100000000, 0x7ffe, true},
    { 0x0000000200000000, 0x7ffe, true},
    { 0x7ffffffffffffffe, 0x7ffe, true},
    { 0x7fffffffffffffff, 0x7ffe, true},
    { 0x8000000000000000, 0x7ffe, true},
    { 0x8000000000000001, 0x7ffe, true},
    { 0xfffffffffffffffe, 0x7ffe, true},
    { 0xffffffffffffffff, 0x7ffe, true},

    { 0x0000000000000000, 0x7fff, false},
    { 0x0000000000000001, 0x7fff, false},
    { 0x0000000000000002, 0x7fff, false},
    { 0x000000007ffffffe, 0x7fff, true},
    { 0x000000007fffffff, 0x7fff, true},
    { 0x0000000080000000, 0x7fff, true},
    { 0x0000000080000001, 0x7fff, true},
    { 0x00000000fffffffe, 0x7fff, true},
    { 0x00000000ffffffff, 0x7fff, true},
    { 0x0000000100000000, 0x7fff, true},
    { 0x0000000200000000, 0x7fff, true},
    { 0x7ffffffffffffffe, 0x7fff, true},
    { 0x7fffffffffffffff, 0x7fff, true},
    { 0x8000000000000000, 0x7fff, true},
    { 0x8000000000000001, 0x7fff, true},
    { 0xfffffffffffffffe, 0x7fff, true},
    { 0xffffffffffffffff, 0x7fff, true},

    { 0x0000000000000000, 0x8000, false},
    { 0x0000000000000001, 0x8000, false},
    { 0x0000000000000002, 0x8000, false},
    { 0x000000007ffffffe, 0x8000, true},
    { 0x000000007fffffff, 0x8000, true},
    { 0x0000000080000000, 0x8000, true},
    { 0x0000000080000001, 0x8000, true},
    { 0x00000000fffffffe, 0x8000, true},
    { 0x00000000ffffffff, 0x8000, true},
    { 0x0000000100000000, 0x8000, true},
    { 0x0000000200000000, 0x8000, true},
    { 0x7ffffffffffffffe, 0x8000, true},
    { 0x7fffffffffffffff, 0x8000, true},
    { 0x8000000000000000, 0x8000, true},
    { 0x8000000000000001, 0x8000, true},
    { 0xfffffffffffffffe, 0x8000, true},
    { 0xffffffffffffffff, 0x8000, true},

    { 0x0000000000000000, 0x8001, false},
    { 0x0000000000000001, 0x8001, false},
    { 0x0000000000000002, 0x8001, false},
    { 0x000000007ffffffe, 0x8001, true},
    { 0x000000007fffffff, 0x8001, true},
    { 0x0000000080000000, 0x8001, true},
    { 0x0000000080000001, 0x8001, true},
    { 0x00000000fffffffe, 0x8001, true},
    { 0x00000000ffffffff, 0x8001, true},
    { 0x0000000100000000, 0x8001, true},
    { 0x0000000200000000, 0x8001, true},
    { 0x7ffffffffffffffe, 0x8001, true},
    { 0x7fffffffffffffff, 0x8001, true},
    { 0x8000000000000000, 0x8001, true},
    { 0x8000000000000001, 0x8001, true},
    { 0xfffffffffffffffe, 0x8001, true},
    { 0xffffffffffffffff, 0x8001, true},

    { 0x0000000000000000, 0xfffe, false},
    { 0x0000000000000001, 0xfffe, false},
    { 0x0000000000000002, 0xfffe, false},
    { 0x000000007ffffffe, 0xfffe, true},
    { 0x000000007fffffff, 0xfffe, true},
    { 0x0000000080000000, 0xfffe, true},
    { 0x0000000080000001, 0xfffe, true},
    { 0x00000000fffffffe, 0xfffe, true},
    { 0x00000000ffffffff, 0xfffe, true},
    { 0x0000000100000000, 0xfffe, true},
    { 0x0000000200000000, 0xfffe, true},
    { 0x7ffffffffffffffe, 0xfffe, true},
    { 0x7fffffffffffffff, 0xfffe, true},
    { 0x8000000000000000, 0xfffe, true},
    { 0x8000000000000001, 0xfffe, true},
    { 0xfffffffffffffffe, 0xfffe, true},
    { 0xffffffffffffffff, 0xfffe, true},

    { 0x0000000000000000, 0xffff, false},
    { 0x0000000000000001, 0xffff, false},
    { 0x0000000000000002, 0xffff, false},
    { 0x000000007ffffffe, 0xffff, true},
    { 0x000000007fffffff, 0xffff, true},
    { 0x0000000080000000, 0xffff, true},
    { 0x0000000080000001, 0xffff, true},
    { 0x00000000fffffffe, 0xffff, true},
    { 0x00000000ffffffff, 0xffff, true},
    { 0x0000000100000000, 0xffff, true},
    { 0x0000000200000000, 0xffff, true},
    { 0x7ffffffffffffffe, 0xffff, true},
    { 0x7fffffffffffffff, 0xffff, true},
    { 0x8000000000000000, 0xffff, true},
    { 0x8000000000000001, 0xffff, true},
    { 0xfffffffffffffffe, 0xffff, true},
    { 0xffffffffffffffff, 0xffff, true},
};

void SubVerifyUint64Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint16); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_uint16[i].x, uint64_uint16[i].y, ret) != uint64_uint16[i].fExpected )
        {
            cerr << "Error in case uint64_uint16: ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_uint16[i].y << ", ";
            cerr << "expected = " << uint64_uint16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_uint16[i].x);
            si -= uint64_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint16[i].fExpected )
        {
            cerr << "Error in case uint64_uint16 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_uint16[i].y << ", ";
            cerr << "expected = " << uint64_uint16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_uint16[i].x);
            x -= SafeInt<unsigned __int64>(uint64_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint16[i].fExpected )
        {
            cerr << "Error in case uint64_uint16 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_uint16[i].y << ", ";
            cerr << "expected = " << uint64_uint16[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, unsigned __int8 > uint64_uint8[] =
{
    { 0x0000000000000000, 0x00, true},
    { 0x0000000000000001, 0x00, true},
    { 0x0000000000000002, 0x00, true},
    { 0x000000007ffffffe, 0x00, true},
    { 0x000000007fffffff, 0x00, true},
    { 0x0000000080000000, 0x00, true},
    { 0x0000000080000001, 0x00, true},
    { 0x00000000fffffffe, 0x00, true},
    { 0x00000000ffffffff, 0x00, true},
    { 0x0000000100000000, 0x00, true},
    { 0x0000000200000000, 0x00, true},
    { 0x7ffffffffffffffe, 0x00, true},
    { 0x7fffffffffffffff, 0x00, true},
    { 0x8000000000000000, 0x00, true},
    { 0x8000000000000001, 0x00, true},
    { 0xfffffffffffffffe, 0x00, true},
    { 0xffffffffffffffff, 0x00, true},

    { 0x0000000000000000, 0x01, false},
    { 0x0000000000000001, 0x01, true},
    { 0x0000000000000002, 0x01, true},
    { 0x000000007ffffffe, 0x01, true},
    { 0x000000007fffffff, 0x01, true},
    { 0x0000000080000000, 0x01, true},
    { 0x0000000080000001, 0x01, true},
    { 0x00000000fffffffe, 0x01, true},
    { 0x00000000ffffffff, 0x01, true},
    { 0x0000000100000000, 0x01, true},
    { 0x0000000200000000, 0x01, true},
    { 0x7ffffffffffffffe, 0x01, true},
    { 0x7fffffffffffffff, 0x01, true},
    { 0x8000000000000000, 0x01, true},
    { 0x8000000000000001, 0x01, true},
    { 0xfffffffffffffffe, 0x01, true},
    { 0xffffffffffffffff, 0x01, true},

    { 0x0000000000000000, 0x02, false},
    { 0x0000000000000001, 0x02, false},
    { 0x0000000000000002, 0x02, true},
    { 0x000000007ffffffe, 0x02, true},
    { 0x000000007fffffff, 0x02, true},
    { 0x0000000080000000, 0x02, true},
    { 0x0000000080000001, 0x02, true},
    { 0x00000000fffffffe, 0x02, true},
    { 0x00000000ffffffff, 0x02, true},
    { 0x0000000100000000, 0x02, true},
    { 0x0000000200000000, 0x02, true},
    { 0x7ffffffffffffffe, 0x02, true},
    { 0x7fffffffffffffff, 0x02, true},
    { 0x8000000000000000, 0x02, true},
    { 0x8000000000000001, 0x02, true},
    { 0xfffffffffffffffe, 0x02, true},
    { 0xffffffffffffffff, 0x02, true},

    { 0x0000000000000000, 0x7e, false},
    { 0x0000000000000001, 0x7e, false},
    { 0x0000000000000002, 0x7e, false},
    { 0x000000007ffffffe, 0x7e, true},
    { 0x000000007fffffff, 0x7e, true},
    { 0x0000000080000000, 0x7e, true},
    { 0x0000000080000001, 0x7e, true},
    { 0x00000000fffffffe, 0x7e, true},
    { 0x00000000ffffffff, 0x7e, true},
    { 0x0000000100000000, 0x7e, true},
    { 0x0000000200000000, 0x7e, true},
    { 0x7ffffffffffffffe, 0x7e, true},
    { 0x7fffffffffffffff, 0x7e, true},
    { 0x8000000000000000, 0x7e, true},
    { 0x8000000000000001, 0x7e, true},
    { 0xfffffffffffffffe, 0x7e, true},
    { 0xffffffffffffffff, 0x7e, true},

    { 0x0000000000000000, 0x7f, false},
    { 0x0000000000000001, 0x7f, false},
    { 0x0000000000000002, 0x7f, false},
    { 0x000000007ffffffe, 0x7f, true},
    { 0x000000007fffffff, 0x7f, true},
    { 0x0000000080000000, 0x7f, true},
    { 0x0000000080000001, 0x7f, true},
    { 0x00000000fffffffe, 0x7f, true},
    { 0x00000000ffffffff, 0x7f, true},
    { 0x0000000100000000, 0x7f, true},
    { 0x0000000200000000, 0x7f, true},
    { 0x7ffffffffffffffe, 0x7f, true},
    { 0x7fffffffffffffff, 0x7f, true},
    { 0x8000000000000000, 0x7f, true},
    { 0x8000000000000001, 0x7f, true},
    { 0xfffffffffffffffe, 0x7f, true},
    { 0xffffffffffffffff, 0x7f, true},

    { 0x0000000000000000, 0x80, false},
    { 0x0000000000000001, 0x80, false},
    { 0x0000000000000002, 0x80, false},
    { 0x000000007ffffffe, 0x80, true},
    { 0x000000007fffffff, 0x80, true},
    { 0x0000000080000000, 0x80, true},
    { 0x0000000080000001, 0x80, true},
    { 0x00000000fffffffe, 0x80, true},
    { 0x00000000ffffffff, 0x80, true},
    { 0x0000000100000000, 0x80, true},
    { 0x0000000200000000, 0x80, true},
    { 0x7ffffffffffffffe, 0x80, true},
    { 0x7fffffffffffffff, 0x80, true},
    { 0x8000000000000000, 0x80, true},
    { 0x8000000000000001, 0x80, true},
    { 0xfffffffffffffffe, 0x80, true},
    { 0xffffffffffffffff, 0x80, true},

    { 0x0000000000000000, 0x81, false},
    { 0x0000000000000001, 0x81, false},
    { 0x0000000000000002, 0x81, false},
    { 0x000000007ffffffe, 0x81, true},
    { 0x000000007fffffff, 0x81, true},
    { 0x0000000080000000, 0x81, true},
    { 0x0000000080000001, 0x81, true},
    { 0x00000000fffffffe, 0x81, true},
    { 0x00000000ffffffff, 0x81, true},
    { 0x0000000100000000, 0x81, true},
    { 0x0000000200000000, 0x81, true},
    { 0x7ffffffffffffffe, 0x81, true},
    { 0x7fffffffffffffff, 0x81, true},
    { 0x8000000000000000, 0x81, true},
    { 0x8000000000000001, 0x81, true},
    { 0xfffffffffffffffe, 0x81, true},
    { 0xffffffffffffffff, 0x81, true},

    { 0x0000000000000000, 0xfe, false},
    { 0x0000000000000001, 0xfe, false},
    { 0x0000000000000002, 0xfe, false},
    { 0x000000007ffffffe, 0xfe, true},
    { 0x000000007fffffff, 0xfe, true},
    { 0x0000000080000000, 0xfe, true},
    { 0x0000000080000001, 0xfe, true},
    { 0x00000000fffffffe, 0xfe, true},
    { 0x00000000ffffffff, 0xfe, true},
    { 0x0000000100000000, 0xfe, true},
    { 0x0000000200000000, 0xfe, true},
    { 0x7ffffffffffffffe, 0xfe, true},
    { 0x7fffffffffffffff, 0xfe, true},
    { 0x8000000000000000, 0xfe, true},
    { 0x8000000000000001, 0xfe, true},
    { 0xfffffffffffffffe, 0xfe, true},
    { 0xffffffffffffffff, 0xfe, true},

    { 0x0000000000000000, 0xff, false},
    { 0x0000000000000001, 0xff, false},
    { 0x0000000000000002, 0xff, false},
    { 0x000000007ffffffe, 0xff, true},
    { 0x000000007fffffff, 0xff, true},
    { 0x0000000080000000, 0xff, true},
    { 0x0000000080000001, 0xff, true},
    { 0x00000000fffffffe, 0xff, true},
    { 0x00000000ffffffff, 0xff, true},
    { 0x0000000100000000, 0xff, true},
    { 0x0000000200000000, 0xff, true},
    { 0x7ffffffffffffffe, 0xff, true},
    { 0x7fffffffffffffff, 0xff, true},
    { 0x8000000000000000, 0xff, true},
    { 0x8000000000000001, 0xff, true},
    { 0xfffffffffffffffe, 0xff, true},
    { 0xffffffffffffffff, 0xff, true},
};

void SubVerifyUint64Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint8); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_uint8[i].x, uint64_uint8[i].y, ret) != uint64_uint8[i].fExpected )
        {
            cerr << "Error in case uint64_uint8: ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_uint8[i].y) << ", ";
            cerr << "expected = " << uint64_uint8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_uint8[i].x);
            si -= uint64_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint8[i].fExpected )
        {
            cerr << "Error in case uint64_uint8 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_uint8[i].y) << ", ";
            cerr << "expected = " << uint64_uint8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_uint8[i].x);
            x -= SafeInt<unsigned __int64>(uint64_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint8[i].fExpected )
        {
            cerr << "Error in case uint64_uint8 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_uint8[i].y) << ", ";
            cerr << "expected = " << uint64_uint8[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, unsigned __int64 > uint8_uint64[] =
{
    { 0x00, 0x0000000000000000, true},
    { 0x01, 0x0000000000000000, true},
    { 0x02, 0x0000000000000000, true},
    { 0x7e, 0x0000000000000000, true},
    { 0x7f, 0x0000000000000000, true},
    { 0x80, 0x0000000000000000, true},
    { 0x81, 0x0000000000000000, true},
    { 0xfe, 0x0000000000000000, true},
    { 0xff, 0x0000000000000000, true},

    { 0x00, 0x0000000000000001, false},
    { 0x01, 0x0000000000000001, true},
    { 0x02, 0x0000000000000001, true},
    { 0x7e, 0x0000000000000001, true},
    { 0x7f, 0x0000000000000001, true},
    { 0x80, 0x0000000000000001, true},
    { 0x81, 0x0000000000000001, true},
    { 0xfe, 0x0000000000000001, true},
    { 0xff, 0x0000000000000001, true},

    { 0x00, 0x0000000000000002, false},
    { 0x01, 0x0000000000000002, false},
    { 0x02, 0x0000000000000002, true},
    { 0x7e, 0x0000000000000002, true},
    { 0x7f, 0x0000000000000002, true},
    { 0x80, 0x0000000000000002, true},
    { 0x81, 0x0000000000000002, true},
    { 0xfe, 0x0000000000000002, true},
    { 0xff, 0x0000000000000002, true},

    { 0x00, 0x000000007ffffffe, false},
    { 0x01, 0x000000007ffffffe, false},
    { 0x02, 0x000000007ffffffe, false},
    { 0x7e, 0x000000007ffffffe, false},
    { 0x7f, 0x000000007ffffffe, false},
    { 0x80, 0x000000007ffffffe, false},
    { 0x81, 0x000000007ffffffe, false},
    { 0xfe, 0x000000007ffffffe, false},
    { 0xff, 0x000000007ffffffe, false},

    { 0x00, 0x000000007fffffff, false},
    { 0x01, 0x000000007fffffff, false},
    { 0x02, 0x000000007fffffff, false},
    { 0x7e, 0x000000007fffffff, false},
    { 0x7f, 0x000000007fffffff, false},
    { 0x80, 0x000000007fffffff, false},
    { 0x81, 0x000000007fffffff, false},
    { 0xfe, 0x000000007fffffff, false},
    { 0xff, 0x000000007fffffff, false},

    { 0x00, 0x0000000080000000, false},
    { 0x01, 0x0000000080000000, false},
    { 0x02, 0x0000000080000000, false},
    { 0x7e, 0x0000000080000000, false},
    { 0x7f, 0x0000000080000000, false},
    { 0x80, 0x0000000080000000, false},
    { 0x81, 0x0000000080000000, false},
    { 0xfe, 0x0000000080000000, false},
    { 0xff, 0x0000000080000000, false},

    { 0x00, 0x0000000080000001, false},
    { 0x01, 0x0000000080000001, false},
    { 0x02, 0x0000000080000001, false},
    { 0x7e, 0x0000000080000001, false},
    { 0x7f, 0x0000000080000001, false},
    { 0x80, 0x0000000080000001, false},
    { 0x81, 0x0000000080000001, false},
    { 0xfe, 0x0000000080000001, false},
    { 0xff, 0x0000000080000001, false},

    { 0x00, 0x00000000fffffffe, false},
    { 0x01, 0x00000000fffffffe, false},
    { 0x02, 0x00000000fffffffe, false},
    { 0x7e, 0x00000000fffffffe, false},
    { 0x7f, 0x00000000fffffffe, false},
    { 0x80, 0x00000000fffffffe, false},
    { 0x81, 0x00000000fffffffe, false},
    { 0xfe, 0x00000000fffffffe, false},
    { 0xff, 0x00000000fffffffe, false},

    { 0x00, 0x00000000ffffffff, false},
    { 0x01, 0x00000000ffffffff, false},
    { 0x02, 0x00000000ffffffff, false},
    { 0x7e, 0x00000000ffffffff, false},
    { 0x7f, 0x00000000ffffffff, false},
    { 0x80, 0x00000000ffffffff, false},
    { 0x81, 0x00000000ffffffff, false},
    { 0xfe, 0x00000000ffffffff, false},
    { 0xff, 0x00000000ffffffff, false},

    { 0x00, 0x0000000100000000, false},
    { 0x01, 0x0000000100000000, false},
    { 0x02, 0x0000000100000000, false},
    { 0x7e, 0x0000000100000000, false},
    { 0x7f, 0x0000000100000000, false},
    { 0x80, 0x0000000100000000, false},
    { 0x81, 0x0000000100000000, false},
    { 0xfe, 0x0000000100000000, false},
    { 0xff, 0x0000000100000000, false},

    { 0x00, 0x0000000200000000, false},
    { 0x01, 0x0000000200000000, false},
    { 0x02, 0x0000000200000000, false},
    { 0x7e, 0x0000000200000000, false},
    { 0x7f, 0x0000000200000000, false},
    { 0x80, 0x0000000200000000, false},
    { 0x81, 0x0000000200000000, false},
    { 0xfe, 0x0000000200000000, false},
    { 0xff, 0x0000000200000000, false},

    { 0x00, 0x7ffffffffffffffe, false},
    { 0x01, 0x7ffffffffffffffe, false},
    { 0x02, 0x7ffffffffffffffe, false},
    { 0x7e, 0x7ffffffffffffffe, false},
    { 0x7f, 0x7ffffffffffffffe, false},
    { 0x80, 0x7ffffffffffffffe, false},
    { 0x81, 0x7ffffffffffffffe, false},
    { 0xfe, 0x7ffffffffffffffe, false},
    { 0xff, 0x7ffffffffffffffe, false},

    { 0x00, 0x7fffffffffffffff, false},
    { 0x01, 0x7fffffffffffffff, false},
    { 0x02, 0x7fffffffffffffff, false},
    { 0x7e, 0x7fffffffffffffff, false},
    { 0x7f, 0x7fffffffffffffff, false},
    { 0x80, 0x7fffffffffffffff, false},
    { 0x81, 0x7fffffffffffffff, false},
    { 0xfe, 0x7fffffffffffffff, false},
    { 0xff, 0x7fffffffffffffff, false},

    { 0x00, 0x8000000000000000, false},
    { 0x01, 0x8000000000000000, false},
    { 0x02, 0x8000000000000000, false},
    { 0x7e, 0x8000000000000000, false},
    { 0x7f, 0x8000000000000000, false},
    { 0x80, 0x8000000000000000, false},
    { 0x81, 0x8000000000000000, false},
    { 0xfe, 0x8000000000000000, false},
    { 0xff, 0x8000000000000000, false},

    { 0x00, 0x8000000000000001, false},
    { 0x01, 0x8000000000000001, false},
    { 0x02, 0x8000000000000001, false},
    { 0x7e, 0x8000000000000001, false},
    { 0x7f, 0x8000000000000001, false},
    { 0x80, 0x8000000000000001, false},
    { 0x81, 0x8000000000000001, false},
    { 0xfe, 0x8000000000000001, false},
    { 0xff, 0x8000000000000001, false},

    { 0x00, 0xfffffffffffffffe, false},
    { 0x01, 0xfffffffffffffffe, false},
    { 0x02, 0xfffffffffffffffe, false},
    { 0x7e, 0xfffffffffffffffe, false},
    { 0x7f, 0xfffffffffffffffe, false},
    { 0x80, 0xfffffffffffffffe, false},
    { 0x81, 0xfffffffffffffffe, false},
    { 0xfe, 0xfffffffffffffffe, false},
    { 0xff, 0xfffffffffffffffe, false},

    { 0x00, 0xffffffffffffffff, false},
    { 0x01, 0xffffffffffffffff, false},
    { 0x02, 0xffffffffffffffff, false},
    { 0x7e, 0xffffffffffffffff, false},
    { 0x7f, 0xffffffffffffffff, false},
    { 0x80, 0xffffffffffffffff, false},
    { 0x81, 0xffffffffffffffff, false},
    { 0xfe, 0xffffffffffffffff, false},
    { 0xff, 0xffffffffffffffff, false},
};

void SubVerifyUint8Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint64); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_uint64[i].x, uint8_uint64[i].y, ret) != uint8_uint64[i].fExpected )
        {
            cerr << "Error in case uint8_uint64: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_uint64[i].y << ", ";
            cerr << "expected = " << uint8_uint64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_uint64[i].x);
            si -= uint8_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint64[i].fExpected )
        {
            cerr << "Error in case uint8_uint64 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_uint64[i].y << ", ";
            cerr << "expected = " << uint8_uint64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_uint64[i].x);
            x -= SafeInt<unsigned __int64>(uint8_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint64[i].fExpected )
        {
            cerr << "Error in case uint8_uint64 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_uint64[i].y << ", ";
            cerr << "expected = " << uint8_uint64[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, unsigned __int32 > uint8_uint32[] =
{
    { 0x00, 0x00000000, true},
    { 0x01, 0x00000000, true},
    { 0x02, 0x00000000, true},
    { 0x7e, 0x00000000, true},
    { 0x7f, 0x00000000, true},
    { 0x80, 0x00000000, true},
    { 0x81, 0x00000000, true},
    { 0xfe, 0x00000000, true},
    { 0xff, 0x00000000, true},

    { 0x00, 0x00000001, false},
    { 0x01, 0x00000001, true},
    { 0x02, 0x00000001, true},
    { 0x7e, 0x00000001, true},
    { 0x7f, 0x00000001, true},
    { 0x80, 0x00000001, true},
    { 0x81, 0x00000001, true},
    { 0xfe, 0x00000001, true},
    { 0xff, 0x00000001, true},

    { 0x00, 0x00000002, false},
    { 0x01, 0x00000002, false},
    { 0x02, 0x00000002, true},
    { 0x7e, 0x00000002, true},
    { 0x7f, 0x00000002, true},
    { 0x80, 0x00000002, true},
    { 0x81, 0x00000002, true},
    { 0xfe, 0x00000002, true},
    { 0xff, 0x00000002, true},

    { 0x00, 0x7ffffffe, false},
    { 0x01, 0x7ffffffe, false},
    { 0x02, 0x7ffffffe, false},
    { 0x7e, 0x7ffffffe, false},
    { 0x7f, 0x7ffffffe, false},
    { 0x80, 0x7ffffffe, false},
    { 0x81, 0x7ffffffe, false},
    { 0xfe, 0x7ffffffe, false},
    { 0xff, 0x7ffffffe, false},

    { 0x00, 0x7fffffff, false},
    { 0x01, 0x7fffffff, false},
    { 0x02, 0x7fffffff, false},
    { 0x7e, 0x7fffffff, false},
    { 0x7f, 0x7fffffff, false},
    { 0x80, 0x7fffffff, false},
    { 0x81, 0x7fffffff, false},
    { 0xfe, 0x7fffffff, false},
    { 0xff, 0x7fffffff, false},

    { 0x00, 0x80000000, false},
    { 0x01, 0x80000000, false},
    { 0x02, 0x80000000, false},
    { 0x7e, 0x80000000, false},
    { 0x7f, 0x80000000, false},
    { 0x80, 0x80000000, false},
    { 0x81, 0x80000000, false},
    { 0xfe, 0x80000000, false},
    { 0xff, 0x80000000, false},

    { 0x00, 0x80000001, false},
    { 0x01, 0x80000001, false},
    { 0x02, 0x80000001, false},
    { 0x7e, 0x80000001, false},
    { 0x7f, 0x80000001, false},
    { 0x80, 0x80000001, false},
    { 0x81, 0x80000001, false},
    { 0xfe, 0x80000001, false},
    { 0xff, 0x80000001, false},

    { 0x00, 0xfffffffe, false},
    { 0x01, 0xfffffffe, false},
    { 0x02, 0xfffffffe, false},
    { 0x7e, 0xfffffffe, false},
    { 0x7f, 0xfffffffe, false},
    { 0x80, 0xfffffffe, false},
    { 0x81, 0xfffffffe, false},
    { 0xfe, 0xfffffffe, false},
    { 0xff, 0xfffffffe, false},

    { 0x00, 0xffffffff, false},
    { 0x01, 0xffffffff, false},
    { 0x02, 0xffffffff, false},
    { 0x7e, 0xffffffff, false},
    { 0x7f, 0xffffffff, false},
    { 0x80, 0xffffffff, false},
    { 0x81, 0xffffffff, false},
    { 0xfe, 0xffffffff, false},
    { 0xff, 0xffffffff, false},
};

void SubVerifyUint8Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint32); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_uint32[i].x, uint8_uint32[i].y, ret) != uint8_uint32[i].fExpected )
        {
            cerr << "Error in case uint8_uint32: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_uint32[i].y << ", ";
            cerr << "expected = " << uint8_uint32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_uint32[i].x);
            si -= uint8_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint32[i].fExpected )
        {
            cerr << "Error in case uint8_uint32 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_uint32[i].y << ", ";
            cerr << "expected = " << uint8_uint32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_uint32[i].x);
            x -= SafeInt<unsigned __int64>(uint8_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint32[i].fExpected )
        {
            cerr << "Error in case uint8_uint32 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_uint32[i].y << ", ";
            cerr << "expected = " << uint8_uint32[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, unsigned __int16 > uint8_uint16[] =
{
    { 0x00, 0x0000, true},
    { 0x01, 0x0000, true},
    { 0x02, 0x0000, true},
    { 0x7e, 0x0000, true},
    { 0x7f, 0x0000, true},
    { 0x80, 0x0000, true},
    { 0x81, 0x0000, true},
    { 0xfe, 0x0000, true},
    { 0xff, 0x0000, true},

    { 0x00, 0x0001, false},
    { 0x01, 0x0001, true},
    { 0x02, 0x0001, true},
    { 0x7e, 0x0001, true},
    { 0x7f, 0x0001, true},
    { 0x80, 0x0001, true},
    { 0x81, 0x0001, true},
    { 0xfe, 0x0001, true},
    { 0xff, 0x0001, true},

    { 0x00, 0x0002, false},
    { 0x01, 0x0002, false},
    { 0x02, 0x0002, true},
    { 0x7e, 0x0002, true},
    { 0x7f, 0x0002, true},
    { 0x80, 0x0002, true},
    { 0x81, 0x0002, true},
    { 0xfe, 0x0002, true},
    { 0xff, 0x0002, true},

    { 0x00, 0x7ffe, false},
    { 0x01, 0x7ffe, false},
    { 0x02, 0x7ffe, false},
    { 0x7e, 0x7ffe, false},
    { 0x7f, 0x7ffe, false},
    { 0x80, 0x7ffe, false},
    { 0x81, 0x7ffe, false},
    { 0xfe, 0x7ffe, false},
    { 0xff, 0x7ffe, false},

    { 0x00, 0x7fff, false},
    { 0x01, 0x7fff, false},
    { 0x02, 0x7fff, false},
    { 0x7e, 0x7fff, false},
    { 0x7f, 0x7fff, false},
    { 0x80, 0x7fff, false},
    { 0x81, 0x7fff, false},
    { 0xfe, 0x7fff, false},
    { 0xff, 0x7fff, false},

    { 0x00, 0x8000, false},
    { 0x01, 0x8000, false},
    { 0x02, 0x8000, false},
    { 0x7e, 0x8000, false},
    { 0x7f, 0x8000, false},
    { 0x80, 0x8000, false},
    { 0x81, 0x8000, false},
    { 0xfe, 0x8000, false},
    { 0xff, 0x8000, false},

    { 0x00, 0x8001, false},
    { 0x01, 0x8001, false},
    { 0x02, 0x8001, false},
    { 0x7e, 0x8001, false},
    { 0x7f, 0x8001, false},
    { 0x80, 0x8001, false},
    { 0x81, 0x8001, false},
    { 0xfe, 0x8001, false},
    { 0xff, 0x8001, false},

    { 0x00, 0xfffe, false},
    { 0x01, 0xfffe, false},
    { 0x02, 0xfffe, false},
    { 0x7e, 0xfffe, false},
    { 0x7f, 0xfffe, false},
    { 0x80, 0xfffe, false},
    { 0x81, 0xfffe, false},
    { 0xfe, 0xfffe, false},
    { 0xff, 0xfffe, false},

    { 0x00, 0xffff, false},
    { 0x01, 0xffff, false},
    { 0x02, 0xffff, false},
    { 0x7e, 0xffff, false},
    { 0x7f, 0xffff, false},
    { 0x80, 0xffff, false},
    { 0x81, 0xffff, false},
    { 0xfe, 0xffff, false},
    { 0xff, 0xffff, false},
};

void SubVerifyUint8Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint16); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_uint16[i].x, uint8_uint16[i].y, ret) != uint8_uint16[i].fExpected )
        {
            cerr << "Error in case uint8_uint16: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_uint16[i].y << ", ";
            cerr << "expected = " << uint8_uint16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_uint16[i].x);
            si -= uint8_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint16[i].fExpected )
        {
            cerr << "Error in case uint8_uint16 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_uint16[i].y << ", ";
            cerr << "expected = " << uint8_uint16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_uint16[i].x);
            x -= SafeInt<unsigned __int64>(uint8_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint16[i].fExpected )
        {
            cerr << "Error in case uint8_uint16 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_uint16[i].y << ", ";
            cerr << "expected = " << uint8_uint16[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, unsigned __int8 > uint8_uint8[] =
{
    { 0x00, 0x00, true},
    { 0x01, 0x00, true},
    { 0x02, 0x00, true},
    { 0x7e, 0x00, true},
    { 0x7f, 0x00, true},
    { 0x80, 0x00, true},
    { 0x81, 0x00, true},
    { 0xfe, 0x00, true},
    { 0xff, 0x00, true},

    { 0x00, 0x01, false},
    { 0x01, 0x01, true},
    { 0x02, 0x01, true},
    { 0x7e, 0x01, true},
    { 0x7f, 0x01, true},
    { 0x80, 0x01, true},
    { 0x81, 0x01, true},
    { 0xfe, 0x01, true},
    { 0xff, 0x01, true},

    { 0x00, 0x02, false},
    { 0x01, 0x02, false},
    { 0x02, 0x02, true},
    { 0x7e, 0x02, true},
    { 0x7f, 0x02, true},
    { 0x80, 0x02, true},
    { 0x81, 0x02, true},
    { 0xfe, 0x02, true},
    { 0xff, 0x02, true},

    { 0x00, 0x7e, false},
    { 0x01, 0x7e, false},
    { 0x02, 0x7e, false},
    { 0x7e, 0x7e, true},
    { 0x7f, 0x7e, true},
    { 0x80, 0x7e, true},
    { 0x81, 0x7e, true},
    { 0xfe, 0x7e, true},
    { 0xff, 0x7e, true},

    { 0x00, 0x7f, false},
    { 0x01, 0x7f, false},
    { 0x02, 0x7f, false},
    { 0x7e, 0x7f, false},
    { 0x7f, 0x7f, true},
    { 0x80, 0x7f, true},
    { 0x81, 0x7f, true},
    { 0xfe, 0x7f, true},
    { 0xff, 0x7f, true},

    { 0x00, 0x80, false},
    { 0x01, 0x80, false},
    { 0x02, 0x80, false},
    { 0x7e, 0x80, false},
    { 0x7f, 0x80, false},
    { 0x80, 0x80, true},
    { 0x81, 0x80, true},
    { 0xfe, 0x80, true},
    { 0xff, 0x80, true},

    { 0x00, 0x81, false},
    { 0x01, 0x81, false},
    { 0x02, 0x81, false},
    { 0x7e, 0x81, false},
    { 0x7f, 0x81, false},
    { 0x80, 0x81, false},
    { 0x81, 0x81, true},
    { 0xfe, 0x81, true},
    { 0xff, 0x81, true},

    { 0x00, 0xfe, false},
    { 0x01, 0xfe, false},
    { 0x02, 0xfe, false},
    { 0x7e, 0xfe, false},
    { 0x7f, 0xfe, false},
    { 0x80, 0xfe, false},
    { 0x81, 0xfe, false},
    { 0xfe, 0xfe, true},
    { 0xff, 0xfe, true},

    { 0x00, 0xff, false},
    { 0x01, 0xff, false},
    { 0x02, 0xff, false},
    { 0x7e, 0xff, false},
    { 0x7f, 0xff, false},
    { 0x80, 0xff, false},
    { 0x81, 0xff, false},
    { 0xfe, 0xff, false},
    { 0xff, 0xff, true},
};

void SubVerifyUint8Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint8); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_uint8[i].x, uint8_uint8[i].y, ret) != uint8_uint8[i].fExpected )
        {
            cerr << "Error in case uint8_uint8: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].y) << ", ";
            cerr << "expected = " << uint8_uint8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_uint8[i].x);
            si -= uint8_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint8[i].fExpected )
        {
            cerr << "Error in case uint8_uint8 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].y) << ", ";
            cerr << "expected = " << uint8_uint8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_uint8[i].x);
            x -= SafeInt<unsigned __int64>(uint8_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint8[i].fExpected )
        {
            cerr << "Error in case uint8_uint8 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_uint8[i].y) << ", ";
            cerr << "expected = " << uint8_uint8[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, __int64 > int64_int64[] =
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
    { 0x8000000000000000, 0x0000000000000001, false},
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
    { 0x7ffffffffffffffe, 0x0000000000000002, true},
    { 0x7fffffffffffffff, 0x0000000000000002, true},
    { 0x8000000000000000, 0x0000000000000002, false},
    { 0x8000000000000001, 0x0000000000000002, false},
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
    { 0x7ffffffffffffffe, 0x000000007ffffffe, true},
    { 0x7fffffffffffffff, 0x000000007ffffffe, true},
    { 0x8000000000000000, 0x000000007ffffffe, false},
    { 0x8000000000000001, 0x000000007ffffffe, false},
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
    { 0x7ffffffffffffffe, 0x000000007fffffff, true},
    { 0x7fffffffffffffff, 0x000000007fffffff, true},
    { 0x8000000000000000, 0x000000007fffffff, false},
    { 0x8000000000000001, 0x000000007fffffff, false},
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
    { 0x7ffffffffffffffe, 0x0000000080000000, true},
    { 0x7fffffffffffffff, 0x0000000080000000, true},
    { 0x8000000000000000, 0x0000000080000000, false},
    { 0x8000000000000001, 0x0000000080000000, false},
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
    { 0x7ffffffffffffffe, 0x0000000080000001, true},
    { 0x7fffffffffffffff, 0x0000000080000001, true},
    { 0x8000000000000000, 0x0000000080000001, false},
    { 0x8000000000000001, 0x0000000080000001, false},
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
    { 0x7ffffffffffffffe, 0x00000000fffffffe, true},
    { 0x7fffffffffffffff, 0x00000000fffffffe, true},
    { 0x8000000000000000, 0x00000000fffffffe, false},
    { 0x8000000000000001, 0x00000000fffffffe, false},
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
    { 0x7ffffffffffffffe, 0x00000000ffffffff, true},
    { 0x7fffffffffffffff, 0x00000000ffffffff, true},
    { 0x8000000000000000, 0x00000000ffffffff, false},
    { 0x8000000000000001, 0x00000000ffffffff, false},
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
    { 0x7ffffffffffffffe, 0x0000000100000000, true},
    { 0x7fffffffffffffff, 0x0000000100000000, true},
    { 0x8000000000000000, 0x0000000100000000, false},
    { 0x8000000000000001, 0x0000000100000000, false},
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
    { 0x7ffffffffffffffe, 0x0000000200000000, true},
    { 0x7fffffffffffffff, 0x0000000200000000, true},
    { 0x8000000000000000, 0x0000000200000000, false},
    { 0x8000000000000001, 0x0000000200000000, false},
    { 0xfffffffffffffffe, 0x0000000200000000, true},
    { 0xffffffffffffffff, 0x0000000200000000, true},

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
    { 0x8000000000000000, 0x7ffffffffffffffe, false},
    { 0x8000000000000001, 0x7ffffffffffffffe, false},
    { 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffffffffffe, true},

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
    { 0x8000000000000000, 0x7fffffffffffffff, false},
    { 0x8000000000000001, 0x7fffffffffffffff, false},
    { 0xfffffffffffffffe, 0x7fffffffffffffff, false},
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

    { 0x0000000000000000, 0x8000000000000001, true},
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
    { 0x7ffffffffffffffe, 0xfffffffffffffffe, false},
    { 0x7fffffffffffffff, 0xfffffffffffffffe, false},
    { 0x8000000000000000, 0xfffffffffffffffe, true},
    { 0x8000000000000001, 0xfffffffffffffffe, true},
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
    { 0x7fffffffffffffff, 0xffffffffffffffff, false},
    { 0x8000000000000000, 0xffffffffffffffff, true},
    { 0x8000000000000001, 0xffffffffffffffff, true},
    { 0xfffffffffffffffe, 0xffffffffffffffff, true},
    { 0xffffffffffffffff, 0xffffffffffffffff, true},
};

void SubVerifyInt64Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int64); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
        {
            cerr << "Error in case int64_int64: ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].y << ", ";
            cerr << "expected = " << int64_int64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_int64[i].x);
            si -= int64_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int64[i].fExpected )
        {
            cerr << "Error in case int64_int64 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].y << ", ";
            cerr << "expected = " << int64_int64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_int64[i].x);
            x -= SafeInt<__int64>(int64_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int64[i].fExpected )
        {
            cerr << "Error in case int64_int64 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_int64[i].y << ", ";
            cerr << "expected = " << int64_int64[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, __int32 > int64_int32[] =
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
    { 0x8000000000000000, 0x00000001, false},
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
    { 0x7ffffffffffffffe, 0x00000002, true},
    { 0x7fffffffffffffff, 0x00000002, true},
    { 0x8000000000000000, 0x00000002, false},
    { 0x8000000000000001, 0x00000002, false},
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
    { 0x7ffffffffffffffe, 0x7ffffffe, true},
    { 0x7fffffffffffffff, 0x7ffffffe, true},
    { 0x8000000000000000, 0x7ffffffe, false},
    { 0x8000000000000001, 0x7ffffffe, false},
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
    { 0x7ffffffffffffffe, 0x7fffffff, true},
    { 0x7fffffffffffffff, 0x7fffffff, true},
    { 0x8000000000000000, 0x7fffffff, false},
    { 0x8000000000000001, 0x7fffffff, false},
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
    { 0x7ffffffffffffffe, 0xffffffff, true},
    { 0x7fffffffffffffff, 0xffffffff, false},
    { 0x8000000000000000, 0xffffffff, true},
    { 0x8000000000000001, 0xffffffff, true},
    { 0xfffffffffffffffe, 0xffffffff, true},
    { 0xffffffffffffffff, 0xffffffff, true},
};

void SubVerifyInt64Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int32); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_int32[i].x, int64_int32[i].y, ret) != int64_int32[i].fExpected )
        {
            cerr << "Error in case int64_int32: ";
            cerr << hex << setw(16) << setfill('0') << int64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_int32[i].y << ", ";
            cerr << "expected = " << int64_int32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_int32[i].x);
            si -= int64_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int32[i].fExpected )
        {
            cerr << "Error in case int64_int32 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_int32[i].y << ", ";
            cerr << "expected = " << int64_int32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_int32[i].x);
            x -= SafeInt<__int64>(int64_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int32[i].fExpected )
        {
            cerr << "Error in case int64_int32 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_int32[i].y << ", ";
            cerr << "expected = " << int64_int32[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, __int16 > int64_int16[] =
{
    { 0x0000000000000000, 0x0000, true},
    { 0x0000000000000001, 0x0000, true},
    { 0x0000000000000002, 0x0000, true},
    { 0x000000007ffffffe, 0x0000, true},
    { 0x000000007fffffff, 0x0000, true},
    { 0x0000000080000000, 0x0000, true},
    { 0x0000000080000001, 0x0000, true},
    { 0x00000000fffffffe, 0x0000, true},
    { 0x00000000ffffffff, 0x0000, true},
    { 0x0000000100000000, 0x0000, true},
    { 0x0000000200000000, 0x0000, true},
    { 0x7ffffffffffffffe, 0x0000, true},
    { 0x7fffffffffffffff, 0x0000, true},
    { 0x8000000000000000, 0x0000, true},
    { 0x8000000000000001, 0x0000, true},
    { 0xfffffffffffffffe, 0x0000, true},
    { 0xffffffffffffffff, 0x0000, true},

    { 0x0000000000000000, 0x0001, true},
    { 0x0000000000000001, 0x0001, true},
    { 0x0000000000000002, 0x0001, true},
    { 0x000000007ffffffe, 0x0001, true},
    { 0x000000007fffffff, 0x0001, true},
    { 0x0000000080000000, 0x0001, true},
    { 0x0000000080000001, 0x0001, true},
    { 0x00000000fffffffe, 0x0001, true},
    { 0x00000000ffffffff, 0x0001, true},
    { 0x0000000100000000, 0x0001, true},
    { 0x0000000200000000, 0x0001, true},
    { 0x7ffffffffffffffe, 0x0001, true},
    { 0x7fffffffffffffff, 0x0001, true},
    { 0x8000000000000000, 0x0001, false},
    { 0x8000000000000001, 0x0001, true},
    { 0xfffffffffffffffe, 0x0001, true},
    { 0xffffffffffffffff, 0x0001, true},

    { 0x0000000000000000, 0x0002, true},
    { 0x0000000000000001, 0x0002, true},
    { 0x0000000000000002, 0x0002, true},
    { 0x000000007ffffffe, 0x0002, true},
    { 0x000000007fffffff, 0x0002, true},
    { 0x0000000080000000, 0x0002, true},
    { 0x0000000080000001, 0x0002, true},
    { 0x00000000fffffffe, 0x0002, true},
    { 0x00000000ffffffff, 0x0002, true},
    { 0x0000000100000000, 0x0002, true},
    { 0x0000000200000000, 0x0002, true},
    { 0x7ffffffffffffffe, 0x0002, true},
    { 0x7fffffffffffffff, 0x0002, true},
    { 0x8000000000000000, 0x0002, false},
    { 0x8000000000000001, 0x0002, false},
    { 0xfffffffffffffffe, 0x0002, true},
    { 0xffffffffffffffff, 0x0002, true},

    { 0x0000000000000000, 0x7ffe, true},
    { 0x0000000000000001, 0x7ffe, true},
    { 0x0000000000000002, 0x7ffe, true},
    { 0x000000007ffffffe, 0x7ffe, true},
    { 0x000000007fffffff, 0x7ffe, true},
    { 0x0000000080000000, 0x7ffe, true},
    { 0x0000000080000001, 0x7ffe, true},
    { 0x00000000fffffffe, 0x7ffe, true},
    { 0x00000000ffffffff, 0x7ffe, true},
    { 0x0000000100000000, 0x7ffe, true},
    { 0x0000000200000000, 0x7ffe, true},
    { 0x7ffffffffffffffe, 0x7ffe, true},
    { 0x7fffffffffffffff, 0x7ffe, true},
    { 0x8000000000000000, 0x7ffe, false},
    { 0x8000000000000001, 0x7ffe, false},
    { 0xfffffffffffffffe, 0x7ffe, true},
    { 0xffffffffffffffff, 0x7ffe, true},

    { 0x0000000000000000, 0x7fff, true},
    { 0x0000000000000001, 0x7fff, true},
    { 0x0000000000000002, 0x7fff, true},
    { 0x000000007ffffffe, 0x7fff, true},
    { 0x000000007fffffff, 0x7fff, true},
    { 0x0000000080000000, 0x7fff, true},
    { 0x0000000080000001, 0x7fff, true},
    { 0x00000000fffffffe, 0x7fff, true},
    { 0x00000000ffffffff, 0x7fff, true},
    { 0x0000000100000000, 0x7fff, true},
    { 0x0000000200000000, 0x7fff, true},
    { 0x7ffffffffffffffe, 0x7fff, true},
    { 0x7fffffffffffffff, 0x7fff, true},
    { 0x8000000000000000, 0x7fff, false},
    { 0x8000000000000001, 0x7fff, false},
    { 0xfffffffffffffffe, 0x7fff, true},
    { 0xffffffffffffffff, 0x7fff, true},

    { 0x0000000000000000, 0x8000, true},
    { 0x0000000000000001, 0x8000, true},
    { 0x0000000000000002, 0x8000, true},
    { 0x000000007ffffffe, 0x8000, true},
    { 0x000000007fffffff, 0x8000, true},
    { 0x0000000080000000, 0x8000, true},
    { 0x0000000080000001, 0x8000, true},
    { 0x00000000fffffffe, 0x8000, true},
    { 0x00000000ffffffff, 0x8000, true},
    { 0x0000000100000000, 0x8000, true},
    { 0x0000000200000000, 0x8000, true},
    { 0x7ffffffffffffffe, 0x8000, false},
    { 0x7fffffffffffffff, 0x8000, false},
    { 0x8000000000000000, 0x8000, true},
    { 0x8000000000000001, 0x8000, true},
    { 0xfffffffffffffffe, 0x8000, true},
    { 0xffffffffffffffff, 0x8000, true},

    { 0x0000000000000000, 0x8001, true},
    { 0x0000000000000001, 0x8001, true},
    { 0x0000000000000002, 0x8001, true},
    { 0x000000007ffffffe, 0x8001, true},
    { 0x000000007fffffff, 0x8001, true},
    { 0x0000000080000000, 0x8001, true},
    { 0x0000000080000001, 0x8001, true},
    { 0x00000000fffffffe, 0x8001, true},
    { 0x00000000ffffffff, 0x8001, true},
    { 0x0000000100000000, 0x8001, true},
    { 0x0000000200000000, 0x8001, true},
    { 0x7ffffffffffffffe, 0x8001, false},
    { 0x7fffffffffffffff, 0x8001, false},
    { 0x8000000000000000, 0x8001, true},
    { 0x8000000000000001, 0x8001, true},
    { 0xfffffffffffffffe, 0x8001, true},
    { 0xffffffffffffffff, 0x8001, true},

    { 0x0000000000000000, 0xfffe, true},
    { 0x0000000000000001, 0xfffe, true},
    { 0x0000000000000002, 0xfffe, true},
    { 0x000000007ffffffe, 0xfffe, true},
    { 0x000000007fffffff, 0xfffe, true},
    { 0x0000000080000000, 0xfffe, true},
    { 0x0000000080000001, 0xfffe, true},
    { 0x00000000fffffffe, 0xfffe, true},
    { 0x00000000ffffffff, 0xfffe, true},
    { 0x0000000100000000, 0xfffe, true},
    { 0x0000000200000000, 0xfffe, true},
    { 0x7ffffffffffffffe, 0xfffe, false},
    { 0x7fffffffffffffff, 0xfffe, false},
    { 0x8000000000000000, 0xfffe, true},
    { 0x8000000000000001, 0xfffe, true},
    { 0xfffffffffffffffe, 0xfffe, true},
    { 0xffffffffffffffff, 0xfffe, true},

    { 0x0000000000000000, 0xffff, true},
    { 0x0000000000000001, 0xffff, true},
    { 0x0000000000000002, 0xffff, true},
    { 0x000000007ffffffe, 0xffff, true},
    { 0x000000007fffffff, 0xffff, true},
    { 0x0000000080000000, 0xffff, true},
    { 0x0000000080000001, 0xffff, true},
    { 0x00000000fffffffe, 0xffff, true},
    { 0x00000000ffffffff, 0xffff, true},
    { 0x0000000100000000, 0xffff, true},
    { 0x0000000200000000, 0xffff, true},
    { 0x7ffffffffffffffe, 0xffff, true},
    { 0x7fffffffffffffff, 0xffff, false},
    { 0x8000000000000000, 0xffff, true},
    { 0x8000000000000001, 0xffff, true},
    { 0xfffffffffffffffe, 0xffff, true},
    { 0xffffffffffffffff, 0xffff, true},
};

void SubVerifyInt64Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int16); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_int16[i].x, int64_int16[i].y, ret) != int64_int16[i].fExpected )
        {
            cerr << "Error in case int64_int16: ";
            cerr << hex << setw(16) << setfill('0') << int64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_int16[i].y << ", ";
            cerr << "expected = " << int64_int16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_int16[i].x);
            si -= int64_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int16[i].fExpected )
        {
            cerr << "Error in case int64_int16 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_int16[i].y << ", ";
            cerr << "expected = " << int64_int16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_int16[i].x);
            x -= SafeInt<__int64>(int64_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int16[i].fExpected )
        {
            cerr << "Error in case int64_int16 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_int16[i].y << ", ";
            cerr << "expected = " << int64_int16[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, __int8 > int64_int8[] =
{
    { 0x0000000000000000, 0x00, true},
    { 0x0000000000000001, 0x00, true},
    { 0x0000000000000002, 0x00, true},
    { 0x000000007ffffffe, 0x00, true},
    { 0x000000007fffffff, 0x00, true},
    { 0x0000000080000000, 0x00, true},
    { 0x0000000080000001, 0x00, true},
    { 0x00000000fffffffe, 0x00, true},
    { 0x00000000ffffffff, 0x00, true},
    { 0x0000000100000000, 0x00, true},
    { 0x0000000200000000, 0x00, true},
    { 0x7ffffffffffffffe, 0x00, true},
    { 0x7fffffffffffffff, 0x00, true},
    { 0x8000000000000000, 0x00, true},
    { 0x8000000000000001, 0x00, true},
    { 0xfffffffffffffffe, 0x00, true},
    { 0xffffffffffffffff, 0x00, true},

    { 0x0000000000000000, 0x01, true},
    { 0x0000000000000001, 0x01, true},
    { 0x0000000000000002, 0x01, true},
    { 0x000000007ffffffe, 0x01, true},
    { 0x000000007fffffff, 0x01, true},
    { 0x0000000080000000, 0x01, true},
    { 0x0000000080000001, 0x01, true},
    { 0x00000000fffffffe, 0x01, true},
    { 0x00000000ffffffff, 0x01, true},
    { 0x0000000100000000, 0x01, true},
    { 0x0000000200000000, 0x01, true},
    { 0x7ffffffffffffffe, 0x01, true},
    { 0x7fffffffffffffff, 0x01, true},
    { 0x8000000000000000, 0x01, false},
    { 0x8000000000000001, 0x01, true},
    { 0xfffffffffffffffe, 0x01, true},
    { 0xffffffffffffffff, 0x01, true},

    { 0x0000000000000000, 0x02, true},
    { 0x0000000000000001, 0x02, true},
    { 0x0000000000000002, 0x02, true},
    { 0x000000007ffffffe, 0x02, true},
    { 0x000000007fffffff, 0x02, true},
    { 0x0000000080000000, 0x02, true},
    { 0x0000000080000001, 0x02, true},
    { 0x00000000fffffffe, 0x02, true},
    { 0x00000000ffffffff, 0x02, true},
    { 0x0000000100000000, 0x02, true},
    { 0x0000000200000000, 0x02, true},
    { 0x7ffffffffffffffe, 0x02, true},
    { 0x7fffffffffffffff, 0x02, true},
    { 0x8000000000000000, 0x02, false},
    { 0x8000000000000001, 0x02, false},
    { 0xfffffffffffffffe, 0x02, true},
    { 0xffffffffffffffff, 0x02, true},

    { 0x0000000000000000, 0x7e, true},
    { 0x0000000000000001, 0x7e, true},
    { 0x0000000000000002, 0x7e, true},
    { 0x000000007ffffffe, 0x7e, true},
    { 0x000000007fffffff, 0x7e, true},
    { 0x0000000080000000, 0x7e, true},
    { 0x0000000080000001, 0x7e, true},
    { 0x00000000fffffffe, 0x7e, true},
    { 0x00000000ffffffff, 0x7e, true},
    { 0x0000000100000000, 0x7e, true},
    { 0x0000000200000000, 0x7e, true},
    { 0x7ffffffffffffffe, 0x7e, true},
    { 0x7fffffffffffffff, 0x7e, true},
    { 0x8000000000000000, 0x7e, false},
    { 0x8000000000000001, 0x7e, false},
    { 0xfffffffffffffffe, 0x7e, true},
    { 0xffffffffffffffff, 0x7e, true},

    { 0x0000000000000000, 0x7f, true},
    { 0x0000000000000001, 0x7f, true},
    { 0x0000000000000002, 0x7f, true},
    { 0x000000007ffffffe, 0x7f, true},
    { 0x000000007fffffff, 0x7f, true},
    { 0x0000000080000000, 0x7f, true},
    { 0x0000000080000001, 0x7f, true},
    { 0x00000000fffffffe, 0x7f, true},
    { 0x00000000ffffffff, 0x7f, true},
    { 0x0000000100000000, 0x7f, true},
    { 0x0000000200000000, 0x7f, true},
    { 0x7ffffffffffffffe, 0x7f, true},
    { 0x7fffffffffffffff, 0x7f, true},
    { 0x8000000000000000, 0x7f, false},
    { 0x8000000000000001, 0x7f, false},
    { 0xfffffffffffffffe, 0x7f, true},
    { 0xffffffffffffffff, 0x7f, true},

    { 0x0000000000000000, 0x80, true},
    { 0x0000000000000001, 0x80, true},
    { 0x0000000000000002, 0x80, true},
    { 0x000000007ffffffe, 0x80, true},
    { 0x000000007fffffff, 0x80, true},
    { 0x0000000080000000, 0x80, true},
    { 0x0000000080000001, 0x80, true},
    { 0x00000000fffffffe, 0x80, true},
    { 0x00000000ffffffff, 0x80, true},
    { 0x0000000100000000, 0x80, true},
    { 0x0000000200000000, 0x80, true},
    { 0x7ffffffffffffffe, 0x80, false},
    { 0x7fffffffffffffff, 0x80, false},
    { 0x8000000000000000, 0x80, true},
    { 0x8000000000000001, 0x80, true},
    { 0xfffffffffffffffe, 0x80, true},
    { 0xffffffffffffffff, 0x80, true},

    { 0x0000000000000000, 0x81, true},
    { 0x0000000000000001, 0x81, true},
    { 0x0000000000000002, 0x81, true},
    { 0x000000007ffffffe, 0x81, true},
    { 0x000000007fffffff, 0x81, true},
    { 0x0000000080000000, 0x81, true},
    { 0x0000000080000001, 0x81, true},
    { 0x00000000fffffffe, 0x81, true},
    { 0x00000000ffffffff, 0x81, true},
    { 0x0000000100000000, 0x81, true},
    { 0x0000000200000000, 0x81, true},
    { 0x7ffffffffffffffe, 0x81, false},
    { 0x7fffffffffffffff, 0x81, false},
    { 0x8000000000000000, 0x81, true},
    { 0x8000000000000001, 0x81, true},
    { 0xfffffffffffffffe, 0x81, true},
    { 0xffffffffffffffff, 0x81, true},

    { 0x0000000000000000, 0xfe, true},
    { 0x0000000000000001, 0xfe, true},
    { 0x0000000000000002, 0xfe, true},
    { 0x000000007ffffffe, 0xfe, true},
    { 0x000000007fffffff, 0xfe, true},
    { 0x0000000080000000, 0xfe, true},
    { 0x0000000080000001, 0xfe, true},
    { 0x00000000fffffffe, 0xfe, true},
    { 0x00000000ffffffff, 0xfe, true},
    { 0x0000000100000000, 0xfe, true},
    { 0x0000000200000000, 0xfe, true},
    { 0x7ffffffffffffffe, 0xfe, false},
    { 0x7fffffffffffffff, 0xfe, false},
    { 0x8000000000000000, 0xfe, true},
    { 0x8000000000000001, 0xfe, true},
    { 0xfffffffffffffffe, 0xfe, true},
    { 0xffffffffffffffff, 0xfe, true},

    { 0x0000000000000000, 0xff, true},
    { 0x0000000000000001, 0xff, true},
    { 0x0000000000000002, 0xff, true},
    { 0x000000007ffffffe, 0xff, true},
    { 0x000000007fffffff, 0xff, true},
    { 0x0000000080000000, 0xff, true},
    { 0x0000000080000001, 0xff, true},
    { 0x00000000fffffffe, 0xff, true},
    { 0x00000000ffffffff, 0xff, true},
    { 0x0000000100000000, 0xff, true},
    { 0x0000000200000000, 0xff, true},
    { 0x7ffffffffffffffe, 0xff, true},
    { 0x7fffffffffffffff, 0xff, false},
    { 0x8000000000000000, 0xff, true},
    { 0x8000000000000001, 0xff, true},
    { 0xfffffffffffffffe, 0xff, true},
    { 0xffffffffffffffff, 0xff, true},
};

void SubVerifyInt64Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int8); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_int8[i].x, int64_int8[i].y, ret) != int64_int8[i].fExpected )
        {
            cerr << "Error in case int64_int8: ";
            cerr << hex << setw(16) << setfill('0') << int64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_int8[i].y) << ", ";
            cerr << "expected = " << int64_int8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_int8[i].x);
            si -= int64_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int8[i].fExpected )
        {
            cerr << "Error in case int64_int8 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_int8[i].y) << ", ";
            cerr << "expected = " << int64_int8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_int8[i].x);
            x -= SafeInt<__int64>(int64_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int8[i].fExpected )
        {
            cerr << "Error in case int64_int8 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_int8[i].y) << ", ";
            cerr << "expected = " << int64_int8[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, __int64 > int8_int64[] =
{
    { 0x00, 0x0000000000000000, true},
    { 0x01, 0x0000000000000000, true},
    { 0x02, 0x0000000000000000, true},
    { 0x7e, 0x0000000000000000, true},
    { 0x7f, 0x0000000000000000, true},
    { 0x80, 0x0000000000000000, true},
    { 0x81, 0x0000000000000000, true},
    { 0xfe, 0x0000000000000000, true},
    { 0xff, 0x0000000000000000, true},

    { 0x00, 0x0000000000000001, true},
    { 0x01, 0x0000000000000001, true},
    { 0x02, 0x0000000000000001, true},
    { 0x7e, 0x0000000000000001, true},
    { 0x7f, 0x0000000000000001, true},
    { 0x80, 0x0000000000000001, false},
    { 0x81, 0x0000000000000001, true},
    { 0xfe, 0x0000000000000001, true},
    { 0xff, 0x0000000000000001, true},

    { 0x00, 0x0000000000000002, true},
    { 0x01, 0x0000000000000002, true},
    { 0x02, 0x0000000000000002, true},
    { 0x7e, 0x0000000000000002, true},
    { 0x7f, 0x0000000000000002, true},
    { 0x80, 0x0000000000000002, false},
    { 0x81, 0x0000000000000002, false},
    { 0xfe, 0x0000000000000002, true},
    { 0xff, 0x0000000000000002, true},

    { 0x00, 0x000000007ffffffe, false},
    { 0x01, 0x000000007ffffffe, false},
    { 0x02, 0x000000007ffffffe, false},
    { 0x7e, 0x000000007ffffffe, false},
    { 0x7f, 0x000000007ffffffe, false},
    { 0x80, 0x000000007ffffffe, false},
    { 0x81, 0x000000007ffffffe, false},
    { 0xfe, 0x000000007ffffffe, false},
    { 0xff, 0x000000007ffffffe, false},

    { 0x00, 0x000000007fffffff, false},
    { 0x01, 0x000000007fffffff, false},
    { 0x02, 0x000000007fffffff, false},
    { 0x7e, 0x000000007fffffff, false},
    { 0x7f, 0x000000007fffffff, false},
    { 0x80, 0x000000007fffffff, false},
    { 0x81, 0x000000007fffffff, false},
    { 0xfe, 0x000000007fffffff, false},
    { 0xff, 0x000000007fffffff, false},

    { 0x00, 0x0000000080000000, false},
    { 0x01, 0x0000000080000000, false},
    { 0x02, 0x0000000080000000, false},
    { 0x7e, 0x0000000080000000, false},
    { 0x7f, 0x0000000080000000, false},
    { 0x80, 0x0000000080000000, false},
    { 0x81, 0x0000000080000000, false},
    { 0xfe, 0x0000000080000000, false},
    { 0xff, 0x0000000080000000, false},

    { 0x00, 0x0000000080000001, false},
    { 0x01, 0x0000000080000001, false},
    { 0x02, 0x0000000080000001, false},
    { 0x7e, 0x0000000080000001, false},
    { 0x7f, 0x0000000080000001, false},
    { 0x80, 0x0000000080000001, false},
    { 0x81, 0x0000000080000001, false},
    { 0xfe, 0x0000000080000001, false},
    { 0xff, 0x0000000080000001, false},

    { 0x00, 0x00000000fffffffe, false},
    { 0x01, 0x00000000fffffffe, false},
    { 0x02, 0x00000000fffffffe, false},
    { 0x7e, 0x00000000fffffffe, false},
    { 0x7f, 0x00000000fffffffe, false},
    { 0x80, 0x00000000fffffffe, false},
    { 0x81, 0x00000000fffffffe, false},
    { 0xfe, 0x00000000fffffffe, false},
    { 0xff, 0x00000000fffffffe, false},

    { 0x00, 0x00000000ffffffff, false},
    { 0x01, 0x00000000ffffffff, false},
    { 0x02, 0x00000000ffffffff, false},
    { 0x7e, 0x00000000ffffffff, false},
    { 0x7f, 0x00000000ffffffff, false},
    { 0x80, 0x00000000ffffffff, false},
    { 0x81, 0x00000000ffffffff, false},
    { 0xfe, 0x00000000ffffffff, false},
    { 0xff, 0x00000000ffffffff, false},

    { 0x00, 0x0000000100000000, false},
    { 0x01, 0x0000000100000000, false},
    { 0x02, 0x0000000100000000, false},
    { 0x7e, 0x0000000100000000, false},
    { 0x7f, 0x0000000100000000, false},
    { 0x80, 0x0000000100000000, false},
    { 0x81, 0x0000000100000000, false},
    { 0xfe, 0x0000000100000000, false},
    { 0xff, 0x0000000100000000, false},

    { 0x00, 0x0000000200000000, false},
    { 0x01, 0x0000000200000000, false},
    { 0x02, 0x0000000200000000, false},
    { 0x7e, 0x0000000200000000, false},
    { 0x7f, 0x0000000200000000, false},
    { 0x80, 0x0000000200000000, false},
    { 0x81, 0x0000000200000000, false},
    { 0xfe, 0x0000000200000000, false},
    { 0xff, 0x0000000200000000, false},

    { 0x00, 0x7ffffffffffffffe, false},
    { 0x01, 0x7ffffffffffffffe, false},
    { 0x02, 0x7ffffffffffffffe, false},
    { 0x7e, 0x7ffffffffffffffe, false},
    { 0x7f, 0x7ffffffffffffffe, false},
    { 0x80, 0x7ffffffffffffffe, false},
    { 0x81, 0x7ffffffffffffffe, false},
    { 0xfe, 0x7ffffffffffffffe, false},
    { 0xff, 0x7ffffffffffffffe, false},

    { 0x00, 0x7fffffffffffffff, false},
    { 0x01, 0x7fffffffffffffff, false},
    { 0x02, 0x7fffffffffffffff, false},
    { 0x7e, 0x7fffffffffffffff, false},
    { 0x7f, 0x7fffffffffffffff, false},
    { 0x80, 0x7fffffffffffffff, false},
    { 0x81, 0x7fffffffffffffff, false},
    { 0xfe, 0x7fffffffffffffff, false},
    { 0xff, 0x7fffffffffffffff, false},

    { 0x00, 0x8000000000000000, false},
    { 0x01, 0x8000000000000000, false},
    { 0x02, 0x8000000000000000, false},
    { 0x7e, 0x8000000000000000, false},
    { 0x7f, 0x8000000000000000, false},
    { 0x80, 0x8000000000000000, false},
    { 0x81, 0x8000000000000000, false},
    { 0xfe, 0x8000000000000000, false},
    { 0xff, 0x8000000000000000, false},

    { 0x00, 0x8000000000000001, false},
    { 0x01, 0x8000000000000001, false},
    { 0x02, 0x8000000000000001, false},
    { 0x7e, 0x8000000000000001, false},
    { 0x7f, 0x8000000000000001, false},
    { 0x80, 0x8000000000000001, false},
    { 0x81, 0x8000000000000001, false},
    { 0xfe, 0x8000000000000001, false},
    { 0xff, 0x8000000000000001, false},

    { 0x00, 0xfffffffffffffffe, true},
    { 0x01, 0xfffffffffffffffe, true},
    { 0x02, 0xfffffffffffffffe, true},
    { 0x7e, 0xfffffffffffffffe, false},
    { 0x7f, 0xfffffffffffffffe, false},
    { 0x80, 0xfffffffffffffffe, true},
    { 0x81, 0xfffffffffffffffe, true},
    { 0xfe, 0xfffffffffffffffe, true},
    { 0xff, 0xfffffffffffffffe, true},

    { 0x00, 0xffffffffffffffff, true},
    { 0x01, 0xffffffffffffffff, true},
    { 0x02, 0xffffffffffffffff, true},
    { 0x7e, 0xffffffffffffffff, true},
    { 0x7f, 0xffffffffffffffff, false},
    { 0x80, 0xffffffffffffffff, true},
    { 0x81, 0xffffffffffffffff, true},
    { 0xfe, 0xffffffffffffffff, true},
    { 0xff, 0xffffffffffffffff, true},
};

void SubVerifyInt8Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int64); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_int64[i].x, int8_int64[i].y, ret) != int8_int64[i].fExpected )
        {
            cerr << "Error in case int8_int64: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_int64[i].y << ", ";
            cerr << "expected = " << int8_int64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_int64[i].x);
            si -= int8_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int64[i].fExpected )
        {
            cerr << "Error in case int8_int64 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_int64[i].y << ", ";
            cerr << "expected = " << int8_int64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_int64[i].x);
            x -= SafeInt<__int64>(int8_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int64[i].fExpected )
        {
            cerr << "Error in case int8_int64 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_int64[i].y << ", ";
            cerr << "expected = " << int8_int64[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, __int32 > int8_int32[] =
{
    { 0x00, 0x00000000, true},
    { 0x01, 0x00000000, true},
    { 0x02, 0x00000000, true},
    { 0x7e, 0x00000000, true},
    { 0x7f, 0x00000000, true},
    { 0x80, 0x00000000, true},
    { 0x81, 0x00000000, true},
    { 0xfe, 0x00000000, true},
    { 0xff, 0x00000000, true},

    { 0x00, 0x00000001, true},
    { 0x01, 0x00000001, true},
    { 0x02, 0x00000001, true},
    { 0x7e, 0x00000001, true},
    { 0x7f, 0x00000001, true},
    { 0x80, 0x00000001, false},
    { 0x81, 0x00000001, true},
    { 0xfe, 0x00000001, true},
    { 0xff, 0x00000001, true},

    { 0x00, 0x00000002, true},
    { 0x01, 0x00000002, true},
    { 0x02, 0x00000002, true},
    { 0x7e, 0x00000002, true},
    { 0x7f, 0x00000002, true},
    { 0x80, 0x00000002, false},
    { 0x81, 0x00000002, false},
    { 0xfe, 0x00000002, true},
    { 0xff, 0x00000002, true},

    { 0x00, 0x7ffffffe, false},
    { 0x01, 0x7ffffffe, false},
    { 0x02, 0x7ffffffe, false},
    { 0x7e, 0x7ffffffe, false},
    { 0x7f, 0x7ffffffe, false},
    { 0x80, 0x7ffffffe, false},
    { 0x81, 0x7ffffffe, false},
    { 0xfe, 0x7ffffffe, false},
    { 0xff, 0x7ffffffe, false},

    { 0x00, 0x7fffffff, false},
    { 0x01, 0x7fffffff, false},
    { 0x02, 0x7fffffff, false},
    { 0x7e, 0x7fffffff, false},
    { 0x7f, 0x7fffffff, false},
    { 0x80, 0x7fffffff, false},
    { 0x81, 0x7fffffff, false},
    { 0xfe, 0x7fffffff, false},
    { 0xff, 0x7fffffff, false},

    { 0x00, 0x80000000, false},
    { 0x01, 0x80000000, false},
    { 0x02, 0x80000000, false},
    { 0x7e, 0x80000000, false},
    { 0x7f, 0x80000000, false},
    { 0x80, 0x80000000, false},
    { 0x81, 0x80000000, false},
    { 0xfe, 0x80000000, false},
    { 0xff, 0x80000000, false},

    { 0x00, 0x80000001, false},
    { 0x01, 0x80000001, false},
    { 0x02, 0x80000001, false},
    { 0x7e, 0x80000001, false},
    { 0x7f, 0x80000001, false},
    { 0x80, 0x80000001, false},
    { 0x81, 0x80000001, false},
    { 0xfe, 0x80000001, false},
    { 0xff, 0x80000001, false},

    { 0x00, 0xfffffffe, true},
    { 0x01, 0xfffffffe, true},
    { 0x02, 0xfffffffe, true},
    { 0x7e, 0xfffffffe, false},
    { 0x7f, 0xfffffffe, false},
    { 0x80, 0xfffffffe, true},
    { 0x81, 0xfffffffe, true},
    { 0xfe, 0xfffffffe, true},
    { 0xff, 0xfffffffe, true},

    { 0x00, 0xffffffff, true},
    { 0x01, 0xffffffff, true},
    { 0x02, 0xffffffff, true},
    { 0x7e, 0xffffffff, true},
    { 0x7f, 0xffffffff, false},
    { 0x80, 0xffffffff, true},
    { 0x81, 0xffffffff, true},
    { 0xfe, 0xffffffff, true},
    { 0xff, 0xffffffff, true},
};

void SubVerifyInt8Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int32); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_int32[i].x, int8_int32[i].y, ret) != int8_int32[i].fExpected )
        {
            cerr << "Error in case int8_int32: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_int32[i].y << ", ";
            cerr << "expected = " << int8_int32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_int32[i].x);
            si -= int8_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int32[i].fExpected )
        {
            cerr << "Error in case int8_int32 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_int32[i].y << ", ";
            cerr << "expected = " << int8_int32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_int32[i].x);
            x -= SafeInt<__int64>(int8_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int32[i].fExpected )
        {
            cerr << "Error in case int8_int32 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_int32[i].y << ", ";
            cerr << "expected = " << int8_int32[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, __int16 > int8_int16[] =
{
    { 0x00, 0x0000, true},
    { 0x01, 0x0000, true},
    { 0x02, 0x0000, true},
    { 0x7e, 0x0000, true},
    { 0x7f, 0x0000, true},
    { 0x80, 0x0000, true},
    { 0x81, 0x0000, true},
    { 0xfe, 0x0000, true},
    { 0xff, 0x0000, true},

    { 0x00, 0x0001, true},
    { 0x01, 0x0001, true},
    { 0x02, 0x0001, true},
    { 0x7e, 0x0001, true},
    { 0x7f, 0x0001, true},
    { 0x80, 0x0001, false},
    { 0x81, 0x0001, true},
    { 0xfe, 0x0001, true},
    { 0xff, 0x0001, true},

    { 0x00, 0x0002, true},
    { 0x01, 0x0002, true},
    { 0x02, 0x0002, true},
    { 0x7e, 0x0002, true},
    { 0x7f, 0x0002, true},
    { 0x80, 0x0002, false},
    { 0x81, 0x0002, false},
    { 0xfe, 0x0002, true},
    { 0xff, 0x0002, true},

    { 0x00, 0x7ffe, false},
    { 0x01, 0x7ffe, false},
    { 0x02, 0x7ffe, false},
    { 0x7e, 0x7ffe, false},
    { 0x7f, 0x7ffe, false},
    { 0x80, 0x7ffe, false},
    { 0x81, 0x7ffe, false},
    { 0xfe, 0x7ffe, false},
    { 0xff, 0x7ffe, false},

    { 0x00, 0x7fff, false},
    { 0x01, 0x7fff, false},
    { 0x02, 0x7fff, false},
    { 0x7e, 0x7fff, false},
    { 0x7f, 0x7fff, false},
    { 0x80, 0x7fff, false},
    { 0x81, 0x7fff, false},
    { 0xfe, 0x7fff, false},
    { 0xff, 0x7fff, false},

    { 0x00, 0x8000, false},
    { 0x01, 0x8000, false},
    { 0x02, 0x8000, false},
    { 0x7e, 0x8000, false},
    { 0x7f, 0x8000, false},
    { 0x80, 0x8000, false},
    { 0x81, 0x8000, false},
    { 0xfe, 0x8000, false},
    { 0xff, 0x8000, false},

    { 0x00, 0x8001, false},
    { 0x01, 0x8001, false},
    { 0x02, 0x8001, false},
    { 0x7e, 0x8001, false},
    { 0x7f, 0x8001, false},
    { 0x80, 0x8001, false},
    { 0x81, 0x8001, false},
    { 0xfe, 0x8001, false},
    { 0xff, 0x8001, false},

    { 0x00, 0xfffe, true},
    { 0x01, 0xfffe, true},
    { 0x02, 0xfffe, true},
    { 0x7e, 0xfffe, false},
    { 0x7f, 0xfffe, false},
    { 0x80, 0xfffe, true},
    { 0x81, 0xfffe, true},
    { 0xfe, 0xfffe, true},
    { 0xff, 0xfffe, true},

    { 0x00, 0xffff, true},
    { 0x01, 0xffff, true},
    { 0x02, 0xffff, true},
    { 0x7e, 0xffff, true},
    { 0x7f, 0xffff, false},
    { 0x80, 0xffff, true},
    { 0x81, 0xffff, true},
    { 0xfe, 0xffff, true},
    { 0xff, 0xffff, true},
};

void SubVerifyInt8Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int16); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_int16[i].x, int8_int16[i].y, ret) != int8_int16[i].fExpected )
        {
            cerr << "Error in case int8_int16: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_int16[i].y << ", ";
            cerr << "expected = " << int8_int16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_int16[i].x);
            si -= int8_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int16[i].fExpected )
        {
            cerr << "Error in case int8_int16 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_int16[i].y << ", ";
            cerr << "expected = " << int8_int16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_int16[i].x);
            x -= SafeInt<__int64>(int8_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int16[i].fExpected )
        {
            cerr << "Error in case int8_int16 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_int16[i].y << ", ";
            cerr << "expected = " << int8_int16[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, __int8 > int8_int8[] =
{
    { 0x00, 0x00, true},
    { 0x01, 0x00, true},
    { 0x02, 0x00, true},
    { 0x7e, 0x00, true},
    { 0x7f, 0x00, true},
    { 0x80, 0x00, true},
    { 0x81, 0x00, true},
    { 0xfe, 0x00, true},
    { 0xff, 0x00, true},

    { 0x00, 0x01, true},
    { 0x01, 0x01, true},
    { 0x02, 0x01, true},
    { 0x7e, 0x01, true},
    { 0x7f, 0x01, true},
    { 0x80, 0x01, false},
    { 0x81, 0x01, true},
    { 0xfe, 0x01, true},
    { 0xff, 0x01, true},

    { 0x00, 0x02, true},
    { 0x01, 0x02, true},
    { 0x02, 0x02, true},
    { 0x7e, 0x02, true},
    { 0x7f, 0x02, true},
    { 0x80, 0x02, false},
    { 0x81, 0x02, false},
    { 0xfe, 0x02, true},
    { 0xff, 0x02, true},

    { 0x00, 0x7e, true},
    { 0x01, 0x7e, true},
    { 0x02, 0x7e, true},
    { 0x7e, 0x7e, true},
    { 0x7f, 0x7e, true},
    { 0x80, 0x7e, false},
    { 0x81, 0x7e, false},
    { 0xfe, 0x7e, true},
    { 0xff, 0x7e, true},

    { 0x00, 0x7f, true},
    { 0x01, 0x7f, true},
    { 0x02, 0x7f, true},
    { 0x7e, 0x7f, true},
    { 0x7f, 0x7f, true},
    { 0x80, 0x7f, false},
    { 0x81, 0x7f, false},
    { 0xfe, 0x7f, false},
    { 0xff, 0x7f, true},

    { 0x00, 0x80, false},
    { 0x01, 0x80, false},
    { 0x02, 0x80, false},
    { 0x7e, 0x80, false},
    { 0x7f, 0x80, false},
    { 0x80, 0x80, true},
    { 0x81, 0x80, true},
    { 0xfe, 0x80, true},
    { 0xff, 0x80, true},

    { 0x00, 0x81, true},
    { 0x01, 0x81, false},
    { 0x02, 0x81, false},
    { 0x7e, 0x81, false},
    { 0x7f, 0x81, false},
    { 0x80, 0x81, true},
    { 0x81, 0x81, true},
    { 0xfe, 0x81, true},
    { 0xff, 0x81, true},

    { 0x00, 0xfe, true},
    { 0x01, 0xfe, true},
    { 0x02, 0xfe, true},
    { 0x7e, 0xfe, false},
    { 0x7f, 0xfe, false},
    { 0x80, 0xfe, true},
    { 0x81, 0xfe, true},
    { 0xfe, 0xfe, true},
    { 0xff, 0xfe, true},

    { 0x00, 0xff, true},
    { 0x01, 0xff, true},
    { 0x02, 0xff, true},
    { 0x7e, 0xff, true},
    { 0x7f, 0xff, false},
    { 0x80, 0xff, true},
    { 0x81, 0xff, true},
    { 0xfe, 0xff, true},
    { 0xff, 0xff, true},
};

void SubVerifyInt8Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int8); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_int8[i].x, int8_int8[i].y, ret) != int8_int8[i].fExpected )
        {
            cerr << "Error in case int8_int8: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].y) << ", ";
            cerr << "expected = " << int8_int8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_int8[i].x);
            si -= int8_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int8[i].fExpected )
        {
            cerr << "Error in case int8_int8 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].y) << ", ";
            cerr << "expected = " << int8_int8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_int8[i].x);
            x -= SafeInt<__int64>(int8_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int8[i].fExpected )
        {
            cerr << "Error in case int8_int8 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_int8[i].y) << ", ";
            cerr << "expected = " << int8_int8[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, __int64 > uint64_int64[] =
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

    { 0x0000000000000000, 0x0000000000000001, false},
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
    { 0xffffffffffffffff, 0x0000000000000001, true},

    { 0x0000000000000000, 0x0000000000000002, false},
    { 0x0000000000000001, 0x0000000000000002, false},
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
    { 0xfffffffffffffffe, 0x0000000000000002, true},
    { 0xffffffffffffffff, 0x0000000000000002, true},

    { 0x0000000000000000, 0x000000007ffffffe, false},
    { 0x0000000000000001, 0x000000007ffffffe, false},
    { 0x0000000000000002, 0x000000007ffffffe, false},
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
    { 0xfffffffffffffffe, 0x000000007ffffffe, true},
    { 0xffffffffffffffff, 0x000000007ffffffe, true},

    { 0x0000000000000000, 0x000000007fffffff, false},
    { 0x0000000000000001, 0x000000007fffffff, false},
    { 0x0000000000000002, 0x000000007fffffff, false},
    { 0x000000007ffffffe, 0x000000007fffffff, false},
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
    { 0xfffffffffffffffe, 0x000000007fffffff, true},
    { 0xffffffffffffffff, 0x000000007fffffff, true},

    { 0x0000000000000000, 0x0000000080000000, false},
    { 0x0000000000000001, 0x0000000080000000, false},
    { 0x0000000000000002, 0x0000000080000000, false},
    { 0x000000007ffffffe, 0x0000000080000000, false},
    { 0x000000007fffffff, 0x0000000080000000, false},
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
    { 0xfffffffffffffffe, 0x0000000080000000, true},
    { 0xffffffffffffffff, 0x0000000080000000, true},

    { 0x0000000000000000, 0x0000000080000001, false},
    { 0x0000000000000001, 0x0000000080000001, false},
    { 0x0000000000000002, 0x0000000080000001, false},
    { 0x000000007ffffffe, 0x0000000080000001, false},
    { 0x000000007fffffff, 0x0000000080000001, false},
    { 0x0000000080000000, 0x0000000080000001, false},
    { 0x0000000080000001, 0x0000000080000001, true},
    { 0x00000000fffffffe, 0x0000000080000001, true},
    { 0x00000000ffffffff, 0x0000000080000001, true},
    { 0x0000000100000000, 0x0000000080000001, true},
    { 0x0000000200000000, 0x0000000080000001, true},
    { 0x7ffffffffffffffe, 0x0000000080000001, true},
    { 0x7fffffffffffffff, 0x0000000080000001, true},
    { 0x8000000000000000, 0x0000000080000001, true},
    { 0x8000000000000001, 0x0000000080000001, true},
    { 0xfffffffffffffffe, 0x0000000080000001, true},
    { 0xffffffffffffffff, 0x0000000080000001, true},

    { 0x0000000000000000, 0x00000000fffffffe, false},
    { 0x0000000000000001, 0x00000000fffffffe, false},
    { 0x0000000000000002, 0x00000000fffffffe, false},
    { 0x000000007ffffffe, 0x00000000fffffffe, false},
    { 0x000000007fffffff, 0x00000000fffffffe, false},
    { 0x0000000080000000, 0x00000000fffffffe, false},
    { 0x0000000080000001, 0x00000000fffffffe, false},
    { 0x00000000fffffffe, 0x00000000fffffffe, true},
    { 0x00000000ffffffff, 0x00000000fffffffe, true},
    { 0x0000000100000000, 0x00000000fffffffe, true},
    { 0x0000000200000000, 0x00000000fffffffe, true},
    { 0x7ffffffffffffffe, 0x00000000fffffffe, true},
    { 0x7fffffffffffffff, 0x00000000fffffffe, true},
    { 0x8000000000000000, 0x00000000fffffffe, true},
    { 0x8000000000000001, 0x00000000fffffffe, true},
    { 0xfffffffffffffffe, 0x00000000fffffffe, true},
    { 0xffffffffffffffff, 0x00000000fffffffe, true},

    { 0x0000000000000000, 0x00000000ffffffff, false},
    { 0x0000000000000001, 0x00000000ffffffff, false},
    { 0x0000000000000002, 0x00000000ffffffff, false},
    { 0x000000007ffffffe, 0x00000000ffffffff, false},
    { 0x000000007fffffff, 0x00000000ffffffff, false},
    { 0x0000000080000000, 0x00000000ffffffff, false},
    { 0x0000000080000001, 0x00000000ffffffff, false},
    { 0x00000000fffffffe, 0x00000000ffffffff, false},
    { 0x00000000ffffffff, 0x00000000ffffffff, true},
    { 0x0000000100000000, 0x00000000ffffffff, true},
    { 0x0000000200000000, 0x00000000ffffffff, true},
    { 0x7ffffffffffffffe, 0x00000000ffffffff, true},
    { 0x7fffffffffffffff, 0x00000000ffffffff, true},
    { 0x8000000000000000, 0x00000000ffffffff, true},
    { 0x8000000000000001, 0x00000000ffffffff, true},
    { 0xfffffffffffffffe, 0x00000000ffffffff, true},
    { 0xffffffffffffffff, 0x00000000ffffffff, true},

    { 0x0000000000000000, 0x0000000100000000, false},
    { 0x0000000000000001, 0x0000000100000000, false},
    { 0x0000000000000002, 0x0000000100000000, false},
    { 0x000000007ffffffe, 0x0000000100000000, false},
    { 0x000000007fffffff, 0x0000000100000000, false},
    { 0x0000000080000000, 0x0000000100000000, false},
    { 0x0000000080000001, 0x0000000100000000, false},
    { 0x00000000fffffffe, 0x0000000100000000, false},
    { 0x00000000ffffffff, 0x0000000100000000, false},
    { 0x0000000100000000, 0x0000000100000000, true},
    { 0x0000000200000000, 0x0000000100000000, true},
    { 0x7ffffffffffffffe, 0x0000000100000000, true},
    { 0x7fffffffffffffff, 0x0000000100000000, true},
    { 0x8000000000000000, 0x0000000100000000, true},
    { 0x8000000000000001, 0x0000000100000000, true},
    { 0xfffffffffffffffe, 0x0000000100000000, true},
    { 0xffffffffffffffff, 0x0000000100000000, true},

    { 0x0000000000000000, 0x0000000200000000, false},
    { 0x0000000000000001, 0x0000000200000000, false},
    { 0x0000000000000002, 0x0000000200000000, false},
    { 0x000000007ffffffe, 0x0000000200000000, false},
    { 0x000000007fffffff, 0x0000000200000000, false},
    { 0x0000000080000000, 0x0000000200000000, false},
    { 0x0000000080000001, 0x0000000200000000, false},
    { 0x00000000fffffffe, 0x0000000200000000, false},
    { 0x00000000ffffffff, 0x0000000200000000, false},
    { 0x0000000100000000, 0x0000000200000000, false},
    { 0x0000000200000000, 0x0000000200000000, true},
    { 0x7ffffffffffffffe, 0x0000000200000000, true},
    { 0x7fffffffffffffff, 0x0000000200000000, true},
    { 0x8000000000000000, 0x0000000200000000, true},
    { 0x8000000000000001, 0x0000000200000000, true},
    { 0xfffffffffffffffe, 0x0000000200000000, true},
    { 0xffffffffffffffff, 0x0000000200000000, true},

    { 0x0000000000000000, 0x7ffffffffffffffe, false},
    { 0x0000000000000001, 0x7ffffffffffffffe, false},
    { 0x0000000000000002, 0x7ffffffffffffffe, false},
    { 0x000000007ffffffe, 0x7ffffffffffffffe, false},
    { 0x000000007fffffff, 0x7ffffffffffffffe, false},
    { 0x0000000080000000, 0x7ffffffffffffffe, false},
    { 0x0000000080000001, 0x7ffffffffffffffe, false},
    { 0x00000000fffffffe, 0x7ffffffffffffffe, false},
    { 0x00000000ffffffff, 0x7ffffffffffffffe, false},
    { 0x0000000100000000, 0x7ffffffffffffffe, false},
    { 0x0000000200000000, 0x7ffffffffffffffe, false},
    { 0x7ffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0x7fffffffffffffff, 0x7ffffffffffffffe, true},
    { 0x8000000000000000, 0x7ffffffffffffffe, true},
    { 0x8000000000000001, 0x7ffffffffffffffe, true},
    { 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffffffffffe, true},

    { 0x0000000000000000, 0x7fffffffffffffff, false},
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
    { 0x7fffffffffffffff, 0x7fffffffffffffff, true},
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
    { 0x8000000000000000, 0x8000000000000001, true},
    { 0x8000000000000001, 0x8000000000000001, false},
    { 0xfffffffffffffffe, 0x8000000000000001, false},
    { 0xffffffffffffffff, 0x8000000000000001, false},

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
    { 0x8000000000000000, 0xfffffffffffffffe, true},
    { 0x8000000000000001, 0xfffffffffffffffe, true},
    { 0xfffffffffffffffe, 0xfffffffffffffffe, false},
    { 0xffffffffffffffff, 0xfffffffffffffffe, false},

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
    { 0x8000000000000000, 0xffffffffffffffff, true},
    { 0x8000000000000001, 0xffffffffffffffff, true},
    { 0xfffffffffffffffe, 0xffffffffffffffff, true},
    { 0xffffffffffffffff, 0xffffffffffffffff, false},
};

void SubVerifyUint64Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int64); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
        {
            cerr << "Error in case uint64_int64: ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].y << ", ";
            cerr << "expected = " << uint64_int64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_int64[i].x);
            si -= (__int64)uint64_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int64[i].fExpected )
        {
            cerr << "Error in case uint64_int64 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].y << ", ";
            cerr << "expected = " << uint64_int64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_int64[i].x);
            x -= SafeInt<__int64>(uint64_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int64[i].fExpected )
        {
            cerr << "Error in case uint64_int64 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << uint64_int64[i].y << ", ";
            cerr << "expected = " << uint64_int64[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, __int32 > uint64_int32[] =
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

    { 0x0000000000000000, 0x00000001, false},
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
    { 0xffffffffffffffff, 0x00000001, true},

    { 0x0000000000000000, 0x00000002, false},
    { 0x0000000000000001, 0x00000002, false},
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
    { 0xfffffffffffffffe, 0x00000002, true},
    { 0xffffffffffffffff, 0x00000002, true},

    { 0x0000000000000000, 0x7ffffffe, false},
    { 0x0000000000000001, 0x7ffffffe, false},
    { 0x0000000000000002, 0x7ffffffe, false},
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
    { 0xfffffffffffffffe, 0x7ffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffe, true},

    { 0x0000000000000000, 0x7fffffff, false},
    { 0x0000000000000001, 0x7fffffff, false},
    { 0x0000000000000002, 0x7fffffff, false},
    { 0x000000007ffffffe, 0x7fffffff, false},
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
    { 0xfffffffffffffffe, 0xffffffff, true},
    { 0xffffffffffffffff, 0xffffffff, false},
};

void SubVerifyUint64Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int32); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
        {
            cerr << "Error in case uint64_int32: ";
            cerr << hex << setw(16) << setfill('0') << uint64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_int32[i].y << ", ";
            cerr << "expected = " << uint64_int32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_int32[i].x);
            si -= (__int32)uint64_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int32[i].fExpected )
        {
            cerr << "Error in case uint64_int32 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_int32[i].y << ", ";
            cerr << "expected = " << uint64_int32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_int32[i].x);
            x -= SafeInt<__int32>(uint64_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int32[i].fExpected )
        {
            cerr << "Error in case uint64_int32 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << uint64_int32[i].y << ", ";
            cerr << "expected = " << uint64_int32[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, __int16 > uint64_int16[] =
{
    { 0x0000000000000000, 0x0000, true},
    { 0x0000000000000001, 0x0000, true},
    { 0x0000000000000002, 0x0000, true},
    { 0x000000007ffffffe, 0x0000, true},
    { 0x000000007fffffff, 0x0000, true},
    { 0x0000000080000000, 0x0000, true},
    { 0x0000000080000001, 0x0000, true},
    { 0x00000000fffffffe, 0x0000, true},
    { 0x00000000ffffffff, 0x0000, true},
    { 0x0000000100000000, 0x0000, true},
    { 0x0000000200000000, 0x0000, true},
    { 0x7ffffffffffffffe, 0x0000, true},
    { 0x7fffffffffffffff, 0x0000, true},
    { 0x8000000000000000, 0x0000, true},
    { 0x8000000000000001, 0x0000, true},
    { 0xfffffffffffffffe, 0x0000, true},
    { 0xffffffffffffffff, 0x0000, true},

    { 0x0000000000000000, 0x0001, false},
    { 0x0000000000000001, 0x0001, true},
    { 0x0000000000000002, 0x0001, true},
    { 0x000000007ffffffe, 0x0001, true},
    { 0x000000007fffffff, 0x0001, true},
    { 0x0000000080000000, 0x0001, true},
    { 0x0000000080000001, 0x0001, true},
    { 0x00000000fffffffe, 0x0001, true},
    { 0x00000000ffffffff, 0x0001, true},
    { 0x0000000100000000, 0x0001, true},
    { 0x0000000200000000, 0x0001, true},
    { 0x7ffffffffffffffe, 0x0001, true},
    { 0x7fffffffffffffff, 0x0001, true},
    { 0x8000000000000000, 0x0001, true},
    { 0x8000000000000001, 0x0001, true},
    { 0xfffffffffffffffe, 0x0001, true},
    { 0xffffffffffffffff, 0x0001, true},

    { 0x0000000000000000, 0x0002, false},
    { 0x0000000000000001, 0x0002, false},
    { 0x0000000000000002, 0x0002, true},
    { 0x000000007ffffffe, 0x0002, true},
    { 0x000000007fffffff, 0x0002, true},
    { 0x0000000080000000, 0x0002, true},
    { 0x0000000080000001, 0x0002, true},
    { 0x00000000fffffffe, 0x0002, true},
    { 0x00000000ffffffff, 0x0002, true},
    { 0x0000000100000000, 0x0002, true},
    { 0x0000000200000000, 0x0002, true},
    { 0x7ffffffffffffffe, 0x0002, true},
    { 0x7fffffffffffffff, 0x0002, true},
    { 0x8000000000000000, 0x0002, true},
    { 0x8000000000000001, 0x0002, true},
    { 0xfffffffffffffffe, 0x0002, true},
    { 0xffffffffffffffff, 0x0002, true},

    { 0x0000000000000000, 0x7ffe, false},
    { 0x0000000000000001, 0x7ffe, false},
    { 0x0000000000000002, 0x7ffe, false},
    { 0x000000007ffffffe, 0x7ffe, true},
    { 0x000000007fffffff, 0x7ffe, true},
    { 0x0000000080000000, 0x7ffe, true},
    { 0x0000000080000001, 0x7ffe, true},
    { 0x00000000fffffffe, 0x7ffe, true},
    { 0x00000000ffffffff, 0x7ffe, true},
    { 0x0000000100000000, 0x7ffe, true},
    { 0x0000000200000000, 0x7ffe, true},
    { 0x7ffffffffffffffe, 0x7ffe, true},
    { 0x7fffffffffffffff, 0x7ffe, true},
    { 0x8000000000000000, 0x7ffe, true},
    { 0x8000000000000001, 0x7ffe, true},
    { 0xfffffffffffffffe, 0x7ffe, true},
    { 0xffffffffffffffff, 0x7ffe, true},

    { 0x0000000000000000, 0x7fff, false},
    { 0x0000000000000001, 0x7fff, false},
    { 0x0000000000000002, 0x7fff, false},
    { 0x000000007ffffffe, 0x7fff, true},
    { 0x000000007fffffff, 0x7fff, true},
    { 0x0000000080000000, 0x7fff, true},
    { 0x0000000080000001, 0x7fff, true},
    { 0x00000000fffffffe, 0x7fff, true},
    { 0x00000000ffffffff, 0x7fff, true},
    { 0x0000000100000000, 0x7fff, true},
    { 0x0000000200000000, 0x7fff, true},
    { 0x7ffffffffffffffe, 0x7fff, true},
    { 0x7fffffffffffffff, 0x7fff, true},
    { 0x8000000000000000, 0x7fff, true},
    { 0x8000000000000001, 0x7fff, true},
    { 0xfffffffffffffffe, 0x7fff, true},
    { 0xffffffffffffffff, 0x7fff, true},

    { 0x0000000000000000, 0x8000, true},
    { 0x0000000000000001, 0x8000, true},
    { 0x0000000000000002, 0x8000, true},
    { 0x000000007ffffffe, 0x8000, true},
    { 0x000000007fffffff, 0x8000, true},
    { 0x0000000080000000, 0x8000, true},
    { 0x0000000080000001, 0x8000, true},
    { 0x00000000fffffffe, 0x8000, true},
    { 0x00000000ffffffff, 0x8000, true},
    { 0x0000000100000000, 0x8000, true},
    { 0x0000000200000000, 0x8000, true},
    { 0x7ffffffffffffffe, 0x8000, true},
    { 0x7fffffffffffffff, 0x8000, true},
    { 0x8000000000000000, 0x8000, true},
    { 0x8000000000000001, 0x8000, true},
    { 0xfffffffffffffffe, 0x8000, false},
    { 0xffffffffffffffff, 0x8000, false},

    { 0x0000000000000000, 0x8001, true},
    { 0x0000000000000001, 0x8001, true},
    { 0x0000000000000002, 0x8001, true},
    { 0x000000007ffffffe, 0x8001, true},
    { 0x000000007fffffff, 0x8001, true},
    { 0x0000000080000000, 0x8001, true},
    { 0x0000000080000001, 0x8001, true},
    { 0x00000000fffffffe, 0x8001, true},
    { 0x00000000ffffffff, 0x8001, true},
    { 0x0000000100000000, 0x8001, true},
    { 0x0000000200000000, 0x8001, true},
    { 0x7ffffffffffffffe, 0x8001, true},
    { 0x7fffffffffffffff, 0x8001, true},
    { 0x8000000000000000, 0x8001, true},
    { 0x8000000000000001, 0x8001, true},
    { 0xfffffffffffffffe, 0x8001, false},
    { 0xffffffffffffffff, 0x8001, false},

    { 0x0000000000000000, 0xfffe, true},
    { 0x0000000000000001, 0xfffe, true},
    { 0x0000000000000002, 0xfffe, true},
    { 0x000000007ffffffe, 0xfffe, true},
    { 0x000000007fffffff, 0xfffe, true},
    { 0x0000000080000000, 0xfffe, true},
    { 0x0000000080000001, 0xfffe, true},
    { 0x00000000fffffffe, 0xfffe, true},
    { 0x00000000ffffffff, 0xfffe, true},
    { 0x0000000100000000, 0xfffe, true},
    { 0x0000000200000000, 0xfffe, true},
    { 0x7ffffffffffffffe, 0xfffe, true},
    { 0x7fffffffffffffff, 0xfffe, true},
    { 0x8000000000000000, 0xfffe, true},
    { 0x8000000000000001, 0xfffe, true},
    { 0xfffffffffffffffe, 0xfffe, false},
    { 0xffffffffffffffff, 0xfffe, false},

    { 0x0000000000000000, 0xffff, true},
    { 0x0000000000000001, 0xffff, true},
    { 0x0000000000000002, 0xffff, true},
    { 0x000000007ffffffe, 0xffff, true},
    { 0x000000007fffffff, 0xffff, true},
    { 0x0000000080000000, 0xffff, true},
    { 0x0000000080000001, 0xffff, true},
    { 0x00000000fffffffe, 0xffff, true},
    { 0x00000000ffffffff, 0xffff, true},
    { 0x0000000100000000, 0xffff, true},
    { 0x0000000200000000, 0xffff, true},
    { 0x7ffffffffffffffe, 0xffff, true},
    { 0x7fffffffffffffff, 0xffff, true},
    { 0x8000000000000000, 0xffff, true},
    { 0x8000000000000001, 0xffff, true},
    { 0xfffffffffffffffe, 0xffff, true},
    { 0xffffffffffffffff, 0xffff, false},
};

void SubVerifyUint64Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int16); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_int16[i].x, uint64_int16[i].y, ret) != uint64_int16[i].fExpected )
        {
            cerr << "Error in case uint64_int16: ";
            cerr << hex << setw(16) << setfill('0') << uint64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_int16[i].y << ", ";
            cerr << "expected = " << uint64_int16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_int16[i].x);
            si -= (__int16)uint64_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int16[i].fExpected )
        {
            cerr << "Error in case uint64_int16 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_int16[i].y << ", ";
            cerr << "expected = " << uint64_int16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_int16[i].x);
            x -= SafeInt<__int16>(uint64_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int16[i].fExpected )
        {
            cerr << "Error in case uint64_int16 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << uint64_int16[i].y << ", ";
            cerr << "expected = " << uint64_int16[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int64, __int8 > uint64_int8[] =
{
    { 0x0000000000000000, 0x00, true},
    { 0x0000000000000001, 0x00, true},
    { 0x0000000000000002, 0x00, true},
    { 0x000000007ffffffe, 0x00, true},
    { 0x000000007fffffff, 0x00, true},
    { 0x0000000080000000, 0x00, true},
    { 0x0000000080000001, 0x00, true},
    { 0x00000000fffffffe, 0x00, true},
    { 0x00000000ffffffff, 0x00, true},
    { 0x0000000100000000, 0x00, true},
    { 0x0000000200000000, 0x00, true},
    { 0x7ffffffffffffffe, 0x00, true},
    { 0x7fffffffffffffff, 0x00, true},
    { 0x8000000000000000, 0x00, true},
    { 0x8000000000000001, 0x00, true},
    { 0xfffffffffffffffe, 0x00, true},
    { 0xffffffffffffffff, 0x00, true},

    { 0x0000000000000000, 0x01, false},
    { 0x0000000000000001, 0x01, true},
    { 0x0000000000000002, 0x01, true},
    { 0x000000007ffffffe, 0x01, true},
    { 0x000000007fffffff, 0x01, true},
    { 0x0000000080000000, 0x01, true},
    { 0x0000000080000001, 0x01, true},
    { 0x00000000fffffffe, 0x01, true},
    { 0x00000000ffffffff, 0x01, true},
    { 0x0000000100000000, 0x01, true},
    { 0x0000000200000000, 0x01, true},
    { 0x7ffffffffffffffe, 0x01, true},
    { 0x7fffffffffffffff, 0x01, true},
    { 0x8000000000000000, 0x01, true},
    { 0x8000000000000001, 0x01, true},
    { 0xfffffffffffffffe, 0x01, true},
    { 0xffffffffffffffff, 0x01, true},

    { 0x0000000000000000, 0x02, false},
    { 0x0000000000000001, 0x02, false},
    { 0x0000000000000002, 0x02, true},
    { 0x000000007ffffffe, 0x02, true},
    { 0x000000007fffffff, 0x02, true},
    { 0x0000000080000000, 0x02, true},
    { 0x0000000080000001, 0x02, true},
    { 0x00000000fffffffe, 0x02, true},
    { 0x00000000ffffffff, 0x02, true},
    { 0x0000000100000000, 0x02, true},
    { 0x0000000200000000, 0x02, true},
    { 0x7ffffffffffffffe, 0x02, true},
    { 0x7fffffffffffffff, 0x02, true},
    { 0x8000000000000000, 0x02, true},
    { 0x8000000000000001, 0x02, true},
    { 0xfffffffffffffffe, 0x02, true},
    { 0xffffffffffffffff, 0x02, true},

    { 0x0000000000000000, 0x7e, false},
    { 0x0000000000000001, 0x7e, false},
    { 0x0000000000000002, 0x7e, false},
    { 0x000000007ffffffe, 0x7e, true},
    { 0x000000007fffffff, 0x7e, true},
    { 0x0000000080000000, 0x7e, true},
    { 0x0000000080000001, 0x7e, true},
    { 0x00000000fffffffe, 0x7e, true},
    { 0x00000000ffffffff, 0x7e, true},
    { 0x0000000100000000, 0x7e, true},
    { 0x0000000200000000, 0x7e, true},
    { 0x7ffffffffffffffe, 0x7e, true},
    { 0x7fffffffffffffff, 0x7e, true},
    { 0x8000000000000000, 0x7e, true},
    { 0x8000000000000001, 0x7e, true},
    { 0xfffffffffffffffe, 0x7e, true},
    { 0xffffffffffffffff, 0x7e, true},

    { 0x0000000000000000, 0x7f, false},
    { 0x0000000000000001, 0x7f, false},
    { 0x0000000000000002, 0x7f, false},
    { 0x000000007ffffffe, 0x7f, true},
    { 0x000000007fffffff, 0x7f, true},
    { 0x0000000080000000, 0x7f, true},
    { 0x0000000080000001, 0x7f, true},
    { 0x00000000fffffffe, 0x7f, true},
    { 0x00000000ffffffff, 0x7f, true},
    { 0x0000000100000000, 0x7f, true},
    { 0x0000000200000000, 0x7f, true},
    { 0x7ffffffffffffffe, 0x7f, true},
    { 0x7fffffffffffffff, 0x7f, true},
    { 0x8000000000000000, 0x7f, true},
    { 0x8000000000000001, 0x7f, true},
    { 0xfffffffffffffffe, 0x7f, true},
    { 0xffffffffffffffff, 0x7f, true},

    { 0x0000000000000000, 0x80, true},
    { 0x0000000000000001, 0x80, true},
    { 0x0000000000000002, 0x80, true},
    { 0x000000007ffffffe, 0x80, true},
    { 0x000000007fffffff, 0x80, true},
    { 0x0000000080000000, 0x80, true},
    { 0x0000000080000001, 0x80, true},
    { 0x00000000fffffffe, 0x80, true},
    { 0x00000000ffffffff, 0x80, true},
    { 0x0000000100000000, 0x80, true},
    { 0x0000000200000000, 0x80, true},
    { 0x7ffffffffffffffe, 0x80, true},
    { 0x7fffffffffffffff, 0x80, true},
    { 0x8000000000000000, 0x80, true},
    { 0x8000000000000001, 0x80, true},
    { 0xfffffffffffffffe, 0x80, false},
    { 0xffffffffffffffff, 0x80, false},

    { 0x0000000000000000, 0x81, true},
    { 0x0000000000000001, 0x81, true},
    { 0x0000000000000002, 0x81, true},
    { 0x000000007ffffffe, 0x81, true},
    { 0x000000007fffffff, 0x81, true},
    { 0x0000000080000000, 0x81, true},
    { 0x0000000080000001, 0x81, true},
    { 0x00000000fffffffe, 0x81, true},
    { 0x00000000ffffffff, 0x81, true},
    { 0x0000000100000000, 0x81, true},
    { 0x0000000200000000, 0x81, true},
    { 0x7ffffffffffffffe, 0x81, true},
    { 0x7fffffffffffffff, 0x81, true},
    { 0x8000000000000000, 0x81, true},
    { 0x8000000000000001, 0x81, true},
    { 0xfffffffffffffffe, 0x81, false},
    { 0xffffffffffffffff, 0x81, false},

    { 0x0000000000000000, 0xfe, true},
    { 0x0000000000000001, 0xfe, true},
    { 0x0000000000000002, 0xfe, true},
    { 0x000000007ffffffe, 0xfe, true},
    { 0x000000007fffffff, 0xfe, true},
    { 0x0000000080000000, 0xfe, true},
    { 0x0000000080000001, 0xfe, true},
    { 0x00000000fffffffe, 0xfe, true},
    { 0x00000000ffffffff, 0xfe, true},
    { 0x0000000100000000, 0xfe, true},
    { 0x0000000200000000, 0xfe, true},
    { 0x7ffffffffffffffe, 0xfe, true},
    { 0x7fffffffffffffff, 0xfe, true},
    { 0x8000000000000000, 0xfe, true},
    { 0x8000000000000001, 0xfe, true},
    { 0xfffffffffffffffe, 0xfe, false},
    { 0xffffffffffffffff, 0xfe, false},

    { 0x0000000000000000, 0xff, true},
    { 0x0000000000000001, 0xff, true},
    { 0x0000000000000002, 0xff, true},
    { 0x000000007ffffffe, 0xff, true},
    { 0x000000007fffffff, 0xff, true},
    { 0x0000000080000000, 0xff, true},
    { 0x0000000080000001, 0xff, true},
    { 0x00000000fffffffe, 0xff, true},
    { 0x00000000ffffffff, 0xff, true},
    { 0x0000000100000000, 0xff, true},
    { 0x0000000200000000, 0xff, true},
    { 0x7ffffffffffffffe, 0xff, true},
    { 0x7fffffffffffffff, 0xff, true},
    { 0x8000000000000000, 0xff, true},
    { 0x8000000000000001, 0xff, true},
    { 0xfffffffffffffffe, 0xff, true},
    { 0xffffffffffffffff, 0xff, false},
};

void SubVerifyUint64Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int8); ++i )
    {
        unsigned __int64 ret;
        if( SafeSubtract(uint64_int8[i].x, uint64_int8[i].y, ret) != uint64_int8[i].fExpected )
        {
            cerr << "Error in case uint64_int8: ";
            cerr << hex << setw(16) << setfill('0') << uint64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_int8[i].y) << ", ";
            cerr << "expected = " << uint64_int8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int64> si(uint64_int8[i].x);
            si -= (__int8)uint64_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int8[i].fExpected )
        {
            cerr << "Error in case uint64_int8 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_int8[i].y) << ", ";
            cerr << "expected = " << uint64_int8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int64 x(uint64_int8[i].x);
            x -= SafeInt<__int8>(uint64_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int8[i].fExpected )
        {
            cerr << "Error in case uint64_int8 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << uint64_int8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint64_int8[i].y) << ", ";
            cerr << "expected = " << uint64_int8[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, __int64 > uint8_int64[] =
{
    { 0x00, 0x0000000000000000, true},
    { 0x01, 0x0000000000000000, true},
    { 0x02, 0x0000000000000000, true},
    { 0x7e, 0x0000000000000000, true},
    { 0x7f, 0x0000000000000000, true},
    { 0x80, 0x0000000000000000, true},
    { 0x81, 0x0000000000000000, true},
    { 0xfe, 0x0000000000000000, true},
    { 0xff, 0x0000000000000000, true},

    { 0x00, 0x0000000000000001, false},
    { 0x01, 0x0000000000000001, true},
    { 0x02, 0x0000000000000001, true},
    { 0x7e, 0x0000000000000001, true},
    { 0x7f, 0x0000000000000001, true},
    { 0x80, 0x0000000000000001, true},
    { 0x81, 0x0000000000000001, true},
    { 0xfe, 0x0000000000000001, true},
    { 0xff, 0x0000000000000001, true},

    { 0x00, 0x0000000000000002, false},
    { 0x01, 0x0000000000000002, false},
    { 0x02, 0x0000000000000002, true},
    { 0x7e, 0x0000000000000002, true},
    { 0x7f, 0x0000000000000002, true},
    { 0x80, 0x0000000000000002, true},
    { 0x81, 0x0000000000000002, true},
    { 0xfe, 0x0000000000000002, true},
    { 0xff, 0x0000000000000002, true},

    { 0x00, 0x000000007ffffffe, false},
    { 0x01, 0x000000007ffffffe, false},
    { 0x02, 0x000000007ffffffe, false},
    { 0x7e, 0x000000007ffffffe, false},
    { 0x7f, 0x000000007ffffffe, false},
    { 0x80, 0x000000007ffffffe, false},
    { 0x81, 0x000000007ffffffe, false},
    { 0xfe, 0x000000007ffffffe, false},
    { 0xff, 0x000000007ffffffe, false},

    { 0x00, 0x000000007fffffff, false},
    { 0x01, 0x000000007fffffff, false},
    { 0x02, 0x000000007fffffff, false},
    { 0x7e, 0x000000007fffffff, false},
    { 0x7f, 0x000000007fffffff, false},
    { 0x80, 0x000000007fffffff, false},
    { 0x81, 0x000000007fffffff, false},
    { 0xfe, 0x000000007fffffff, false},
    { 0xff, 0x000000007fffffff, false},

    { 0x00, 0x0000000080000000, false},
    { 0x01, 0x0000000080000000, false},
    { 0x02, 0x0000000080000000, false},
    { 0x7e, 0x0000000080000000, false},
    { 0x7f, 0x0000000080000000, false},
    { 0x80, 0x0000000080000000, false},
    { 0x81, 0x0000000080000000, false},
    { 0xfe, 0x0000000080000000, false},
    { 0xff, 0x0000000080000000, false},

    { 0x00, 0x0000000080000001, false},
    { 0x01, 0x0000000080000001, false},
    { 0x02, 0x0000000080000001, false},
    { 0x7e, 0x0000000080000001, false},
    { 0x7f, 0x0000000080000001, false},
    { 0x80, 0x0000000080000001, false},
    { 0x81, 0x0000000080000001, false},
    { 0xfe, 0x0000000080000001, false},
    { 0xff, 0x0000000080000001, false},

    { 0x00, 0x00000000fffffffe, false},
    { 0x01, 0x00000000fffffffe, false},
    { 0x02, 0x00000000fffffffe, false},
    { 0x7e, 0x00000000fffffffe, false},
    { 0x7f, 0x00000000fffffffe, false},
    { 0x80, 0x00000000fffffffe, false},
    { 0x81, 0x00000000fffffffe, false},
    { 0xfe, 0x00000000fffffffe, false},
    { 0xff, 0x00000000fffffffe, false},

    { 0x00, 0x00000000ffffffff, false},
    { 0x01, 0x00000000ffffffff, false},
    { 0x02, 0x00000000ffffffff, false},
    { 0x7e, 0x00000000ffffffff, false},
    { 0x7f, 0x00000000ffffffff, false},
    { 0x80, 0x00000000ffffffff, false},
    { 0x81, 0x00000000ffffffff, false},
    { 0xfe, 0x00000000ffffffff, false},
    { 0xff, 0x00000000ffffffff, false},

    { 0x00, 0x0000000100000000, false},
    { 0x01, 0x0000000100000000, false},
    { 0x02, 0x0000000100000000, false},
    { 0x7e, 0x0000000100000000, false},
    { 0x7f, 0x0000000100000000, false},
    { 0x80, 0x0000000100000000, false},
    { 0x81, 0x0000000100000000, false},
    { 0xfe, 0x0000000100000000, false},
    { 0xff, 0x0000000100000000, false},

    { 0x00, 0x0000000200000000, false},
    { 0x01, 0x0000000200000000, false},
    { 0x02, 0x0000000200000000, false},
    { 0x7e, 0x0000000200000000, false},
    { 0x7f, 0x0000000200000000, false},
    { 0x80, 0x0000000200000000, false},
    { 0x81, 0x0000000200000000, false},
    { 0xfe, 0x0000000200000000, false},
    { 0xff, 0x0000000200000000, false},

    { 0x00, 0x7ffffffffffffffe, false},
    { 0x01, 0x7ffffffffffffffe, false},
    { 0x02, 0x7ffffffffffffffe, false},
    { 0x7e, 0x7ffffffffffffffe, false},
    { 0x7f, 0x7ffffffffffffffe, false},
    { 0x80, 0x7ffffffffffffffe, false},
    { 0x81, 0x7ffffffffffffffe, false},
    { 0xfe, 0x7ffffffffffffffe, false},
    { 0xff, 0x7ffffffffffffffe, false},

    { 0x00, 0x7fffffffffffffff, false},
    { 0x01, 0x7fffffffffffffff, false},
    { 0x02, 0x7fffffffffffffff, false},
    { 0x7e, 0x7fffffffffffffff, false},
    { 0x7f, 0x7fffffffffffffff, false},
    { 0x80, 0x7fffffffffffffff, false},
    { 0x81, 0x7fffffffffffffff, false},
    { 0xfe, 0x7fffffffffffffff, false},
    { 0xff, 0x7fffffffffffffff, false},

    { 0x00, 0x8000000000000000, false},
    { 0x01, 0x8000000000000000, false},
    { 0x02, 0x8000000000000000, false},
    { 0x7e, 0x8000000000000000, false},
    { 0x7f, 0x8000000000000000, false},
    { 0x80, 0x8000000000000000, false},
    { 0x81, 0x8000000000000000, false},
    { 0xfe, 0x8000000000000000, false},
    { 0xff, 0x8000000000000000, false},

    { 0x00, 0x8000000000000001, false},
    { 0x01, 0x8000000000000001, false},
    { 0x02, 0x8000000000000001, false},
    { 0x7e, 0x8000000000000001, false},
    { 0x7f, 0x8000000000000001, false},
    { 0x80, 0x8000000000000001, false},
    { 0x81, 0x8000000000000001, false},
    { 0xfe, 0x8000000000000001, false},
    { 0xff, 0x8000000000000001, false},

    { 0x00, 0xfffffffffffffffe, true},
    { 0x01, 0xfffffffffffffffe, true},
    { 0x02, 0xfffffffffffffffe, true},
    { 0x7e, 0xfffffffffffffffe, true},
    { 0x7f, 0xfffffffffffffffe, true},
    { 0x80, 0xfffffffffffffffe, true},
    { 0x81, 0xfffffffffffffffe, true},
    { 0xfe, 0xfffffffffffffffe, false},
    { 0xff, 0xfffffffffffffffe, false},

    { 0x00, 0xffffffffffffffff, true},
    { 0x01, 0xffffffffffffffff, true},
    { 0x02, 0xffffffffffffffff, true},
    { 0x7e, 0xffffffffffffffff, true},
    { 0x7f, 0xffffffffffffffff, true},
    { 0x80, 0xffffffffffffffff, true},
    { 0x81, 0xffffffffffffffff, true},
    { 0xfe, 0xffffffffffffffff, true},
    { 0xff, 0xffffffffffffffff, false},
};

void SubVerifyUint8Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int64); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_int64[i].x, uint8_int64[i].y, ret) != uint8_int64[i].fExpected )
        {
            cerr << "Error in case uint8_int64: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_int64[i].y << ", ";
            cerr << "expected = " << uint8_int64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_int64[i].x);
            si -= uint8_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int64[i].fExpected )
        {
            cerr << "Error in case uint8_int64 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_int64[i].y << ", ";
            cerr << "expected = " << uint8_int64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_int64[i].x);
            x -= SafeInt<__int64>(uint8_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int64[i].fExpected )
        {
            cerr << "Error in case uint8_int64 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << uint8_int64[i].y << ", ";
            cerr << "expected = " << uint8_int64[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, __int32 > uint8_int32[] =
{
    { 0x00, 0x00000000, true},
    { 0x01, 0x00000000, true},
    { 0x02, 0x00000000, true},
    { 0x7e, 0x00000000, true},
    { 0x7f, 0x00000000, true},
    { 0x80, 0x00000000, true},
    { 0x81, 0x00000000, true},
    { 0xfe, 0x00000000, true},
    { 0xff, 0x00000000, true},

    { 0x00, 0x00000001, false},
    { 0x01, 0x00000001, true},
    { 0x02, 0x00000001, true},
    { 0x7e, 0x00000001, true},
    { 0x7f, 0x00000001, true},
    { 0x80, 0x00000001, true},
    { 0x81, 0x00000001, true},
    { 0xfe, 0x00000001, true},
    { 0xff, 0x00000001, true},

    { 0x00, 0x00000002, false},
    { 0x01, 0x00000002, false},
    { 0x02, 0x00000002, true},
    { 0x7e, 0x00000002, true},
    { 0x7f, 0x00000002, true},
    { 0x80, 0x00000002, true},
    { 0x81, 0x00000002, true},
    { 0xfe, 0x00000002, true},
    { 0xff, 0x00000002, true},

    { 0x00, 0x7ffffffe, false},
    { 0x01, 0x7ffffffe, false},
    { 0x02, 0x7ffffffe, false},
    { 0x7e, 0x7ffffffe, false},
    { 0x7f, 0x7ffffffe, false},
    { 0x80, 0x7ffffffe, false},
    { 0x81, 0x7ffffffe, false},
    { 0xfe, 0x7ffffffe, false},
    { 0xff, 0x7ffffffe, false},

    { 0x00, 0x7fffffff, false},
    { 0x01, 0x7fffffff, false},
    { 0x02, 0x7fffffff, false},
    { 0x7e, 0x7fffffff, false},
    { 0x7f, 0x7fffffff, false},
    { 0x80, 0x7fffffff, false},
    { 0x81, 0x7fffffff, false},
    { 0xfe, 0x7fffffff, false},
    { 0xff, 0x7fffffff, false},

    { 0x00, 0x80000000, false},
    { 0x01, 0x80000000, false},
    { 0x02, 0x80000000, false},
    { 0x7e, 0x80000000, false},
    { 0x7f, 0x80000000, false},
    { 0x80, 0x80000000, false},
    { 0x81, 0x80000000, false},
    { 0xfe, 0x80000000, false},
    { 0xff, 0x80000000, false},

    { 0x00, 0x80000001, false},
    { 0x01, 0x80000001, false},
    { 0x02, 0x80000001, false},
    { 0x7e, 0x80000001, false},
    { 0x7f, 0x80000001, false},
    { 0x80, 0x80000001, false},
    { 0x81, 0x80000001, false},
    { 0xfe, 0x80000001, false},
    { 0xff, 0x80000001, false},

    { 0x00, 0xfffffffe, true},
    { 0x01, 0xfffffffe, true},
    { 0x02, 0xfffffffe, true},
    { 0x7e, 0xfffffffe, true},
    { 0x7f, 0xfffffffe, true},
    { 0x80, 0xfffffffe, true},
    { 0x81, 0xfffffffe, true},
    { 0xfe, 0xfffffffe, false},
    { 0xff, 0xfffffffe, false},

    { 0x00, 0xffffffff, true},
    { 0x01, 0xffffffff, true},
    { 0x02, 0xffffffff, true},
    { 0x7e, 0xffffffff, true},
    { 0x7f, 0xffffffff, true},
    { 0x80, 0xffffffff, true},
    { 0x81, 0xffffffff, true},
    { 0xfe, 0xffffffff, true},
    { 0xff, 0xffffffff, false},
};

void SubVerifyUint8Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int32); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_int32[i].x, uint8_int32[i].y, ret) != uint8_int32[i].fExpected )
        {
            cerr << "Error in case uint8_int32: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_int32[i].y << ", ";
            cerr << "expected = " << uint8_int32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_int32[i].x);
            si -= uint8_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int32[i].fExpected )
        {
            cerr << "Error in case uint8_int32 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_int32[i].y << ", ";
            cerr << "expected = " << uint8_int32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_int32[i].x);
            x -= SafeInt<__int32>(uint8_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int32[i].fExpected )
        {
            cerr << "Error in case uint8_int32 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << uint8_int32[i].y << ", ";
            cerr << "expected = " << uint8_int32[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, __int16 > uint8_int16[] =
{
    { 0x00, 0x0000, true},
    { 0x01, 0x0000, true},
    { 0x02, 0x0000, true},
    { 0x7e, 0x0000, true},
    { 0x7f, 0x0000, true},
    { 0x80, 0x0000, true},
    { 0x81, 0x0000, true},
    { 0xfe, 0x0000, true},
    { 0xff, 0x0000, true},

    { 0x00, 0x0001, false},
    { 0x01, 0x0001, true},
    { 0x02, 0x0001, true},
    { 0x7e, 0x0001, true},
    { 0x7f, 0x0001, true},
    { 0x80, 0x0001, true},
    { 0x81, 0x0001, true},
    { 0xfe, 0x0001, true},
    { 0xff, 0x0001, true},

    { 0x00, 0x0002, false},
    { 0x01, 0x0002, false},
    { 0x02, 0x0002, true},
    { 0x7e, 0x0002, true},
    { 0x7f, 0x0002, true},
    { 0x80, 0x0002, true},
    { 0x81, 0x0002, true},
    { 0xfe, 0x0002, true},
    { 0xff, 0x0002, true},

    { 0x00, 0x7ffe, false},
    { 0x01, 0x7ffe, false},
    { 0x02, 0x7ffe, false},
    { 0x7e, 0x7ffe, false},
    { 0x7f, 0x7ffe, false},
    { 0x80, 0x7ffe, false},
    { 0x81, 0x7ffe, false},
    { 0xfe, 0x7ffe, false},
    { 0xff, 0x7ffe, false},

    { 0x00, 0x7fff, false},
    { 0x01, 0x7fff, false},
    { 0x02, 0x7fff, false},
    { 0x7e, 0x7fff, false},
    { 0x7f, 0x7fff, false},
    { 0x80, 0x7fff, false},
    { 0x81, 0x7fff, false},
    { 0xfe, 0x7fff, false},
    { 0xff, 0x7fff, false},

    { 0x00, 0x8000, false},
    { 0x01, 0x8000, false},
    { 0x02, 0x8000, false},
    { 0x7e, 0x8000, false},
    { 0x7f, 0x8000, false},
    { 0x80, 0x8000, false},
    { 0x81, 0x8000, false},
    { 0xfe, 0x8000, false},
    { 0xff, 0x8000, false},

    { 0x00, 0x8001, false},
    { 0x01, 0x8001, false},
    { 0x02, 0x8001, false},
    { 0x7e, 0x8001, false},
    { 0x7f, 0x8001, false},
    { 0x80, 0x8001, false},
    { 0x81, 0x8001, false},
    { 0xfe, 0x8001, false},
    { 0xff, 0x8001, false},

    { 0x00, 0xfffe, true},
    { 0x01, 0xfffe, true},
    { 0x02, 0xfffe, true},
    { 0x7e, 0xfffe, true},
    { 0x7f, 0xfffe, true},
    { 0x80, 0xfffe, true},
    { 0x81, 0xfffe, true},
    { 0xfe, 0xfffe, false},
    { 0xff, 0xfffe, false},

    { 0x00, 0xffff, true},
    { 0x01, 0xffff, true},
    { 0x02, 0xffff, true},
    { 0x7e, 0xffff, true},
    { 0x7f, 0xffff, true},
    { 0x80, 0xffff, true},
    { 0x81, 0xffff, true},
    { 0xfe, 0xffff, true},
    { 0xff, 0xffff, false},
};

void SubVerifyUint8Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int16); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_int16[i].x, uint8_int16[i].y, ret) != uint8_int16[i].fExpected )
        {
            cerr << "Error in case uint8_int16: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_int16[i].y << ", ";
            cerr << "expected = " << uint8_int16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_int16[i].x);
            si -= uint8_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int16[i].fExpected )
        {
            cerr << "Error in case uint8_int16 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_int16[i].y << ", ";
            cerr << "expected = " << uint8_int16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_int16[i].x);
            x -= SafeInt<__int16>(uint8_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int16[i].fExpected )
        {
            cerr << "Error in case uint8_int16 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << uint8_int16[i].y << ", ";
            cerr << "expected = " << uint8_int16[i].fExpected << endl;
        }
    }
}

static const SubTest< unsigned __int8, __int8 > uint8_int8[] =
{
    { 0x00, 0x00, true},
    { 0x01, 0x00, true},
    { 0x02, 0x00, true},
    { 0x7e, 0x00, true},
    { 0x7f, 0x00, true},
    { 0x80, 0x00, true},
    { 0x81, 0x00, true},
    { 0xfe, 0x00, true},
    { 0xff, 0x00, true},

    { 0x00, 0x01, false},
    { 0x01, 0x01, true},
    { 0x02, 0x01, true},
    { 0x7e, 0x01, true},
    { 0x7f, 0x01, true},
    { 0x80, 0x01, true},
    { 0x81, 0x01, true},
    { 0xfe, 0x01, true},
    { 0xff, 0x01, true},

    { 0x00, 0x02, false},
    { 0x01, 0x02, false},
    { 0x02, 0x02, true},
    { 0x7e, 0x02, true},
    { 0x7f, 0x02, true},
    { 0x80, 0x02, true},
    { 0x81, 0x02, true},
    { 0xfe, 0x02, true},
    { 0xff, 0x02, true},

    { 0x00, 0x7e, false},
    { 0x01, 0x7e, false},
    { 0x02, 0x7e, false},
    { 0x7e, 0x7e, true},
    { 0x7f, 0x7e, true},
    { 0x80, 0x7e, true},
    { 0x81, 0x7e, true},
    { 0xfe, 0x7e, true},
    { 0xff, 0x7e, true},

    { 0x00, 0x7f, false},
    { 0x01, 0x7f, false},
    { 0x02, 0x7f, false},
    { 0x7e, 0x7f, false},
    { 0x7f, 0x7f, true},
    { 0x80, 0x7f, true},
    { 0x81, 0x7f, true},
    { 0xfe, 0x7f, true},
    { 0xff, 0x7f, true},

    { 0x00, 0x80, true},
    { 0x01, 0x80, true},
    { 0x02, 0x80, true},
    { 0x7e, 0x80, true},
    { 0x7f, 0x80, true},
    { 0x80, 0x80, false},
    { 0x81, 0x80, false},
    { 0xfe, 0x80, false},
    { 0xff, 0x80, false},

    { 0x00, 0x81, true},
    { 0x01, 0x81, true},
    { 0x02, 0x81, true},
    { 0x7e, 0x81, true},
    { 0x7f, 0x81, true},
    { 0x80, 0x81, true},
    { 0x81, 0x81, false},
    { 0xfe, 0x81, false},
    { 0xff, 0x81, false},

    { 0x00, 0xfe, true},
    { 0x01, 0xfe, true},
    { 0x02, 0xfe, true},
    { 0x7e, 0xfe, true},
    { 0x7f, 0xfe, true},
    { 0x80, 0xfe, true},
    { 0x81, 0xfe, true},
    { 0xfe, 0xfe, false},
    { 0xff, 0xfe, false},

    { 0x00, 0xff, true},
    { 0x01, 0xff, true},
    { 0x02, 0xff, true},
    { 0x7e, 0xff, true},
    { 0x7f, 0xff, true},
    { 0x80, 0xff, true},
    { 0x81, 0xff, true},
    { 0xfe, 0xff, true},
    { 0xff, 0xff, false},
};

void SubVerifyUint8Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int8); ++i )
    {
        unsigned __int8 ret;
        if( SafeSubtract(uint8_int8[i].x, uint8_int8[i].y, ret) != uint8_int8[i].fExpected )
        {
            cerr << "Error in case uint8_int8: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].y) << ", ";
            cerr << "expected = " << uint8_int8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<unsigned __int8> si(uint8_int8[i].x);
            si -= uint8_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int8[i].fExpected )
        {
            cerr << "Error in case uint8_int8 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].y) << ", ";
            cerr << "expected = " << uint8_int8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            unsigned __int8 x(uint8_int8[i].x);
            x -= SafeInt<__int8>(uint8_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int8[i].fExpected )
        {
            cerr << "Error in case uint8_int8 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)uint8_int8[i].y) << ", ";
            cerr << "expected = " << uint8_int8[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, unsigned __int64 > int64_uint64[] =
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
    { 0x8000000000000000, 0x0000000000000001, false},
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
    { 0x7ffffffffffffffe, 0x0000000000000002, true},
    { 0x7fffffffffffffff, 0x0000000000000002, true},
    { 0x8000000000000000, 0x0000000000000002, false},
    { 0x8000000000000001, 0x0000000000000002, false},
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
    { 0x7ffffffffffffffe, 0x000000007ffffffe, true},
    { 0x7fffffffffffffff, 0x000000007ffffffe, true},
    { 0x8000000000000000, 0x000000007ffffffe, false},
    { 0x8000000000000001, 0x000000007ffffffe, false},
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
    { 0x7ffffffffffffffe, 0x000000007fffffff, true},
    { 0x7fffffffffffffff, 0x000000007fffffff, true},
    { 0x8000000000000000, 0x000000007fffffff, false},
    { 0x8000000000000001, 0x000000007fffffff, false},
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
    { 0x7ffffffffffffffe, 0x0000000080000000, true},
    { 0x7fffffffffffffff, 0x0000000080000000, true},
    { 0x8000000000000000, 0x0000000080000000, false},
    { 0x8000000000000001, 0x0000000080000000, false},
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
    { 0x7ffffffffffffffe, 0x0000000080000001, true},
    { 0x7fffffffffffffff, 0x0000000080000001, true},
    { 0x8000000000000000, 0x0000000080000001, false},
    { 0x8000000000000001, 0x0000000080000001, false},
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
    { 0x7ffffffffffffffe, 0x00000000fffffffe, true},
    { 0x7fffffffffffffff, 0x00000000fffffffe, true},
    { 0x8000000000000000, 0x00000000fffffffe, false},
    { 0x8000000000000001, 0x00000000fffffffe, false},
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
    { 0x7ffffffffffffffe, 0x00000000ffffffff, true},
    { 0x7fffffffffffffff, 0x00000000ffffffff, true},
    { 0x8000000000000000, 0x00000000ffffffff, false},
    { 0x8000000000000001, 0x00000000ffffffff, false},
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
    { 0x7ffffffffffffffe, 0x0000000100000000, true},
    { 0x7fffffffffffffff, 0x0000000100000000, true},
    { 0x8000000000000000, 0x0000000100000000, false},
    { 0x8000000000000001, 0x0000000100000000, false},
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
    { 0x7ffffffffffffffe, 0x0000000200000000, true},
    { 0x7fffffffffffffff, 0x0000000200000000, true},
    { 0x8000000000000000, 0x0000000200000000, false},
    { 0x8000000000000001, 0x0000000200000000, false},
    { 0xfffffffffffffffe, 0x0000000200000000, true},
    { 0xffffffffffffffff, 0x0000000200000000, true},

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
    { 0x8000000000000000, 0x7ffffffffffffffe, false},
    { 0x8000000000000001, 0x7ffffffffffffffe, false},
    { 0xfffffffffffffffe, 0x7ffffffffffffffe, true},
    { 0xffffffffffffffff, 0x7ffffffffffffffe, true},

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
    { 0x8000000000000000, 0x7fffffffffffffff, false},
    { 0x8000000000000001, 0x7fffffffffffffff, false},
    { 0xfffffffffffffffe, 0x7fffffffffffffff, false},
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

    { 0x0000000000000000, 0x8000000000000001, false},
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
    { 0x7ffffffffffffffe, 0xfffffffffffffffe, true},
    { 0x7fffffffffffffff, 0xfffffffffffffffe, true},
    { 0x8000000000000000, 0xfffffffffffffffe, false},
    { 0x8000000000000001, 0xfffffffffffffffe, false},
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
    { 0x7fffffffffffffff, 0xffffffffffffffff, true},
    { 0x8000000000000000, 0xffffffffffffffff, false},
    { 0x8000000000000001, 0xffffffffffffffff, false},
    { 0xfffffffffffffffe, 0xffffffffffffffff, false},
    { 0xffffffffffffffff, 0xffffffffffffffff, false},
};

void SubVerifyInt64Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint64); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
        {
            cerr << "Error in case int64_uint64: ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].y << ", ";
            cerr << "expected = " << int64_uint64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_uint64[i].x);
            si -= int64_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint64[i].fExpected )
        {
            cerr << "Error in case int64_uint64 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].y << ", ";
            cerr << "expected = " << int64_uint64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_uint64[i].x);
            x -= SafeInt<unsigned __int64>(int64_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint64[i].fExpected )
        {
            cerr << "Error in case int64_uint64 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].x << ", ";
            cerr << hex << setw(16) << setfill('0') << int64_uint64[i].y << ", ";
            cerr << "expected = " << int64_uint64[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, unsigned __int32 > int64_uint32[] =
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
    { 0x8000000000000000, 0x00000001, false},
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
    { 0x7ffffffffffffffe, 0x00000002, true},
    { 0x7fffffffffffffff, 0x00000002, true},
    { 0x8000000000000000, 0x00000002, false},
    { 0x8000000000000001, 0x00000002, false},
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
    { 0x7ffffffffffffffe, 0x7ffffffe, true},
    { 0x7fffffffffffffff, 0x7ffffffe, true},
    { 0x8000000000000000, 0x7ffffffe, false},
    { 0x8000000000000001, 0x7ffffffe, false},
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
    { 0x7ffffffffffffffe, 0x7fffffff, true},
    { 0x7fffffffffffffff, 0x7fffffff, true},
    { 0x8000000000000000, 0x7fffffff, false},
    { 0x8000000000000001, 0x7fffffff, false},
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
    { 0x8000000000000001, 0xffffffff, false},
    { 0xfffffffffffffffe, 0xffffffff, true},
    { 0xffffffffffffffff, 0xffffffff, true},
};

void SubVerifyInt64Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint32); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_uint32[i].x, int64_uint32[i].y, ret) != int64_uint32[i].fExpected )
        {
            cerr << "Error in case int64_uint32: ";
            cerr << hex << setw(16) << setfill('0') << int64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_uint32[i].y << ", ";
            cerr << "expected = " << int64_uint32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_uint32[i].x);
            si -= int64_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint32[i].fExpected )
        {
            cerr << "Error in case int64_uint32 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_uint32[i].y << ", ";
            cerr << "expected = " << int64_uint32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_uint32[i].x);
            x -= SafeInt<unsigned __int32>(int64_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint32[i].fExpected )
        {
            cerr << "Error in case int64_uint32 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint32[i].x << ", ";
            cerr << hex << setw(8) << setfill('0') << int64_uint32[i].y << ", ";
            cerr << "expected = " << int64_uint32[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, unsigned __int16 > int64_uint16[] =
{
    { 0x0000000000000000, 0x0000, true},
    { 0x0000000000000001, 0x0000, true},
    { 0x0000000000000002, 0x0000, true},
    { 0x000000007ffffffe, 0x0000, true},
    { 0x000000007fffffff, 0x0000, true},
    { 0x0000000080000000, 0x0000, true},
    { 0x0000000080000001, 0x0000, true},
    { 0x00000000fffffffe, 0x0000, true},
    { 0x00000000ffffffff, 0x0000, true},
    { 0x0000000100000000, 0x0000, true},
    { 0x0000000200000000, 0x0000, true},
    { 0x7ffffffffffffffe, 0x0000, true},
    { 0x7fffffffffffffff, 0x0000, true},
    { 0x8000000000000000, 0x0000, true},
    { 0x8000000000000001, 0x0000, true},
    { 0xfffffffffffffffe, 0x0000, true},
    { 0xffffffffffffffff, 0x0000, true},

    { 0x0000000000000000, 0x0001, true},
    { 0x0000000000000001, 0x0001, true},
    { 0x0000000000000002, 0x0001, true},
    { 0x000000007ffffffe, 0x0001, true},
    { 0x000000007fffffff, 0x0001, true},
    { 0x0000000080000000, 0x0001, true},
    { 0x0000000080000001, 0x0001, true},
    { 0x00000000fffffffe, 0x0001, true},
    { 0x00000000ffffffff, 0x0001, true},
    { 0x0000000100000000, 0x0001, true},
    { 0x0000000200000000, 0x0001, true},
    { 0x7ffffffffffffffe, 0x0001, true},
    { 0x7fffffffffffffff, 0x0001, true},
    { 0x8000000000000000, 0x0001, false},
    { 0x8000000000000001, 0x0001, true},
    { 0xfffffffffffffffe, 0x0001, true},
    { 0xffffffffffffffff, 0x0001, true},

    { 0x0000000000000000, 0x0002, true},
    { 0x0000000000000001, 0x0002, true},
    { 0x0000000000000002, 0x0002, true},
    { 0x000000007ffffffe, 0x0002, true},
    { 0x000000007fffffff, 0x0002, true},
    { 0x0000000080000000, 0x0002, true},
    { 0x0000000080000001, 0x0002, true},
    { 0x00000000fffffffe, 0x0002, true},
    { 0x00000000ffffffff, 0x0002, true},
    { 0x0000000100000000, 0x0002, true},
    { 0x0000000200000000, 0x0002, true},
    { 0x7ffffffffffffffe, 0x0002, true},
    { 0x7fffffffffffffff, 0x0002, true},
    { 0x8000000000000000, 0x0002, false},
    { 0x8000000000000001, 0x0002, false},
    { 0xfffffffffffffffe, 0x0002, true},
    { 0xffffffffffffffff, 0x0002, true},

    { 0x0000000000000000, 0x7ffe, true},
    { 0x0000000000000001, 0x7ffe, true},
    { 0x0000000000000002, 0x7ffe, true},
    { 0x000000007ffffffe, 0x7ffe, true},
    { 0x000000007fffffff, 0x7ffe, true},
    { 0x0000000080000000, 0x7ffe, true},
    { 0x0000000080000001, 0x7ffe, true},
    { 0x00000000fffffffe, 0x7ffe, true},
    { 0x00000000ffffffff, 0x7ffe, true},
    { 0x0000000100000000, 0x7ffe, true},
    { 0x0000000200000000, 0x7ffe, true},
    { 0x7ffffffffffffffe, 0x7ffe, true},
    { 0x7fffffffffffffff, 0x7ffe, true},
    { 0x8000000000000000, 0x7ffe, false},
    { 0x8000000000000001, 0x7ffe, false},
    { 0xfffffffffffffffe, 0x7ffe, true},
    { 0xffffffffffffffff, 0x7ffe, true},

    { 0x0000000000000000, 0x7fff, true},
    { 0x0000000000000001, 0x7fff, true},
    { 0x0000000000000002, 0x7fff, true},
    { 0x000000007ffffffe, 0x7fff, true},
    { 0x000000007fffffff, 0x7fff, true},
    { 0x0000000080000000, 0x7fff, true},
    { 0x0000000080000001, 0x7fff, true},
    { 0x00000000fffffffe, 0x7fff, true},
    { 0x00000000ffffffff, 0x7fff, true},
    { 0x0000000100000000, 0x7fff, true},
    { 0x0000000200000000, 0x7fff, true},
    { 0x7ffffffffffffffe, 0x7fff, true},
    { 0x7fffffffffffffff, 0x7fff, true},
    { 0x8000000000000000, 0x7fff, false},
    { 0x8000000000000001, 0x7fff, false},
    { 0xfffffffffffffffe, 0x7fff, true},
    { 0xffffffffffffffff, 0x7fff, true},

    { 0x0000000000000000, 0x8000, true},
    { 0x0000000000000001, 0x8000, true},
    { 0x0000000000000002, 0x8000, true},
    { 0x000000007ffffffe, 0x8000, true},
    { 0x000000007fffffff, 0x8000, true},
    { 0x0000000080000000, 0x8000, true},
    { 0x0000000080000001, 0x8000, true},
    { 0x00000000fffffffe, 0x8000, true},
    { 0x00000000ffffffff, 0x8000, true},
    { 0x0000000100000000, 0x8000, true},
    { 0x0000000200000000, 0x8000, true},
    { 0x7ffffffffffffffe, 0x8000, true},
    { 0x7fffffffffffffff, 0x8000, true},
    { 0x8000000000000000, 0x8000, false},
    { 0x8000000000000001, 0x8000, false},
    { 0xfffffffffffffffe, 0x8000, true},
    { 0xffffffffffffffff, 0x8000, true},

    { 0x0000000000000000, 0x8001, true},
    { 0x0000000000000001, 0x8001, true},
    { 0x0000000000000002, 0x8001, true},
    { 0x000000007ffffffe, 0x8001, true},
    { 0x000000007fffffff, 0x8001, true},
    { 0x0000000080000000, 0x8001, true},
    { 0x0000000080000001, 0x8001, true},
    { 0x00000000fffffffe, 0x8001, true},
    { 0x00000000ffffffff, 0x8001, true},
    { 0x0000000100000000, 0x8001, true},
    { 0x0000000200000000, 0x8001, true},
    { 0x7ffffffffffffffe, 0x8001, true},
    { 0x7fffffffffffffff, 0x8001, true},
    { 0x8000000000000000, 0x8001, false},
    { 0x8000000000000001, 0x8001, false},
    { 0xfffffffffffffffe, 0x8001, true},
    { 0xffffffffffffffff, 0x8001, true},

    { 0x0000000000000000, 0xfffe, true},
    { 0x0000000000000001, 0xfffe, true},
    { 0x0000000000000002, 0xfffe, true},
    { 0x000000007ffffffe, 0xfffe, true},
    { 0x000000007fffffff, 0xfffe, true},
    { 0x0000000080000000, 0xfffe, true},
    { 0x0000000080000001, 0xfffe, true},
    { 0x00000000fffffffe, 0xfffe, true},
    { 0x00000000ffffffff, 0xfffe, true},
    { 0x0000000100000000, 0xfffe, true},
    { 0x0000000200000000, 0xfffe, true},
    { 0x7ffffffffffffffe, 0xfffe, true},
    { 0x7fffffffffffffff, 0xfffe, true},
    { 0x8000000000000000, 0xfffe, false},
    { 0x8000000000000001, 0xfffe, false},
    { 0xfffffffffffffffe, 0xfffe, true},
    { 0xffffffffffffffff, 0xfffe, true},

    { 0x0000000000000000, 0xffff, true},
    { 0x0000000000000001, 0xffff, true},
    { 0x0000000000000002, 0xffff, true},
    { 0x000000007ffffffe, 0xffff, true},
    { 0x000000007fffffff, 0xffff, true},
    { 0x0000000080000000, 0xffff, true},
    { 0x0000000080000001, 0xffff, true},
    { 0x00000000fffffffe, 0xffff, true},
    { 0x00000000ffffffff, 0xffff, true},
    { 0x0000000100000000, 0xffff, true},
    { 0x0000000200000000, 0xffff, true},
    { 0x7ffffffffffffffe, 0xffff, true},
    { 0x7fffffffffffffff, 0xffff, true},
    { 0x8000000000000000, 0xffff, false},
    { 0x8000000000000001, 0xffff, false},
    { 0xfffffffffffffffe, 0xffff, true},
    { 0xffffffffffffffff, 0xffff, true},
};

void SubVerifyInt64Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint16); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_uint16[i].x, int64_uint16[i].y, ret) != int64_uint16[i].fExpected )
        {
            cerr << "Error in case int64_uint16: ";
            cerr << hex << setw(16) << setfill('0') << int64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_uint16[i].y << ", ";
            cerr << "expected = " << int64_uint16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_uint16[i].x);
            si -= int64_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint16[i].fExpected )
        {
            cerr << "Error in case int64_uint16 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_uint16[i].y << ", ";
            cerr << "expected = " << int64_uint16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_uint16[i].x);
            x -= SafeInt<unsigned __int16>(int64_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint16[i].fExpected )
        {
            cerr << "Error in case int64_uint16 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint16[i].x << ", ";
            cerr << hex << setw(4) << setfill('0') << int64_uint16[i].y << ", ";
            cerr << "expected = " << int64_uint16[i].fExpected << endl;
        }
    }
}

static const SubTest< __int64, unsigned __int8 > int64_uint8[] =
{
    { 0x0000000000000000, 0x00, true},
    { 0x0000000000000001, 0x00, true},
    { 0x0000000000000002, 0x00, true},
    { 0x000000007ffffffe, 0x00, true},
    { 0x000000007fffffff, 0x00, true},
    { 0x0000000080000000, 0x00, true},
    { 0x0000000080000001, 0x00, true},
    { 0x00000000fffffffe, 0x00, true},
    { 0x00000000ffffffff, 0x00, true},
    { 0x0000000100000000, 0x00, true},
    { 0x0000000200000000, 0x00, true},
    { 0x7ffffffffffffffe, 0x00, true},
    { 0x7fffffffffffffff, 0x00, true},
    { 0x8000000000000000, 0x00, true},
    { 0x8000000000000001, 0x00, true},
    { 0xfffffffffffffffe, 0x00, true},
    { 0xffffffffffffffff, 0x00, true},

    { 0x0000000000000000, 0x01, true},
    { 0x0000000000000001, 0x01, true},
    { 0x0000000000000002, 0x01, true},
    { 0x000000007ffffffe, 0x01, true},
    { 0x000000007fffffff, 0x01, true},
    { 0x0000000080000000, 0x01, true},
    { 0x0000000080000001, 0x01, true},
    { 0x00000000fffffffe, 0x01, true},
    { 0x00000000ffffffff, 0x01, true},
    { 0x0000000100000000, 0x01, true},
    { 0x0000000200000000, 0x01, true},
    { 0x7ffffffffffffffe, 0x01, true},
    { 0x7fffffffffffffff, 0x01, true},
    { 0x8000000000000000, 0x01, false},
    { 0x8000000000000001, 0x01, true},
    { 0xfffffffffffffffe, 0x01, true},
    { 0xffffffffffffffff, 0x01, true},

    { 0x0000000000000000, 0x02, true},
    { 0x0000000000000001, 0x02, true},
    { 0x0000000000000002, 0x02, true},
    { 0x000000007ffffffe, 0x02, true},
    { 0x000000007fffffff, 0x02, true},
    { 0x0000000080000000, 0x02, true},
    { 0x0000000080000001, 0x02, true},
    { 0x00000000fffffffe, 0x02, true},
    { 0x00000000ffffffff, 0x02, true},
    { 0x0000000100000000, 0x02, true},
    { 0x0000000200000000, 0x02, true},
    { 0x7ffffffffffffffe, 0x02, true},
    { 0x7fffffffffffffff, 0x02, true},
    { 0x8000000000000000, 0x02, false},
    { 0x8000000000000001, 0x02, false},
    { 0xfffffffffffffffe, 0x02, true},
    { 0xffffffffffffffff, 0x02, true},

    { 0x0000000000000000, 0x7e, true},
    { 0x0000000000000001, 0x7e, true},
    { 0x0000000000000002, 0x7e, true},
    { 0x000000007ffffffe, 0x7e, true},
    { 0x000000007fffffff, 0x7e, true},
    { 0x0000000080000000, 0x7e, true},
    { 0x0000000080000001, 0x7e, true},
    { 0x00000000fffffffe, 0x7e, true},
    { 0x00000000ffffffff, 0x7e, true},
    { 0x0000000100000000, 0x7e, true},
    { 0x0000000200000000, 0x7e, true},
    { 0x7ffffffffffffffe, 0x7e, true},
    { 0x7fffffffffffffff, 0x7e, true},
    { 0x8000000000000000, 0x7e, false},
    { 0x8000000000000001, 0x7e, false},
    { 0xfffffffffffffffe, 0x7e, true},
    { 0xffffffffffffffff, 0x7e, true},

    { 0x0000000000000000, 0x7f, true},
    { 0x0000000000000001, 0x7f, true},
    { 0x0000000000000002, 0x7f, true},
    { 0x000000007ffffffe, 0x7f, true},
    { 0x000000007fffffff, 0x7f, true},
    { 0x0000000080000000, 0x7f, true},
    { 0x0000000080000001, 0x7f, true},
    { 0x00000000fffffffe, 0x7f, true},
    { 0x00000000ffffffff, 0x7f, true},
    { 0x0000000100000000, 0x7f, true},
    { 0x0000000200000000, 0x7f, true},
    { 0x7ffffffffffffffe, 0x7f, true},
    { 0x7fffffffffffffff, 0x7f, true},
    { 0x8000000000000000, 0x7f, false},
    { 0x8000000000000001, 0x7f, false},
    { 0xfffffffffffffffe, 0x7f, true},
    { 0xffffffffffffffff, 0x7f, true},

    { 0x0000000000000000, 0x80, true},
    { 0x0000000000000001, 0x80, true},
    { 0x0000000000000002, 0x80, true},
    { 0x000000007ffffffe, 0x80, true},
    { 0x000000007fffffff, 0x80, true},
    { 0x0000000080000000, 0x80, true},
    { 0x0000000080000001, 0x80, true},
    { 0x00000000fffffffe, 0x80, true},
    { 0x00000000ffffffff, 0x80, true},
    { 0x0000000100000000, 0x80, true},
    { 0x0000000200000000, 0x80, true},
    { 0x7ffffffffffffffe, 0x80, true},
    { 0x7fffffffffffffff, 0x80, true},
    { 0x8000000000000000, 0x80, false},
    { 0x8000000000000001, 0x80, false},
    { 0xfffffffffffffffe, 0x80, true},
    { 0xffffffffffffffff, 0x80, true},

    { 0x0000000000000000, 0x81, true},
    { 0x0000000000000001, 0x81, true},
    { 0x0000000000000002, 0x81, true},
    { 0x000000007ffffffe, 0x81, true},
    { 0x000000007fffffff, 0x81, true},
    { 0x0000000080000000, 0x81, true},
    { 0x0000000080000001, 0x81, true},
    { 0x00000000fffffffe, 0x81, true},
    { 0x00000000ffffffff, 0x81, true},
    { 0x0000000100000000, 0x81, true},
    { 0x0000000200000000, 0x81, true},
    { 0x7ffffffffffffffe, 0x81, true},
    { 0x7fffffffffffffff, 0x81, true},
    { 0x8000000000000000, 0x81, false},
    { 0x8000000000000001, 0x81, false},
    { 0xfffffffffffffffe, 0x81, true},
    { 0xffffffffffffffff, 0x81, true},

    { 0x0000000000000000, 0xfe, true},
    { 0x0000000000000001, 0xfe, true},
    { 0x0000000000000002, 0xfe, true},
    { 0x000000007ffffffe, 0xfe, true},
    { 0x000000007fffffff, 0xfe, true},
    { 0x0000000080000000, 0xfe, true},
    { 0x0000000080000001, 0xfe, true},
    { 0x00000000fffffffe, 0xfe, true},
    { 0x00000000ffffffff, 0xfe, true},
    { 0x0000000100000000, 0xfe, true},
    { 0x0000000200000000, 0xfe, true},
    { 0x7ffffffffffffffe, 0xfe, true},
    { 0x7fffffffffffffff, 0xfe, true},
    { 0x8000000000000000, 0xfe, false},
    { 0x8000000000000001, 0xfe, false},
    { 0xfffffffffffffffe, 0xfe, true},
    { 0xffffffffffffffff, 0xfe, true},

    { 0x0000000000000000, 0xff, true},
    { 0x0000000000000001, 0xff, true},
    { 0x0000000000000002, 0xff, true},
    { 0x000000007ffffffe, 0xff, true},
    { 0x000000007fffffff, 0xff, true},
    { 0x0000000080000000, 0xff, true},
    { 0x0000000080000001, 0xff, true},
    { 0x00000000fffffffe, 0xff, true},
    { 0x00000000ffffffff, 0xff, true},
    { 0x0000000100000000, 0xff, true},
    { 0x0000000200000000, 0xff, true},
    { 0x7ffffffffffffffe, 0xff, true},
    { 0x7fffffffffffffff, 0xff, true},
    { 0x8000000000000000, 0xff, false},
    { 0x8000000000000001, 0xff, false},
    { 0xfffffffffffffffe, 0xff, true},
    { 0xffffffffffffffff, 0xff, true},
};

void SubVerifyInt64Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint8); ++i )
    {
        __int64 ret;
        if( SafeSubtract(int64_uint8[i].x, int64_uint8[i].y, ret) != int64_uint8[i].fExpected )
        {
            cerr << "Error in case int64_uint8: ";
            cerr << hex << setw(16) << setfill('0') << int64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_uint8[i].y) << ", ";
            cerr << "expected = " << int64_uint8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int64> si(int64_uint8[i].x);
            si -= int64_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint8[i].fExpected )
        {
            cerr << "Error in case int64_uint8 throw (1): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_uint8[i].y) << ", ";
            cerr << "expected = " << int64_uint8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int64 x(int64_uint8[i].x);
            x -= SafeInt<unsigned __int8>(int64_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint8[i].fExpected )
        {
            cerr << "Error in case int64_uint8 throw (2): ";
            cerr << hex << setw(16) << setfill('0') << int64_uint8[i].x << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int64_uint8[i].y) << ", ";
            cerr << "expected = " << int64_uint8[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, unsigned __int64 > int8_uint64[] =
{
    { 0x00, 0x0000000000000000, true},
    { 0x01, 0x0000000000000000, true},
    { 0x02, 0x0000000000000000, true},
    { 0x7e, 0x0000000000000000, true},
    { 0x7f, 0x0000000000000000, true},
    { 0x80, 0x0000000000000000, true},
    { 0x81, 0x0000000000000000, true},
    { 0xfe, 0x0000000000000000, true},
    { 0xff, 0x0000000000000000, true},

    { 0x00, 0x0000000000000001, true},
    { 0x01, 0x0000000000000001, true},
    { 0x02, 0x0000000000000001, true},
    { 0x7e, 0x0000000000000001, true},
    { 0x7f, 0x0000000000000001, true},
    { 0x80, 0x0000000000000001, false},
    { 0x81, 0x0000000000000001, true},
    { 0xfe, 0x0000000000000001, true},
    { 0xff, 0x0000000000000001, true},

    { 0x00, 0x0000000000000002, true},
    { 0x01, 0x0000000000000002, true},
    { 0x02, 0x0000000000000002, true},
    { 0x7e, 0x0000000000000002, true},
    { 0x7f, 0x0000000000000002, true},
    { 0x80, 0x0000000000000002, false},
    { 0x81, 0x0000000000000002, false},
    { 0xfe, 0x0000000000000002, true},
    { 0xff, 0x0000000000000002, true},

    { 0x00, 0x000000007ffffffe, false},
    { 0x01, 0x000000007ffffffe, false},
    { 0x02, 0x000000007ffffffe, false},
    { 0x7e, 0x000000007ffffffe, false},
    { 0x7f, 0x000000007ffffffe, false},
    { 0x80, 0x000000007ffffffe, false},
    { 0x81, 0x000000007ffffffe, false},
    { 0xfe, 0x000000007ffffffe, false},
    { 0xff, 0x000000007ffffffe, false},

    { 0x00, 0x000000007fffffff, false},
    { 0x01, 0x000000007fffffff, false},
    { 0x02, 0x000000007fffffff, false},
    { 0x7e, 0x000000007fffffff, false},
    { 0x7f, 0x000000007fffffff, false},
    { 0x80, 0x000000007fffffff, false},
    { 0x81, 0x000000007fffffff, false},
    { 0xfe, 0x000000007fffffff, false},
    { 0xff, 0x000000007fffffff, false},

    { 0x00, 0x0000000080000000, false},
    { 0x01, 0x0000000080000000, false},
    { 0x02, 0x0000000080000000, false},
    { 0x7e, 0x0000000080000000, false},
    { 0x7f, 0x0000000080000000, false},
    { 0x80, 0x0000000080000000, false},
    { 0x81, 0x0000000080000000, false},
    { 0xfe, 0x0000000080000000, false},
    { 0xff, 0x0000000080000000, false},

    { 0x00, 0x0000000080000001, false},
    { 0x01, 0x0000000080000001, false},
    { 0x02, 0x0000000080000001, false},
    { 0x7e, 0x0000000080000001, false},
    { 0x7f, 0x0000000080000001, false},
    { 0x80, 0x0000000080000001, false},
    { 0x81, 0x0000000080000001, false},
    { 0xfe, 0x0000000080000001, false},
    { 0xff, 0x0000000080000001, false},

    { 0x00, 0x00000000fffffffe, false},
    { 0x01, 0x00000000fffffffe, false},
    { 0x02, 0x00000000fffffffe, false},
    { 0x7e, 0x00000000fffffffe, false},
    { 0x7f, 0x00000000fffffffe, false},
    { 0x80, 0x00000000fffffffe, false},
    { 0x81, 0x00000000fffffffe, false},
    { 0xfe, 0x00000000fffffffe, false},
    { 0xff, 0x00000000fffffffe, false},

    { 0x00, 0x00000000ffffffff, false},
    { 0x01, 0x00000000ffffffff, false},
    { 0x02, 0x00000000ffffffff, false},
    { 0x7e, 0x00000000ffffffff, false},
    { 0x7f, 0x00000000ffffffff, false},
    { 0x80, 0x00000000ffffffff, false},
    { 0x81, 0x00000000ffffffff, false},
    { 0xfe, 0x00000000ffffffff, false},
    { 0xff, 0x00000000ffffffff, false},

    { 0x00, 0x0000000100000000, false},
    { 0x01, 0x0000000100000000, false},
    { 0x02, 0x0000000100000000, false},
    { 0x7e, 0x0000000100000000, false},
    { 0x7f, 0x0000000100000000, false},
    { 0x80, 0x0000000100000000, false},
    { 0x81, 0x0000000100000000, false},
    { 0xfe, 0x0000000100000000, false},
    { 0xff, 0x0000000100000000, false},

    { 0x00, 0x0000000200000000, false},
    { 0x01, 0x0000000200000000, false},
    { 0x02, 0x0000000200000000, false},
    { 0x7e, 0x0000000200000000, false},
    { 0x7f, 0x0000000200000000, false},
    { 0x80, 0x0000000200000000, false},
    { 0x81, 0x0000000200000000, false},
    { 0xfe, 0x0000000200000000, false},
    { 0xff, 0x0000000200000000, false},

    { 0x00, 0x7ffffffffffffffe, false},
    { 0x01, 0x7ffffffffffffffe, false},
    { 0x02, 0x7ffffffffffffffe, false},
    { 0x7e, 0x7ffffffffffffffe, false},
    { 0x7f, 0x7ffffffffffffffe, false},
    { 0x80, 0x7ffffffffffffffe, false},
    { 0x81, 0x7ffffffffffffffe, false},
    { 0xfe, 0x7ffffffffffffffe, false},
    { 0xff, 0x7ffffffffffffffe, false},

    { 0x00, 0x7fffffffffffffff, false},
    { 0x01, 0x7fffffffffffffff, false},
    { 0x02, 0x7fffffffffffffff, false},
    { 0x7e, 0x7fffffffffffffff, false},
    { 0x7f, 0x7fffffffffffffff, false},
    { 0x80, 0x7fffffffffffffff, false},
    { 0x81, 0x7fffffffffffffff, false},
    { 0xfe, 0x7fffffffffffffff, false},
    { 0xff, 0x7fffffffffffffff, false},

    { 0x00, 0x8000000000000000, false},
    { 0x01, 0x8000000000000000, false},
    { 0x02, 0x8000000000000000, false},
    { 0x7e, 0x8000000000000000, false},
    { 0x7f, 0x8000000000000000, false},
    { 0x80, 0x8000000000000000, false},
    { 0x81, 0x8000000000000000, false},
    { 0xfe, 0x8000000000000000, false},
    { 0xff, 0x8000000000000000, false},

    { 0x00, 0x8000000000000001, false},
    { 0x01, 0x8000000000000001, false},
    { 0x02, 0x8000000000000001, false},
    { 0x7e, 0x8000000000000001, false},
    { 0x7f, 0x8000000000000001, false},
    { 0x80, 0x8000000000000001, false},
    { 0x81, 0x8000000000000001, false},
    { 0xfe, 0x8000000000000001, false},
    { 0xff, 0x8000000000000001, false},

    { 0x00, 0xfffffffffffffffe, false},
    { 0x01, 0xfffffffffffffffe, false},
    { 0x02, 0xfffffffffffffffe, false},
    { 0x7e, 0xfffffffffffffffe, false},
    { 0x7f, 0xfffffffffffffffe, false},
    { 0x80, 0xfffffffffffffffe, false},
    { 0x81, 0xfffffffffffffffe, false},
    { 0xfe, 0xfffffffffffffffe, false},
    { 0xff, 0xfffffffffffffffe, false},

    { 0x00, 0xffffffffffffffff, false},
    { 0x01, 0xffffffffffffffff, false},
    { 0x02, 0xffffffffffffffff, false},
    { 0x7e, 0xffffffffffffffff, false},
    { 0x7f, 0xffffffffffffffff, false},
    { 0x80, 0xffffffffffffffff, false},
    { 0x81, 0xffffffffffffffff, false},
    { 0xfe, 0xffffffffffffffff, false},
    { 0xff, 0xffffffffffffffff, false},
};

void SubVerifyInt8Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint64); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_uint64[i].x, int8_uint64[i].y, ret) != int8_uint64[i].fExpected )
        {
            cerr << "Error in case int8_uint64: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_uint64[i].y << ", ";
            cerr << "expected = " << int8_uint64[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_uint64[i].x);
            si -= int8_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint64[i].fExpected )
        {
            cerr << "Error in case int8_uint64 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_uint64[i].y << ", ";
            cerr << "expected = " << int8_uint64[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_uint64[i].x);
            x -= SafeInt<unsigned __int64>(int8_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint64[i].fExpected )
        {
            cerr << "Error in case int8_uint64 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint64[i].x) << ", ";
            cerr << hex << setw(16) << setfill('0') << int8_uint64[i].y << ", ";
            cerr << "expected = " << int8_uint64[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, unsigned __int32 > int8_uint32[] =
{
    { 0x00, 0x00000000, true},
    { 0x01, 0x00000000, true},
    { 0x02, 0x00000000, true},
    { 0x7e, 0x00000000, true},
    { 0x7f, 0x00000000, true},
    { 0x80, 0x00000000, true},
    { 0x81, 0x00000000, true},
    { 0xfe, 0x00000000, true},
    { 0xff, 0x00000000, true},

    { 0x00, 0x00000001, true},
    { 0x01, 0x00000001, true},
    { 0x02, 0x00000001, true},
    { 0x7e, 0x00000001, true},
    { 0x7f, 0x00000001, true},
    { 0x80, 0x00000001, false},
    { 0x81, 0x00000001, true},
    { 0xfe, 0x00000001, true},
    { 0xff, 0x00000001, true},

    { 0x00, 0x00000002, true},
    { 0x01, 0x00000002, true},
    { 0x02, 0x00000002, true},
    { 0x7e, 0x00000002, true},
    { 0x7f, 0x00000002, true},
    { 0x80, 0x00000002, false},
    { 0x81, 0x00000002, false},
    { 0xfe, 0x00000002, true},
    { 0xff, 0x00000002, true},

    { 0x00, 0x7ffffffe, false},
    { 0x01, 0x7ffffffe, false},
    { 0x02, 0x7ffffffe, false},
    { 0x7e, 0x7ffffffe, false},
    { 0x7f, 0x7ffffffe, false},
    { 0x80, 0x7ffffffe, false},
    { 0x81, 0x7ffffffe, false},
    { 0xfe, 0x7ffffffe, false},
    { 0xff, 0x7ffffffe, false},

    { 0x00, 0x7fffffff, false},
    { 0x01, 0x7fffffff, false},
    { 0x02, 0x7fffffff, false},
    { 0x7e, 0x7fffffff, false},
    { 0x7f, 0x7fffffff, false},
    { 0x80, 0x7fffffff, false},
    { 0x81, 0x7fffffff, false},
    { 0xfe, 0x7fffffff, false},
    { 0xff, 0x7fffffff, false},

    { 0x00, 0x80000000, false},
    { 0x01, 0x80000000, false},
    { 0x02, 0x80000000, false},
    { 0x7e, 0x80000000, false},
    { 0x7f, 0x80000000, false},
    { 0x80, 0x80000000, false},
    { 0x81, 0x80000000, false},
    { 0xfe, 0x80000000, false},
    { 0xff, 0x80000000, false},

    { 0x00, 0x80000001, false},
    { 0x01, 0x80000001, false},
    { 0x02, 0x80000001, false},
    { 0x7e, 0x80000001, false},
    { 0x7f, 0x80000001, false},
    { 0x80, 0x80000001, false},
    { 0x81, 0x80000001, false},
    { 0xfe, 0x80000001, false},
    { 0xff, 0x80000001, false},

    { 0x00, 0xfffffffe, false},
    { 0x01, 0xfffffffe, false},
    { 0x02, 0xfffffffe, false},
    { 0x7e, 0xfffffffe, false},
    { 0x7f, 0xfffffffe, false},
    { 0x80, 0xfffffffe, false},
    { 0x81, 0xfffffffe, false},
    { 0xfe, 0xfffffffe, false},
    { 0xff, 0xfffffffe, false},

    { 0x00, 0xffffffff, false},
    { 0x01, 0xffffffff, false},
    { 0x02, 0xffffffff, false},
    { 0x7e, 0xffffffff, false},
    { 0x7f, 0xffffffff, false},
    { 0x80, 0xffffffff, false},
    { 0x81, 0xffffffff, false},
    { 0xfe, 0xffffffff, false},
    { 0xff, 0xffffffff, false},
};

void SubVerifyInt8Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint32); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_uint32[i].x, int8_uint32[i].y, ret) != int8_uint32[i].fExpected )
        {
            cerr << "Error in case int8_uint32: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_uint32[i].y << ", ";
            cerr << "expected = " << int8_uint32[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_uint32[i].x);
            si -= int8_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint32[i].fExpected )
        {
            cerr << "Error in case int8_uint32 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_uint32[i].y << ", ";
            cerr << "expected = " << int8_uint32[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_uint32[i].x);
            x -= SafeInt<unsigned __int32>(int8_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint32[i].fExpected )
        {
            cerr << "Error in case int8_uint32 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint32[i].x) << ", ";
            cerr << hex << setw(8) << setfill('0') << int8_uint32[i].y << ", ";
            cerr << "expected = " << int8_uint32[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, unsigned __int16 > int8_uint16[] =
{
    { 0x00, 0x0000, true},
    { 0x01, 0x0000, true},
    { 0x02, 0x0000, true},
    { 0x7e, 0x0000, true},
    { 0x7f, 0x0000, true},
    { 0x80, 0x0000, true},
    { 0x81, 0x0000, true},
    { 0xfe, 0x0000, true},
    { 0xff, 0x0000, true},

    { 0x00, 0x0001, true},
    { 0x01, 0x0001, true},
    { 0x02, 0x0001, true},
    { 0x7e, 0x0001, true},
    { 0x7f, 0x0001, true},
    { 0x80, 0x0001, false},
    { 0x81, 0x0001, true},
    { 0xfe, 0x0001, true},
    { 0xff, 0x0001, true},

    { 0x00, 0x0002, true},
    { 0x01, 0x0002, true},
    { 0x02, 0x0002, true},
    { 0x7e, 0x0002, true},
    { 0x7f, 0x0002, true},
    { 0x80, 0x0002, false},
    { 0x81, 0x0002, false},
    { 0xfe, 0x0002, true},
    { 0xff, 0x0002, true},

    { 0x00, 0x7ffe, false},
    { 0x01, 0x7ffe, false},
    { 0x02, 0x7ffe, false},
    { 0x7e, 0x7ffe, false},
    { 0x7f, 0x7ffe, false},
    { 0x80, 0x7ffe, false},
    { 0x81, 0x7ffe, false},
    { 0xfe, 0x7ffe, false},
    { 0xff, 0x7ffe, false},

    { 0x00, 0x7fff, false},
    { 0x01, 0x7fff, false},
    { 0x02, 0x7fff, false},
    { 0x7e, 0x7fff, false},
    { 0x7f, 0x7fff, false},
    { 0x80, 0x7fff, false},
    { 0x81, 0x7fff, false},
    { 0xfe, 0x7fff, false},
    { 0xff, 0x7fff, false},

    { 0x00, 0x8000, false},
    { 0x01, 0x8000, false},
    { 0x02, 0x8000, false},
    { 0x7e, 0x8000, false},
    { 0x7f, 0x8000, false},
    { 0x80, 0x8000, false},
    { 0x81, 0x8000, false},
    { 0xfe, 0x8000, false},
    { 0xff, 0x8000, false},

    { 0x00, 0x8001, false},
    { 0x01, 0x8001, false},
    { 0x02, 0x8001, false},
    { 0x7e, 0x8001, false},
    { 0x7f, 0x8001, false},
    { 0x80, 0x8001, false},
    { 0x81, 0x8001, false},
    { 0xfe, 0x8001, false},
    { 0xff, 0x8001, false},

    { 0x00, 0xfffe, false},
    { 0x01, 0xfffe, false},
    { 0x02, 0xfffe, false},
    { 0x7e, 0xfffe, false},
    { 0x7f, 0xfffe, false},
    { 0x80, 0xfffe, false},
    { 0x81, 0xfffe, false},
    { 0xfe, 0xfffe, false},
    { 0xff, 0xfffe, false},

    { 0x00, 0xffff, false},
    { 0x01, 0xffff, false},
    { 0x02, 0xffff, false},
    { 0x7e, 0xffff, false},
    { 0x7f, 0xffff, false},
    { 0x80, 0xffff, false},
    { 0x81, 0xffff, false},
    { 0xfe, 0xffff, false},
    { 0xff, 0xffff, false},
};

void SubVerifyInt8Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint16); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_uint16[i].x, int8_uint16[i].y, ret) != int8_uint16[i].fExpected )
        {
            cerr << "Error in case int8_uint16: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_uint16[i].y << ", ";
            cerr << "expected = " << int8_uint16[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_uint16[i].x);
            si -= int8_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint16[i].fExpected )
        {
            cerr << "Error in case int8_uint16 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_uint16[i].y << ", ";
            cerr << "expected = " << int8_uint16[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_uint16[i].x);
            x -= SafeInt<unsigned __int16>(int8_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint16[i].fExpected )
        {
            cerr << "Error in case int8_uint16 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint16[i].x) << ", ";
            cerr << hex << setw(4) << setfill('0') << int8_uint16[i].y << ", ";
            cerr << "expected = " << int8_uint16[i].fExpected << endl;
        }
    }
}

static const SubTest< __int8, unsigned __int8 > int8_uint8[] =
{
    { 0x00, 0x00, true},
    { 0x01, 0x00, true},
    { 0x02, 0x00, true},
    { 0x7e, 0x00, true},
    { 0x7f, 0x00, true},
    { 0x80, 0x00, true},
    { 0x81, 0x00, true},
    { 0xfe, 0x00, true},
    { 0xff, 0x00, true},

    { 0x00, 0x01, true},
    { 0x01, 0x01, true},
    { 0x02, 0x01, true},
    { 0x7e, 0x01, true},
    { 0x7f, 0x01, true},
    { 0x80, 0x01, false},
    { 0x81, 0x01, true},
    { 0xfe, 0x01, true},
    { 0xff, 0x01, true},

    { 0x00, 0x02, true},
    { 0x01, 0x02, true},
    { 0x02, 0x02, true},
    { 0x7e, 0x02, true},
    { 0x7f, 0x02, true},
    { 0x80, 0x02, false},
    { 0x81, 0x02, false},
    { 0xfe, 0x02, true},
    { 0xff, 0x02, true},

    { 0x00, 0x7e, true},
    { 0x01, 0x7e, true},
    { 0x02, 0x7e, true},
    { 0x7e, 0x7e, true},
    { 0x7f, 0x7e, true},
    { 0x80, 0x7e, false},
    { 0x81, 0x7e, false},
    { 0xfe, 0x7e, true},
    { 0xff, 0x7e, true},

    { 0x00, 0x7f, true},
    { 0x01, 0x7f, true},
    { 0x02, 0x7f, true},
    { 0x7e, 0x7f, true},
    { 0x7f, 0x7f, true},
    { 0x80, 0x7f, false},
    { 0x81, 0x7f, false},
    { 0xfe, 0x7f, false},
    { 0xff, 0x7f, true},

    { 0x00, 0x80, true},
    { 0x01, 0x80, true},
    { 0x02, 0x80, true},
    { 0x7e, 0x80, true},
    { 0x7f, 0x80, true},
    { 0x80, 0x80, false},
    { 0x81, 0x80, false},
    { 0xfe, 0x80, false},
    { 0xff, 0x80, false},

    { 0x00, 0x81, false},
    { 0x01, 0x81, true},
    { 0x02, 0x81, true},
    { 0x7e, 0x81, true},
    { 0x7f, 0x81, true},
    { 0x80, 0x81, false},
    { 0x81, 0x81, false},
    { 0xfe, 0x81, false},
    { 0xff, 0x81, false},

    { 0x00, 0xfe, false},
    { 0x01, 0xfe, false},
    { 0x02, 0xfe, false},
    { 0x7e, 0xfe, true},
    { 0x7f, 0xfe, true},
    { 0x80, 0xfe, false},
    { 0x81, 0xfe, false},
    { 0xfe, 0xfe, false},
    { 0xff, 0xfe, false},

    { 0x00, 0xff, false},
    { 0x01, 0xff, false},
    { 0x02, 0xff, false},
    { 0x7e, 0xff, false},
    { 0x7f, 0xff, true},
    { 0x80, 0xff, false},
    { 0x81, 0xff, false},
    { 0xfe, 0xff, false},
    { 0xff, 0xff, false},
};

void SubVerifyInt8Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint8); ++i )
    {
        __int8 ret;
        if( SafeSubtract(int8_uint8[i].x, int8_uint8[i].y, ret) != int8_uint8[i].fExpected )
        {
            cerr << "Error in case int8_uint8: ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].y) << ", ";
            cerr << "expected = " << int8_uint8[i].fExpected << endl;
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<__int8> si(int8_uint8[i].x);
            si -= int8_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint8[i].fExpected )
        {
            cerr << "Error in case int8_uint8 throw (1): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].y) << ", ";
            cerr << "expected = " << int8_uint8[i].fExpected << endl;
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            __int8 x(int8_uint8[i].x);
            x -= SafeInt<unsigned __int8>(int8_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint8[i].fExpected )
        {
            cerr << "Error in case int8_uint8 throw (2): ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].x) << ", ";
            cerr << hex << setw(2) << setfill('0') << (0xFF & (int)int8_uint8[i].y) << ", ";
            cerr << "expected = " << int8_uint8[i].fExpected << endl;
        }
    }
}

void SubVerify()
{
    cout << "Verifying Subtraction:" << endl;

    // Unsigned int64, unsigned cases
    SubVerifyUint64Uint64();
    SubVerifyUint64Uint32();
    SubVerifyUint64Uint16();
    SubVerifyUint64Uint8();

    // Unsigned int64, signed cases
    SubVerifyUint64Int64();
    SubVerifyUint64Int32();
    SubVerifyUint64Int16();
    SubVerifyUint64Int8();

    /////////////////////////////////////

    // Unsigned int8, unsigned cases
    SubVerifyUint8Uint64();
    SubVerifyUint8Uint32();
    SubVerifyUint8Uint16();
    SubVerifyUint8Uint8();

    // Unsigned int8, signed cases
    SubVerifyUint8Int64();
    SubVerifyUint8Int32();
    SubVerifyUint8Int16();
    SubVerifyUint8Int8();

    /////////////////////////////////////

    // Signed int64, unsigned cases
    SubVerifyInt64Uint64();
    SubVerifyInt64Uint32();
    SubVerifyInt64Uint16();
    SubVerifyInt64Uint8();

    // Signed int64, signed cases
    SubVerifyInt64Int64();
    SubVerifyInt64Int32();
    SubVerifyInt64Int16();
    SubVerifyInt64Int8();

    /////////////////////////////////////

    // Signed int8, unsigned cases
    SubVerifyInt8Uint64();
    SubVerifyInt8Uint32();
    SubVerifyInt8Uint16();
    SubVerifyInt8Uint8();

    // Signed int8, signed cases
    SubVerifyInt8Int64();
    SubVerifyInt8Int32();
    SubVerifyInt8Int16();
    SubVerifyInt8Int8();
}

}
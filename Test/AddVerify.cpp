// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"

namespace add_verify
{

template <typename T, typename U>
struct AddTest
{
    T x;
    U y;
    bool fExpected;
};

static const AddTest< std::uint64_t, std::uint64_t > uint64_uint64[] = 
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

void AddVerifyUint64Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint64); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
        {
            err_msg( "Error in case uint64_uint64: ",
            uint64_uint64[i].x, 
            uint64_uint64[i].y, 
            uint64_uint64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_uint64[i].x);
            si += uint64_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint64[i].fExpected )
        {
            err_msg( "Error in case uint64_uint64 throw (1): ", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_uint64[i].x);
            x += SafeInt<std::uint64_t>(uint64_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint64[i].fExpected )
        {
            err_msg( "Error in case uint64_uint64 throw (2): ", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::uint32_t > uint64_uint32[] = 
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

void AddVerifyUint64Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint32); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
        {
            err_msg( "Error in case uint64_uint32: ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_uint32[i].x);
            si += uint64_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint32[i].fExpected )
        {
            err_msg( "Error in case uint64_uint32 throw (1): ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_uint32[i].x);
            x += SafeInt<std::uint32_t>(uint64_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint32[i].fExpected )
        {
            err_msg( "Error in case uint64_uint32 throw (2): ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::uint16_t > uint64_uint16[] = 
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
	{ 0x8000000000000000, 0x0001, true},
	{ 0x8000000000000001, 0x0001, true},
	{ 0xfffffffffffffffe, 0x0001, true},
	{ 0xffffffffffffffff, 0x0001, false},

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
	{ 0x8000000000000000, 0x0002, true},
	{ 0x8000000000000001, 0x0002, true},
	{ 0xfffffffffffffffe, 0x0002, false},
	{ 0xffffffffffffffff, 0x0002, false},

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
	{ 0x8000000000000000, 0x7ffe, true},
	{ 0x8000000000000001, 0x7ffe, true},
	{ 0xfffffffffffffffe, 0x7ffe, false},
	{ 0xffffffffffffffff, 0x7ffe, false},

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
	{ 0x8000000000000000, 0x7fff, true},
	{ 0x8000000000000001, 0x7fff, true},
	{ 0xfffffffffffffffe, 0x7fff, false},
	{ 0xffffffffffffffff, 0x7fff, false},

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
	{ 0xfffffffffffffffe, 0xffff, false},
	{ 0xffffffffffffffff, 0xffff, false},
};

void AddVerifyUint64Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint16); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_uint16[i].x, uint64_uint16[i].y, ret) != uint64_uint16[i].fExpected )
        {
            err_msg( "Error in case uint64_uint16: ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_uint16[i].x);
            si += uint64_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint16[i].fExpected )
        {
            err_msg( "Error in case uint64_uint16 throw (1): ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_uint16[i].x);
            x += SafeInt<std::uint16_t>(uint64_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint16[i].fExpected )
        {
            err_msg( "Error in case uint64_uint16 throw (2): ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::uint8_t > uint64_uint8[] = 
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
	{ 0x8000000000000000, 0x01, true},
	{ 0x8000000000000001, 0x01, true},
	{ 0xfffffffffffffffe, 0x01, true},
	{ 0xffffffffffffffff, 0x01, false},

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
	{ 0x8000000000000000, 0x02, true},
	{ 0x8000000000000001, 0x02, true},
	{ 0xfffffffffffffffe, 0x02, false},
	{ 0xffffffffffffffff, 0x02, false},

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
	{ 0x8000000000000000, 0x7e, true},
	{ 0x8000000000000001, 0x7e, true},
	{ 0xfffffffffffffffe, 0x7e, false},
	{ 0xffffffffffffffff, 0x7e, false},

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
	{ 0x8000000000000000, 0x7f, true},
	{ 0x8000000000000001, 0x7f, true},
	{ 0xfffffffffffffffe, 0x7f, false},
	{ 0xffffffffffffffff, 0x7f, false},

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
	{ 0xfffffffffffffffe, 0xff, false},
	{ 0xffffffffffffffff, 0xff, false},
};

void AddVerifyUint64Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_uint8); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_uint8[i].x, uint64_uint8[i].y, ret) != uint64_uint8[i].fExpected )
        {
            err_msg( "Error in case uint64_uint8: ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_uint8[i].x);
            si += uint64_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint8[i].fExpected )
        {
            err_msg( "Error in case uint64_uint8 throw (1): ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_uint8[i].x);
            x += SafeInt<std::uint8_t>(uint64_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_uint8[i].fExpected )
        {
            err_msg( "Error in case uint64_uint8 throw (2): ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::int64_t > uint64_int64[] = 
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

void AddVerifyUint64Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int64); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
        {
            err_msg( "Error in case uint64_int64: ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_int64[i].x);
            si += uint64_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int64[i].fExpected )
        {
            err_msg( "Error in case uint64_int64 throw (1): ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_int64[i].x);
            x += SafeInt<std::int64_t>(uint64_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int64[i].fExpected )
        {
            err_msg( "Error in case uint64_int64 throw (2): ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::int32_t > uint64_int32[] = 
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

void AddVerifyUint64Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int32); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
        {
            err_msg( "Error in case uint64_int32: ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_int32[i].x);
            si += uint64_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int32[i].fExpected )
        {
            err_msg( "Error in case uint64_int32 throw (1): ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_int32[i].x);
            x += SafeInt<std::int32_t>(uint64_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int32[i].fExpected )
        {
            err_msg( "Error in case uint64_int32 throw (2): ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::int16_t > uint64_int16[] = 
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
	{ 0x8000000000000000, 0x0001, true},
	{ 0x8000000000000001, 0x0001, true},
	{ 0xfffffffffffffffe, 0x0001, true},
	{ 0xffffffffffffffff, 0x0001, false},

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
	{ 0x8000000000000000, 0x0002, true},
	{ 0x8000000000000001, 0x0002, true},
	{ 0xfffffffffffffffe, 0x0002, false},
	{ 0xffffffffffffffff, 0x0002, false},

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
	{ 0x8000000000000000, 0x7ffe, true},
	{ 0x8000000000000001, 0x7ffe, true},
	{ 0xfffffffffffffffe, 0x7ffe, false},
	{ 0xffffffffffffffff, 0x7ffe, false},

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
	{ 0x8000000000000000, 0x7fff, true},
	{ 0x8000000000000001, 0x7fff, true},
	{ 0xfffffffffffffffe, 0x7fff, false},
	{ 0xffffffffffffffff, 0x7fff, false},

	{ 0x0000000000000000, (std::int16_t)0x8000, false},
	{ 0x0000000000000001, (std::int16_t)0x8000, false},
	{ 0x0000000000000002, (std::int16_t)0x8000, false},
	{ 0x000000007ffffffe, (std::int16_t)0x8000, true},
	{ 0x000000007fffffff, (std::int16_t)0x8000, true},
	{ 0x0000000080000000, (std::int16_t)0x8000, true},
	{ 0x0000000080000001, (std::int16_t)0x8000, true},
	{ 0x00000000fffffffe, (std::int16_t)0x8000, true},
	{ 0x00000000ffffffff, (std::int16_t)0x8000, true},
	{ 0x0000000100000000, (std::int16_t)0x8000, true},
	{ 0x0000000200000000, (std::int16_t)0x8000, true},
	{ 0x7ffffffffffffffe, (std::int16_t)0x8000, true},
	{ 0x7fffffffffffffff, (std::int16_t)0x8000, true},
	{ 0x8000000000000000, (std::int16_t)0x8000, true},
	{ 0x8000000000000001, (std::int16_t)0x8000, true},
	{ 0xfffffffffffffffe, (std::int16_t)0x8000, true},
	{ 0xffffffffffffffff, (std::int16_t)0x8000, true},

	{ 0x0000000000000000, (std::int16_t)0x8001, false},
	{ 0x0000000000000001, (std::int16_t)0x8001, false},
	{ 0x0000000000000002, (std::int16_t)0x8001, false},
	{ 0x000000007ffffffe, (std::int16_t)0x8001, true},
	{ 0x000000007fffffff, (std::int16_t)0x8001, true},
	{ 0x0000000080000000, (std::int16_t)0x8001, true},
	{ 0x0000000080000001, (std::int16_t)0x8001, true},
	{ 0x00000000fffffffe, (std::int16_t)0x8001, true},
	{ 0x00000000ffffffff, (std::int16_t)0x8001, true},
	{ 0x0000000100000000, (std::int16_t)0x8001, true},
	{ 0x0000000200000000, (std::int16_t)0x8001, true},
	{ 0x7ffffffffffffffe, (std::int16_t)0x8001, true},
	{ 0x7fffffffffffffff, (std::int16_t)0x8001, true},
	{ 0x8000000000000000, (std::int16_t)0x8001, true},
	{ 0x8000000000000001, (std::int16_t)0x8001, true},
	{ 0xfffffffffffffffe, (std::int16_t)0x8001, true},
	{ 0xffffffffffffffff, (std::int16_t)0x8001, true},

	{ 0x0000000000000000, (std::int16_t)0xfffe, false},
	{ 0x0000000000000001, (std::int16_t)0xfffe, false},
	{ 0x0000000000000002, (std::int16_t)0xfffe, true},
	{ 0x000000007ffffffe, (std::int16_t)0xfffe, true},
	{ 0x000000007fffffff, (std::int16_t)0xfffe, true},
	{ 0x0000000080000000, (std::int16_t)0xfffe, true},
	{ 0x0000000080000001, (std::int16_t)0xfffe, true},
	{ 0x00000000fffffffe, (std::int16_t)0xfffe, true},
	{ 0x00000000ffffffff, (std::int16_t)0xfffe, true},
	{ 0x0000000100000000, (std::int16_t)0xfffe, true},
	{ 0x0000000200000000, (std::int16_t)0xfffe, true},
	{ 0x7ffffffffffffffe, (std::int16_t)0xfffe, true},
	{ 0x7fffffffffffffff, (std::int16_t)0xfffe, true},
	{ 0x8000000000000000, (std::int16_t)0xfffe, true},
	{ 0x8000000000000001, (std::int16_t)0xfffe, true},
	{ 0xfffffffffffffffe, (std::int16_t)0xfffe, true},
	{ 0xffffffffffffffff, (std::int16_t)0xfffe, true},

	{ 0x0000000000000000, (std::int16_t)0xffff, false},
	{ 0x0000000000000001, (std::int16_t)0xffff, true},
	{ 0x0000000000000002, (std::int16_t)0xffff, true},
	{ 0x000000007ffffffe, (std::int16_t)0xffff, true},
	{ 0x000000007fffffff, (std::int16_t)0xffff, true},
	{ 0x0000000080000000, (std::int16_t)0xffff, true},
	{ 0x0000000080000001, (std::int16_t)0xffff, true},
	{ 0x00000000fffffffe, (std::int16_t)0xffff, true},
	{ 0x00000000ffffffff, (std::int16_t)0xffff, true},
	{ 0x0000000100000000, (std::int16_t)0xffff, true},
	{ 0x0000000200000000, (std::int16_t)0xffff, true},
	{ 0x7ffffffffffffffe, (std::int16_t)0xffff, true},
	{ 0x7fffffffffffffff, (std::int16_t)0xffff, true},
	{ 0x8000000000000000, (std::int16_t)0xffff, true},
	{ 0x8000000000000001, (std::int16_t)0xffff, true},
	{ 0xfffffffffffffffe, (std::int16_t)0xffff, true},
	{ 0xffffffffffffffff, (std::int16_t)0xffff, true},
};

void AddVerifyUint64Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int16); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_int16[i].x, uint64_int16[i].y, ret) != uint64_int16[i].fExpected )
        {
            err_msg( "Error in case uint64_int16: ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_int16[i].x);
            si += uint64_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int16[i].fExpected )
        {
            err_msg( "Error in case uint64_int16 throw (1): ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_int16[i].x);
            x += SafeInt<std::int16_t>(uint64_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int16[i].fExpected )
        {
            err_msg( "Error in case uint64_int16 throw (2): ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
        }
    }
}

static const AddTest< std::uint64_t, std::int8_t > uint64_int8[] = 
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
	{ 0x8000000000000000, 0x01, true},
	{ 0x8000000000000001, 0x01, true},
	{ 0xfffffffffffffffe, 0x01, true},
	{ 0xffffffffffffffff, 0x01, false},

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
	{ 0x8000000000000000, 0x02, true},
	{ 0x8000000000000001, 0x02, true},
	{ 0xfffffffffffffffe, 0x02, false},
	{ 0xffffffffffffffff, 0x02, false},

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
	{ 0x8000000000000000, 0x7e, true},
	{ 0x8000000000000001, 0x7e, true},
	{ 0xfffffffffffffffe, 0x7e, false},
	{ 0xffffffffffffffff, 0x7e, false},

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
	{ 0x8000000000000000, 0x7f, true},
	{ 0x8000000000000001, 0x7f, true},
	{ 0xfffffffffffffffe, 0x7f, false},
	{ 0xffffffffffffffff, 0x7f, false},

	{ 0x0000000000000000, (std::int8_t)0x80, false},
	{ 0x0000000000000001, (std::int8_t)0x80, false},
	{ 0x0000000000000002, (std::int8_t)0x80, false},
	{ 0x000000007ffffffe, (std::int8_t)0x80, true},
	{ 0x000000007fffffff, (std::int8_t)0x80, true},
	{ 0x0000000080000000, (std::int8_t)0x80, true},
	{ 0x0000000080000001, (std::int8_t)0x80, true},
	{ 0x00000000fffffffe, (std::int8_t)0x80, true},
	{ 0x00000000ffffffff, (std::int8_t)0x80, true},
	{ 0x0000000100000000, (std::int8_t)0x80, true},
	{ 0x0000000200000000, (std::int8_t)0x80, true},
	{ 0x7ffffffffffffffe, (std::int8_t)0x80, true},
	{ 0x7fffffffffffffff, (std::int8_t)0x80, true},
	{ 0x8000000000000000, (std::int8_t)0x80, true},
	{ 0x8000000000000001, (std::int8_t)0x80, true},
	{ 0xfffffffffffffffe, (std::int8_t)0x80, true},
	{ 0xffffffffffffffff, (std::int8_t)0x80, true},

	{ 0x0000000000000000, (std::int8_t)0x81, false},
	{ 0x0000000000000001, (std::int8_t)0x81, false},
	{ 0x0000000000000002, (std::int8_t)0x81, false},
	{ 0x000000007ffffffe, (std::int8_t)0x81, true},
	{ 0x000000007fffffff, (std::int8_t)0x81, true},
	{ 0x0000000080000000, (std::int8_t)0x81, true},
	{ 0x0000000080000001, (std::int8_t)0x81, true},
	{ 0x00000000fffffffe, (std::int8_t)0x81, true},
	{ 0x00000000ffffffff, (std::int8_t)0x81, true},
	{ 0x0000000100000000, (std::int8_t)0x81, true},
	{ 0x0000000200000000, (std::int8_t)0x81, true},
	{ 0x7ffffffffffffffe, (std::int8_t)0x81, true},
	{ 0x7fffffffffffffff, (std::int8_t)0x81, true},
	{ 0x8000000000000000, (std::int8_t)0x81, true},
	{ 0x8000000000000001, (std::int8_t)0x81, true},
	{ 0xfffffffffffffffe, (std::int8_t)0x81, true},
	{ 0xffffffffffffffff, (std::int8_t)0x81, true},

	{ 0x0000000000000000, (std::int8_t)0xfe, false},
	{ 0x0000000000000001, (std::int8_t)0xfe, false},
	{ 0x0000000000000002, (std::int8_t)0xfe, true},
	{ 0x000000007ffffffe, (std::int8_t)0xfe, true},
	{ 0x000000007fffffff, (std::int8_t)0xfe, true},
	{ 0x0000000080000000, (std::int8_t)0xfe, true},
	{ 0x0000000080000001, (std::int8_t)0xfe, true},
	{ 0x00000000fffffffe, (std::int8_t)0xfe, true},
	{ 0x00000000ffffffff, (std::int8_t)0xfe, true},
	{ 0x0000000100000000, (std::int8_t)0xfe, true},
	{ 0x0000000200000000, (std::int8_t)0xfe, true},
	{ 0x7ffffffffffffffe, (std::int8_t)0xfe, true},
	{ 0x7fffffffffffffff, (std::int8_t)0xfe, true},
	{ 0x8000000000000000, (std::int8_t)0xfe, true},
	{ 0x8000000000000001, (std::int8_t)0xfe, true},
	{ 0xfffffffffffffffe, (std::int8_t)0xfe, true},
	{ 0xffffffffffffffff, (std::int8_t)0xfe, true},

	{ 0x0000000000000000, (std::int8_t)0xff, false},
	{ 0x0000000000000001, (std::int8_t)0xff, true},
	{ 0x0000000000000002, (std::int8_t)0xff, true},
	{ 0x000000007ffffffe, (std::int8_t)0xff, true},
	{ 0x000000007fffffff, (std::int8_t)0xff, true},
	{ 0x0000000080000000, (std::int8_t)0xff, true},
	{ 0x0000000080000001, (std::int8_t)0xff, true},
	{ 0x00000000fffffffe, (std::int8_t)0xff, true},
	{ 0x00000000ffffffff, (std::int8_t)0xff, true},
	{ 0x0000000100000000, (std::int8_t)0xff, true},
	{ 0x0000000200000000, (std::int8_t)0xff, true},
	{ 0x7ffffffffffffffe, (std::int8_t)0xff, true},
	{ 0x7fffffffffffffff, (std::int8_t)0xff, true},
	{ 0x8000000000000000, (std::int8_t)0xff, true},
	{ 0x8000000000000001, (std::int8_t)0xff, true},
	{ 0xfffffffffffffffe, (std::int8_t)0xff, true},
	{ 0xffffffffffffffff, (std::int8_t)0xff, true},
};

void AddVerifyUint64Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint64_int8); ++i )
    {
        std::uint64_t ret;
        if( SafeAdd(uint64_int8[i].x, uint64_int8[i].y, ret) != uint64_int8[i].fExpected )
        {
            err_msg( "Error in case uint64_int8: ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint64_t> si(uint64_int8[i].x);
            si += uint64_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int8[i].fExpected )
        {
            err_msg( "Error in case uint64_int8 throw (1): ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint64_t x(uint64_int8[i].x);
            x += SafeInt<std::int8_t>(uint64_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint64_int8[i].fExpected )
        {
            err_msg( "Error in case uint64_int8 throw (2): ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::uint64_t > int64_uint64[] = 
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

void AddVerifyInt64Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint64); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
        {
            err_msg( "Error in case int64_uint64: ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_uint64[i].x);
            si += int64_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint64[i].fExpected )
        {
            err_msg( "Error in case int64_uint64 throw (1): ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_uint64[i].x);
            x += SafeInt<std::uint64_t>(int64_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint64[i].fExpected )
        {
            err_msg( "Error in case int64_uint64 throw (2): ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::uint32_t > int64_uint32[] = 
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

void AddVerifyInt64Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint32); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_uint32[i].x, int64_uint32[i].y, ret) != int64_uint32[i].fExpected )
        {
            err_msg( "Error in case int64_uint32: ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_uint32[i].x);
            si += int64_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint32[i].fExpected )
        {
            err_msg( "Error in case int64_uint32 throw (1): ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_uint32[i].x);
            x += SafeInt<std::uint32_t>(int64_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint32[i].fExpected )
        {
            err_msg( "Error in case int64_uint32 throw (2): ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::uint16_t > int64_uint16[] = 
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
	{ 0x7fffffffffffffff, 0x0001, false},
	{ 0x8000000000000000, 0x0001, true},
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
	{ 0x7ffffffffffffffe, 0x0002, false},
	{ 0x7fffffffffffffff, 0x0002, false},
	{ 0x8000000000000000, 0x0002, true},
	{ 0x8000000000000001, 0x0002, true},
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
	{ 0x7ffffffffffffffe, 0x7ffe, false},
	{ 0x7fffffffffffffff, 0x7ffe, false},
	{ 0x8000000000000000, 0x7ffe, true},
	{ 0x8000000000000001, 0x7ffe, true},
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
	{ 0x7ffffffffffffffe, 0x7fff, false},
	{ 0x7fffffffffffffff, 0x7fff, false},
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
	{ 0x7ffffffffffffffe, 0xffff, false},
	{ 0x7fffffffffffffff, 0xffff, false},
	{ 0x8000000000000000, 0xffff, true},
	{ 0x8000000000000001, 0xffff, true},
	{ 0xfffffffffffffffe, 0xffff, true},
	{ 0xffffffffffffffff, 0xffff, true},
};

void AddVerifyInt64Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint16); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_uint16[i].x, int64_uint16[i].y, ret) != int64_uint16[i].fExpected )
        {
            err_msg( "Error in case int64_uint16: ", int64_uint16[i].x, int64_uint16[i].y, int64_uint16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_uint16[i].x);
            si += int64_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint16[i].fExpected )
        {
            err_msg( "Error in case int64_uint16 throw (1): ", int64_uint16[i].x, int64_uint16[i].y, int64_uint16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_uint16[i].x);
            x += SafeInt<std::uint16_t>(int64_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint16[i].fExpected )
        {
            err_msg( "Error in case int64_uint16 throw (2): ", int64_uint16[i].x, int64_uint16[i].y, int64_uint16[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::uint8_t > int64_uint8[] = 
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
	{ 0x7fffffffffffffff, 0x01, false},
	{ 0x8000000000000000, 0x01, true},
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
	{ 0x7ffffffffffffffe, 0x02, false},
	{ 0x7fffffffffffffff, 0x02, false},
	{ 0x8000000000000000, 0x02, true},
	{ 0x8000000000000001, 0x02, true},
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
	{ 0x7ffffffffffffffe, 0x7e, false},
	{ 0x7fffffffffffffff, 0x7e, false},
	{ 0x8000000000000000, 0x7e, true},
	{ 0x8000000000000001, 0x7e, true},
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
	{ 0x7ffffffffffffffe, 0x7f, false},
	{ 0x7fffffffffffffff, 0x7f, false},
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
	{ 0x7ffffffffffffffe, 0xff, false},
	{ 0x7fffffffffffffff, 0xff, false},
	{ 0x8000000000000000, 0xff, true},
	{ 0x8000000000000001, 0xff, true},
	{ 0xfffffffffffffffe, 0xff, true},
	{ 0xffffffffffffffff, 0xff, true},
};

void AddVerifyInt64Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_uint8); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_uint8[i].x, int64_uint8[i].y, ret) != int64_uint8[i].fExpected )
        {
            err_msg( "Error in case int64_uint8: ", int64_uint8[i].x, int64_uint8[i].y, int64_uint8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_uint8[i].x);
            si += int64_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint8[i].fExpected )
        {
            err_msg( "Error in case int64_uint8 throw (1): ", int64_uint8[i].x, int64_uint8[i].y, int64_uint8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_uint8[i].x);
            x += SafeInt<std::uint8_t>(int64_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_uint8[i].fExpected )
        {
            err_msg( "Error in case int64_uint8 throw (2): ", int64_uint8[i].x, int64_uint8[i].y, int64_uint8[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::int64_t > int64_int64[] = 
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

void AddVerifyInt64Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int64); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
        {
            err_msg( "Error in case int64_int64: ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_int64[i].x);
            si += int64_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int64[i].fExpected )
        {
            err_msg( "Error in case int64_int64 throw (1): ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_int64[i].x);
            x += SafeInt<std::int64_t>(int64_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int64[i].fExpected )
        {
            err_msg( "Error in case int64_int64 throw (2): ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::int32_t > int64_int32[] = 
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

void AddVerifyInt64Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int32); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_int32[i].x, int64_int32[i].y, ret) != int64_int32[i].fExpected )
        {
            err_msg( "Error in case int64_int32: ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_int32[i].x);
            si += int64_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int32[i].fExpected )
        {
            err_msg( "Error in case int64_int32 throw (1): ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_int32[i].x);
            x += SafeInt<std::int32_t>(int64_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int32[i].fExpected )
        {
            err_msg( "Error in case int64_int32 throw (2): ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::int16_t > int64_int16[] = 
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
	{ 0x7fffffffffffffff, 0x0001, false},
	{ 0x8000000000000000, 0x0001, true},
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
	{ 0x7ffffffffffffffe, 0x0002, false},
	{ 0x7fffffffffffffff, 0x0002, false},
	{ 0x8000000000000000, 0x0002, true},
	{ 0x8000000000000001, 0x0002, true},
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
	{ 0x7ffffffffffffffe, 0x7ffe, false},
	{ 0x7fffffffffffffff, 0x7ffe, false},
	{ 0x8000000000000000, 0x7ffe, true},
	{ 0x8000000000000001, 0x7ffe, true},
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
	{ 0x7ffffffffffffffe, 0x7fff, false},
	{ 0x7fffffffffffffff, 0x7fff, false},
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
	{ 0x8000000000000001, 0xffff, true},
	{ 0xfffffffffffffffe, 0xffff, true},
	{ 0xffffffffffffffff, 0xffff, true},
};

void AddVerifyInt64Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int16); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_int16[i].x, int64_int16[i].y, ret) != int64_int16[i].fExpected )
        {
            err_msg( "Error in case int64_int16: ", int64_int16[i].x, int64_int16[i].y, int64_int16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_int16[i].x);
            si += int64_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int16[i].fExpected )
        {
            err_msg( "Error in case int64_int16 throw (1): ", int64_int16[i].x, int64_int16[i].y, int64_int16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_int16[i].x);
            x += SafeInt<std::int16_t>(int64_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int16[i].fExpected )
        {
            err_msg( "Error in case int64_int16 throw (2): ", int64_int16[i].x, int64_int16[i].y, int64_int16[i].fExpected );
        }
    }
}

static const AddTest< std::int64_t, std::int8_t > int64_int8[] = 
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
	{ 0x7fffffffffffffff, 0x01, false},
	{ 0x8000000000000000, 0x01, true},
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
	{ 0x7ffffffffffffffe, 0x02, false},
	{ 0x7fffffffffffffff, 0x02, false},
	{ 0x8000000000000000, 0x02, true},
	{ 0x8000000000000001, 0x02, true},
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
	{ 0x7ffffffffffffffe, 0x7e, false},
	{ 0x7fffffffffffffff, 0x7e, false},
	{ 0x8000000000000000, 0x7e, true},
	{ 0x8000000000000001, 0x7e, true},
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
	{ 0x7ffffffffffffffe, 0x7f, false},
	{ 0x7fffffffffffffff, 0x7f, false},
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
	{ 0x8000000000000001, 0xff, true},
	{ 0xfffffffffffffffe, 0xff, true},
	{ 0xffffffffffffffff, 0xff, true},
};

void AddVerifyInt64Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int64_int8); ++i )
    {
        std::int64_t ret;
        if( SafeAdd(int64_int8[i].x, int64_int8[i].y, ret) != int64_int8[i].fExpected )
        {
            err_msg( "Error in case int64_int8: ", int64_int8[i].x, int64_int8[i].y, int64_int8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int64_t> si(int64_int8[i].x);
            si += int64_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int8[i].fExpected )
        {
            err_msg( "Error in case int64_int8 throw (1): ", int64_int8[i].x, int64_int8[i].y, int64_int8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int64_t x(int64_int8[i].x);
            x += SafeInt<std::int8_t>(int64_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int64_int8[i].fExpected )
        {
            err_msg( "Error in case int64_int8 throw (2): ", int64_int8[i].x, int64_int8[i].y, int64_int8[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::uint64_t > uint8_uint64[] = 
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
	{ 0x80, 0x0000000000000001, true},
	{ 0x81, 0x0000000000000001, true},
	{ 0xfe, 0x0000000000000001, true},
	{ 0xff, 0x0000000000000001, false},

	{ 0x00, 0x0000000000000002, true},
	{ 0x01, 0x0000000000000002, true},
	{ 0x02, 0x0000000000000002, true},
	{ 0x7e, 0x0000000000000002, true},
	{ 0x7f, 0x0000000000000002, true},
	{ 0x80, 0x0000000000000002, true},
	{ 0x81, 0x0000000000000002, true},
	{ 0xfe, 0x0000000000000002, false},
	{ 0xff, 0x0000000000000002, false},

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

void AddVerifyUint8Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint64); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_uint64[i].x, uint8_uint64[i].y, ret) != uint8_uint64[i].fExpected )
        {
            err_msg( "Error in case uint8_uint64: ", uint8_uint64[i].x, uint8_uint64[i].y, uint8_uint64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_uint64[i].x);
            si += uint8_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint64[i].fExpected )
        {
            err_msg( "Error in case uint8_uint64 throw (1): ", uint8_uint64[i].x, uint8_uint64[i].y, uint8_uint64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_uint64[i].x);
            x += SafeInt<std::uint64_t>(uint8_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint64[i].fExpected )
        {
            err_msg( "Error in case uint8_uint64 throw (2): ", uint8_uint64[i].x, uint8_uint64[i].y, uint8_uint64[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::uint32_t > uint8_uint32[] = 
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
	{ 0x80, 0x00000001, true},
	{ 0x81, 0x00000001, true},
	{ 0xfe, 0x00000001, true},
	{ 0xff, 0x00000001, false},

	{ 0x00, 0x00000002, true},
	{ 0x01, 0x00000002, true},
	{ 0x02, 0x00000002, true},
	{ 0x7e, 0x00000002, true},
	{ 0x7f, 0x00000002, true},
	{ 0x80, 0x00000002, true},
	{ 0x81, 0x00000002, true},
	{ 0xfe, 0x00000002, false},
	{ 0xff, 0x00000002, false},

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

void AddVerifyUint8Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint32); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_uint32[i].x, uint8_uint32[i].y, ret) != uint8_uint32[i].fExpected )
        {
            err_msg( "Error in case uint8_uint32: ", uint8_uint32[i].x, uint8_uint32[i].y, uint8_uint32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_uint32[i].x);
            si += uint8_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint32[i].fExpected )
        {
            err_msg( "Error in case uint8_uint32 throw (1): ", uint8_uint32[i].x, uint8_uint32[i].y, uint8_uint32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_uint32[i].x);
            x += SafeInt<std::uint32_t>(uint8_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint32[i].fExpected )
        {
            err_msg( "Error in case uint8_uint32 throw (2): ", uint8_uint32[i].x, uint8_uint32[i].y, uint8_uint32[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::uint16_t > uint8_uint16[] = 
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
	{ 0x80, 0x0001, true},
	{ 0x81, 0x0001, true},
	{ 0xfe, 0x0001, true},
	{ 0xff, 0x0001, false},

	{ 0x00, 0x0002, true},
	{ 0x01, 0x0002, true},
	{ 0x02, 0x0002, true},
	{ 0x7e, 0x0002, true},
	{ 0x7f, 0x0002, true},
	{ 0x80, 0x0002, true},
	{ 0x81, 0x0002, true},
	{ 0xfe, 0x0002, false},
	{ 0xff, 0x0002, false},

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

void AddVerifyUint8Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint16); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_uint16[i].x, uint8_uint16[i].y, ret) != uint8_uint16[i].fExpected )
        {
            err_msg( "Error in case uint8_uint16: ", uint8_uint16[i].x, uint8_uint16[i].y, uint8_uint16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_uint16[i].x);
            si += uint8_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint16[i].fExpected )
        {
            err_msg( "Error in case uint8_uint16 throw (1): ", uint8_uint16[i].x, uint8_uint16[i].y, uint8_uint16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_uint16[i].x);
            x += SafeInt<std::uint16_t>(uint8_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint16[i].fExpected )
        {
            err_msg( "Error in case uint8_uint16 throw (2): ", uint8_uint16[i].x, uint8_uint16[i].y, uint8_uint16[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::uint8_t > uint8_uint8[] = 
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
	{ 0x80, 0x01, true},
	{ 0x81, 0x01, true},
	{ 0xfe, 0x01, true},
	{ 0xff, 0x01, false},

	{ 0x00, 0x02, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x02, true},
	{ 0x7e, 0x02, true},
	{ 0x7f, 0x02, true},
	{ 0x80, 0x02, true},
	{ 0x81, 0x02, true},
	{ 0xfe, 0x02, false},
	{ 0xff, 0x02, false},

	{ 0x00, 0x7e, true},
	{ 0x01, 0x7e, true},
	{ 0x02, 0x7e, true},
	{ 0x7e, 0x7e, true},
	{ 0x7f, 0x7e, true},
	{ 0x80, 0x7e, true},
	{ 0x81, 0x7e, true},
	{ 0xfe, 0x7e, false},
	{ 0xff, 0x7e, false},

	{ 0x00, 0x7f, true},
	{ 0x01, 0x7f, true},
	{ 0x02, 0x7f, true},
	{ 0x7e, 0x7f, true},
	{ 0x7f, 0x7f, true},
	{ 0x80, 0x7f, true},
	{ 0x81, 0x7f, false},
	{ 0xfe, 0x7f, false},
	{ 0xff, 0x7f, false},

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
	{ 0x7f, 0x81, false},
	{ 0x80, 0x81, false},
	{ 0x81, 0x81, false},
	{ 0xfe, 0x81, false},
	{ 0xff, 0x81, false},

	{ 0x00, 0xfe, true},
	{ 0x01, 0xfe, true},
	{ 0x02, 0xfe, false},
	{ 0x7e, 0xfe, false},
	{ 0x7f, 0xfe, false},
	{ 0x80, 0xfe, false},
	{ 0x81, 0xfe, false},
	{ 0xfe, 0xfe, false},
	{ 0xff, 0xfe, false},

	{ 0x00, 0xff, true},
	{ 0x01, 0xff, false},
	{ 0x02, 0xff, false},
	{ 0x7e, 0xff, false},
	{ 0x7f, 0xff, false},
	{ 0x80, 0xff, false},
	{ 0x81, 0xff, false},
	{ 0xfe, 0xff, false},
	{ 0xff, 0xff, false},
};

void AddVerifyUint8Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_uint8); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_uint8[i].x, uint8_uint8[i].y, ret) != uint8_uint8[i].fExpected )
        {
            err_msg( "Error in case uint8_uint8: ", uint8_uint8[i].x, uint8_uint8[i].y, uint8_uint8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_uint8[i].x);
            si += uint8_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint8[i].fExpected )
        {
            err_msg( "Error in case uint8_uint8 throw (1): ", uint8_uint8[i].x, uint8_uint8[i].y, uint8_uint8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_uint8[i].x);
            x += SafeInt<std::uint8_t>(uint8_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_uint8[i].fExpected )
        {
            err_msg( "Error in case uint8_uint8 throw (2): ", uint8_uint8[i].x, uint8_uint8[i].y, uint8_uint8[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::int64_t > uint8_int64[] = 
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
	{ 0x80, 0x0000000000000001, true},
	{ 0x81, 0x0000000000000001, true},
	{ 0xfe, 0x0000000000000001, true},
	{ 0xff, 0x0000000000000001, false},

	{ 0x00, 0x0000000000000002, true},
	{ 0x01, 0x0000000000000002, true},
	{ 0x02, 0x0000000000000002, true},
	{ 0x7e, 0x0000000000000002, true},
	{ 0x7f, 0x0000000000000002, true},
	{ 0x80, 0x0000000000000002, true},
	{ 0x81, 0x0000000000000002, true},
	{ 0xfe, 0x0000000000000002, false},
	{ 0xff, 0x0000000000000002, false},

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
	{ 0x02, 0xfffffffffffffffe, true},
	{ 0x7e, 0xfffffffffffffffe, true},
	{ 0x7f, 0xfffffffffffffffe, true},
	{ 0x80, 0xfffffffffffffffe, true},
	{ 0x81, 0xfffffffffffffffe, true},
	{ 0xfe, 0xfffffffffffffffe, true},
	{ 0xff, 0xfffffffffffffffe, true},

	{ 0x00, 0xffffffffffffffff, false},
	{ 0x01, 0xffffffffffffffff, true},
	{ 0x02, 0xffffffffffffffff, true},
	{ 0x7e, 0xffffffffffffffff, true},
	{ 0x7f, 0xffffffffffffffff, true},
	{ 0x80, 0xffffffffffffffff, true},
	{ 0x81, 0xffffffffffffffff, true},
	{ 0xfe, 0xffffffffffffffff, true},
	{ 0xff, 0xffffffffffffffff, true},
};

void AddVerifyUint8Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int64); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_int64[i].x, uint8_int64[i].y, ret) != uint8_int64[i].fExpected )
        {
            err_msg( "Error in case uint8_int64: ", uint8_int64[i].x, uint8_int64[i].y, uint8_int64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_int64[i].x);
            si += uint8_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int64[i].fExpected )
        {
            err_msg( "Error in case uint8_int64 throw (1): ", uint8_int64[i].x, uint8_int64[i].y, uint8_int64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_int64[i].x);
            x += SafeInt<std::int64_t>(uint8_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int64[i].fExpected )
        {
            err_msg( "Error in case uint8_int64 throw (2): ", uint8_int64[i].x, uint8_int64[i].y, uint8_int64[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::int32_t > uint8_int32[] = 
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
	{ 0x80, 0x00000001, true},
	{ 0x81, 0x00000001, true},
	{ 0xfe, 0x00000001, true},
	{ 0xff, 0x00000001, false},

	{ 0x00, 0x00000002, true},
	{ 0x01, 0x00000002, true},
	{ 0x02, 0x00000002, true},
	{ 0x7e, 0x00000002, true},
	{ 0x7f, 0x00000002, true},
	{ 0x80, 0x00000002, true},
	{ 0x81, 0x00000002, true},
	{ 0xfe, 0x00000002, false},
	{ 0xff, 0x00000002, false},

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
	{ 0x02, 0xfffffffe, true},
	{ 0x7e, 0xfffffffe, true},
	{ 0x7f, 0xfffffffe, true},
	{ 0x80, 0xfffffffe, true},
	{ 0x81, 0xfffffffe, true},
	{ 0xfe, 0xfffffffe, true},
	{ 0xff, 0xfffffffe, true},

	{ 0x00, 0xffffffff, false},
	{ 0x01, 0xffffffff, true},
	{ 0x02, 0xffffffff, true},
	{ 0x7e, 0xffffffff, true},
	{ 0x7f, 0xffffffff, true},
	{ 0x80, 0xffffffff, true},
	{ 0x81, 0xffffffff, true},
	{ 0xfe, 0xffffffff, true},
	{ 0xff, 0xffffffff, true},
};

void AddVerifyUint8Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int32); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_int32[i].x, uint8_int32[i].y, ret) != uint8_int32[i].fExpected )
        {
            err_msg( "Error in case uint8_int32: ", uint8_int32[i].x, uint8_int32[i].y, uint8_int32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_int32[i].x);
            si += uint8_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int32[i].fExpected )
        {
            err_msg( "Error in case uint8_int32 throw (1): ", uint8_int32[i].x, uint8_int32[i].y, uint8_int32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_int32[i].x);
            x += SafeInt<std::int32_t>(uint8_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int32[i].fExpected )
        {
            err_msg( "Error in case uint8_int32 throw (2): ", uint8_int32[i].x, uint8_int32[i].y, uint8_int32[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::int16_t > uint8_int16[] = 
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
	{ 0x80, 0x0001, true},
	{ 0x81, 0x0001, true},
	{ 0xfe, 0x0001, true},
	{ 0xff, 0x0001, false},

	{ 0x00, 0x0002, true},
	{ 0x01, 0x0002, true},
	{ 0x02, 0x0002, true},
	{ 0x7e, 0x0002, true},
	{ 0x7f, 0x0002, true},
	{ 0x80, 0x0002, true},
	{ 0x81, 0x0002, true},
	{ 0xfe, 0x0002, false},
	{ 0xff, 0x0002, false},

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
	{ 0x02, 0xfffe, true},
	{ 0x7e, 0xfffe, true},
	{ 0x7f, 0xfffe, true},
	{ 0x80, 0xfffe, true},
	{ 0x81, 0xfffe, true},
	{ 0xfe, 0xfffe, true},
	{ 0xff, 0xfffe, true},

	{ 0x00, 0xffff, false},
	{ 0x01, 0xffff, true},
	{ 0x02, 0xffff, true},
	{ 0x7e, 0xffff, true},
	{ 0x7f, 0xffff, true},
	{ 0x80, 0xffff, true},
	{ 0x81, 0xffff, true},
	{ 0xfe, 0xffff, true},
	{ 0xff, 0xffff, true},
};

void AddVerifyUint8Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int16); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_int16[i].x, uint8_int16[i].y, ret) != uint8_int16[i].fExpected )
        {
            err_msg( "Error in case uint8_int16: ", uint8_int16[i].x, uint8_int16[i].y, uint8_int16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_int16[i].x);
            si += uint8_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int16[i].fExpected )
        {
            err_msg( "Error in case uint8_int16 throw (1): ", uint8_int16[i].x, uint8_int16[i].y, uint8_int16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_int16[i].x);
            x += SafeInt<std::int16_t>(uint8_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int16[i].fExpected )
        {
            err_msg( "Error in case uint8_int16 throw (2): ", uint8_int16[i].x, uint8_int16[i].y, uint8_int16[i].fExpected );
        }
    }
}

static const AddTest< std::uint8_t, std::int8_t > uint8_int8[] = 
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
	{ 0x80, 0x01, true},
	{ 0x81, 0x01, true},
	{ 0xfe, 0x01, true},
	{ 0xff, 0x01, false},

	{ 0x00, 0x02, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x02, true},
	{ 0x7e, 0x02, true},
	{ 0x7f, 0x02, true},
	{ 0x80, 0x02, true},
	{ 0x81, 0x02, true},
	{ 0xfe, 0x02, false},
	{ 0xff, 0x02, false},

	{ 0x00, 0x7e, true},
	{ 0x01, 0x7e, true},
	{ 0x02, 0x7e, true},
	{ 0x7e, 0x7e, true},
	{ 0x7f, 0x7e, true},
	{ 0x80, 0x7e, true},
	{ 0x81, 0x7e, true},
	{ 0xfe, 0x7e, false},
	{ 0xff, 0x7e, false},

	{ 0x00, 0x7f, true},
	{ 0x01, 0x7f, true},
	{ 0x02, 0x7f, true},
	{ 0x7e, 0x7f, true},
	{ 0x7f, 0x7f, true},
	{ 0x80, 0x7f, true},
	{ 0x81, 0x7f, false},
	{ 0xfe, 0x7f, false},
	{ 0xff, 0x7f, false},

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
	{ 0x7f, 0x81, true},
	{ 0x80, 0x81, true},
	{ 0x81, 0x81, true},
	{ 0xfe, 0x81, true},
	{ 0xff, 0x81, true},

	{ 0x00, 0xfe, false},
	{ 0x01, 0xfe, false},
	{ 0x02, 0xfe, true},
	{ 0x7e, 0xfe, true},
	{ 0x7f, 0xfe, true},
	{ 0x80, 0xfe, true},
	{ 0x81, 0xfe, true},
	{ 0xfe, 0xfe, true},
	{ 0xff, 0xfe, true},

	{ 0x00, 0xff, false},
	{ 0x01, 0xff, true},
	{ 0x02, 0xff, true},
	{ 0x7e, 0xff, true},
	{ 0x7f, 0xff, true},
	{ 0x80, 0xff, true},
	{ 0x81, 0xff, true},
	{ 0xfe, 0xff, true},
	{ 0xff, 0xff, true},
};

void AddVerifyUint8Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(uint8_int8); ++i )
    {
        std::uint8_t ret;
        if( SafeAdd(uint8_int8[i].x, uint8_int8[i].y, ret) != uint8_int8[i].fExpected )
        {
            err_msg( "Error in case uint8_int8: ", uint8_int8[i].x, uint8_int8[i].y, uint8_int8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::uint8_t> si(uint8_int8[i].x);
            si += uint8_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int8[i].fExpected )
        {
            err_msg( "Error in case uint8_int8 throw (1): ", uint8_int8[i].x, uint8_int8[i].y, uint8_int8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::uint8_t x(uint8_int8[i].x);
            x += SafeInt<std::int8_t>(uint8_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != uint8_int8[i].fExpected )
        {
            err_msg( "Error in case uint8_int8 throw (2): ", uint8_int8[i].x, uint8_int8[i].y, uint8_int8[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t, std::uint64_t > int8_uint64[] = 
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
	{ 0x7f, 0x0000000000000001, false},
	{ 0x80, 0x0000000000000001, true},
	{ 0x81, 0x0000000000000001, true},
	{ 0xfe, 0x0000000000000001, true},
	{ 0xff, 0x0000000000000001, true},

	{ 0x00, 0x0000000000000002, true},
	{ 0x01, 0x0000000000000002, true},
	{ 0x02, 0x0000000000000002, true},
	{ 0x7e, 0x0000000000000002, false},
	{ 0x7f, 0x0000000000000002, false},
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

void AddVerifyInt8Uint64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint64); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_uint64[i].x, int8_uint64[i].y, ret) != int8_uint64[i].fExpected )
        {
            err_msg( "Error in case int8_uint64: ", int8_uint64[i].x, int8_uint64[i].y, int8_uint64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_uint64[i].x);
            si += int8_uint64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint64[i].fExpected )
        {
            err_msg( "Error in case int8_uint64 throw (1): ", int8_uint64[i].x, int8_uint64[i].y, int8_uint64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_uint64[i].x);
            x += SafeInt<std::uint64_t>(int8_uint64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint64[i].fExpected )
        {
            err_msg( "Error in case int8_uint64 throw (2): ", int8_uint64[i].x, int8_uint64[i].y, int8_uint64[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t, std::uint32_t > int8_uint32[] = 
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
	{ 0x7f, 0x00000001, false},
	{ 0x80, 0x00000001, true},
	{ 0x81, 0x00000001, true},
	{ 0xfe, 0x00000001, true},
	{ 0xff, 0x00000001, true},

	{ 0x00, 0x00000002, true},
	{ 0x01, 0x00000002, true},
	{ 0x02, 0x00000002, true},
	{ 0x7e, 0x00000002, false},
	{ 0x7f, 0x00000002, false},
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

void AddVerifyInt8Uint32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint32); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_uint32[i].x, int8_uint32[i].y, ret) != int8_uint32[i].fExpected )
        {
            err_msg( "Error in case int8_uint32: ", int8_uint32[i].x, int8_uint32[i].y, int8_uint32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_uint32[i].x);
            si += int8_uint32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint32[i].fExpected )
        {
            err_msg( "Error in case int8_uint32 throw (1): ", int8_uint32[i].x, int8_uint32[i].y, int8_uint32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_uint32[i].x);
            x += SafeInt<std::uint32_t>(int8_uint32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint32[i].fExpected )
        {
            err_msg( "Error in case int8_uint32 throw (2): ", int8_uint32[i].x, int8_uint32[i].y, int8_uint32[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t, std::uint16_t > int8_uint16[] = 
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
	{ 0x7f, 0x0001, false},
	{ 0x80, 0x0001, true},
	{ 0x81, 0x0001, true},
	{ 0xfe, 0x0001, true},
	{ 0xff, 0x0001, true},

	{ 0x00, 0x0002, true},
	{ 0x01, 0x0002, true},
	{ 0x02, 0x0002, true},
	{ 0x7e, 0x0002, false},
	{ 0x7f, 0x0002, false},
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

void AddVerifyInt8Uint16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint16); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_uint16[i].x, int8_uint16[i].y, ret) != int8_uint16[i].fExpected )
        {
            err_msg( "Error in case int8_uint16: ", int8_uint16[i].x, int8_uint16[i].y, int8_uint16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_uint16[i].x);
            si += int8_uint16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint16[i].fExpected )
        {
            err_msg( "Error in case int8_uint16 throw (1): ", int8_uint16[i].x, int8_uint16[i].y, int8_uint16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_uint16[i].x);
            x += SafeInt<std::uint16_t>(int8_uint16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint16[i].fExpected )
        {
            err_msg( "Error in case int8_uint16 throw (2): ", int8_uint16[i].x, int8_uint16[i].y, int8_uint16[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t, std::uint8_t > int8_uint8[] = 
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
	{ 0x7f, 0x01, false},
	{ 0x80, 0x01, true},
	{ 0x81, 0x01, true},
	{ 0xfe, 0x01, true},
	{ 0xff, 0x01, true},

	{ 0x00, 0x02, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x02, true},
	{ 0x7e, 0x02, false},
	{ 0x7f, 0x02, false},
	{ 0x80, 0x02, true},
	{ 0x81, 0x02, true},
	{ 0xfe, 0x02, true},
	{ 0xff, 0x02, true},

	{ 0x00, 0x7e, true},
	{ 0x01, 0x7e, true},
	{ 0x02, 0x7e, false},
	{ 0x7e, 0x7e, false},
	{ 0x7f, 0x7e, false},
	{ 0x80, 0x7e, true},
	{ 0x81, 0x7e, true},
	{ 0xfe, 0x7e, true},
	{ 0xff, 0x7e, true},

	{ 0x00, 0x7f, true},
	{ 0x01, 0x7f, false},
	{ 0x02, 0x7f, false},
	{ 0x7e, 0x7f, false},
	{ 0x7f, 0x7f, false},
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
	{ 0x80, 0x81, true},
	{ 0x81, 0x81, true},
	{ 0xfe, 0x81, true},
	{ 0xff, 0x81, false},

	{ 0x00, 0xfe, false},
	{ 0x01, 0xfe, false},
	{ 0x02, 0xfe, false},
	{ 0x7e, 0xfe, false},
	{ 0x7f, 0xfe, false},
	{ 0x80, 0xfe, true},
	{ 0x81, 0xfe, true},
	{ 0xfe, 0xfe, false},
	{ 0xff, 0xfe, false},

	{ 0x00, 0xff, false},
	{ 0x01, 0xff, false},
	{ 0x02, 0xff, false},
	{ 0x7e, 0xff, false},
	{ 0x7f, 0xff, false},
	{ 0x80, 0xff, true},
	{ 0x81, 0xff, false},
	{ 0xfe, 0xff, false},
	{ 0xff, 0xff, false},
};

void AddVerifyInt8Uint8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_uint8); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_uint8[i].x, int8_uint8[i].y, ret) != int8_uint8[i].fExpected )
        {
            err_msg( "Error in case int8_uint8: ", int8_uint8[i].x, int8_uint8[i].y, int8_uint8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_uint8[i].x);
            si += int8_uint8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint8[i].fExpected )
        {
            err_msg( "Error in case int8_uint8 throw (1): ", int8_uint8[i].x, int8_uint8[i].y, int8_uint8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_uint8[i].x);
            x += SafeInt<std::uint8_t>(int8_uint8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_uint8[i].fExpected )
        {
            err_msg( "Error in case int8_uint8 throw (2): ", int8_uint8[i].x, int8_uint8[i].y, int8_uint8[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t,  std::int64_t > int8_int64[] = 
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
	{ 0x7f, 0x0000000000000001, false},
	{ 0x80, 0x0000000000000001, true},
	{ 0x81, 0x0000000000000001, true},
	{ 0xfe, 0x0000000000000001, true},
	{ 0xff, 0x0000000000000001, true},

	{ 0x00, 0x0000000000000002, true},
	{ 0x01, 0x0000000000000002, true},
	{ 0x02, 0x0000000000000002, true},
	{ 0x7e, 0x0000000000000002, false},
	{ 0x7f, 0x0000000000000002, false},
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
	{ 0x80, 0xfffffffffffffffe, false},
	{ 0x81, 0xfffffffffffffffe, false},
	{ 0xfe, 0xfffffffffffffffe, true},
	{ 0xff, 0xfffffffffffffffe, true},

	{ 0x00, 0xffffffffffffffff, true},
	{ 0x01, 0xffffffffffffffff, true},
	{ 0x02, 0xffffffffffffffff, true},
	{ 0x7e, 0xffffffffffffffff, true},
	{ 0x7f, 0xffffffffffffffff, true},
	{ 0x80, 0xffffffffffffffff, false},
	{ 0x81, 0xffffffffffffffff, true},
	{ 0xfe, 0xffffffffffffffff, true},
	{ 0xff, 0xffffffffffffffff, true},
};

void AddVerifyInt8Int64()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int64); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_int64[i].x, int8_int64[i].y, ret) != int8_int64[i].fExpected )
        {
            err_msg( "Error in case int8_int64: ", int8_int64[i].x, int8_int64[i].y, int8_int64[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_int64[i].x);
            si += int8_int64[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int64[i].fExpected )
        {
            err_msg( "Error in case int8_int64 throw (1): ", int8_int64[i].x, int8_int64[i].y, int8_int64[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_int64[i].x);
            x += SafeInt<std::int64_t>(int8_int64[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int64[i].fExpected )
        {
            err_msg( "Error in case int8_int64 throw (2): ", int8_int64[i].x, int8_int64[i].y, int8_int64[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t,  std::int32_t > int8_int32[] = 
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
	{ 0x7f, 0x00000001, false},
	{ 0x80, 0x00000001, true},
	{ 0x81, 0x00000001, true},
	{ 0xfe, 0x00000001, true},
	{ 0xff, 0x00000001, true},

	{ 0x00, 0x00000002, true},
	{ 0x01, 0x00000002, true},
	{ 0x02, 0x00000002, true},
	{ 0x7e, 0x00000002, false},
	{ 0x7f, 0x00000002, false},
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
	{ 0x80, 0xfffffffe, false},
	{ 0x81, 0xfffffffe, false},
	{ 0xfe, 0xfffffffe, true},
	{ 0xff, 0xfffffffe, true},

	{ 0x00, 0xffffffff, true},
	{ 0x01, 0xffffffff, true},
	{ 0x02, 0xffffffff, true},
	{ 0x7e, 0xffffffff, true},
	{ 0x7f, 0xffffffff, true},
	{ 0x80, 0xffffffff, false},
	{ 0x81, 0xffffffff, true},
	{ 0xfe, 0xffffffff, true},
	{ 0xff, 0xffffffff, true},
};

void AddVerifyInt8Int32()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int32); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_int32[i].x, int8_int32[i].y, ret) != int8_int32[i].fExpected )
        {
            err_msg( "Error in case int8_int32: ", int8_int32[i].x, int8_int32[i].y, int8_int32[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_int32[i].x);
            si += int8_int32[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int32[i].fExpected )
        {
            err_msg( "Error in case int8_int32 throw (1): ", int8_int32[i].x, int8_int32[i].y, int8_int32[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_int32[i].x);
            x += SafeInt<std::int32_t>(int8_int32[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int32[i].fExpected )
        {
            err_msg( "Error in case int8_int32 throw (2): ", int8_int32[i].x, int8_int32[i].y, int8_int32[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t,  std::int16_t > int8_int16[] = 
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
	{ 0x7f, 0x0001, false},
	{ 0x80, 0x0001, true},
	{ 0x81, 0x0001, true},
	{ 0xfe, 0x0001, true},
	{ 0xff, 0x0001, true},

	{ 0x00, 0x0002, true},
	{ 0x01, 0x0002, true},
	{ 0x02, 0x0002, true},
	{ 0x7e, 0x0002, false},
	{ 0x7f, 0x0002, false},
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
	{ 0x80, 0xfffe, false},
	{ 0x81, 0xfffe, false},
	{ 0xfe, 0xfffe, true},
	{ 0xff, 0xfffe, true},

	{ 0x00, 0xffff, true},
	{ 0x01, 0xffff, true},
	{ 0x02, 0xffff, true},
	{ 0x7e, 0xffff, true},
	{ 0x7f, 0xffff, true},
	{ 0x80, 0xffff, false},
	{ 0x81, 0xffff, true},
	{ 0xfe, 0xffff, true},
	{ 0xff, 0xffff, true},
};

void AddVerifyInt8Int16()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int16); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_int16[i].x, int8_int16[i].y, ret) != int8_int16[i].fExpected )
        {
            err_msg( "Error in case int8_int16: ", int8_int16[i].x, int8_int16[i].y, int8_int16[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_int16[i].x);
            si += int8_int16[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int16[i].fExpected )
        {
            err_msg( "Error in case int8_int16 throw (1): ", int8_int16[i].x, int8_int16[i].y, int8_int16[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_int16[i].x);
            x += SafeInt<std::int16_t>(int8_int16[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int16[i].fExpected )
        {
            err_msg( "Error in case int8_int16 throw (2): ", int8_int16[i].x, int8_int16[i].y, int8_int16[i].fExpected );
        }
    }
}

static const AddTest< std::int8_t,  std::int8_t > int8_int8[] = 
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
	{ 0x7f, 0x01, false},
	{ 0x80, 0x01, true},
	{ 0x81, 0x01, true},
	{ 0xfe, 0x01, true},
	{ 0xff, 0x01, true},

	{ 0x00, 0x02, true},
	{ 0x01, 0x02, true},
	{ 0x02, 0x02, true},
	{ 0x7e, 0x02, false},
	{ 0x7f, 0x02, false},
	{ 0x80, 0x02, true},
	{ 0x81, 0x02, true},
	{ 0xfe, 0x02, true},
	{ 0xff, 0x02, true},

	{ 0x00, 0x7e, true},
	{ 0x01, 0x7e, true},
	{ 0x02, 0x7e, false},
	{ 0x7e, 0x7e, false},
	{ 0x7f, 0x7e, false},
	{ 0x80, 0x7e, true},
	{ 0x81, 0x7e, true},
	{ 0xfe, 0x7e, true},
	{ 0xff, 0x7e, true},

	{ 0x00, 0x7f, true},
	{ 0x01, 0x7f, false},
	{ 0x02, 0x7f, false},
	{ 0x7e, 0x7f, false},
	{ 0x7f, 0x7f, false},
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
	{ 0x80, 0x81, false},
	{ 0x81, 0x81, false},
	{ 0xfe, 0x81, false},
	{ 0xff, 0x81, true},

	{ 0x00, 0xfe, true},
	{ 0x01, 0xfe, true},
	{ 0x02, 0xfe, true},
	{ 0x7e, 0xfe, true},
	{ 0x7f, 0xfe, true},
	{ 0x80, 0xfe, false},
	{ 0x81, 0xfe, false},
	{ 0xfe, 0xfe, true},
	{ 0xff, 0xfe, true},

	{ 0x00, 0xff, true},
	{ 0x01, 0xff, true},
	{ 0x02, 0xff, true},
	{ 0x7e, 0xff, true},
	{ 0x7f, 0xff, true},
	{ 0x80, 0xff, false},
	{ 0x81, 0xff, true},
	{ 0xfe, 0xff, true},
	{ 0xff, 0xff, true},
};

void AddVerifyInt8Int8()
{
    size_t i;

    for( i = 0; i < COUNTOF(int8_int8); ++i )
    {
        std::int8_t ret;
        if( SafeAdd(int8_int8[i].x, int8_int8[i].y, ret) != int8_int8[i].fExpected )
        {
            err_msg( "Error in case int8_int8: ", int8_int8[i].x, int8_int8[i].y, int8_int8[i].fExpected );
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<std::int8_t> si(int8_int8[i].x);
            si += int8_int8[i].y;
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int8[i].fExpected )
        {
            err_msg( "Error in case int8_int8 throw (1): ", int8_int8[i].x, int8_int8[i].y, int8_int8[i].fExpected );
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            std::int8_t x(int8_int8[i].x);
            x += SafeInt<std::int8_t>(int8_int8[i].y);
        }
        catch(...)
        {
            fSuccess = false;
        }

        if( fSuccess != int8_int8[i].fExpected )
        {
            err_msg( "Error in case int8_int8 throw (2): ", int8_int8[i].x, int8_int8[i].y, int8_int8[i].fExpected );
        }
    }
}

void AddVerify()
{
    std::cout << "Verifying Addition:" << std::endl;

    // Unsigned int64, unsigned cases
    AddVerifyUint64Uint64();
    AddVerifyUint64Uint32();
    AddVerifyUint64Uint16();
    AddVerifyUint64Uint8();

    // Unsigned int64, signed cases
    AddVerifyUint64Int64();
    AddVerifyUint64Int32();
    AddVerifyUint64Int16();
    AddVerifyUint64Int8();

	// Signed int64, unsigned cases
    AddVerifyInt64Uint64();
    AddVerifyInt64Uint32();
    AddVerifyInt64Uint16();
    AddVerifyInt64Uint8();

    // Signed int64, signed cases
    AddVerifyInt64Int64();
    AddVerifyInt64Int32();
    AddVerifyInt64Int16();
    AddVerifyInt64Int8();

	// Unsigned int8, unsigned cases
    AddVerifyUint8Uint64();
    AddVerifyUint8Uint32();
    AddVerifyUint8Uint16();
    AddVerifyUint8Uint8();

    // Unsigned int8, signed cases
    AddVerifyUint8Int64();
    AddVerifyUint8Int32();
    AddVerifyUint8Int16();
    AddVerifyUint8Int8();

	// Signed int8, unsigned cases
    AddVerifyInt8Uint64();
    AddVerifyInt8Uint32();
    AddVerifyInt8Uint16();
    AddVerifyInt8Uint8();

    // Signed int8, signed cases
    AddVerifyInt8Int64();
    AddVerifyInt8Int32();
    AddVerifyInt8Int16();
    AddVerifyInt8Int8();
}

}
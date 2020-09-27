// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"

namespace div_verify
{
/*
* Interesting numbers:
*
*  std::uint64_t
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000000, 0x200000000, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff
*  std::uint32_t
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff
*  std::int64_t
*  0, 1, 2, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000000, 0x200000000, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff
*/

template <typename T, typename U>
struct DivTest
{
   T x;
   U y;
   bool fExpected;
};

// For the most part, unsigned-unsigned combinations are not going to give us any problems
// Only thing to verify is that 0/0 still throws
DivTest< std::uint64_t, std::uint64_t > uint64_uint64[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, true },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, true },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, true },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, true },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, true },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, true },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, true },
   { 1,                     0x8000000000000000, true },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
   { 0x8000000000000000,    0x8000000000000000, true },
   { 0xffffffffffffffff,    0x8000000000000000, true },
   { 0,                     0xffffffffffffffff, true },
   { 1,                     0xffffffffffffffff, true },
   { 2,                     0xffffffffffffffff, true },
   { 0x7fffffff,            0xffffffffffffffff, true },
   { 0x80000000,            0xffffffffffffffff, true },
   { 0xffffffff,            0xffffffffffffffff, true },
   { 0x100000000,           0xffffffffffffffff, true },
   { 0x200000000,           0xffffffffffffffff, true },
   { 0x7fffffffffffffff,    0xffffffffffffffff, true },
   { 0x8000000000000000,    0xffffffffffffffff, true },
   { 0xffffffffffffffff,    0xffffffffffffffff, true },
};

void DivVerifyUint64Uint64()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_uint64)/sizeof(uint64_uint64[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint64: ", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_uint64[i].x);
         si /= uint64_uint64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint64[i].fExpected )
      {
          err_msg( "Error in case uint64_uint64 throw: ", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_uint64[i].x);
         x /= SafeInt<std::uint64_t>(uint64_uint64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint64[i].fExpected )
      {
          err_msg( "Error in case uint64_uint64 throw: ", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::uint32_t > uint64_uint32[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
};

void DivVerifyUint64Uint32()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_uint32)/sizeof(uint64_uint32[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
      {
         //assert(false);
         err_msg( "Error in case uint64_uint32: ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_uint32[i].x);
         si /= uint64_uint32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint32[i].fExpected )
      {
          err_msg( "Error in case uint64_uint32 throw: ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_uint32[i].x);
         x /= SafeInt<std::uint32_t>(uint64_uint32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint32[i].fExpected )
      {
          err_msg( "Error in case uint64_uint32 throw: ", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::uint16_t > uint64_uint16[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
};

void DivVerifyUint64Uint16()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_uint16)/sizeof(uint64_uint16[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_uint16[i].x, uint64_uint16[i].y, ret) != uint64_uint16[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint16: ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_uint16[i].x);
         si /= uint64_uint16[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint16[i].fExpected )
      {
          err_msg( "Error in case uint64_uint16 throw: ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_uint16[i].x);
         x /= SafeInt<std::uint16_t>(uint64_uint16[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint16[i].fExpected )
      {
          err_msg( "Error in case uint64_uint16 throw: ", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::uint8_t > uint64_uint8[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
};

void DivVerifyUint64Uint8()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_uint8)/sizeof(uint64_uint8[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_uint8[i].x, uint64_uint8[i].y, ret) != uint64_uint8[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint8: ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_uint8[i].x);
         si /= uint64_uint8[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint8[i].fExpected )
      {
          err_msg( "Error in case uint64_uint8 throw: ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_uint8[i].x);
         x /= SafeInt<std::uint8_t>(uint64_uint8[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint8[i].fExpected )
      {
          err_msg( "Error in case uint64_uint8 throw: ", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected );
      }
   }
}

// Same problem as unsigned-signed, but anything negative should now fail
// There are corner cases in the U op SafeInt<T> path, which has to be tested
// individually
DivTest< std::uint64_t, std::int64_t > uint64_int64[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, true },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, true },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, true },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, true },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, true },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, true },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, true },
   { 1,                     0x8000000000000000, true },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
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
   { 0xffffffffffffffff,    0xffffffffffffffff, false },
};

void DivVerifyUint64Int64()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_int64)/sizeof(uint64_int64[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_int64[i].x);
         si /= uint64_int64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int64[i].fExpected )
      {
          err_msg( "Error in case uint64_int64 throw: ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_int64[i].x);
         x /= SafeInt<std::int64_t>(uint64_int64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int64[i].fExpected )
      {
          err_msg( "Error in case uint64_int64 throw: ", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::uint64_t > int64_uint64_2[] = 
{
   { 0,                     0, false },
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
   { 0,                     1, false },
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
   { 0,                     2, false },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7fffffff,            2, true },
   { 0x80000000,            2, true },
   { 0xffffffff,            2, true },
   { 0x100000000,           2, true },
   { 0x200000000,           2, true },
   { 0x7fffffffffffffff,    2, true },
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, false },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, false },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
   { 0xffffffffffffffff,    0x80000000, true },
   { 0,                     0xffffffff, false },
   { 1,                     0xffffffff, true },
   { 2,                     0xffffffff, true },
   { 0x7fffffff,            0xffffffff, true },
   { 0x80000000,            0xffffffff, true },
   { 0xffffffff,            0xffffffff, true },
   { 0x100000000,           0xffffffff, true },
   { 0x200000000,           0xffffffff, true },
   { 0x7fffffffffffffff,    0xffffffff, true },
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, false },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, true },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, false },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, true },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, false },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, true },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, false },
   { 1,                     0x8000000000000000, false },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
   { 0x8000000000000000,    0x8000000000000000, true },
   { 0xffffffffffffffff,    0x8000000000000000, true },
   { 0,                     0xffffffffffffffff, false },
   { 1,                     0xffffffffffffffff, false },
   { 2,                     0xffffffffffffffff, true },
   { 0x7fffffff,            0xffffffffffffffff, true },
   { 0x80000000,            0xffffffffffffffff, true },
   { 0xffffffff,            0xffffffffffffffff, true },
   { 0x100000000,           0xffffffffffffffff, true },
   { 0x200000000,           0xffffffffffffffff, true },
   { 0x7fffffffffffffff,    0xffffffffffffffff, true },
   { 0x8000000000000000,    0xffffffffffffffff, true },
   { 0xffffffffffffffff,    0xffffffffffffffff, false },
};

void DivVerifyUint64Int64_2()
{
   size_t i;

   for( i = 0; i < sizeof(int64_uint64_2)/sizeof(int64_uint64_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_uint64_2[i].x);
         SafeInt<std::int64_t> si2;

         si2 = int64_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64_2[i].fExpected )
      {
          err_msg( "Error in case int64_uint64_2 throw: ", int64_uint64_2[i].x, int64_uint64_2[i].y, int64_uint64_2[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::int32_t > uint64_int32[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
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
   { 0xffffffffffffffff,    0xffffffff, false },
};

void DivVerifyUint64Int32()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_int32)/sizeof(uint64_int32[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_int32[i].x);
         si /= uint64_int32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int32[i].fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_int32[i].x);
         x /= SafeInt<std::int64_t>(uint64_int32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int32[i].fExpected )
      {
          err_msg( "Error in case uint64_int64 throw: ", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected );
      }
   }
}

DivTest< std::int32_t, std::uint64_t > int32_uint64_2[] = 
{
   { 0,                     0, false },
   { 1,                     0, true },
   { 2,                     0, true },
   { 0x7fffffff,            0, true },
   { 0x80000000,            0, true },
   { 0xffffffff,            0, true },
   { 0,                     1, false },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7fffffff,            1, true },
   { 0x80000000,            1, true },
   { 0xffffffff,            1, true },
   { 0,                     2, false },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7fffffff,            2, true },
   { 0x80000000,            2, true },
   { 0xffffffff,            2, true },
   { 0,                     0x7fffffff, false },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0,                     0x80000000, false },
   { 1,                     0x80000000, false },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0,                     0xffffffff, false },
   { 1,                     0xffffffff, false },
   { 2,                     0xffffffff, true },
   { 0x7fffffff,            0xffffffff, true },
   { 0x80000000,            0xffffffff, true },
   { 0xffffffff,            0xffffffff, false },
   { 0,                     0x100000000, false },
   { 1,                     0x100000000, false },
   { 2,                     0x100000000, false },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, false },
   { 0,                     0x200000000, false },
   { 1,                     0x200000000, false },
   { 2,                     0x200000000, false },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, false },
   { 0,                     0x7fffffffffffffff, false },
   { 1,                     0x7fffffffffffffff, false },
   { 2,                     0x7fffffffffffffff, false },
   { 0x7fffffff,            0x7fffffffffffffff, false },
   { 0x80000000,            0x7fffffffffffffff, false },
   { 0xffffffff,            0x7fffffffffffffff, false },
   { 0,                     0x8000000000000000, false },
   { 1,                     0x8000000000000000, false },
   { 2,                     0x8000000000000000, false },
   { 0x7fffffff,            0x8000000000000000, false },
   { 0x80000000,            0x8000000000000000, false },
   { 0xffffffff,            0x8000000000000000, false },
   { 0,                     0xffffffffffffffff, false },
   { 1,                     0xffffffffffffffff, false },
   { 2,                     0xffffffffffffffff, false },
   { 0x7fffffff,            0xffffffffffffffff, false },
   { 0x80000000,            0xffffffffffffffff, false },
   { 0xffffffff,            0xffffffffffffffff, false },
};

void DivVerifyUint64Int32_2()
{
   size_t i;

   for( i = 0; i < sizeof(int32_uint64_2)/sizeof(int32_uint64_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(int32_uint64_2[i].x);
         SafeInt<std::int32_t> si2;

         si2 = int32_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int32_uint64_2[i].fExpected )
      {
          err_msg( "Error in case int32_uint64_2 throw: ", int32_uint64_2[i].x, int32_uint64_2[i].y, int32_uint64_2[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::int16_t > uint64_int16[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     -1, true },
   { 1,                     -1, false },
   { 2,                     -1, false },
   { 0x7fffffff,            -1, false },
   { 0x80000000,            -1, false },
   { 0xffffffff,            -1, false },
   { 0x100000000,           -1, false },
   { 0x200000000,           -1, false },
   { 0x7fffffffffffffff,    -1, false },
   { 0x8000000000000000,    -1, false },
   { 0xffffffffffffffff,    -1, false },
};

void DivVerifyUint64Int16()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_int16)/sizeof(uint64_int16[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_int16[i].x, uint64_int16[i].y, ret) != uint64_int16[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_int16[i].x);
         si /= uint64_int16[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int16[i].fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_int16[i].x);
         x /= SafeInt<std::int64_t>(uint64_int16[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int16[i].fExpected )
      {
          err_msg( "Error in case uint64_int16 throw: ", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected );
      }
   }
}

DivTest< std::int16_t, std::uint64_t > int16_uint64_2[] = 
{
   { 0,                     0, false },
   { 1,                     0, true },
   { 2,                     0, true },
   { 0x7fff,                0, true },
   { 0x8000,                0, true },
   { 0xffff,                0, true },
   { 0,                     1, false },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7fff,                1, true },
   { 0x8000,                1, true },
   { 0xffff,                1, true },
   { 0,                     2, false },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7fff,                2, true },
   { 0x8000,                2, true },
   { 0xffff,                2, true },
   { 0,                     0x7fffffff, false },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fff,                0x7fffffff, true },
   { 0x8000,                0x7fffffff, true },
   { 0xffff,                0x7fffffff, true },
   { 0,                     0x80000000, false },
   { 1,                     0x80000000, false },
   { 2,                     0x80000000, true },
   { 0x7fff,                0x80000000, true },
   { 0x8000,                0x80000000, true },
   { 0xffff,                0x80000000, true },
   { 0,                     0xffffffff, false },
   { 1,                     0xffffffff, false },
   { 2,                     0xffffffff, true },
   { 0x7fff,                0xffffffff, true },
   { 0x8000,                0xffffffff, true },
   { 0xffff,                0xffffffff, false },
   { 0,                     0x100000000, false },
   { 1,                     0x100000000, false },
   { 2,                     0x100000000, false },
   { 0x7fff,                0x100000000, true },
   { 0x8000,                0x100000000, true },
   { 0xffff,                0x100000000, false },
   { 0,                     0x200000000, false },
   { 1,                     0x200000000, false },
   { 2,                     0x200000000, false },
   { 0x7fff,                0x200000000, true },
   { 0x8000,                0x200000000, true },
   { 0xffff,                0x200000000, false },
   { 0,                     0x7fffffffffffffff, false },
   { 1,                     0x7fffffffffffffff, false },
   { 2,                     0x7fffffffffffffff, false },
   { 0x7fff,                0x7fffffffffffffff, false },
   { 0x8000,                0x7fffffffffffffff, false },
   { 0xffff,                0x7fffffffffffffff, false },
   { 0,                     0x8000000000000000, false },
   { 1,                     0x8000000000000000, false },
   { 2,                     0x8000000000000000, false },
   { 0x7fff,                0x8000000000000000, false },
   { 0x8000,                0x8000000000000000, false },
   { 0xffff,                0x8000000000000000, false },
   { 0,                     0xffffffffffffffff, false },
   { 1,                     0xffffffffffffffff, false },
   { 2,                     0xffffffffffffffff, false },
   { 0x7fff,                0xffffffffffffffff, false },
   { 0x8000,                0xffffffffffffffff, false },
   { 0xffff,                0xffffffffffffffff, false },
};

void DivVerifyUint64Int16_2()
{
   size_t i;

   for( i = 0; i < sizeof(int16_uint64_2)/sizeof(int16_uint64_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(int16_uint64_2[i].x);
         SafeInt<std::int32_t> si2;

         si2 = int16_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int16_uint64_2[i].fExpected )
      {
          err_msg( "Error in case int16_uint64_2 throw: ", int16_uint64_2[i].x, int16_uint64_2[i].y, int16_uint64_2[i].fExpected );
      }
   }
}

DivTest< std::uint64_t, std::int8_t > uint64_int8[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     -1, true },
   { 1,                     -1, false },
   { 2,                     -1, false },
   { 0x7fffffff,            -1, false },
   { 0x80000000,            -1, false },
   { 0xffffffff,            -1, false },
   { 0x100000000,           -1, false },
   { 0x200000000,           -1, false },
   { 0x7fffffffffffffff,    -1, false },
   { 0x8000000000000000,    -1, false },
   { 0xffffffffffffffff,    -1, false },
};

void DivVerifyUint64Int8()
{
   size_t i;

   for( i = 0; i < sizeof(uint64_int8)/sizeof(uint64_int8[0]); ++i )
   {
      std::uint64_t ret;
      if( SafeDivide(uint64_int8[i].x, uint64_int8[i].y, ret) != uint64_int8[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(uint64_int8[i].x);
         si /= uint64_int8[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int8[i].fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(uint64_int8[i].x);
         x /= SafeInt<std::int64_t>(uint64_int8[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int8[i].fExpected )
      {
          err_msg( "Error in case uint64_int8 throw: ", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected );
      }
   }
}

DivTest< std::int8_t, std::uint64_t > int8_uint64_2[] = 
{
   { 0,                     0, false },
   { 1,                     0, true },
   { 2,                     0, true },
   { 0x7f,                  0, true },
   { 0x80,                  0, true },
   { 0xff,                  0, true },
   { 0,                     1, false },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7f,                  1, true },
   { 0x80,                  1, true },
   { 0xff,                  1, true },
   { 0,                     2, false },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7f,                  2, true },
   { 0x80,                  2, true },
   { 0xff,                  2, true },
   { 0,                     0x7fffffff, false },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7f,                  0x7fffffff, true },
   { 0x80,                  0x7fffffff, true },
   { 0xff,                  0x7fffffff, true },
   { 0,                     0x80000000, false },
   { 1,                     0x80000000, false },
   { 2,                     0x80000000, true },
   { 0x7f,                  0x80000000, true },
   { 0x80,                  0x80000000, true },
   { 0xff,                  0x80000000, true },
   { 0,                     0xffffffff, false },
   { 1,                     0xffffffff, false },
   { 2,                     0xffffffff, true },
   { 0x7f,                  0xffffffff, true },
   { 0x80,                  0xffffffff, true },
   { 0xff,                  0xffffffff, false },
   { 0,                     0x100000000, false },
   { 1,                     0x100000000, false },
   { 2,                     0x100000000, false },
   { 0x7f,                  0x100000000, true },
   { 0x80,                  0x100000000, true },
   { 0xff,                  0x100000000, false },
   { 0,                     0x200000000, false },
   { 1,                     0x200000000, false },
   { 2,                     0x200000000, false },
   { 0x7f,                  0x200000000, true },
   { 0x80,                  0x200000000, true },
   { 0xff,                  0x200000000, false },
   { 0,                     0x7fffffffffffffff, false },
   { 1,                     0x7fffffffffffffff, false },
   { 2,                     0x7fffffffffffffff, false },
   { 0x7f,                  0x7fffffffffffffff, false },
   { 0x80,                  0x7fffffffffffffff, false },
   { 0xff,                  0x7fffffffffffffff, false },
   { 0,                     0x8000000000000000, false },
   { 1,                     0x8000000000000000, false },
   { 2,                     0x8000000000000000, false },
   { 0x7f,                  0x8000000000000000, false },
   { 0x80,                  0x8000000000000000, false },
   { 0xff,                  0x8000000000000000, false },
   { 0,                     0xffffffffffffffff, false },
   { 1,                     0xffffffffffffffff, false },
   { 2,                     0xffffffffffffffff, false },
   { 0x7f,                  0xffffffffffffffff, false },
   { 0x80,                  0xffffffffffffffff, false },
   { 0xff,                  0xffffffffffffffff, false },
};

void DivVerifyUint64Int8_2()
{
   size_t i;

   for( i = 0; i < sizeof(int8_uint64_2)/sizeof(int8_uint64_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(int8_uint64_2[i].x);
         SafeInt<std::int32_t> si2;

         si2 = int8_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int8_uint64_2[i].fExpected )
      {
          err_msg( "Error in case int8_uint64_2 throw: ", int8_uint64_2[i].x, int8_uint64_2[i].y, int8_uint64_2[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::int64_t > int64_int64[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, true },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, true },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, true },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, true },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, true },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, true },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, true },
   { 1,                     0x8000000000000000, true },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
   { 0x8000000000000000,    0x8000000000000000, true },
   { 0xffffffffffffffff,    0x8000000000000000, true },
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
};

void DivVerifyInt64Int64()
{
   size_t i;

   for( i = 0; i < sizeof(int64_int64)/sizeof(int64_int64[0]); ++i )
   {
      std::int64_t ret;
      if( SafeDivide(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_int64: ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_int64[i].x);
         si /= int64_int64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
         err_msg( "Error in case int64_int64 throw: ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(int64_int64[i].x);
         x /= SafeInt<std::int64_t>(int64_int64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
          err_msg( "Error in case int64_int64 throw: ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
      }
   }
}

void DivVerifyInt64Int64_2()
{
   size_t i;

   for( i = 0; i < sizeof(int64_int64)/sizeof(int64_int64[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_int64[i].y);
         SafeInt<std::int64_t> si2;

         si2 = int64_int64[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
          err_msg( "Error in case int64_int64 throw: ", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::int32_t > int64_int32[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0xffffffffffffffff,    0xffffffff, true },
};

void DivVerifyInt64Int32()
{
   size_t i;

   for( i = 0; i < sizeof(int64_int32)/sizeof(int64_int32[0]); ++i )
   {
      std::int64_t ret;
      if( SafeDivide(int64_int32[i].x, int64_int32[i].y, ret) != int64_int32[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_int32: ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_int32[i].x);
         si /= int64_int32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32[i].fExpected )
      {
          err_msg( "Error in case int64_int32 throw: ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(int64_int32[i].x);
         x /= SafeInt<std::int32_t>(int64_int32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32[i].fExpected )
      {
          err_msg( "Error in case int64_int32 throw: ", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::int32_t > int64_int32_2[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
   { 0,                     1, true },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7fffffff,            1, true },
   { 0x80000000,            1, false },
   { 0xffffffff,            1, false },
   { 0x100000000,           1, false },
   { 0x200000000,           1, false },
   { 0x7fffffffffffffff,    1, false },
   { 0x8000000000000000,    1, false },
   { 0xffffffffffffffff,    1, true },
   { 0,                     2, true },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7fffffff,            2, true },
   { 0x80000000,            2, true },
   { 0xffffffff,            2, true },
   { 0x100000000,           2, false },
   { 0x200000000,           2, false },
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
   { 0x200000000,           0x7fffffff, true },
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
   { 0x200000000,           0x80000000, true },
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
};

void DivVerifyInt64Int32_2()
{
   size_t i;

   for( i = 0; i < sizeof(int64_int32_2)/sizeof(int64_int32_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(int64_int32_2[i].y);
         SafeInt<std::int32_t> si2;

         si2 = int64_int32_2[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32_2[i].fExpected )
      {
          err_msg( "Error in case int64_int32_2 throw: ", int64_int32_2[i].x, int64_int32_2[i].y, int64_int32_2[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::uint64_t > int64_uint64[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, true },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, true },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, true },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, true },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, true },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, true },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, true },
   { 1,                     0x8000000000000000, true },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
   { 0x8000000000000000,    0x8000000000000000, true },
   { 0xffffffffffffffff,    0x8000000000000000, true },
   { 0,                     0xffffffffffffffff, true },
   { 1,                     0xffffffffffffffff, true },
   { 2,                     0xffffffffffffffff, true },
   { 0x7fffffff,            0xffffffffffffffff, true },
   { 0x80000000,            0xffffffffffffffff, true },
   { 0xffffffff,            0xffffffffffffffff, true },
   { 0x100000000,           0xffffffffffffffff, true },
   { 0x200000000,           0xffffffffffffffff, true },
   { 0x7fffffffffffffff,    0xffffffffffffffff, true },
   { 0x8000000000000000,    0xffffffffffffffff, true },
   { 0xffffffffffffffff,    0xffffffffffffffff, true },
};

void DivVerifyInt64Uint64()
{
   size_t i;

   for( i = 0; i < sizeof(int64_uint64)/sizeof(int64_uint64[0]); ++i )
   {
      std::int64_t ret;
      if( SafeDivide(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_uint64: ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_uint64[i].x);
         si /= int64_uint64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64[i].fExpected )
      {
          err_msg( "Error in case int64_uint64 throw: ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(int64_uint64[i].x);
         x /= SafeInt<std::uint64_t>(int64_uint64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64[i].fExpected )
      {
         err_msg( "Error in case int64_uint64 throw: ", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::uint64_t > int64_uint64_3[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
   { 0,                     1, true },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7fffffff,            1, true },
   { 0x80000000,            1, true },
   { 0xffffffff,            1, true },
   { 0x100000000,           1, true },
   { 0x200000000,           1, true },
   { 0x7fffffffffffffff,    1, true },
   { 0x8000000000000000,    1, false },
   { 0xffffffffffffffff,    1, false },
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
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, false },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
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
   { 0xffffffffffffffff,    0xffffffff, true },
   { 0,                     0x100000000, true },
   { 1,                     0x100000000, true },
   { 2,                     0x100000000, true },
   { 0x7fffffff,            0x100000000, true },
   { 0x80000000,            0x100000000, true },
   { 0xffffffff,            0x100000000, true },
   { 0x100000000,           0x100000000, true },
   { 0x200000000,           0x100000000, true },
   { 0x7fffffffffffffff,    0x100000000, true },
   { 0x8000000000000000,    0x100000000, false },
   { 0xffffffffffffffff,    0x100000000, true },
   { 0,                     0x200000000, true },
   { 1,                     0x200000000, true },
   { 2,                     0x200000000, true },
   { 0x7fffffff,            0x200000000, true },
   { 0x80000000,            0x200000000, true },
   { 0xffffffff,            0x200000000, true },
   { 0x100000000,           0x200000000, true },
   { 0x200000000,           0x200000000, true },
   { 0x7fffffffffffffff,    0x200000000, true },
   { 0x8000000000000000,    0x200000000, false },
   { 0xffffffffffffffff,    0x200000000, true },
   { 0,                     0x7fffffffffffffff, true },
   { 1,                     0x7fffffffffffffff, true },
   { 2,                     0x7fffffffffffffff, true },
   { 0x7fffffff,            0x7fffffffffffffff, true },
   { 0x80000000,            0x7fffffffffffffff, true },
   { 0xffffffff,            0x7fffffffffffffff, true },
   { 0x100000000,           0x7fffffffffffffff, true },
   { 0x200000000,           0x7fffffffffffffff, true },
   { 0x7fffffffffffffff,    0x7fffffffffffffff, true },
   { 0x8000000000000000,    0x7fffffffffffffff, false },
   { 0xffffffffffffffff,    0x7fffffffffffffff, true },
   { 0,                     0x8000000000000000, true },
   { 1,                     0x8000000000000000, true },
   { 2,                     0x8000000000000000, true },
   { 0x7fffffff,            0x8000000000000000, true },
   { 0x80000000,            0x8000000000000000, true },
   { 0xffffffff,            0x8000000000000000, true },
   { 0x100000000,           0x8000000000000000, true },
   { 0x200000000,           0x8000000000000000, true },
   { 0x7fffffffffffffff,    0x8000000000000000, true },
   { 0x8000000000000000,    0x8000000000000000, false },
   { 0xffffffffffffffff,    0x8000000000000000, true },
   { 0,                     0xffffffffffffffff, true },
   { 1,                     0xffffffffffffffff, true },
   { 2,                     0xffffffffffffffff, true },
   { 0x7fffffff,            0xffffffffffffffff, true },
   { 0x80000000,            0xffffffffffffffff, true },
   { 0xffffffff,            0xffffffffffffffff, true },
   { 0x100000000,           0xffffffffffffffff, true },
   { 0x200000000,           0xffffffffffffffff, true },
   { 0x7fffffffffffffff,    0xffffffffffffffff, true },
   { 0x8000000000000000,    0xffffffffffffffff, true },
   { 0xffffffffffffffff,    0xffffffffffffffff, true },
};

void DivVerifyInt64Uint64_2()
{
   size_t i;

   for( i = 0; i < sizeof(int64_uint64_3)/sizeof(int64_uint64_3[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(int64_uint64_3[i].y);
         SafeInt<std::uint64_t> si2;

         si2 = int64_uint64_3[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64_3[i].fExpected )
      {
         err_msg( "Error in case int64_uint64_3 throw: ", int64_uint64_3[i].x, int64_uint64_3[i].y, int64_uint64_3[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::uint32_t > int64_uint32[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
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
   { 0x8000000000000000,    2, true },
   { 0xffffffffffffffff,    2, true },
   { 0,                     0x7fffffff, true },
   { 1,                     0x7fffffff, true },
   { 2,                     0x7fffffff, true },
   { 0x7fffffff,            0x7fffffff, true },
   { 0x80000000,            0x7fffffff, true },
   { 0xffffffff,            0x7fffffff, true },
   { 0x100000000,           0x7fffffff, true },
   { 0x200000000,           0x7fffffff, true },
   { 0x7fffffffffffffff,    0x7fffffff, true },
   { 0x8000000000000000,    0x7fffffff, true },
   { 0xffffffffffffffff,    0x7fffffff, true },
   { 0,                     0x80000000, true },
   { 1,                     0x80000000, true },
   { 2,                     0x80000000, true },
   { 0x7fffffff,            0x80000000, true },
   { 0x80000000,            0x80000000, true },
   { 0xffffffff,            0x80000000, true },
   { 0x100000000,           0x80000000, true },
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
   { 0x8000000000000000,    0x80000000, true },
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
   { 0x8000000000000000,    0xffffffff, true },
   { 0xffffffffffffffff,    0xffffffff, true },
};

void DivVerifyInt64Uint32()
{
   size_t i;

   for( i = 0; i < sizeof(int64_uint32)/sizeof(int64_uint32[0]); ++i )
   {
      std::int64_t ret;
      if( SafeDivide(int64_uint32[i].x, int64_uint32[i].y, ret) != int64_uint32[i].fExpected )
      {
         //assert(false);
         err_msg( "Error in case int64_uint32: ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(int64_uint32[i].x);
         si /= int64_uint32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32[i].fExpected )
      {
         err_msg( "Error in case int64_uint32 throw: ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(int64_uint32[i].x);
         x /= SafeInt<std::uint32_t>(int64_uint32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32[i].fExpected )
      {
         err_msg( "Error in case int64_uint32 throw: ", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected );
      }
   }
}

DivTest< std::int64_t, std::uint32_t > int64_uint32_2[] = 
{
   { 0,                     0, false },
   { 1,                     0, false },
   { 2,                     0, false },
   { 0x7fffffff,            0, false },
   { 0x80000000,            0, false },
   { 0xffffffff,            0, false },
   { 0x100000000,           0, false },
   { 0x200000000,           0, false },
   { 0x7fffffffffffffff,    0, false },
   { 0x8000000000000000,    0, false },
   { 0xffffffffffffffff,    0, false },
   { 0,                     1, true },
   { 1,                     1, true },
   { 2,                     1, true },
   { 0x7fffffff,            1, true },
   { 0x80000000,            1, true },
   { 0xffffffff,            1, true },
   { 0x100000000,           1, false },
   { 0x200000000,           1, false },
   { 0x7fffffffffffffff,    1, false },
   { 0x8000000000000000,    1, false },
   { 0xffffffffffffffff,    1, false },
   { 0,                     2, true },
   { 1,                     2, true },
   { 2,                     2, true },
   { 0x7fffffff,            2, true },
   { 0x80000000,            2, true },
   { 0xffffffff,            2, true },
   { 0x100000000,           2, true },
   { 0x200000000,           2, false },
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
   { 0x200000000,           0x7fffffff, true },
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
   { 0x200000000,           0x80000000, true },
   { 0x7fffffffffffffff,    0x80000000, true },
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
   { 0xffffffffffffffff,    0xffffffff, true },
};

void DivVerifyInt64Uint32_2()
{
   size_t i;

   for( i = 0; i < sizeof(int64_uint32_2)/sizeof(int64_uint32_2[0]); ++i )
   {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint32_t> si(int64_uint32_2[i].y);
         SafeInt<std::uint32_t> si2;

         si2 = int64_uint32_2[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32_2[i].fExpected )
      {
         err_msg( "Error in case int64_uint32_2 throw: ", int64_uint32_2[i].x, int64_uint32_2[i].y, int64_uint32_2[i].fExpected );
      }
   }
}

void DivVerify()
{
    std::cout << "Verifying Division:" << std::endl;

   // Unsigned int64, unsigned cases
   DivVerifyUint64Uint64();
   DivVerifyUint64Uint32();
   DivVerifyUint64Uint16();
   DivVerifyUint64Uint8();

   // Unsigned int64, signed cases
   DivVerifyUint64Int64();
   DivVerifyUint64Int64_2();
   DivVerifyUint64Int32();
   DivVerifyUint64Int32_2();
   DivVerifyUint64Int16();
   DivVerifyUint64Int16_2();
   DivVerifyUint64Int8();
   DivVerifyUint64Int8_2();

   // int64, signed
   DivVerifyInt64Int64();
   DivVerifyInt64Int64_2();
   DivVerifyInt64Int32();
   DivVerifyInt64Int32_2();
   // 16 and 8-bit cases do not go down 
   // any individual paths

   // int64, unsigned
   DivVerifyInt64Uint64();
   DivVerifyInt64Uint64_2();
   DivVerifyInt64Uint32();
   DivVerifyInt64Uint32_2();
}

} //end namespace
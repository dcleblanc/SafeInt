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

namespace div_verify
{
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
struct DivTest
{
   T x;
   U y;
   bool fExpected;
};

// For the most part, unsigned-unsigned combinations are not going to give us any problems
// Only thing to verify is that 0/0 still throws
DivTest< unsigned __int64, unsigned __int64 > uint64_uint64[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_uint64[i].x, uint64_uint64[i].y, ret) != uint64_uint64[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_uint64: %I64X, %I64X, expected = %s\n", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_uint64[i].x);
         si /= uint64_uint64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint64[i].fExpected )
      {
         printf("Error in case uint64_uint64 throw: %I64X, %I64X, expected = %s\n", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_uint64[i].x);
         x /= SafeInt<unsigned __int64>(uint64_uint64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint64[i].fExpected )
      {
         printf("Error in case uint64_uint64 throw: %I64X, %I64X, expected = %s\n", uint64_uint64[i].x, uint64_uint64[i].y, uint64_uint64[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, unsigned __int32 > uint64_uint32[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_uint32[i].x, uint64_uint32[i].y, ret) != uint64_uint32[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_uint32: %I64X, %X, expected = %s\n", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_uint32[i].x);
         si /= uint64_uint32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint32[i].fExpected )
      {
         printf("Error in case uint64_uint32 throw: %I64X, %X, expected = %s\n", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_uint32[i].x);
         x /= SafeInt<unsigned __int32>(uint64_uint32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint32[i].fExpected )
      {
         printf("Error in case uint64_uint32 throw: %I64X, %X, expected = %s\n", uint64_uint32[i].x, uint64_uint32[i].y, uint64_uint32[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, unsigned __int16 > uint64_uint16[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_uint16[i].x, uint64_uint16[i].y, ret) != uint64_uint16[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_uint16: %I64X, %X, expected = %s\n", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_uint16[i].x);
         si /= uint64_uint16[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint16[i].fExpected )
      {
         printf("Error in case uint64_uint16 throw: %I64X, %X, expected = %s\n", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_uint16[i].x);
         x /= SafeInt<unsigned __int16>(uint64_uint16[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint16[i].fExpected )
      {
         printf("Error in case uint64_uint16 throw: %I64X, %X, expected = %s\n", uint64_uint16[i].x, uint64_uint16[i].y, uint64_uint16[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, unsigned __int8 > uint64_uint8[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_uint8[i].x, uint64_uint8[i].y, ret) != uint64_uint8[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_uint8: %I64X, %X, expected = %s\n", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_uint8[i].x);
         si /= uint64_uint8[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint8[i].fExpected )
      {
         printf("Error in case uint64_uint8 throw: %I64X, %X, expected = %s\n", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_uint8[i].x);
         x /= SafeInt<unsigned __int8>(uint64_uint8[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_uint8[i].fExpected )
      {
         printf("Error in case uint64_uint8 throw: %I64X, %X, expected = %s\n", uint64_uint8[i].x, uint64_uint8[i].y, uint64_uint8[i].fExpected ? "true" : "false");
      }
   }
}

// Same problem as unsigned-signed, but anything negative should now fail
// There are corner cases in the U op SafeInt<T> path, which has to be tested
// individually
DivTest< unsigned __int64, __int64 > uint64_int64[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_int64[i].x, uint64_int64[i].y, ret) != uint64_int64[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_int64: %I64X, %I64X, expected = %s\n", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_int64[i].x);
         si /= uint64_int64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int64[i].fExpected )
      {
         printf("Error in case uint64_int64 throw: %I64X, %I64X, expected = %s\n", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_int64[i].x);
         x /= SafeInt<__int64>(uint64_int64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int64[i].fExpected )
      {
         printf("Error in case uint64_int64 throw: %I64X, %I64X, expected = %s\n", uint64_int64[i].x, uint64_int64[i].y, uint64_int64[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, unsigned __int64 > int64_uint64_2[] = 
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
         SafeInt<__int64> si(int64_uint64_2[i].x);
         SafeInt<__int64> si2;

         si2 = int64_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64_2[i].fExpected )
      {
         printf("Error in case int64_uint64_2 throw: %I64X, %I64X, expected = %s\n", int64_uint64_2[i].x, int64_uint64_2[i].y, int64_uint64_2[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, __int32 > uint64_int32[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_int32[i].x, uint64_int32[i].y, ret) != uint64_int32[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_int64: %I64X, %I64X, expected = %s\n", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_int32[i].x);
         si /= uint64_int32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int32[i].fExpected )
      {
         printf("Error in case uint64_int32 throw: %I64X, %X, expected = %s\n", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_int32[i].x);
         x /= SafeInt<__int64>(uint64_int32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int32[i].fExpected )
      {
         printf("Error in case uint64_int64 throw: %I64X, %X, expected = %s\n", uint64_int32[i].x, uint64_int32[i].y, uint64_int32[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int32, unsigned __int64 > int32_uint64_2[] = 
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
         SafeInt<__int32> si(int32_uint64_2[i].x);
         SafeInt<__int32> si2;

         si2 = int32_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int32_uint64_2[i].fExpected )
      {
         printf("Error in case int32_uint64_2 throw: %X, %I64X, expected = %s\n", int32_uint64_2[i].x, int32_uint64_2[i].y, int32_uint64_2[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, __int16 > uint64_int16[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_int16[i].x, uint64_int16[i].y, ret) != uint64_int16[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_int64: %I64X, %I64X, expected = %s\n", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_int16[i].x);
         si /= uint64_int16[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int16[i].fExpected )
      {
         printf("Error in case uint64_int32 throw: %I64X, %X, expected = %s\n", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_int16[i].x);
         x /= SafeInt<__int64>(uint64_int16[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int16[i].fExpected )
      {
         printf("Error in case uint64_int16 throw: %I64X, %X, expected = %s\n", uint64_int16[i].x, uint64_int16[i].y, uint64_int16[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int16, unsigned __int64 > int16_uint64_2[] = 
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
         SafeInt<__int32> si(int16_uint64_2[i].x);
         SafeInt<__int32> si2;

         si2 = int16_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int16_uint64_2[i].fExpected )
      {
         printf("Error in case int16_uint64_2 throw: %X, %I64X, expected = %s\n", int16_uint64_2[i].x, int16_uint64_2[i].y, int16_uint64_2[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< unsigned __int64, __int8 > uint64_int8[] = 
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
      unsigned __int64 ret;
      if( SafeDivide(uint64_int8[i].x, uint64_int8[i].y, ret) != uint64_int8[i].fExpected )
      {
         //assert(false);
         printf("Error in case uint64_int64: %I64X, %I64X, expected = %s\n", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<unsigned __int64> si(uint64_int8[i].x);
         si /= uint64_int8[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int8[i].fExpected )
      {
         printf("Error in case uint64_int32 throw: %I64X, %X, expected = %s\n", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         unsigned __int64 x(uint64_int8[i].x);
         x /= SafeInt<__int64>(uint64_int8[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != uint64_int8[i].fExpected )
      {
         printf("Error in case uint64_int8 throw: %I64X, %X, expected = %s\n", uint64_int8[i].x, uint64_int8[i].y, uint64_int8[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int8, unsigned __int64 > int8_uint64_2[] = 
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
         SafeInt<__int32> si(int8_uint64_2[i].x);
         SafeInt<__int32> si2;

         si2 = int8_uint64_2[i].y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int8_uint64_2[i].fExpected )
      {
         printf("Error in case int8_uint64_2 throw: %X, %I64X, expected = %s\n", int8_uint64_2[i].x, int8_uint64_2[i].y, int8_uint64_2[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, __int64 > int64_int64[] = 
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
      __int64 ret;
      if( SafeDivide(int64_int64[i].x, int64_int64[i].y, ret) != int64_int64[i].fExpected )
      {
         //assert(false);
         printf("Error in case int64_int64: %I64X, %I64X, expected = %s\n", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<__int64> si(int64_int64[i].x);
         si /= int64_int64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
         printf("Error in case int64_int64 throw: %I64X, %I64X, expected = %s\n", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         __int64 x(int64_int64[i].x);
         x /= SafeInt<__int64>(int64_int64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
         printf("Error in case int64_int64 throw: %I64X, %I64X, expected = %s\n", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
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
         SafeInt<__int64> si(int64_int64[i].y);
         SafeInt<__int64> si2;

         si2 = int64_int64[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int64[i].fExpected )
      {
         printf("Error in case int64_int64 throw: %X, %I64X, expected = %s\n", int64_int64[i].x, int64_int64[i].y, int64_int64[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, __int32 > int64_int32[] = 
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
      __int64 ret;
      if( SafeDivide(int64_int32[i].x, int64_int32[i].y, ret) != int64_int32[i].fExpected )
      {
         //assert(false);
         printf("Error in case int64_int32: %I64X, %I64X, expected = %s\n", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<__int64> si(int64_int32[i].x);
         si /= int64_int32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32[i].fExpected )
      {
         printf("Error in case int64_int32 throw: %I64X, %I64X, expected = %s\n", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         __int64 x(int64_int32[i].x);
         x /= SafeInt<__int32>(int64_int32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32[i].fExpected )
      {
         printf("Error in case int64_int32 throw: %I64X, %I64X, expected = %s\n", int64_int32[i].x, int64_int32[i].y, int64_int32[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, __int32 > int64_int32_2[] = 
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
         SafeInt<__int32> si(int64_int32_2[i].y);
         SafeInt<__int32> si2;

         si2 = int64_int32_2[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_int32_2[i].fExpected )
      {
         printf("Error in case int64_int32_2 throw: %X, %I64X, expected = %s\n", int64_int32_2[i].x, int64_int32_2[i].y, int64_int32_2[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, unsigned __int64 > int64_uint64[] = 
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
      __int64 ret;
      if( SafeDivide(int64_uint64[i].x, int64_uint64[i].y, ret) != int64_uint64[i].fExpected )
      {
         //assert(false);
         printf("Error in case int64_uint64: %I64X, %I64X, expected = %s\n", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<__int64> si(int64_uint64[i].x);
         si /= int64_uint64[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64[i].fExpected )
      {
         printf("Error in case int64_uint64 throw: %I64X, %I64X, expected = %s\n", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         __int64 x(int64_uint64[i].x);
         x /= SafeInt<unsigned __int64>(int64_uint64[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64[i].fExpected )
      {
         printf("Error in case int64_uint64 throw: %I64X, %I64X, expected = %s\n", int64_uint64[i].x, int64_uint64[i].y, int64_uint64[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, unsigned __int64 > int64_uint64_3[] = 
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
         SafeInt<unsigned __int64> si(int64_uint64_3[i].y);
         SafeInt<unsigned __int64> si2;

         si2 = int64_uint64_3[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint64_3[i].fExpected )
      {
         printf("Error in case int64_uint64_3 throw: %X, %I64X, expected = %s\n", int64_uint64_3[i].x, int64_uint64_3[i].y, int64_uint64_3[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, unsigned __int32 > int64_uint32[] = 
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
      __int64 ret;
      if( SafeDivide(int64_uint32[i].x, int64_uint32[i].y, ret) != int64_uint32[i].fExpected )
      {
         //assert(false);
         printf("Error in case int64_uint32: %I64X, %I64X, expected = %s\n", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected ? "true" : "false");
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<__int64> si(int64_uint32[i].x);
         si /= int64_uint32[i].y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32[i].fExpected )
      {
         printf("Error in case int64_uint32 throw: %I64X, %I64X, expected = %s\n", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected ? "true" : "false");
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         __int64 x(int64_uint32[i].x);
         x /= SafeInt<unsigned __int32>(int64_uint32[i].y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32[i].fExpected )
      {
         printf("Error in case int64_uint32 throw: %I64X, %I64X, expected = %s\n", int64_uint32[i].x, int64_uint32[i].y, int64_uint32[i].fExpected ? "true" : "false");
      }
   }
}

DivTest< __int64, unsigned __int32 > int64_uint32_2[] = 
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
         SafeInt<unsigned __int32> si(int64_uint32_2[i].y);
         SafeInt<unsigned __int32> si2;

         si2 = int64_uint32_2[i].x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != int64_uint32_2[i].fExpected )
      {
         printf("Error in case int64_uint32_2 throw: %X, %I64X, expected = %s\n", int64_uint32_2[i].x, int64_uint32_2[i].y, int64_uint32_2[i].fExpected ? "true" : "false");
      }
   }
}

void DivVerify()
{
   printf( "Verifying Division:\n" );

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
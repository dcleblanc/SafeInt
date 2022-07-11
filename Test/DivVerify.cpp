// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"

void DivVerifyUint64Uint64()
{
    TestVector< std::uint64_t, std::uint64_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::uint64_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint64 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::uint64_t>(test.y);
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

void DivVerifyUint64Uint32()
{
    TestVector< std::uint64_t, std::uint32_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::uint32_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
         err_msg( "Error in case uint64_uint32: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::uint32_t>(test.y);
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

void DivVerifyUint64Uint16()
{
    TestVector< std::uint64_t, std::uint16_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::uint16_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint16: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint16 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::uint16_t>(test.y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint16 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Uint8()
{
    TestVector< std::uint64_t, std::uint8_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::uint8_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_uint8: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint8 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::uint8_t>(test.y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_uint8 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int64()
{
    TestVector< std::uint64_t, std::int64_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::int64_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int64 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::int64_t>(test.y);
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

void DivVerifyUint64Int64_2()
{
    TestVector< std::int64_t, std::uint64_t, OpType::Div2 > tests;
    TestCase< std::int64_t, std::uint64_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.x);
         SafeInt<std::int64_t> si2;

         si2 = test.y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int64_uint64_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int32()
{
    TestVector< std::uint64_t, std::int32_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::int32_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::int64_t>(test.y);
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

void DivVerifyUint64Int32_2()
{
    TestVector< std::int32_t, std::uint64_t, OpType::Div2 > tests;
    TestCase< std::int32_t, std::uint64_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(test.x);
         SafeInt<std::int32_t> si2;

         si2 = test.y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int32_uint64_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int16()
{
    TestVector< std::uint64_t, std::int16_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::int16_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::int64_t>(test.y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int16 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int16_2()
{
    TestVector< std::int16_t, std::uint64_t, OpType::Div2 > tests;
    TestCase< std::int16_t, std::uint64_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(test.x);
         SafeInt<std::int32_t> si2;

         si2 = test.y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int16_uint64_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int8()
{
    TestVector< std::uint64_t, std::int8_t, OpType::Div > tests;
    TestCase< std::uint64_t, std::int8_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::uint64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case uint64_int64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::uint64_t x(test.x);
         x /= SafeInt<std::int64_t>(test.y);
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case uint64_int8 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyUint64Int8_2()
{
    TestVector< std::int8_t, std::uint64_t, OpType::Div2 > tests;
    TestCase< std::int8_t, std::uint64_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(test.x);
         SafeInt<std::int32_t> si2;

         si2 = test.y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int8_uint64_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyInt64Int64()
{
    TestVector< std::int64_t, std::int64_t, OpType::Div > tests;
    TestCase< std::int64_t, std::int64_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::int64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_int64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
         err_msg( "Error in case int64_int64 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(test.x);
         x /= SafeInt<std::int64_t>(test.y);
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

void DivVerifyInt64Int64_2()
{
    TestVector< std::int64_t, std::int64_t, OpType::Div > tests;
    TestCase< std::int64_t, std::int64_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.y);
         SafeInt<std::int64_t> si2;

         si2 = test.x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int64_int64 throw: ", test.x, test.y, test.fExpected );
      }

      tests.GetNext();
   }
}

void DivVerifyInt64Int32()
{
    TestVector< std::int64_t, std::int32_t, OpType::Div > tests;
    TestCase< std::int64_t, std::int32_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::int64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_int32: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int64_int32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(test.x);
         x /= SafeInt<std::int32_t>(test.y);
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

void DivVerifyInt64Int32_2()
{
    TestVector< std::int64_t, std::int32_t, OpType::Div2 > tests;
    TestCase< std::int64_t, std::int32_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int32_t> si(test.y);
         SafeInt<std::int32_t> si2;

         si2 = test.x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int64_int32_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyInt64Uint64()
{
    TestVector< std::int64_t, std::uint64_t, OpType::Div > tests;
    TestCase< std::int64_t, std::uint64_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::int64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
          err_msg( "Error in case int64_uint64: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
          err_msg( "Error in case int64_uint64 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(test.x);
         x /= SafeInt<std::uint64_t>(test.y);
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

void DivVerifyInt64Uint64_2()
{
    TestVector< std::uint64_t, std::int64_t, OpType::Div2 > tests;
    TestCase< std::uint64_t, std::int64_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint64_t> si(test.x);
         SafeInt<std::uint64_t> si2;

         si2 = test.y / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
         err_msg( "Error in case int64_uint64_3 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

void DivVerifyInt64Uint32()
{
    TestVector< std::int64_t, std::uint32_t, OpType::Div > tests;
    TestCase< std::int64_t, std::uint32_t, OpType::Div > test = tests.GetNext();

    while (!tests.Done())
    {
      std::int64_t ret;
      if( SafeDivide(test.x, test.y, ret) != test.fExpected )
      {
         //assert(false);
         err_msg( "Error in case int64_uint32: ", test.x, test.y, test.fExpected );
      }

      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::int64_t> si(test.x);
         si /= test.y;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
         err_msg( "Error in case int64_uint32 throw: ", test.x, test.y, test.fExpected );
      }

      // Also need to test the version that assigns back out
      // to a plain int, as it has different logic
      fSuccess = true;
      try
      {
         std::int64_t x(test.x);
         x /= SafeInt<std::uint32_t>(test.y);
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

void DivVerifyInt64Uint32_2()
{
    TestVector< std::int64_t, std::uint32_t, OpType::Div2 > tests;
    TestCase< std::int64_t, std::uint32_t, OpType::Div2 > test = tests.GetNext();

    while (!tests.Done())
    {
      // Now test throwing version
      bool fSuccess = true;
      try
      {
         SafeInt<std::uint32_t> si(test.y);
         SafeInt<std::uint32_t> si2;

         si2 = test.x / si;
      }
      catch(...)
      {
         fSuccess = false;
      }

      if( fSuccess != test.fExpected )
      {
         err_msg( "Error in case int64_uint32_2 throw: ", test.x, test.y, test.fExpected );
      }

      test = tests.GetNext();
   }
}

namespace div_verify
{

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
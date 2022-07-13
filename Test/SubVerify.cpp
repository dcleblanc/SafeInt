// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"

template <typename T, typename U>
void SubVerifyBase(const char* types)
{
    TestVector< T, U, OpType::Sub > tests;
    TestCase< T, U, OpType::Sub > test = tests.GetNext();

    while (!tests.Done())
    {
        T ret;
        if (SafeSubtract(test.x, test.y, ret) != test.fExpected)
        {
            std::string msg = std::string("Error in case ") + types;
            err_msg(msg.c_str(), test.x, test.y, test.fExpected);
        }

        // Now test throwing version
        bool fSuccess = true;
        try
        {
            SafeInt<T> si(test.x);
            si -= test.y;
        }
        catch (...)
        {
            fSuccess = false;
        }

        if (fSuccess != test.fExpected)
        {
            std::string msg = std::string("Error in case ") + types + " throw (1): ";
            err_msg(msg.c_str(), test.x, test.y, test.fExpected);
        }

        // Also need to test the version that assigns back out
        // to a plain int, as it has different logic
        fSuccess = true;
        try
        {
            T x(test.x);
            x -= SafeInt<U>(test.y);
        }
        catch (...)
        {
            fSuccess = false;
        }

        if (fSuccess != test.fExpected)
        {
            std::string msg = std::string("Error in case ") + types + " throw (2): ";
            err_msg(msg.c_str(), test.x, test.y, test.fExpected);
        }

        test = tests.GetNext();
    }
}

namespace sub_verify
{

void SubVerify()
{
    std::cout << "Verifying Subtraction:" << std::endl;

    // Unsigned int64, unsigned cases
    SubVerifyBase< std::uint64_t, std::uint64_t>("uint64_uint64");
    SubVerifyBase< std::uint64_t, std::uint32_t >("uint64_uint32");
    SubVerifyBase< std::uint64_t, std::uint16_t >("uint64_uint16");
    SubVerifyBase< std::uint64_t, std::uint8_t >("uint64_uint8");

    // Unsigned int64, signed cases
    SubVerifyBase< std::uint64_t, std::int64_t >("uint64_int64");
    SubVerifyBase< std::uint64_t, std::int32_t >("uint64_int32");
    SubVerifyBase< std::uint64_t, std::int16_t >("uint64_int16");
    SubVerifyBase< std::uint64_t, std::int8_t >("uint64_int8");

    /////////////////////////////////////
    SubVerifyBase< std::uint32_t, std::uint64_t >("uint32_uint64");
    SubVerifyBase< std::uint32_t, std::uint32_t >("uint32_uint32");
    SubVerifyBase< std::uint32_t, std::int64_t >("uint32_int64");
    SubVerifyBase< std::uint32_t, std::int32_t >("uint32_int32");

    SubVerifyBase< std::int32_t, std::uint64_t >("int32_uint64");
    SubVerifyBase< std::int32_t, std::uint32_t >("int32_uint32");
    SubVerifyBase< std::int32_t, std::int64_t >("int32_int64");
    SubVerifyBase< std::int32_t, std::int32_t >("int32_int32");

    // Unsigned int8, unsigned cases
    SubVerifyBase< std::uint8_t, std::uint64_t >("uint8_uint64");
    SubVerifyBase< std::uint8_t, std::uint32_t >("uint8_uint32");
    SubVerifyBase< std::uint8_t, std::uint16_t >("uint8_uint16");
    SubVerifyBase< std::uint8_t, std::uint8_t >("uint8_uint8");

    // Unsigned int8, signed cases
    SubVerifyBase< std::uint8_t, std::int64_t >("uint8_int64");
    SubVerifyBase< std::uint8_t, std::int32_t >("uint8_int32");
    SubVerifyBase< std::uint8_t, std::int16_t >("uint8_int16");
    SubVerifyBase< std::uint8_t, std::int8_t >("uint8_int8");

    /////////////////////////////////////

    // Signed int64, unsigned cases
    SubVerifyBase< std::int64_t, std::uint64_t >("int64_uint64");
    SubVerifyBase< std::int64_t, std::uint32_t >("int64_uint32");
    SubVerifyBase< std::int64_t, std::uint16_t >("int64_uint16");
    SubVerifyBase< std::int64_t, std::uint8_t >("int64_uint8");

    // Signed int64, signed cases
    SubVerifyBase< std::int64_t, std::int64_t >("int64_int64");
    SubVerifyBase< std::int64_t, std::int32_t >("int64_int32");
    SubVerifyBase< std::int64_t, std::int16_t >("int64_int16");
    SubVerifyBase< std::int64_t, std::int8_t >("int64_int8");

    /////////////////////////////////////

    // Signed int8, unsigned cases
    SubVerifyBase< std::int8_t, std::uint64_t >("int8_uint64");
    SubVerifyBase< std::int8_t, std::uint32_t >("int8_uint32");
    SubVerifyBase< std::int8_t, std::uint16_t >("int8_uint16");
    SubVerifyBase< std::int8_t, std::uint8_t >("int8_uint8");

    // Signed int8, signed cases
    SubVerifyBase< std::int8_t, std::int64_t >("int8_int64");
    SubVerifyBase< std::int8_t, std::int32_t >("int8_int32");
    SubVerifyBase< std::int8_t, std::int16_t >("int8_int16");
    SubVerifyBase< std::int8_t, std::int8_t >("int8_int8");
}

}

namespace negation_verify
{
    template < typename T >
    void NegationVerifyT()
    {
        T minInt = std::numeric_limits<T>::min();
        T test = 2;
        bool result = false;
        T out = 0;

        try
        {
            out = -SafeInt< T >(minInt);
        }
        catch (...)
        {
            result = true;
        }

        if (result == false)
            std::cerr << "Error in NegationVerifyT throw (1): " << std::endl;

        try
        {
            out = -SafeInt< T >(test);
        }
        catch (...)
        {
            result = false;
        }

        if (result == false)
            std::cerr << "Error in NegationVerifyT throw (2): " << std::endl;

        // Now try the non-throwing version

        result = SafeNegation(minInt, out);

        if (result != false)
            std::cerr << "Error in NegationVerifyT nothrow (1): " << std::endl;

        result = SafeNegation(test, out);

        if (result == false)
            std::cerr << "Error in NegationVerifyT nothrow (2): " << std::endl;
    }

    void NegationVerifyAll()
    {
        NegationVerifyT< std::int8_t>();
        NegationVerifyT< std::int16_t>();
        NegationVerifyT< std::int32_t>();
        NegationVerifyT< std::int64_t>();
    }

    void NegationVerify()
    {
        std::cout << "Verifying Negation:" << std::endl;
        NegationVerifyAll();
    }
}
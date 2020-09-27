// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include <math.h>

#if !defined _countof
#define _countof(x) (sizeof(x)/sizeof(x[0]))
#endif

namespace cast_verify
{
	template <typename T>
	struct CastTest
	{
		T x;
		bool fExpected;
	};

	template <typename T>
	void InitializeCastArray(CastTest<T>* tests, size_t cTests)
	{
		for (unsigned long i = 0; i < cTests; ++i)
		{
			switch (i)
			{
			case 0:
				tests[i].x = static_cast<T>(pow(2, 64));
				tests[i].fExpected = false;
				break;
			case 1:
				tests[i].x = static_cast<T>(pow(2, 63));
				tests[i].fExpected = true;
				break;
			case 2:
				tests[i].x = 0;
				tests[i].fExpected = true;
				break;
			case 3:
				// This is peculiar, but (-0.0 < 0.0) == false
				tests[i].x = -0.0;
				tests[i].fExpected = true;
				break;
			case 4:
				tests[i].x = static_cast<T>(-0.01);
				tests[i].fExpected = false;
				break;
			default:
				assert(false);
				break;
			}
		}
	}

	void TestDouble()
	{
		CastTest<double> tests[5];

		InitializeCastArray(tests, _countof(tests));

		for (unsigned i = 0; i < _countof(tests); ++i)
		{
			SafeInt<std::uint64_t> test;
			bool fSuccess;

			try
			{
				test = tests[i].x;
				fSuccess = true;
			}
			catch (...)
			{
				fSuccess = false;
			}

			if(fSuccess != tests[i].fExpected)
				std::cerr << "Error in cast double to std::uint64_t case " << i << std::endl;
		}
	}

	void TestFloat()
	{
		CastTest<float> tests[5];

		InitializeCastArray(tests, _countof(tests));

		for (unsigned i = 0; i < _countof(tests); ++i)
		{
			SafeInt<std::uint64_t> test;
			bool fSuccess;

			try
			{
				test = tests[i].x;
				fSuccess = true;
			}
			catch (...)
			{
				fSuccess = false;
			}

			if (fSuccess != tests[i].fExpected)
				std::cerr << "Error in cast float to std::uint64_t case " << i << std::endl;
		}
	}

	void CastVerify()
	{
		std::cout << "Verifying Casting:" << std::endl;
		TestDouble();
	}
}


// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"
#include <cmath>
#include <cstdint>
#include <limits>

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

	// ---- Float-to-int matrix tests (issue #69) -----------------------------
	//
	// Verifies the float-to-int constructor across all eight integer target
	// cases (signed and unsigned at 1, 2, 4, 8 bytes) crossed with all three
	// floating-point source types (float, double, long double).
	//
	// Acceptance rule: a value u is accepted iff truncation toward zero
	// (the C cast's behavior) produces an in-range T, with one extra policy:
	// any strictly-negative value is rejected for unsigned targets (even
	// -0.5, which would truncate to 0). -0.0 is accepted because -0.0 == 0.0.

	static int g_floatCastErrors = 0;

	template <typename T, typename U>
	static bool TryConstruct(U u, T& out)
	{
		try
		{
			SafeInt<T> s = u;
			out = (T)s;
			return true;
		}
		catch (...)
		{
			out = 0;
			return false;
		}
	}

	template <typename T, typename U>
	static void CheckCase(const char* targetName, const char* sourceName,
	                      const char* caseName, U u,
	                      bool expectAccept, T expectValue = 0)
	{
		T got = 0;
		bool accepted = TryConstruct<T, U>(u, got);

		if (accepted != expectAccept)
		{
			std::cerr << "Error: SafeInt<" << targetName << "> from "
			          << sourceName << " '" << caseName << "': expected "
			          << (expectAccept ? "accept" : "reject") << ", got "
			          << (accepted ? "accept" : "reject") << std::endl;
			++g_floatCastErrors;
			return;
		}

		if (accepted && got != expectValue)
		{
			std::cerr << "Error: SafeInt<" << targetName << "> from "
			          << sourceName << " '" << caseName
			          << "': accepted, but value wrong (got "
			          << static_cast<long long>(got) << ", expected "
			          << static_cast<long long>(expectValue) << ")" << std::endl;
			++g_floatCastErrors;
		}
	}

	// Negative-value cases differ between signed and unsigned targets, so we
	// split into two overloads selected by tag dispatch on whether T is
	// signed. This avoids both MSVC's "conditional expression is constant"
	// warning (C4127) and "unary minus applied to unsigned" (C4146) that
	// fire when an if-statement on a compile-time constant gates code that
	// references T(-N) -- MSVC inspects both branches during template
	// instantiation even when only one is reachable.
	template <typename T, typename U>
	static void RunNegativeCases(const char* targetName, const char* sourceName,
	                             std::true_type /* T is signed */)
	{
		CheckCase<T, U>(targetName, sourceName, "-42.0", U(-42.0), true, T(-42));
		CheckCase<T, U>(targetName, sourceName, "-42.7", U(-42.7), true, T(-42));
		CheckCase<T, U>(targetName, sourceName, "-0.5", U(-0.5), true, T(0));
		CheckCase<T, U>(targetName, sourceName, "-0.999", U(-0.999), true, T(0));

		CheckCase<T, U>(targetName, sourceName, "-min_subnormal",
		                -std::numeric_limits<U>::denorm_min(), true, T(0));
	}

	template <typename T, typename U>
	static void RunNegativeCases(const char* targetName, const char* sourceName,
	                             std::false_type /* T is unsigned */)
	{
		CheckCase<T, U>(targetName, sourceName, "-42.0", U(-42.0), false);
		CheckCase<T, U>(targetName, sourceName, "-42.7", U(-42.7), false);
		CheckCase<T, U>(targetName, sourceName, "-0.5", U(-0.5), false);
		CheckCase<T, U>(targetName, sourceName, "-0.999", U(-0.999), false);

		CheckCase<T, U>(targetName, sourceName, "-min_subnormal",
		                -std::numeric_limits<U>::denorm_min(), false);
	}

	// Run the common test cases that apply to every (T, U) pair.
	template <typename T, typename U>
	static void RunCommonCases(const char* targetName, const char* sourceName)
	{
		// Zero, both signed
		CheckCase<T, U>(targetName, sourceName, "+0.0", U(0.0), true, T(0));
		CheckCase<T, U>(targetName, sourceName, "-0.0", U(-0.0), true, T(0));

		// Small positive integer and fractional
		CheckCase<T, U>(targetName, sourceName, "42.0", U(42.0), true, T(42));
		CheckCase<T, U>(targetName, sourceName, "42.7", U(42.7), true, T(42));

		// 0.5 truncates to 0
		CheckCase<T, U>(targetName, sourceName, "0.5", U(0.5), true, T(0));
		CheckCase<T, U>(targetName, sourceName, "0.999", U(0.999), true, T(0));

		// Subnormal: smallest positive denormal truncates to 0 (accepted always)
		CheckCase<T, U>(targetName, sourceName, "min_subnormal",
		                std::numeric_limits<U>::denorm_min(), true, T(0));

		// Negative-value cases: dispatched on signedness of T.
		RunNegativeCases<T, U>(targetName, sourceName,
		    std::integral_constant<bool, std::numeric_limits<T>::is_signed>());

		// Way out of range
		CheckCase<T, U>(targetName, sourceName, "1e20", U(1e20), false);
		CheckCase<T, U>(targetName, sourceName, "-1e20", U(-1e20), false);

		// NaN, +Inf, -Inf all rejected
		CheckCase<T, U>(targetName, sourceName, "NaN",
		                std::numeric_limits<U>::quiet_NaN(), false);
		CheckCase<T, U>(targetName, sourceName, "+Inf",
		                std::numeric_limits<U>::infinity(), false);
		CheckCase<T, U>(targetName, sourceName, "-Inf",
		                -std::numeric_limits<U>::infinity(), false);
	}

	// Per-target boundary cases. For each target we check T_MIN, T_MAX, and
	// values just inside and just outside the truncation-acceptable range.
	// We only test boundaries that the U type can represent exactly enough
	// to make the test meaningful.

	template <typename U> static void RunBoundary_Int8(const char* sourceName)
	{
		// int8: [-128, 127], so accept (-129, 128).
		CheckCase<std::int8_t, U>("int8", sourceName, "-128.0 (MIN)",
		                          U(-128.0), true, std::int8_t(-128));
		CheckCase<std::int8_t, U>("int8", sourceName, "-128.5 (MIN-0.5, truncates to MIN)",
		                          U(-128.5), true, std::int8_t(-128));
		CheckCase<std::int8_t, U>("int8", sourceName, "-128.999 (truncates to MIN)",
		                          U(-128.999), true, std::int8_t(-128));
		CheckCase<std::int8_t, U>("int8", sourceName, "-129.0 (truncates to -129, out)",
		                          U(-129.0), false);
		CheckCase<std::int8_t, U>("int8", sourceName, "127.0 (MAX)",
		                          U(127.0), true, std::int8_t(127));
		CheckCase<std::int8_t, U>("int8", sourceName, "127.5 (MAX+0.5, truncates to MAX)",
		                          U(127.5), true, std::int8_t(127));
		CheckCase<std::int8_t, U>("int8", sourceName, "127.999 (truncates to MAX)",
		                          U(127.999), true, std::int8_t(127));
		CheckCase<std::int8_t, U>("int8", sourceName, "128.0 (== MAX+1)",
		                          U(128.0), false);
	}

	template <typename U> static void RunBoundary_Uint8(const char* sourceName)
	{
		// uint8: [0, 255], so accept [0, 256). Negative-policy applies.
		CheckCase<std::uint8_t, U>("uint8", sourceName, "0.0", U(0.0),
		                           true, std::uint8_t(0));
		CheckCase<std::uint8_t, U>("uint8", sourceName, "255.0 (MAX)",
		                           U(255.0), true, std::uint8_t(255));
		CheckCase<std::uint8_t, U>("uint8", sourceName, "255.5 (truncates to MAX)",
		                           U(255.5), true, std::uint8_t(255));
		CheckCase<std::uint8_t, U>("uint8", sourceName, "255.999",
		                           U(255.999), true, std::uint8_t(255));
		CheckCase<std::uint8_t, U>("uint8", sourceName, "256.0 (== MAX+1)",
		                           U(256.0), false);
	}

	template <typename U> static void RunBoundary_Int16(const char* sourceName)
	{
		CheckCase<std::int16_t, U>("int16", sourceName, "-32768.0 (MIN)",
		                           U(-32768.0), true, std::int16_t(-32768));
		CheckCase<std::int16_t, U>("int16", sourceName, "-32768.5 (truncates to MIN)",
		                           U(-32768.5), true, std::int16_t(-32768));
		CheckCase<std::int16_t, U>("int16", sourceName, "-32769.0 (out)",
		                           U(-32769.0), false);
		CheckCase<std::int16_t, U>("int16", sourceName, "32767.0 (MAX)",
		                           U(32767.0), true, std::int16_t(32767));
		CheckCase<std::int16_t, U>("int16", sourceName, "32767.5 (truncates to MAX)",
		                           U(32767.5), true, std::int16_t(32767));
		CheckCase<std::int16_t, U>("int16", sourceName, "32768.0 (== MAX+1)",
		                           U(32768.0), false);
	}

	template <typename U> static void RunBoundary_Uint16(const char* sourceName)
	{
		CheckCase<std::uint16_t, U>("uint16", sourceName, "65535.0 (MAX)",
		                            U(65535.0), true, std::uint16_t(65535));
		CheckCase<std::uint16_t, U>("uint16", sourceName, "65535.5 (truncates to MAX)",
		                            U(65535.5), true, std::uint16_t(65535));
		CheckCase<std::uint16_t, U>("uint16", sourceName, "65536.0 (== MAX+1)",
		                            U(65536.0), false);
	}

	// int32 against float: float can't exactly represent every int32 value
	// (24-bit mantissa). The only float value that lands "between"
	// INT32_MIN-1 and INT32_MIN is INT32_MIN itself; we cover that.
	template <typename U> static void RunBoundary_Int32(const char* sourceName)
	{
		// INT32_MIN is exactly representable in any U (-2^31, power of two).
		// We use numeric_limits::min() rather than the literal -2147483648
		// because that literal parses as -(2147483648), and 2147483648 may
		// overflow int on some platforms, becoming unsigned -- which then
		// trips MSVC's C4146 (unary minus on unsigned). Same trick used
		// elsewhere in this file for the int64 boundary cases.
		CheckCase<std::int32_t, U>("int32", sourceName, "INT32_MIN",
		                           U(-2147483648.0), true,
		                           std::numeric_limits<std::int32_t>::min());
		// 2^31 == INT32_MAX+1, exactly representable, must be rejected.
		CheckCase<std::int32_t, U>("int32", sourceName, "INT32_MAX+1 == 2^31",
		                           U(2147483648.0), false);
	}

	// int32 vs double or long double: full open-interval semantics applies.
	template <typename U> static void RunBoundary_Int32_WidePrecision(const char* sourceName)
	{
		CheckCase<std::int32_t, U>("int32", sourceName, "-2147483648.5 (truncates to MIN)",
		                           U(-2147483648.5), true,
		                           std::numeric_limits<std::int32_t>::min());
		CheckCase<std::int32_t, U>("int32", sourceName, "-2147483649.0 (out)",
		                           U(-2147483649.0), false);
		CheckCase<std::int32_t, U>("int32", sourceName, "2147483647.0 (MAX)",
		                           U(2147483647.0), true,
		                           std::numeric_limits<std::int32_t>::max());
		CheckCase<std::int32_t, U>("int32", sourceName, "2147483647.5 (truncates to MAX)",
		                           U(2147483647.5), true,
		                           std::numeric_limits<std::int32_t>::max());
	}

	template <typename U> static void RunBoundary_Uint32(const char* sourceName)
	{
		CheckCase<std::uint32_t, U>("uint32", sourceName, "0.0", U(0.0),
		                            true, std::uint32_t(0));
		CheckCase<std::uint32_t, U>("uint32", sourceName, "4294967296.0 (== MAX+1)",
		                            U(4294967296.0), false);
	}

	template <typename U> static void RunBoundary_Uint32_WidePrecision(const char* sourceName)
	{
		CheckCase<std::uint32_t, U>("uint32", sourceName, "4294967295.0 (MAX)",
		                            U(4294967295.0), true, std::uint32_t(4294967295));
		CheckCase<std::uint32_t, U>("uint32", sourceName, "4294967295.5 (truncates to MAX)",
		                            U(4294967295.5), true, std::uint32_t(4294967295));
	}

	// int64 vs any U: T_MIN-1 = -2^63 - 1 is NOT representable in float or
	// double (53-bit mantissa at this magnitude gives ULP 1024 / 2048). The
	// truncation-acceptance rule still applies over the representable U
	// values -- the only one between "below INT64_MIN-1" and "INT64_MIN" is
	// INT64_MIN itself.
	template <typename U> static void RunBoundary_Int64(const char* sourceName)
	{
		CheckCase<std::int64_t, U>("int64", sourceName, "INT64_MIN",
		                           U(-9223372036854775808.0),
		                           true, std::numeric_limits<std::int64_t>::min());
		CheckCase<std::int64_t, U>("int64", sourceName, "2^63 (== MAX+1)",
		                           U(9223372036854775808.0), false);
	}

	template <typename U> static void RunBoundary_Uint64(const char* sourceName)
	{
		CheckCase<std::uint64_t, U>("uint64", sourceName, "0.0", U(0.0),
		                            true, std::uint64_t(0));
		CheckCase<std::uint64_t, U>("uint64", sourceName, "2^64 (== MAX+1)",
		                            U(18446744073709551616.0), false);
	}

	// int64 against long double where long double has more than 64 mantissa
	// bits (e.g. 80-bit x87 extended on Linux/macOS, or 128-bit on some
	// platforms). On these platforms, T_MIN - 1 = -2^63 - 1 IS exactly
	// representable, and the open-interval rule applies fully.
	// On platforms where long double has 64 mantissa bits or fewer
	// (e.g. MSVC's long double == double), T_MIN - 1 cannot be expressed
	// distinctly from T_MIN, and the gap is empty. The implementation
	// switches forms via tag dispatch on numeric_limits<U>::digits, and
	// so does the test, to avoid MSVC's C4127 ("conditional expression is
	// constant") on the runtime branch.

	template <typename U>
	static void RunBoundary_Int64_WideMantissaLD_Impl(const char* sourceName,
	                                                  std::true_type /* wide */)
	{
		// Open lower bound is active: values in (T_MIN - 1, T_MIN) that
		// truncate to T_MIN are accepted.
		CheckCase<std::int64_t, U>("int64", sourceName,
		                           "-9223372036854775808.5 (truncates to MIN)",
		                           U(-9223372036854775808.5L),
		                           true, std::numeric_limits<std::int64_t>::min());
		CheckCase<std::int64_t, U>("int64", sourceName,
		                           "-9223372036854775809.0 (out)",
		                           U(-9223372036854775809.0L), false);
	}

	template <typename U>
	static void RunBoundary_Int64_WideMantissaLD_Impl(const char* /*sourceName*/,
	                                                  std::false_type /* narrow */)
	{
		// Platform's long double doesn't have enough mantissa to express
		// T_MIN - 1 distinctly from T_MIN; this test set doesn't apply.
	}

	template <typename U> static void RunBoundary_Int64_WideMantissaLD(const char* sourceName)
	{
		RunBoundary_Int64_WideMantissaLD_Impl<U>(sourceName,
		    std::integral_constant<bool, (std::numeric_limits<U>::digits > 64)>());
	}

	template <typename U>
	static void RunAllCommon(const char* sourceName)
	{
		RunCommonCases<std::int8_t,   U>("int8",   sourceName);
		RunCommonCases<std::uint8_t,  U>("uint8",  sourceName);
		RunCommonCases<std::int16_t,  U>("int16",  sourceName);
		RunCommonCases<std::uint16_t, U>("uint16", sourceName);
		RunCommonCases<std::int32_t,  U>("int32",  sourceName);
		RunCommonCases<std::uint32_t, U>("uint32", sourceName);
		RunCommonCases<std::int64_t,  U>("int64",  sourceName);
		RunCommonCases<std::uint64_t, U>("uint64", sourceName);

		RunBoundary_Int8<U>(sourceName);
		RunBoundary_Uint8<U>(sourceName);
		RunBoundary_Int16<U>(sourceName);
		RunBoundary_Uint16<U>(sourceName);
		RunBoundary_Int32<U>(sourceName);
		RunBoundary_Uint32<U>(sourceName);
		RunBoundary_Int64<U>(sourceName);
		RunBoundary_Uint64<U>(sourceName);
	}

	void TestFloatToIntMatrix()
	{
		RunAllCommon<float>("float");

		RunAllCommon<double>("double");
		// double has enough precision for MIN-0.5 etc. on int32 and uint32
		RunBoundary_Int32_WidePrecision<double>("double");
		RunBoundary_Uint32_WidePrecision<double>("double");

		RunAllCommon<long double>("long double");
		RunBoundary_Int32_WidePrecision<long double>("long double");
		RunBoundary_Uint32_WidePrecision<long double>("long double");
		RunBoundary_Int64_WideMantissaLD<long double>("long double");

		if (g_floatCastErrors == 0)
		{
			std::cout << "  All float-to-int cast checks passed." << std::endl;
		}
		else
		{
			std::cout << "  " << g_floatCastErrors
			          << " float-to-int cast failures." << std::endl;
		}
	}

	void CastVerify()
	{
		std::cout << "Verifying Casting:" << std::endl;
		TestDouble();
		TestFloat();
		TestFloatToIntMatrix();
	}
}

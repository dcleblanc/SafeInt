// Copyright (c) OWASP Project (https://www.owasp.org), 2011. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"

#if defined(__GNUC__)
# include <stdint.h>
#endif

#if !defined(CHAR_BIT)
# include <limits.h>
#endif

namespace mod_verify
{
	template <typename T>
	std::string type_name()
	{
		std::ostringstream ostm;
		ostm << (std::numeric_limits<T>::is_signed ? "int" : "uint");
		ostm << (sizeof(T) == 1 ? 8 : sizeof(T) * 8);
		return ostm.str();
	}

// ModVerifyTest2 tests (x) % (0).
template<typename T>
struct ModVerifyTest1
{
	ModVerifyTest1<T>()
	{
		const size_t width = sizeof(T);
		const size_t shift = width * CHAR_BIT - 1;
		const bool expected = true;

		bool divzero;
		SafeInt<T> x = (T)((std::uint64_t)1 << shift);
		SafeInt<T> m(0);

		///////////////////////////////////////////////

		try
		{
			T r;
			r = x % m;
			divzero = false;
		}
		catch(SafeIntException&)
		{
			divzero = true;
		}

		if(divzero != expected)
		{
			std::cerr << "Error in case " << type_name<T>() << ": ";
			std::cerr << to_hex((T)x) << ", " << to_hex((T)m) << ", ";
			std::cerr << "expected = " << (expected ? "divzero" : "no divzero") << std::endl;
		}

		///////////////////////////////////////////////

		try
		{
			T r = x;
			r %= m;
			divzero = false;
		}
		catch(SafeIntException&)
		{
			divzero = true;
		}

		if(divzero != expected)
		{
			std::cerr << "Error in case " << type_name<T>() << ": ";
			std::cerr << to_hex((T)x) << ", " << to_hex((T)m) << ", ";
			std::cerr << "expected = " << (expected ? "divzero" : "no divzero") << std::endl;
		}
	}
};

// ModVerifyTest2 tests (INT_MIN) % (-1).
template<typename T>
struct ModVerifyTest2
{
	ModVerifyTest2<T>()
	{
		const size_t width = sizeof(T);
		const size_t shift = width * CHAR_BIT - 1;

		// GCC using a native built-in int will raise SIGFPE or
		// #DE. However, according to LeBlanc, SafeInt's contract
		// is to return the correct mathematical result or throw.
		// const bool expected = (s == Signed ? true : false);
		const bool expected = false;

		bool overflow;
		SafeInt<T> x = (T)((std::uint64_t)1 << shift);
		SafeInt<T> m((T)-1);

		///////////////////////////////////////////////

		try
		{
			T r;
			r = x % m;
			overflow = false;
		}
		catch(SafeIntException&)
		{
			overflow = true;
		}

		if(overflow != expected)
		{
			std::cerr << "Error in case " << type_name<T>() << ": ";
			std::cerr << to_hex((T)x) << ", " << to_hex((T)m) << ", ";
			std::cerr << "expected = " << (expected ? "overflow" : "no overflow") << std::endl;
		}

		///////////////////////////////////////////////

		try
		{
			T r = x;
			r %= m;
			overflow = false;
		}
		catch(SafeIntException&)
		{
			overflow = true;
		}

		if(overflow != expected)
		{
			std::cerr << "Error in case " << type_name<T>() << ": ";
			std::cerr << to_hex((T)x) << ", " << to_hex((T)m) << ", ";
			std::cerr << "expected = " << (expected ? "overflow" : "no overflow") << std::endl;
		}
	}
};

void ModVerify()
{
	std::cout << "Verifying Reduction:" << std::endl;

	ModVerifyTest1<std::uint64_t> t11;
	ModVerifyTest1<std::int64_t> t12;

	ModVerifyTest1<std::uint32_t> t13;
	ModVerifyTest1<std::int32_t> t14;

	ModVerifyTest1<std::uint16_t> t15;
	ModVerifyTest1<std::int16_t> t16;

	ModVerifyTest1<std::uint8_t> t17;
	ModVerifyTest1<std::int8_t> t18;


	ModVerifyTest2<std::uint64_t> t21;
	ModVerifyTest2<std::int64_t> t22;

	ModVerifyTest2<std::uint32_t> t23;
	ModVerifyTest2<std::int32_t> t24;

	ModVerifyTest2<std::uint16_t> t25;
	ModVerifyTest2<std::int16_t> t26;

	ModVerifyTest2<std::uint8_t> t27;
	ModVerifyTest2<std::int8_t> t28;

	// Lets see.....
	ModVerifyTest1<size_t> t50;
	ModVerifyTest2<size_t> t51;
}

}
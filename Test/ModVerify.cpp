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

enum Sign{ Unsigned, Signed };

// ModVerifyTest2 tests (x) % (0).
template<typename T, Sign s>
struct ModVerifyTest1
{
	ModVerifyTest1<T, s>()
	{
		const size_t width = sizeof(T);
		const size_t shift = width * CHAR_BIT - 1;
		const bool expected = true;

		bool divzero;
		SafeInt<T> x = (T)((unsigned __int64)1 << shift);
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
			cerr << "Error in case " << (s == Unsigned ? "u" : "");
			cerr << "int" << dec << width*CHAR_BIT << " (1): ";

#if !defined(__GNUC__)
# pragma warning(disable: 4127)
#endif
			if(width > 1)
			{
				cerr << HEX(width*2) << (T)x << ", " << HEX(width*2) << (T)m << ", ";
				cerr << "expected = " << (expected ? "divzero" : "no divzero") << endl;
			}
			else
			{
				cerr << HEX(2) << int(0xFF & (T)x) << ", " << HEX(2) << int(0xFF & (T)m) << ", ";
				cerr << "expected = " << (expected ? "divzero" : "no divzero") << endl;
			}
#if !defined(__GNUC__)
# pragma warning(default: 4127)
#endif
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
			cerr << "Error in case " << (s == Unsigned ? "u" : "");
			cerr << "int" << dec << width*CHAR_BIT << " (2): ";

#if !defined(__GNUC__)
# pragma warning(disable: 4127)
#endif
			if(width > 1)
			{
				cerr << HEX(width*2) << (T)x << ", " << HEX(width*2) << (T)m << ", ";
				cerr << "expected = " << (expected ? "divzero" : "no divzero") << endl;
			}
			else
			{
				cerr << HEX(2) << int(0xFF & (T)x) << ", " << HEX(2) << int(0xFF & (T)m) << ", ";
				cerr << "expected = " << (expected ? "divzero" : "no divzero") << endl;
			}
#if !defined(__GNUC__)
# pragma warning(default: 4127)
#endif
		}
	}
};

// ModVerifyTest2 tests (INT_MIN) % (-1).
template<typename T, Sign s>
struct ModVerifyTest2
{
	ModVerifyTest2<T, s>()
	{
		const size_t width = sizeof(T);
		const size_t shift = width * CHAR_BIT - 1;

		// GCC using a native built-in int will raise SIGFPE or
		// #DE. However, according to LeBlanc, SafeInt's contract
		// is to return the correct mathematical result or throw.
		// const bool expected = (s == Signed ? true : false);
		const bool expected = false;

		bool overflow;
		SafeInt<T> x = (T)((unsigned __int64)1 << shift);
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
			cerr << "Error in case " << (s == Unsigned ? "u" : "");
			cerr << "int" << dec << width*CHAR_BIT << " (1): ";

#if !defined(__GNUC__)
# pragma warning(disable: 4127)
#endif
			if(width > 1)
			{
				cerr << HEX(width*2) << (T)x << ", " << HEX(width*2) << (T)m << ", ";
				cerr << "expected = " << (expected ? "overflow" : "no overflow") << endl;
			}
			else
			{
				cerr << HEX(2) << int(0xFF & (T)x) << ", " << HEX(2) << int(0xFF & (T)m) << ", ";
				cerr << "expected = " << (expected ? "overflow" : "no overflow") << endl;
			}
#if !defined(__GNUC__)
# pragma warning(default: 4127)
#endif
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
			cerr << "Error in case " << (s == Unsigned ? "u" : "");
			cerr << "int" << dec << width*CHAR_BIT << " (2): ";

#if !defined(__GNUC__)
# pragma warning(disable: 4127)
#endif
			if(width > 1)
			{
				cerr << HEX(width*2) << (T)x << ", " << HEX(width*2) << (T)m << ", ";
				cerr << "expected = " << (expected ? "overflow" : "no overflow") << endl;
			}
			else
			{
				cerr << HEX(2) << int(0xFF & (T)x) << ", " << HEX(2) << int(0xFF & (T)m) << ", ";
				cerr << "expected = " << (expected ? "overflow" : "no overflow") << endl;
			}
#if !defined(__GNUC__)
# pragma warning(default: 4127)
#endif
		}
	}
};

void ModVerify()
{
	cout << "Verifying Reduction:" << endl;

	ModVerifyTest1<unsigned __int64, Unsigned> t11;
	ModVerifyTest1<__int64, Signed> t12;

	ModVerifyTest1<unsigned __int32, Unsigned> t13;
	ModVerifyTest1<__int32, Signed> t14;

	ModVerifyTest1<unsigned __int16, Unsigned> t15;
	ModVerifyTest1<__int16, Signed> t16;

	ModVerifyTest1<unsigned __int8, Unsigned> t17;
	ModVerifyTest1<__int8, Signed> t18;

#if defined(__GNUC__)
	ModVerifyTest1<uint64_t, Unsigned> t31;
	ModVerifyTest1<int64_t, Signed> t32;

	ModVerifyTest1<uint32_t, Unsigned> t33;
	ModVerifyTest1<int32_t, Signed> t34;

	ModVerifyTest1<uint16_t, Unsigned> t35;
	ModVerifyTest1<int16_t, Signed> t36;

	ModVerifyTest1<uint8_t, Unsigned> t37;
	ModVerifyTest1<int8_t, Signed> t38;
#endif

	ModVerifyTest2<unsigned __int64, Unsigned> t21;
	ModVerifyTest2<__int64, Signed> t22;

	ModVerifyTest2<unsigned __int32, Unsigned> t23;
	ModVerifyTest2<__int32, Signed> t24;

	ModVerifyTest2<unsigned __int16, Unsigned> t25;
	ModVerifyTest2<__int16, Signed> t26;

	ModVerifyTest2<unsigned __int8, Unsigned> t27;
	ModVerifyTest2<__int8, Signed> t28;

#if defined(__GNUC__)
	ModVerifyTest2<uint64_t, Unsigned> t41;
	ModVerifyTest2<int64_t, Signed> t42;

	ModVerifyTest2<uint32_t, Unsigned> t43;
	ModVerifyTest2<int32_t, Signed> t44;

	ModVerifyTest2<uint16_t, Unsigned> t45;
	ModVerifyTest2<int16_t, Signed> t46;

	ModVerifyTest2<uint8_t, Unsigned> t47;
	ModVerifyTest2<int8_t, Signed> t48;
#endif

	// Lets see.....
	ModVerifyTest1<size_t, Unsigned> t50;
	ModVerifyTest2<size_t, Unsigned> t51;
}

}
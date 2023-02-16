#if defined _MSC_VER
#pragma warning(disable: 4464 5045) // include path contains .., Qspectre mitigation
#endif

#include <stdio.h>
#include "../../safe_math.h"

void call_functions(void);

static void safe_cast_compile(void)
{
	char ret_char;
	signed char ret_schar;
	unsigned char ret_uchar;
	short ret_short;
	unsigned short ret_ushort;
	int ret_int;
	unsigned int ret_uint;
	long ret_long;
	unsigned long ret_ulong;
	long long ret_llong;
	unsigned long long ret_ullong;

	int in_int = 1;
	unsigned int in_uint = 1;
	long in_long = 1;
	unsigned long in_ulong = 1;
	long long in_llong = 1;
	unsigned long long in_ullong = 1;


	ret_char = safe_cast_char_int(in_int);
	ret_char = safe_cast_char_uint(in_uint);
	ret_char = safe_cast_char_long(in_long);
	ret_char = safe_cast_char_longlong(in_llong);
	ret_char = safe_cast_char_ulonglong(in_ullong);
	ret_char = safe_cast_char_int(in_int);
	ret_char = safe_cast_char_uint(in_uint);

	ret_schar = safe_cast_schar_int(in_int);
	ret_schar = safe_cast_schar_uint(in_uint);
	ret_schar = safe_cast_schar_long(in_long);
	ret_schar = safe_cast_schar_long(in_long);
	ret_schar = safe_cast_schar_longlong(in_llong);
	ret_schar = safe_cast_schar_ulonglong(in_ullong);
	ret_uchar = safe_cast_uchar_int(in_int);
	ret_uchar = safe_cast_uchar_uint(in_uint);
	ret_uchar = safe_cast_uchar_long(in_long);
	ret_uchar = safe_cast_uchar_long(in_long);
	ret_uchar = safe_cast_uchar_longlong(in_llong);
	ret_uchar = safe_cast_uchar_ulonglong(in_ullong);
	ret_short = safe_cast_short_int(in_int);
	ret_short = safe_cast_short_uint(in_uint);
	ret_short = safe_cast_short_long(in_long);
	ret_short = safe_cast_short_long(in_long);
	ret_short = safe_cast_short_longlong(in_llong);
	ret_short = safe_cast_short_ulonglong(in_ullong);
	ret_ushort = safe_cast_ushort_int(in_int);
	ret_ushort = safe_cast_ushort_uint(in_uint);
	ret_ushort = safe_cast_ushort_long(in_long);
	ret_ushort = safe_cast_ushort_long(in_long);
	ret_ushort = safe_cast_ushort_longlong(in_llong);
	ret_ushort = safe_cast_ushort_ulonglong(in_ullong);
	ret_int = safe_cast_int_uint(in_uint);
	ret_int = safe_cast_int_long(in_long);
	ret_int = safe_cast_int_ulong(in_ulong);
	ret_int = safe_cast_int_ulong(in_ulong);
	ret_int = safe_cast_int_longlong(in_llong);
	ret_int = safe_cast_int_ulonglong(in_ullong);
	ret_uint = safe_cast_uint_int(in_int);
	ret_uint = safe_cast_uint_long(in_long);
	ret_uint = safe_cast_uint_ulong(in_ulong);
	ret_uint = safe_cast_uint_long(in_long);
	ret_uint = safe_cast_uint_ulong(in_ulong);
	ret_uint = safe_cast_uint_longlong(in_llong);
	ret_uint = safe_cast_uint_ulonglong(in_ullong);
	ret_long = safe_cast_long_ulong(in_ulong);
	ret_long = safe_cast_long_longlong(in_llong);
	ret_long = safe_cast_long_ulonglong(in_ullong);
	ret_ulong = safe_cast_ulong_long(in_long);
	ret_ulong = safe_cast_ulong_ulonglong(in_ullong);
	ret_long = safe_cast_long_ulong(in_ulong);
	ret_long = safe_cast_long_longlong(in_llong);
	ret_long = safe_cast_long_ulonglong(in_ullong);
	ret_ulong = safe_cast_ulong_long(in_long);
	ret_ulong = safe_cast_ulong_ulonglong(in_ullong);
	ret_ulong = safe_cast_ulong_longlong(in_llong);
	ret_llong = safe_cast_longlong_ulonglong(in_ullong);
	ret_ullong = safe_cast_ulonglong_longlong(in_llong);

	// quench warnings about unused variables
	if(ret_char ||
		ret_schar ||
		ret_uchar ||
		ret_short ||
		ret_ushort ||
		ret_int ||
		ret_uint ||
		ret_long ||
		ret_ulong ||
		ret_llong ||
		ret_ullong)
		printf(" ");
}

static void check_cast_compile(void)
{
	int ret;
	int in_int = 1;
	unsigned int in_uint = 1;
	long in_long = 1;
	unsigned long in_ulong = 1;
	long long in_llong = 1;
	unsigned long long in_ullong = 1;

	ret = check_cast_char_int(in_int);
	ret = check_cast_char_uint(in_uint);
	ret = check_cast_char_long(in_long);
	ret = check_cast_char_long(in_long);
	ret = check_cast_char_longlong(in_llong);
	ret = check_cast_char_ulonglong(in_ullong);
	ret = check_cast_char_int(in_int);
	ret = check_cast_char_uint(in_uint);
	ret = check_cast_char_long(in_long);
	ret = check_cast_char_long(in_long);
	ret = check_cast_char_longlong(in_llong);
	ret = check_cast_char_ulonglong(in_ullong);
	ret = check_cast_schar_int(in_int);
	ret = check_cast_schar_uint(in_uint);
	ret = check_cast_schar_long(in_long);
	ret = check_cast_schar_long(in_long);
	ret = check_cast_schar_longlong(in_llong);
	ret = check_cast_schar_ulonglong(in_ullong);
	ret = check_cast_uchar_int(in_int);
	ret = check_cast_uchar_uint(in_uint);
	ret = check_cast_uchar_long(in_long);
	ret = check_cast_uchar_long(in_long);
	ret = check_cast_uchar_longlong(in_llong);
	ret = check_cast_uchar_ulonglong(in_ullong);
	ret = check_cast_short_int(in_int);
	ret = check_cast_short_uint(in_uint);
	ret = check_cast_short_long(in_long);
	ret = check_cast_short_long(in_long);
	ret = check_cast_short_longlong(in_llong);
	ret = check_cast_short_ulonglong(in_ullong);
	ret = check_cast_ushort_int(in_int);
	ret = check_cast_ushort_uint(in_uint);
	ret = check_cast_ushort_long(in_long);
	ret = check_cast_ushort_long(in_long);
	ret = check_cast_ushort_longlong(in_llong);
	ret = check_cast_ushort_ulonglong(in_ullong);
	ret = check_cast_int_uint(in_uint);
	ret = check_cast_int_long(in_long);
	ret = check_cast_int_ulong(in_ulong);
	ret = check_cast_int_long(in_long);
	ret = check_cast_int_ulong(in_ulong);
	ret = check_cast_int_longlong(in_llong);
	ret = check_cast_int_ulonglong(in_ullong);
	ret = check_cast_uint_int(in_int);
	ret = check_cast_uint_long(in_long);
	ret = check_cast_uint_ulong(in_ulong);
	ret = check_cast_uint_long(in_long);
	ret = check_cast_uint_ulong(in_ulong);
	ret = check_cast_uint_longlong(in_llong);
	ret = check_cast_uint_ulonglong(in_ullong);
	ret = check_cast_long_ulong(in_ulong);
	ret = check_cast_long_longlong(in_llong);
	ret = check_cast_long_ulonglong(in_ullong);
	ret = check_cast_ulong_long(in_long);
	ret = check_cast_ulong_ulonglong(in_ullong);
	ret = check_cast_ulong_longlong(in_llong);
	ret = check_cast_long_ulong(in_ulong);
	ret = check_cast_long_longlong(in_llong);
	ret = check_cast_long_ulonglong(in_ullong);
	ret = check_cast_ulong_long(in_long);
	ret = check_cast_ulong_ulonglong(in_ullong);
	ret = check_cast_longlong_ulonglong(in_ullong);
	ret = check_cast_ulonglong_longlong(in_llong);

	if(ret) 
		printf(" ");
}

static void safe_add_compile(void)
{
	int ret_int;
	unsigned int ret_uint;
	long ret_long;
	unsigned long ret_ulong;
	long long ret_llong;
	unsigned long long ret_ullong;

	int arg_int = 1;
	unsigned int arg_uint = 1;
	long arg_long = 1;
	unsigned long arg_ulong = 1;
	long long arg_llong = 1;
	unsigned long long arg_ullong = 1;

	ret_int = safe_add_int_int(arg_int, arg_int);
	ret_int = safe_add_int_uint(arg_int, arg_uint);
	ret_int = safe_add_int_longlong(arg_int, arg_llong);
	ret_int = safe_add_int_ulonglong(arg_int, arg_ullong);
	ret_uint = safe_add_uint_int(arg_uint, arg_int);
	ret_uint = safe_add_uint_uint(arg_uint, arg_uint);
	ret_uint = safe_add_uint_longlong(arg_uint, arg_llong);
	ret_uint = safe_add_uint_ulonglong(arg_uint, arg_ullong);
	ret_int = safe_add_int_long(arg_int, arg_long);
	ret_int = safe_add_int_ulong(arg_int, arg_ulong);
	ret_uint = safe_add_uint_long(arg_uint, arg_long);
	ret_uint = safe_add_uint_ulong(arg_uint, arg_ulong);
	ret_long = safe_add_long_int(arg_long, arg_int);
	ret_long = safe_add_long_uint(arg_long, arg_uint);
	ret_long = safe_add_long_long(arg_long, arg_long);
	ret_long = safe_add_long_ulong(arg_long, arg_ulong);
	ret_long = safe_add_long_longlong(arg_long, arg_llong);
	ret_long = safe_add_long_ulonglong(arg_long, arg_ullong);
	ret_ulong = safe_add_ulong_int(arg_ulong, arg_int);
	ret_ulong = safe_add_ulong_uint(arg_ulong, arg_uint);
	ret_ulong = safe_add_ulong_long(arg_ulong, arg_long);
	ret_ulong = safe_add_ulong_ulong(arg_ulong, arg_ulong);
	ret_ulong = safe_add_ulong_longlong(arg_ulong, arg_llong);
	ret_ulong = safe_add_ulong_ulonglong(arg_ulong, arg_ullong);
	ret_llong = safe_add_longlong_long(arg_llong, arg_long);
	ret_llong = safe_add_longlong_ulong(arg_llong, arg_ulong);
	ret_ullong = safe_add_ulonglong_long(arg_ullong, arg_long);
	ret_ullong = safe_add_ulonglong_ulong(arg_ullong, arg_ulong);
	ret_int = safe_add_int_long(arg_int, arg_long);
	ret_int = safe_add_int_ulong(arg_int, arg_ulong);
	ret_uint = safe_add_uint_long(arg_uint, arg_long);
	ret_uint = safe_add_uint_ulong(arg_uint, arg_ulong);
	ret_long = safe_add_long_int(arg_long, arg_int);
	ret_long = safe_add_long_uint(arg_long, arg_uint);
	ret_long = safe_add_long_long(arg_long, arg_long);
	ret_long = safe_add_long_ulong(arg_long, arg_ulong);
	ret_long = safe_add_long_longlong(arg_long, arg_llong);
	ret_long = safe_add_long_ulonglong(arg_long, arg_ullong);
	ret_ulong = safe_add_ulong_int(arg_ulong, arg_int);
	ret_ulong = safe_add_ulong_uint(arg_ulong, arg_uint);
	ret_ulong = safe_add_ulong_long(arg_ulong, arg_long);
	ret_ulong = safe_add_ulong_ulong(arg_ulong, arg_ulong);
	ret_ulong = safe_add_ulong_longlong(arg_ulong, arg_llong);
	ret_ulong = safe_add_ulong_ulonglong(arg_ulong, arg_ullong);
	ret_llong = safe_add_longlong_long(arg_llong, arg_long);
	ret_llong = safe_add_longlong_ulong(arg_llong, arg_ulong);
	ret_ullong = safe_add_ulonglong_long(arg_ullong, arg_long);
	ret_ullong = safe_add_ulonglong_ulong(arg_ullong, arg_ulong);
	ret_llong = safe_add_longlong_int(arg_llong, arg_int);
	ret_llong = safe_add_longlong_uint(arg_llong, arg_uint);
	ret_llong = safe_add_longlong_longlong(arg_llong, arg_llong);
	ret_llong = safe_add_longlong_ulonglong(arg_llong, arg_ullong);
	ret_ullong = safe_add_ulonglong_int(arg_ullong, arg_int);
	ret_ullong = safe_add_ulonglong_uint(arg_ullong, arg_uint);
	ret_ullong = safe_add_ulonglong_longlong(arg_ullong, arg_llong);
	ret_ullong = safe_add_ulonglong_ulonglong(arg_ullong, arg_ullong);

	if(ret_int ||
		ret_uint ||
		ret_long ||
		ret_ulong ||
		ret_llong ||
		ret_ullong) printf(" ");

}

static void check_add_compile(void)
{
	bool ret;
	int arg_int = 1;
	unsigned int arg_uint = 1;
	long arg_long = 1;
	unsigned long arg_ulong = 1;
	long long arg_llong = 1;
	unsigned long long arg_ullong = 1;

		ret = check_add_int_int(arg_int, arg_int, &arg_int);
		ret = check_add_int_uint(arg_int, arg_uint, &arg_int);
		ret = check_add_int_longlong(arg_int, arg_llong, &arg_int);
		ret = check_add_int_ulonglong(arg_int, arg_ullong, &arg_int);
		ret = check_add_uint_int(arg_uint, arg_int, &arg_uint);
		ret = check_add_uint_uint(arg_uint, arg_uint, &arg_uint);
		ret = check_add_uint_longlong(arg_uint, arg_llong, &arg_uint);
		ret = check_add_uint_ulonglong(arg_uint, arg_ullong, &arg_uint);
		ret = check_add_int_long(arg_int, arg_long, &arg_int);
		ret = check_add_int_ulong(arg_int, arg_ulong, &arg_int);
		ret = check_add_uint_long(arg_uint, arg_long, &arg_uint);
		ret = check_add_uint_ulong(arg_uint, arg_ulong, &arg_uint);
		ret = check_add_long_int(arg_long, arg_int, &arg_long);
		ret = check_add_long_uint(arg_long, arg_uint, &arg_long);
		ret = check_add_long_long(arg_long, arg_long, &arg_long);
		ret = check_add_long_ulong(arg_long, arg_ulong, &arg_long);
		ret = check_add_long_longlong(arg_long, arg_llong, &arg_long);
		ret = check_add_long_ulonglong(arg_long, arg_ullong, &arg_long);
		ret = check_add_ulong_int(arg_ulong, arg_int, &arg_ulong);
		ret = check_add_ulong_uint(arg_ulong, arg_uint, &arg_ulong);
		ret = check_add_ulong_long(arg_ulong, arg_long, &arg_ulong);
		ret = check_add_ulong_ulong(arg_ulong, arg_ulong, &arg_ulong);
		ret = check_add_ulong_longlong(arg_ulong, arg_llong, &arg_ulong);
		ret = check_add_ulong_ulonglong(arg_ulong, arg_ullong, &arg_ulong);
		ret = check_add_longlong_long(arg_llong, arg_long, &arg_llong);
		ret = check_add_longlong_ulong(arg_llong, arg_ulong, &arg_llong);
		ret = check_add_ulonglong_long(arg_ullong, arg_long, &arg_ullong);
		ret = check_add_ulonglong_ulong(arg_ullong, arg_ulong, &arg_ullong);
		ret = check_add_int_long(arg_int, arg_long, &arg_int);
		ret = check_add_int_ulong(arg_int, arg_ulong, &arg_int);
		ret = check_add_uint_long(arg_uint, arg_long, &arg_uint);
		ret = check_add_uint_ulong(arg_uint, arg_ulong, &arg_uint);
		ret = check_add_long_int(arg_long, arg_int, &arg_long);
		ret = check_add_long_uint(arg_long, arg_uint, &arg_long);
		ret = check_add_long_long(arg_long, arg_long, &arg_long);
		ret = check_add_long_ulong(arg_long, arg_ulong, &arg_long);
		ret = check_add_long_longlong(arg_long, arg_llong, &arg_long);
		ret = check_add_long_ulonglong(arg_long, arg_ullong, &arg_long);
		ret = check_add_ulong_int(arg_ulong, arg_int, &arg_ulong);
		ret = check_add_ulong_uint(arg_ulong, arg_uint, &arg_ulong);
		ret = check_add_ulong_long(arg_ulong, arg_long, &arg_ulong);
		ret = check_add_ulong_ulong(arg_ulong, arg_ulong, &arg_ulong);
		ret = check_add_ulong_longlong(arg_ulong, arg_llong, &arg_ulong);
		ret = check_add_ulong_ulonglong(arg_ulong, arg_ullong, &arg_ulong);
		ret = check_add_longlong_long(arg_llong, arg_long, &arg_llong);
		ret = check_add_longlong_ulong(arg_llong, arg_ulong, &arg_llong);
		ret = check_add_ulonglong_long(arg_ullong, arg_long, &arg_ullong);
		ret = check_add_ulonglong_ulong(arg_ullong, arg_ulong, &arg_ullong);
		ret = check_add_longlong_int(arg_llong, arg_int, &arg_llong);
		ret = check_add_longlong_uint(arg_llong, arg_uint, &arg_llong);
		ret = check_add_longlong_longlong(arg_llong, arg_llong, &arg_llong);
		ret = check_add_longlong_ulonglong(arg_llong, arg_ullong, &arg_llong);
		ret = check_add_ulonglong_int(arg_ullong, arg_int, &arg_ullong);
		ret = check_add_ulonglong_uint(arg_ullong, arg_uint, &arg_ullong);
		ret = check_add_ulonglong_longlong(arg_ullong, arg_llong, &arg_ullong);
		ret = check_add_ulonglong_ulonglong(arg_ullong, arg_ullong, &arg_ullong);

		if(ret)
		{
			printf(" ");
		}
}

static void safe_mul_compile(void)
{
	int ret_int;
	unsigned int ret_uint;
	long ret_long;
	unsigned long ret_ulong;
	long long ret_llong;
	unsigned long long ret_ullong;
	int arg_int = 1;
	unsigned int arg_uint = 1;
	long arg_long = 1;
	unsigned long arg_ulong = 1;
	long long arg_llong = 1;
	unsigned long long arg_ullong = 1;

	ret_int = safe_mul_int_int(arg_int, arg_int);
	ret_int = safe_mul_int_uint(arg_int, arg_uint);
	ret_int = safe_mul_int_longlong(arg_int, arg_llong);
	ret_int = safe_mul_int_ulonglong(arg_int, arg_ullong);
	ret_uint = safe_mul_uint_int(arg_uint, arg_int);
	ret_uint = safe_mul_uint_uint(arg_uint, arg_uint);
	ret_uint = safe_mul_uint_longlong(arg_uint, arg_llong);
	ret_uint = safe_mul_uint_ulonglong(arg_uint, arg_ullong);
	ret_int = safe_mul_int_long(arg_int, arg_long);
	ret_int = safe_mul_int_ulong(arg_int, arg_ulong);
	ret_uint = safe_mul_uint_long(arg_uint, arg_long);
	ret_uint = safe_mul_uint_ulong(arg_uint, arg_ulong);
	ret_long = safe_mul_long_int(arg_long, arg_int);
	ret_long = safe_mul_long_uint(arg_long, arg_uint);
	ret_long = safe_mul_long_long(arg_long, arg_long);
	ret_long = safe_mul_long_ulong(arg_long, arg_ulong);
	ret_long = safe_mul_long_longlong(arg_long, arg_llong);
	ret_long = safe_mul_long_ulonglong(arg_long, arg_ullong);
	ret_ulong = safe_mul_ulong_int(arg_ulong, arg_int);
	ret_ulong = safe_mul_ulong_uint(arg_ulong, arg_uint);
	ret_ulong = safe_mul_ulong_long(arg_ulong, arg_long);
	ret_ulong = safe_mul_ulong_ulong(arg_ulong, arg_ulong);
	ret_ulong = safe_mul_ulong_longlong(arg_ulong, arg_llong);
	ret_ulong = safe_mul_ulong_ulonglong(arg_ulong, arg_ullong);
	ret_llong = safe_mul_longlong_long(arg_llong, arg_long);
	ret_llong = safe_mul_longlong_ulong(arg_llong, arg_ulong);
	ret_ullong = safe_mul_ulonglong_long(arg_ullong, arg_long);
	ret_ullong = safe_mul_ulonglong_ulong(arg_ullong, arg_ulong);
	ret_int = safe_mul_int_long(arg_int, arg_long);
	ret_int = safe_mul_int_ulong(arg_int, arg_ulong);
	ret_uint = safe_mul_uint_long(arg_uint, arg_long);
	ret_uint = safe_mul_uint_ulong(arg_uint, arg_ulong);
	ret_long = safe_mul_long_int(arg_long, arg_int);
	ret_long = safe_mul_long_uint(arg_long, arg_uint);
	ret_long = safe_mul_long_long(arg_long, arg_long);
	ret_long = safe_mul_long_ulong(arg_long, arg_ulong);
	ret_long = safe_mul_long_longlong(arg_long, arg_llong);
	ret_long = safe_mul_long_ulonglong(arg_long, arg_ullong);
	ret_ulong = safe_mul_ulong_int(arg_ulong, arg_int);
	ret_ulong = safe_mul_ulong_uint(arg_ulong, arg_uint);
	ret_ulong = safe_mul_ulong_long(arg_ulong, arg_long);
	ret_ulong = safe_mul_ulong_ulong(arg_ulong, arg_ulong);
	ret_ulong = safe_mul_ulong_longlong(arg_ulong, arg_llong);
	ret_ulong = safe_mul_ulong_ulonglong(arg_ulong, arg_ullong);
	ret_llong = safe_mul_longlong_long(arg_llong, arg_long);
	ret_llong = safe_mul_longlong_ulong(arg_llong, arg_ulong);
	ret_ullong = safe_mul_ulonglong_long(arg_ullong, arg_long);
	ret_ullong = safe_mul_ulonglong_ulong(arg_ullong, arg_ulong);
	ret_llong = safe_mul_longlong_int(arg_llong, arg_int);
	ret_llong = safe_mul_longlong_uint(arg_llong, arg_uint);
	ret_llong = safe_mul_longlong_longlong(arg_llong, arg_llong);
	ret_llong = safe_mul_longlong_ulonglong(arg_llong, arg_ullong);
	ret_ullong = safe_mul_ulonglong_int(arg_ullong, arg_int);
	ret_ullong = safe_mul_ulonglong_uint(arg_ullong, arg_uint);
	ret_ullong = safe_mul_ulonglong_longlong(arg_ullong, arg_llong);
	ret_ullong = safe_mul_ulonglong_ulonglong(arg_ullong, arg_ullong);

	if(ret_int ||
		ret_uint ||
		ret_long ||
		ret_ulong ||
		ret_llong ||
		ret_ullong) printf(" ");

}

static void check_mul_compile(void)
{
	bool ret;
	int arg_int = 1;
	unsigned int arg_uint = 1;
	long arg_long = 1;
	unsigned long arg_ulong = 1;
	long long arg_llong = 1;
	unsigned long long arg_ullong = 1;

	ret = check_mul_int_int(arg_int, arg_int, &arg_int);
	ret = check_mul_int_uint(arg_int, arg_uint, &arg_int);
	ret = check_mul_int_longlong(arg_int, arg_llong, &arg_int);
	ret = check_mul_int_ulonglong(arg_int, arg_ullong, &arg_int);
	ret = check_mul_uint_int(arg_uint, arg_int, &arg_uint);
	ret = check_mul_uint_uint(arg_uint, arg_uint, &arg_uint);
	ret = check_mul_uint_longlong(arg_uint, arg_llong, &arg_uint);
	ret = check_mul_uint_ulonglong(arg_uint, arg_ullong, &arg_uint);
	ret = check_mul_int_long(arg_int, arg_long, &arg_int);
	ret = check_mul_int_ulong(arg_int, arg_ulong, &arg_int);
	ret = check_mul_uint_long(arg_uint, arg_long, &arg_uint);
	ret = check_mul_uint_ulong(arg_uint, arg_ulong, &arg_uint);
	ret = check_mul_long_int(arg_long, arg_int, &arg_long);
	ret = check_mul_long_uint(arg_long, arg_uint, &arg_long);
	ret = check_mul_long_long(arg_long, arg_long, &arg_long);
	ret = check_mul_long_ulong(arg_long, arg_ulong, &arg_long);
	ret = check_mul_long_longlong(arg_long, arg_llong, &arg_long);
	ret = check_mul_long_ulonglong(arg_long, arg_ullong, &arg_long);
	ret = check_mul_ulong_int(arg_ulong, arg_int, &arg_ulong);
	ret = check_mul_ulong_uint(arg_ulong, arg_uint, &arg_ulong);
	ret = check_mul_ulong_long(arg_ulong, arg_long, &arg_ulong);
	ret = check_mul_ulong_ulong(arg_ulong, arg_ulong, &arg_ulong);
	ret = check_mul_ulong_longlong(arg_ulong, arg_llong, &arg_ulong);
	ret = check_mul_ulong_ulonglong(arg_ulong, arg_ullong, &arg_ulong);
	ret = check_mul_longlong_long(arg_llong, arg_long, &arg_llong);
	ret = check_mul_longlong_ulong(arg_llong, arg_ulong, &arg_llong);
	ret = check_mul_ulonglong_long(arg_ullong, arg_long, &arg_ullong);
	ret = check_mul_ulonglong_ulong(arg_ullong, arg_ulong, &arg_ullong);
	ret = check_mul_int_long(arg_int, arg_long, &arg_int);
	ret = check_mul_int_ulong(arg_int, arg_ulong, &arg_int);
	ret = check_mul_uint_long(arg_uint, arg_long, &arg_uint);
	ret = check_mul_uint_ulong(arg_uint, arg_ulong, &arg_uint);
	ret = check_mul_long_int(arg_long, arg_int, &arg_long);
	ret = check_mul_long_uint(arg_long, arg_uint, &arg_long);
	ret = check_mul_long_long(arg_long, arg_long, &arg_long);
	ret = check_mul_long_ulong(arg_long, arg_ulong, &arg_long);
	ret = check_mul_long_longlong(arg_long, arg_llong, &arg_long);
	ret = check_mul_long_ulonglong(arg_long, arg_ullong, &arg_long);
	ret = check_mul_ulong_int(arg_ulong, arg_int, &arg_ulong);
	ret = check_mul_ulong_uint(arg_ulong, arg_uint, &arg_ulong);
	ret = check_mul_ulong_long(arg_ulong, arg_long, &arg_ulong);
	ret = check_mul_ulong_ulong(arg_ulong, arg_ulong, &arg_ulong);
	ret = check_mul_ulong_longlong(arg_ulong, arg_llong, &arg_ulong);
	ret = check_mul_ulong_ulonglong(arg_ulong, arg_ullong, &arg_ulong);
	ret = check_mul_longlong_long(arg_llong, arg_long, &arg_llong);
	ret = check_mul_longlong_ulong(arg_llong, arg_ulong, &arg_llong);
	ret = check_mul_ulonglong_long(arg_ullong, arg_long, &arg_ullong);
	ret = check_mul_ulonglong_ulong(arg_ullong, arg_ulong, &arg_ullong);
	ret = check_mul_longlong_int(arg_llong, arg_int, &arg_llong);
	ret = check_mul_longlong_uint(arg_llong, arg_uint, &arg_llong);
	ret = check_mul_longlong_longlong(arg_llong, arg_llong, &arg_llong);
	ret = check_mul_longlong_ulonglong(arg_llong, arg_ullong, &arg_llong);
	ret = check_mul_ulonglong_int(arg_ullong, arg_int, &arg_ullong);
	ret = check_mul_ulonglong_uint(arg_ullong, arg_uint, &arg_ullong);
	ret = check_mul_ulonglong_longlong(arg_ullong, arg_llong, &arg_ullong);
	ret = check_mul_ulonglong_ulonglong(arg_ullong, arg_ullong, &arg_ullong);

	if(ret)
		printf(" ");
}

void call_functions(void)
{
	safe_add_compile();
	check_add_compile();
	safe_mul_compile();
	check_mul_compile();
	safe_cast_compile();
	check_cast_compile();
}

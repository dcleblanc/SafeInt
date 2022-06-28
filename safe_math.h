#if !defined SAFE_MATH_H
#define SAFE_MATH_H

#include "safe_math_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
	The following functions are defined in safe_math_impl.h:

	// All check_cast functions return 0 if safe, non-zero if unsafe
	// Casting test to int8
	int check_cast_int8_int32(int32_t in)
	int check_cast_int8_uint32(uint32_t in)
	int check_cast_int8_int64(int64_t in)
	int check_cast_int8_uint64(uint64_t in)

	// Casting to int64
	int check_cast_int16_int32(int32_t in)
	int check_cast_int16_uint32(uint32_t in)
	int check_cast_int16_int64(int64_t in)
	int check_cast_int16_uint64(uint64_t in)

	// Casting to int32
	int check_cast_int32_uint32(uint32_t in)
	int check_cast_int32_int64(int64_t in)
	int check_cast_int32_uint64(uint64_t in)
	int check_cast_int64_uint64(uint64_t in)

	// Casting to uint8
	int check_cast_uint8_int32(int32_t in)
	int check_cast_uint8_uint32(uint32_t in)
	int check_cast_uint8_int64(int64_t in)
	int check_cast_uint8_uint64(uint64_t in)

	// Casting to uint16
	int check_cast_uint16_int32(int32_t in)
	int check_cast_uint16_uint32(uint32_t in)
	int check_cast_uint16_int64(int64_t in)
	int check_cast_uint16_uint64(uint64_t in)

	// Casting to uint32
	int check_cast_uint32_int32(int32_t in)
	int check_cast_uint32_int64(int64_t in)
	int check_cast_uint32_uint64(uint64_t in)

	// Casting to uint64
	int check_cast_uint64_int64(int64_t in)

	// safe_cast functions all abort on failure

	// Casting to int8
	int8_t safe_cast_int8_int32(int32_t in)
	int8_t safe_cast_int8_uint32(uint32_t in)
	int8_t safe_cast_int8_int64(int64_t in)
	int8_t safe_cast_int8_uint64(uint64_t in)

	// Casting to int16
	int16_t safe_cast_int16_int32(int32_t in)
	int16_t safe_cast_int16_uint32(uint32_t in)
	int16_t safe_cast_int16_int64(int64_t in)
	int16_t safe_cast_int16_uint64(uint64_t in)

	// Casting to int32
	int32_t safe_cast_int32_uint32(uint32_t in)
	int32_t safe_cast_int32_int64(int64_t in)
	int32_t safe_cast_int32_uint64(uint64_t in)

	// Casting to int64
	int64_t safe_cast_int64_uint64(uint64_t in)

	// Casting to uint8
	uint8_t safe_cast_uint8_int32(int32_t in)
	uint8_t safe_cast_uint8_uint32(uint32_t in)
	uint8_t safe_cast_uint8_int64(int64_t in)
	uint8_t safe_cast_uint8_uint64(uint64_t in)

	// Casting to uint16
	uint16_t safe_cast_uint16_int32(int32_t in)
	uint16_t safe_cast_uint16_uint32(uint32_t in)
	uint16_t safe_cast_uint16_int64(int64_t in)
	uint16_t safe_cast_uint16_uint64(uint64_t in)

	// Casting to uint32
	uint32_t safe_cast_uint32_int32(int32_t in)
	uint32_t safe_cast_uint32_int64(int64_t in)
	uint32_t safe_cast_uint32_uint64(uint64_t in)

	// Casting to uint64
	uint64_t safe_cast_uint64_int64(int64_t in)

	// Only 32-bit or larger types are supported for 
	// addition, subtraction, multiplication and division

	// If smaller types are needed, either wrap the result
	// in a safe_cast, or pass the smaller type in as a
	// 32-bit type of the same signedness

	// Addition functions, all of these abort on failure

	int32_t safe_add_int32_int32(int32_t a, int32_t b)
	int32_t safe_add_int32_uint32(int32_t a, uint32_t b)
	int32_t safe_add_int32_int64(int32_t a, int64_t b)
	int32_t safe_add_int32_uint64(int32_t a, uint64_t b)

	uint32_t safe_add_uint32_int32(uint32_t a, int32_t b)
	uint32_t safe_add_uint32_uint32(uint32_t a, uint32_t b)
	uint32_t safe_add_uint32_int64(uint32_t a, int64_t b)
	uint32_t safe_add_uint32_uint64(uint32_t a, uint64_t b)

	int64_t safe_add_int64_int32(int64_t a, int32_t b)
	int64_t safe_add_int64_uint32(int64_t a, uint32_t b)
	int64_t safe_add_int64_int64(int64_t a, int64_t b)
	int64_t safe_add_int64_uint64(int64_t a, uint64_t b)

	uint64_t safe_add_uint64_int32(uint64_t a, int32_t b)
	uint64_t safe_add_uint64_uint32(uint64_t a, uint32_t b)
	uint64_t safe_add_uint64_int64(uint64_t a, int64_t b)
	uint64_t safe_add_uint64_uint64(uint64_t a, uint64_t b)

	// Multiplication
	int32_t safe_mul_int32_int32(int32_t a, int32_t b)
	int32_t safe_mul_int32_uint32(int32_t a, uint32_t b)
	int32_t safe_mul_int32_int64(int32_t a, int64_t b)
	int32_t safe_mul_int32_uint64(int32_t a, uint64_t b)

	uint32_t safe_mul_uint32_int32(uint32_t a, int32_t b)
	uint32_t safe_mul_uint32_uint32(uint32_t a, uint32_t b)
	uint32_t safe_mul_uint32_int64(uint32_t a, int64_t b)
	uint32_t safe_mul_uint32_uint64(uint32_t a, uint64_t b)

	int64_t safe_mul_int64_int32(int64_t a, int32_t b)
	int64_t safe_mul_int64_uint32(int64_t a, uint32_t b)
	int64_t safe_mul_int64_int64(int64_t a, int64_t b)
	int64_t safe_mul_int64_uint64(int64_t a, uint64_t b)

	uint64_t safe_mul_uint64_int32(uint64_t a, int32_t b)
	uint64_t safe_mul_uint64_uint32(uint64_t a, uint32_t b)
	uint64_t safe_mul_uint64_int64(uint64_t a, int64_t b)
	uint64_t safe_mul_uint64_uint64(uint64_t a, uint64_t b)

	// Division
	int32_t safe_div_int32_int32(int32_t a, int32_t b)
	int32_t safe_div_int32_uint32(int32_t a, uint32_t b)
	int32_t safe_div_int32_int64(int32_t a, int64_t b)
	int32_t safe_div_int32_uint64(int32_t a, uint64_t b)

	uint32_t safe_div_uint32_int32(uint32_t a, int32_t b)
	uint32_t safe_div_uint32_uint32(uint32_t a, uint32_t b)
	uint32_t safe_div_uint32_int64(uint32_t a, int64_t b)
	uint32_t safe_div_uint32_uint64(uint32_t a, uint64_t b)

	int64_t safe_div_int64_int32(int64_t a, int32_t b)
	int64_t safe_div_int64_uint32(int64_t a, uint32_t b)
	int64_t safe_div_int64_int64(int64_t a, int64_t b)
	int64_t safe_div_int64_uint64(int64_t a, uint64_t b)

	uint64_t safe_div_uint64_int32(uint64_t a, int32_t b)
	uint64_t safe_div_uint64_uint32(uint64_t a, uint32_t b)
	uint64_t safe_div_uint64_int64(uint64_t a, int64_t b)
	uint64_t safe_div_uint64_uint64(uint64_t a, uint64_t b)

	// Subtraction
	int32_t safe_sub_int32_int32(int32_t a, int32_t b)
	int32_t safe_sub_int32_uint32(int32_t a, uint32_t b)
	int32_t safe_sub_int32_int64(int32_t a, int64_t b)
	int32_t safe_sub_int32_uint64(int32_t a, uint64_t b)

	uint32_t safe_sub_uint32_int32(uint32_t a, int32_t b)
	uint32_t safe_sub_uint32_uint32(uint32_t a, uint32_t b)
	uint32_t safe_sub_uint32_int64(uint32_t a, int64_t b)
	uint32_t safe_sub_uint32_uint64(uint32_t a, uint64_t b)

	int64_t safe_sub_int64_int32(int64_t a, int32_t b)
	int64_t safe_sub_int64_uint32(int64_t a, uint32_t b)
	int64_t safe_sub_int64_int64(int64_t a, int64_t b)
	int64_t safe_sub_int64_uint64(int64_t a, uint64_t b)

	uint64_t safe_sub_uint64_int32(uint64_t a, int32_t b)
	uint64_t safe_sub_uint64_uint32(uint64_t a, uint32_t b)
	uint64_t safe_sub_uint64_int64(uint64_t a, int64_t b)
	uint64_t safe_sub_uint64_uint64(uint64_t a, uint64_t b)
*/

// Do some sorting out of standard types and sizes

#if CHAR_MIN != 0
#define SAFE_MATH_SIGNED_CHAR 1
#else
#define SAFE_MATH_SIGNED_CHAR 0
#endif

#if LONG_MAX == LLONG_MAX
#define SAFE_MATH_LONG 64
#else
#define SAFE_MATH_LONG 32
#endif

// Not going to support odd sizes of things
extern char __CHECK_SHORT_IS_16__[1 / !(sizeof(short)-2)];
extern char __CHECK_INT_IS_32__[1 / !(sizeof(int) - 4)];

// In order to help keep people from making mistakes by 
// incorrectly guessing which types match which of the intXX types,
// make some functions.

// Cast to char, char might be signed or unsigned
#if SAFE_MATH_SIGNED_CHAR
inline char safe_cast_char_int(int in) { return safe_cast_int8_int32(in); }
inline char safe_cast_char_uint(unsigned int in) { return safe_cast_int8_uint32(in); }

#if SAFE_MATH_LONG == 64
inline char safe_cast_char_long(long in) { return safe_cast_int8_int64(in); }
#else
inline char safe_cast_char_long(long in) { return safe_cast_int8_int32(in); }
#endif

inline char safe_cast_char_longlong(long long in) { return safe_cast_int8_int64(in); }
inline char safe_cast_char_ulonglong(unsigned long long in) { return safe_cast_int8_uint64(in); }
#else
inline char safe_cast_char_int(int in) { return safe_cast_uint8_int32(in); }
inline char safe_cast_char_uint(unsigned int in) { return safe_cast_uint8_uint32(in); }

#if SAFE_MATH_LONG == 64
inline char safe_cast_char_long(long in) { return safe_cast_uint8_int64(in); }
#else
inline char safe_cast_char_long(long in) { return safe_cast_uint8_int32(in); }
#endif

inline char safe_cast_char_longlong(long long in) { return safe_cast_uint8_int64(in); }
inline char safe_cast_char_ulonglong(unsigned long long in) { return safe_cast_uint8_uint64(in); }
#endif

// Signed char
inline signed char safe_cast_schar_int(int in) { return safe_cast_int8_int32(in); }
inline signed char safe_cast_schar_uint(unsigned int in) { return safe_cast_int8_uint32(in); }

#if SAFE_MATH_LONG == 64
inline signed char safe_cast_schar_long(long in) { return safe_cast_int8_int64(in); }
#else
inline signed char safe_cast_schar_long(long in) { return safe_cast_int8_int32(in); }
#endif

inline signed char safe_cast_schar_longlong(long long in) { return safe_cast_int8_int64(in); }
inline signed char safe_cast_schar_ulonglong(unsigned long long in) { return safe_cast_int8_uint64(in); }

// Unsigned char
inline unsigned char safe_cast_uchar_int(int in) { return safe_cast_uint8_int32(in); }
inline unsigned char safe_cast_uchar_uint(unsigned int in) { return safe_cast_uint8_uint32(in); }

#if SAFE_MATH_LONG == 64
inline unsigned char safe_cast_uchar_long(long in) { return safe_cast_uint8_int64(in); }
#else
inline unsigned char safe_cast_uchar_long(long in) { return safe_cast_uint8_int32(in); }
#endif

inline unsigned char safe_cast_uchar_longlong(long long in) { return safe_cast_uint8_int64(in); }
inline unsigned char safe_cast_uchar_ulonglong(unsigned long long in) { return safe_cast_uint8_uint64(in); }

// 16-bit signed casting
inline short safe_cast_short_int(int in) { return safe_cast_int16_int32(in); }
inline short safe_cast_short_uint(unsigned int in) { return safe_cast_int16_uint32(in); }
#if SAFE_MATH_LONG == 64
inline short safe_cast_short_long(long in) { return safe_cast_int16_int64(in); }
#else
inline short safe_cast_short_long(long in) { return safe_cast_int16_int32(in); }
#endif

inline short safe_cast_short_longlong(long long in) { return safe_cast_int16_int64(in); }
inline short safe_cast_short_ulonglong(unsigned long long in) { return safe_cast_int16_uint64(in); }

// 16-bit unsigned casting
inline unsigned short safe_cast_ushort_int(int in) { return safe_cast_uint16_int32(in); }
inline unsigned short safe_cast_ushort_uint(unsigned int in) { return safe_cast_uint16_uint32(in); }
#if SAFE_MATH_LONG == 64
inline unsigned short safe_cast_ushort_long(long in) { return safe_cast_uint16_int64(in); }
#else
inline unsigned short safe_cast_ushort_long(long in) { return safe_cast_uint16_int32(in); }
#endif

inline unsigned short safe_cast_ushort_longlong(long long in) { return safe_cast_uint16_int64(in); }
inline unsigned short safe_cast_ushort_ulonglong(unsigned long long in) { return safe_cast_uint16_uint64(in); }

// Cast to int
inline int safe_cast_int_uint(unsigned int in) { return safe_cast_int32_uint32(in); }
#if SAFE_MATH_LONG == 64
inline int safe_cast_int_long(long in) { return safe_cast_int32_int64(in); }
inline int safe_cast_int_ulong(unsigned long in) { return safe_cast_int32_uint64(in); }
#else
inline int safe_cast_int_ulong(unsigned long in) { return safe_cast_int32_uint32(in); }
#endif

inline int safe_cast_int_longlong(long long in) { return safe_cast_int32_int64(in); }
inline int safe_cast_int_ulonglong(unsigned long long in) { return safe_cast_int32_uint64(in); }

// Cast to unsigned int
inline unsigned int safe_cast_uint_int(int in) { return safe_cast_uint32_int32(in); }
#if SAFE_MATH_LONG == 64
inline unsigned int safe_cast_uint_long(long in) { return safe_cast_uint32_int64(in); }
inline unsigned int safe_cast_uint_ulong(unsigned long in) { return safe_cast_uint32_uint64(in); }
#else
inline unsigned int safe_cast_uint_long(long in) { return safe_cast_uint32_int32(in); }
inline unsigned int safe_cast_uint_ulong(unsigned long in) { return in; }
#endif

inline unsigned int safe_cast_uint_longlong(long long in) { return safe_cast_uint32_int64(in); }
inline unsigned int safe_cast_uint_ulonglong(unsigned long long in) { return safe_cast_uint32_uint64(in); }

// Cast to long
// Also have to keep parity in the case of different compilations
// of the same code.
#if SAFE_MATH_LONG == 64
inline long safe_cast_long_ulong(unsigned long in) { return safe_cast_int64_uint64(in); }
inline long safe_cast_long_longlong(long long in) { return in; }
inline long safe_cast_long_ulonglong(unsigned long long in) { return safe_cast_int64_uint64(in); }

inline unsigned long safe_cast_ulong_long(long in) { return safe_cast_uint64_int64(in); }
inline unsigned long safe_cast_ulong_ulonglong(unsigned long long in) { return in; }
inline unsigned long safe_cast_ulong_longlong(unsigned long long in) { return safe_cast_uint64_int64(in); }
#else
inline long safe_cast_long_ulong(unsigned long in) { return safe_cast_int32_uint32(in); }
inline long safe_cast_long_longlong(long long in) { return safe_cast_int32_int64(in); }
inline long safe_cast_long_ulonglong(unsigned long long in) { return safe_cast_int32_uint64(in); }

inline unsigned long safe_cast_ulong_long(long in) { return safe_cast_uint32_int32(in); }
inline unsigned long safe_cast_ulong_ulonglong(unsigned long long in) { return safe_cast_uint32_uint64(in); }
inline unsigned long safe_cast_ulong_longlong(long long in) { return safe_cast_uint32_int64(in); }
#endif

// And long long
inline long long safe_cast_longlong_ulonglong(unsigned long long in) { return safe_cast_int64_uint64(in); }
inline unsigned long long safe_cast_ulonglong_longlong(long long in) { return safe_cast_uint64_int64(in); }


#ifdef __cplusplus
}
#endif

#endif
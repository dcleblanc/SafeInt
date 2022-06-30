#pragma warning(push)
#pragma warning(disable: 4365) // signed/unsigned mismatch in iostream
#include <exception>
#include <assert.h>
#include <iostream>
#pragma warning(pop)

#pragma warning(disable: 4514 5045 4464 4820)

#if defined __clang__ || defined __GNUC__
#define NORETURN __attribute__((noreturn))
#elif defined _MSC_VER
#define NORETURN __declspec(noreturn)
#else
#define NORETURN
#endif

// This has to be done in C++ so we can catch exceptions, not abort
NORETURN void safe_math_fail(const char* msg)
{
	throw std::exception(msg);
}

#define SAFE_MATH_FAIL_DEFINED
#include "../../safe_math.h"

// Suppress warnings in test files
#pragma warning(disable: 4838)
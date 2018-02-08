#if !defined SAFEINT_GCC_HPP
#define SAFEINT_GCC_HPP
#define NEEDS_INT_DEFINED

#if !defined NULL
#define NULL ((void*)0)
#endif

// Need this for ptrdiff_t
#include <cstddef>
// These two may not be defined, either
#if !defined uintptr_t
#define uintptr_t size_t
#endif

#if !defined intptr_t
#define intptr_t ptrdiff_t
#endif

#endif

cmake_minimum_required(VERSION 3.0)

project(SafeInt CXX)

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

option(SAFEINT_TESTS "compile the tests" OFF)
option(SAFEINT_NO_EXCEPTIONS "disable exceptions" OFF)
option(SAFEINT_SANITIZE "sanitize undefined behaviour" OFF)

add_library(SafeInt INTERFACE)
target_include_directories(SafeInt INTERFACE .)
install(FILES SafeInt.hpp DESTINATION include)
install(FILES LICENSE DESTINATION share)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(MSVC_VERSION LESS 1900)
        # Visual Studio compilers prior to 2015 don't support noexcept:
        target_compile_definitions(SafeInt INTERFACE SAFEINT_REMOVE_NOTHROW)
    endif()
endif()

if(SAFEINT_NO_EXCEPTIONS)
    target_compile_definitions(SafeInt INTERFACE SAFE_INT_HAS_EXCEPTIONS=0)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(SafeInt INTERFACE -fno-exceptions)
    endif()
else()
    target_compile_definitions(SafeInt INTERFACE SAFE_INT_HAS_EXCEPTIONS=1)
endif()

if(SAFEINT_TESTS)
    add_subdirectory(Test)
endif()

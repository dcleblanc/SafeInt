cmake_minimum_required(VERSION 3.0)

project(SafeInt CXX)

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

option(SAFEINT_TESTS "compile the tests" OFF)
option(SAFEINT_NO_EXCEPTIONS "disable exceptions" OFF)

add_library(SafeInt INTERFACE)
target_include_directories(SafeInt INTERFACE .)
install(FILES SafeInt.hpp DESTINATION include)
install(FILES LICENSE DESTINATION share)

if(SAFEINT_NO_EXCEPTIONS)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(SafeInt INTERFACE -fno-exceptions)
    endif()
endif()

if(SAFEINT_TESTS)
    add_subdirectory(Test)
endif()

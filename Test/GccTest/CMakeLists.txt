cmake_minimum_required(VERSION 3.10)
project(SafeInt VERSION 3.0.26)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Runtime tests are:
# - default
# - without built-in 128-bit support
# - without intrinsics

# Compile time tests are:
# - default C++11
# - C++14
# - TODO - consider adding in 17, 20 just to see if anything breaks
# - compile without exceptions

# Supported compilers:
# - Microsoft
# - clang
# - gcc
# - Intel (not regularly tested)
# other compilers on a best effort

# test for g++
find_program(GCC_PLUS_PLUS "g++")

if(NOT GCC_PLUS_PLUS)
    message(STATUS "Skipping g++ testing")
else()
    message(STATUS "g++ available, configuring g++ tests")
    set(CMAKE_CXX_COMPILER ${GCC_PLUS_PLUS})
    # the standard level is already at C++11, which is what we need for runtime tests
    add_compile_options(-O3 -ftrapv)

    # Note - -fsanitize=undefined isn't currently working with g++ and cmake
    # if you go build from the old makefile in Test/GccTest, it does work
    # -fsanitize-trap=undefined does work in clang++, so we have coverage there

    # This will test whatever the mainline code can do, typically using int128
    add_executable(SafeIntTest_gcc 
        ../AddVerify.cpp 
        ../CastVerify.cpp 
        ../DivVerify.cpp 
        ../IncDecVerify.cpp 
        ../ModVerify.cpp 
        ../MultVerify.cpp 
        ../SubVerify.cpp 
        ../TestMain.cpp
        ../TestMain.h
        ../../SafeInt.hpp
    )

    # Forces use of the older, less efficient code that can't use either int128 or intrinsics
    add_executable(SafeIntTest_gcc_NoIntrinsic
        ../AddVerify.cpp 
        ../CastVerify.cpp 
        ../DivVerify.cpp 
        ../IncDecVerify.cpp 
        ../ModVerify.cpp 
        ../MultVerify.cpp 
        ../SubVerify.cpp 
        ../TestMain.cpp
        ../TestMain.h
        ../../SafeInt.hpp
    )

    target_compile_definitions(SafeIntTest_gcc_NoIntrinsic PUBLIC "SAFEINT_USE_INTRINSICS=0" "SAFEINT_HAS_INT128=0")

    # Forces use of either intrinsics or the older code
    add_executable(SafeIntTest_gcc_NoInt128
        ../AddVerify.cpp 
        ../CastVerify.cpp 
        ../DivVerify.cpp 
        ../IncDecVerify.cpp 
        ../ModVerify.cpp 
        ../MultVerify.cpp 
        ../SubVerify.cpp 
        ../TestMain.cpp
        ../TestMain.h
        ../../SafeInt.hpp
    )

    target_compile_definitions(SafeIntTest_gcc_NoInt128 PUBLIC "SAFEINT_HAS_INT128=0")

    # compilation tests, these are good if they just build
    add_executable(CompileTest_gcc
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_gcc PUBLIC -Wall)

    add_executable(CompileTest_gcc14
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_gcc14 PUBLIC -Wall -std=c++14)

    add_executable(CompileTest_gcc14_NoEH
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_gcc14_NoEH PUBLIC -Wall -std=c++14 -fno-exceptions)

endif()


enable_testing()

if(GCC_PLUS_PLUS)
    add_test(NAME SafeIntTest_gcc COMMAND SafeIntTest_gcc)
    add_test(NAME SafeIntTest_gcc_NoIntrinsic COMMAND SafeIntTest_gcc_NoIntrinsic)
    add_test(NAME SafeIntTest_gcc_NoInt128 COMMAND SafeIntTest_gcc_NoInt128)


    set_tests_properties(SafeIntTest_gcc 
                        SafeIntTest_gcc_NoIntrinsic 
                        SafeIntTest_gcc_NoInt128 
                        PROPERTIES FAIL_REGULAR_EXPRESSION "Error")
endif()

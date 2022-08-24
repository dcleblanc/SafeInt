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
find_program(MSVC_CL "cl.exe")

if(NOT MSVC_CL)
    message(STATUS "Skipping MSVC testing")
else()
    message(STATUS "MSVC available, configuring MSVC tests")
    set(CMAKE_CXX_COMPILER ${MSVC_CL})

    # the standard level is already at C++11, which is what we need for runtime tests
    add_compile_options(/Wall /wd4710 /wd4711)

    # This will test whatever the mainline code can do, typically using int128
    add_executable(SafeIntTest_msvc 
        ../AddVerify.cpp 
        ../AddTestCase.cpp
        ../CastVerify.cpp 
        ../DivVerify.cpp 
        ../DivTestCase.cpp
        ../IncDecVerify.cpp 
        ../ModVerify.cpp 
        ../MultVerify.cpp 
        ../MultTestCase.cpp
        ../SubVerify.cpp 
        ../SubTestCase.cpp
        ../TestMain.cpp
        ../TestMain.h
        ../../SafeInt.hpp
    )
    
        # Forces use of the older, less efficient code that can't use either int128 or intrinsics
        add_executable(SafeIntTest_msvc_NoIntrinsic
        ../AddVerify.cpp 
        ../AddTestCase.cpp
        ../CastVerify.cpp 
        ../DivVerify.cpp 
        ../DivTestCase.cpp
        ../IncDecVerify.cpp 
        ../ModVerify.cpp 
        ../MultVerify.cpp 
        ../MultTestCase.cpp
        ../SubVerify.cpp 
        ../SubTestCase.cpp
        ../TestMain.cpp
        ../TestMain.h
        ../../SafeInt.hpp
    )

    target_compile_definitions(SafeIntTest_msvc_NoIntrinsic PUBLIC "SAFEINT_USE_INTRINSICS=0" "SAFEINT_HAS_INT128=0")

    # compilation tests, these are good if they just build
    add_executable(CompileTest_msvc
    ../CompileTest.cpp
    ../ConstExpr.cpp 
    ../CleanCompile.cpp
    ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_msvc PUBLIC /wd4711 /wd4710)

    add_executable(CompileTest_msvc14
    ../CompileTest.cpp
    ../ConstExpr.cpp 
    ../CleanCompile.cpp
    ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_msvc14 PUBLIC /std:c++14 /wd4711)

    add_executable(CompileTest_msvc17
    ../CompileTest.cpp
    ../ConstExpr.cpp 
    ../CleanCompile.cpp
    ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_msvc17 PUBLIC /std:c++17)

    # compilation tests, these are good if they just build
    add_executable(CompileTest_msvc_noexcept
    ../CompileTest.cpp
    ../ConstExpr.cpp 
    ../CleanCompile.cpp
    ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_msvc_noexcept PUBLIC /wd4711 /wd4710 /EHsc)

    add_executable(safe_math_test_msvc
    ../c_safe_math/safe_math_test.c
    ../c_safe_math/safe_math_test.h
    ../c_safe_math/safe_math_test_add.cpp
    ../c_safe_math/safe_math_test_div.cpp
    ../c_safe_math/safe_math_test_mult.cpp
    ../c_safe_math/safe_math_test_sub.cpp
    ../c_safe_math/compile_test.c
    ../AddTestCase.cpp
    ../DivTestCase.cpp
    ../MultTestCase.cpp
    ../SubTestCase.cpp
    )

    target_compile_definitions(safe_math_test_msvc PUBLIC)
    target_compile_options(safe_math_test_msvc PUBLIC /wd4464)

    add_executable(safe_math_compile_msvc
    ../c_safe_math/safe_math_compile.c
    ../c_safe_math/compile_test.c
    ../../safe_math.h
    ../../safe_math_impl.h
    )

    target_compile_options(safe_math_compile_msvc PUBLIC -Wall /wd4464)

endif()

enable_testing()

if(MSVC_CL)
    add_test(NAME SafeIntTest_msvc COMMAND SafeIntTest_msvc)
    add_test(NAME SafeIntTest_msvc_NoIntrinsic COMMAND SafeIntTest_msvc_NoIntrinsic)
    add_test(NAME safe_math_test_msvc COMMAND safe_math_test_msvc)

    set_tests_properties(SafeIntTest_msvc 
                        SafeIntTest_msvc_NoIntrinsic 
                        safe_math_test_msvc
                        PROPERTIES FAIL_REGULAR_EXPRESSION "Error")
endif()
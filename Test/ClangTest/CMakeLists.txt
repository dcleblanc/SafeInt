cmake_minimum_required(VERSION 3.10)
project(SafeInt_clang VERSION 3.0.26)

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

# test for clang++
find_program(CLANG_PLUS_PLUS "clang++")

if(NOT CLANG_PLUS_PLUS)
    message(STATUS "Clang compiler not available, skipping")
else()
    message(STATUS "clang++ available, configuring clang tests")

    set(CMAKE_CXX_COMPILER ${CLANG_PLUS_PLUS})

    # the standard level is already at C++11, which is what we need for runtime tests
    add_compile_options(-O3 -ftrapv)

    # Note - the test matrix here is as follows:
    # int128 is available (best case)
    # no int128, but we do have intrinsics
    # fallback C++ code, which is less efficient
    # 
    # Coverage will vary, depending on the capabilities of the platform. 
    # We cannot force coverage for options that aren't supported.
    # Tests are:
    # SafeIntTest_clang - this will test the best option this platform has
    # SafeIntTest_clang_NoIntrinsic - ensures that the older (potentially more fragile) code is tested
    # SafeIntTest_clang_NoInt128 - if we do have intrinsic support, this will force testing this, 
    #                              else is the same as previous.

    # This will test whatever the mainline code can do, typically using int128
    add_executable(SafeIntTest_clang 
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

    target_compile_options(SafeIntTest_clang PUBLIC -fsanitize-trap=undefined)

    # Forces use of the older, less efficient code that can't use either int128 or intrinsics
    add_executable(SafeIntTest_clang_NoIntrinsic
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

    target_compile_definitions(SafeIntTest_clang_NoIntrinsic PUBLIC "SAFEINT_USE_INTRINSICS=0" "SAFEINT_HAS_INT128=0")
    target_compile_options(SafeIntTest_clang_NoIntrinsic PUBLIC -fsanitize-trap=undefined)

    # Forces use of either intrinsics or the older code
    add_executable(SafeIntTest_clang_NoInt128
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

    target_compile_definitions(SafeIntTest_clang_NoInt128 PUBLIC "SAFEINT_HAS_INT128=0")
    target_compile_options(SafeIntTest_clang_NoInt128 PUBLIC -fsanitize-trap=undefined)

    # compilation tests, these are good if they just build
    add_executable(CompileTest_clang
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang PUBLIC -Wall -Wextra)

    add_executable(CompileTest_clang14
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang14 PUBLIC -Wall  -Wextra -std=c++14)

    add_executable(CompileTest_clang17
    ../CompileTest.cpp
    ../ConstExpr.cpp 
    ../CleanCompile.cpp
    ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang17 PUBLIC -Wall  -Wextra -std=c++17)

    add_executable(CompileTest_clang14_NoEH
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang14_NoEH PUBLIC -Wall  -Wextra -std=c++14 -fno-exceptions)

    add_executable(CompileTest_clang17_NoEH
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang17_NoEH PUBLIC -Wall  -Wextra -std=c++17 -fno-exceptions)

    add_executable(CompileTest_clang98
        ../CompileTest.cpp
        ../ConstExpr.cpp 
        ../CleanCompile.cpp
        ../../SafeInt.hpp
    )

    target_compile_options(CompileTest_clang98 PUBLIC -D SAFEINT_USE_CPLUSCPLUS_98 -Wall -std=c++98 -fno-exceptions)

    add_executable(safe_math_test_clang
        ../c_safe_math/safe_math_test.c
        ../c_safe_math/safe_math_test.h
        ../c_safe_math/safe_math_test_add.cpp
        ../c_safe_math/safe_math_test_div.cpp
        ../c_safe_math/safe_math_test_mult.cpp
        ../c_safe_math/safe_math_test_sub.cpp
        ../AddTestCase.cpp
        ../DivTestCase.cpp
        ../MultTestCase.cpp
        ../SubTestCase.cpp
        ../../safe_math.h
        ../../safe_math_impl.h
        )

    target_compile_definitions(safe_math_test_clang PUBLIC)
    target_compile_options(safe_math_test_clang PUBLIC -Wall)

    add_executable(safe_math_compile_clang
        ../c_safe_math/safe_math_compile.c
        ../c_safe_math/compile_test.c
        ../../safe_math.h
        ../../safe_math_impl.h
    )

    target_compile_options(safe_math_compile_clang PUBLIC -Wall -Werror=incompatible-pointer-types)

 endif()

enable_testing()

if(CLANG_PLUS_PLUS)
    add_test(NAME SafeIntTest_clang COMMAND SafeIntTest_clang)
    add_test(NAME SafeIntTest_clang_NoIntrinsic COMMAND SafeIntTest_clang_NoIntrinsic)
    add_test(NAME SafeIntTest_clang_NoInt128 COMMAND SafeIntTest_clang_NoInt128)
    add_test(NAME safe_math_test_clang COMMAND safe_math_test_clang)


    set_tests_properties(SafeIntTest_clang 
                        SafeIntTest_clang_NoIntrinsic 
                        SafeIntTest_clang_NoInt128 
                        safe_math_test_clang
                        PROPERTIES FAIL_REGULAR_EXPRESSION "Error")
endif()


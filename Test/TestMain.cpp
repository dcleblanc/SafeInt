// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"
#include "TestCase.h"

#if !defined __GNUC__
#pragma warning( disable: 4711 4514 4820 )
#endif

int main(int, char**)
{
    #if SAFEINT_USE_INTRINSICS == 0
    std::cout << "Testing without intrinsics" << std::endl;
    #else
    std::cout << "Testing with intrinsics" << std::endl;
    #endif

    #if SAFEINT_HAS_INT128 == 1
    std::cout << "Testing using int128" << std::endl;
    #else
    std::cout << "Testing not using int128" << std::endl;
    #endif

    #if SAFEINT_COMPILER == GCC_COMPILER 
    std::cout << "Compiler = g++" << std::endl;
    #endif
    
    #if SAFEINT_COMPILER == CLANG_COMPILER
    std::cout << "Compiler = clang" << std::endl;
    #endif

    #if SAFEINT_COMPILER == VISUAL_STUDIO_COMPILER
    std::cout << "Compiler = Visual Studio" << std::endl;
    #endif

    cast_verify::CastVerify();
    mult_verify::MultVerify();
    div_verify::DivVerify();
    sub_verify::SubVerify();
    add_verify::AddVerify();
    mod_verify::ModVerify();
    incdec_verify::IncDecVerify();
    negation_verify::NegationVerify();
    return 0;
}

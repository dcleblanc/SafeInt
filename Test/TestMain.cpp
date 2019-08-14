// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "TestMain.h"

#if !defined __GNUC__
#pragma warning( disable: 4711 4514 4820 )
#endif

int main(int, char**)
{
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

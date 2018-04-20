#pragma once
#include <mdec.h>

#define make_tmp_mdec(var, sign, numerator, denominator)\
int __ ## var ## _make_argument1 = sign;\
mint *__ ## var ## _make_argument2 = numerator;\
mint *__ ## var ## _make_argument3 = denominator;\
mdec __ ## var;\
mdec *var = &__ ## var;\
init_mdec(\
__ ## var ## _make_argument1,\
__ ## var ## _make_argument2,\
__ ## var ## _make_argument3, var);

#define make_tmp_mdec_from_int(var, num)\
int __ ## var ## _make_argument1 = num;\
make_tmp_mint_from_int(__ ## var ## _numerator,\
__ ## var ## _make_argument1 < 0 ?\
-__ ## var ## _make_argument1 :\
__ ## var ## _make_argument1);\
make_tmp_mint_from_int(__ ## var ## _denominator, 1);\
make_tmp_mdec(\
__ ## var ## _make_argument < 0 ? MDEC_NEGATIVE : MDEC_POSITIVE,\
__ ## var ## _numerator,\
__ ## var ## _denominator);

#define make_tmp_mdec_from_long(var, num)\
long __ ## var ## _make_argument1 = num;\
make_tmp_mint_from_long(__ ## var ## _numerator,\
__ ## var ## _make_argument1 < 0 ?\
-__ ## var ## _make_argument1 :\
__ ## var ## _make_argument1);\
make_tmp_mint_from_int(__ ## var ## _denominator, 1);\
make_tmp_mdec(\
__ ## var ## _make_argument < 0 ? MDEC_NEGATIVE : MDEC_POSITIVE,\
__ ## var ## _numerator,\
__ ## var ## _denominator);

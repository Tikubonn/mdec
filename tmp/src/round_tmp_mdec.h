#pragma once
#include <mdec.h>

#define round_tmp_mdec(var, num)\
mdec *__ ## var ## _round_argument1 = num;\
mint *var = make_mint(\
size_mint(__ ## var ## _round_argument1->numerator) +1); {\
mint *__ ## var ## _round_tmp = make_mint(\
size_mint(__ ## var ## _round_argument1->numerator) +1);\
round_mdec_manually(\
__ ## var ## _round_argument1, var,\
__ ## var ## _round_tmp); }

#pragma once
#include <mdec.h>

#define ceil_tmp_mdec(var, num)\
mdec *__ ## var ## _ceil_argument1 = num;\
mint *var = make_mint(\
size_mint(__ ## var ## _ceil_argument1->numerator) +1); {\
mint *__ ## var ## _ceil_tmp = make_mint(\
size_mint(__ ## var ## _ceil_argument1->numerator));\
ceil_mdec_manually(\
__ ## var ## _ceil_argument1, var,\
__ ## var ## _ceil_tmp); }

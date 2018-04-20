#pragma once
#include <mdec.h>

#define abs_tmp_mdec(var, num)\
mdec *__ ## var ## _abs_argument1 = num;\
make_tmp_mdec(var,\
size_mint(__ ## var ## _abs_argument1->numerator),\
size_mint(__ ## var ## _abs_argument1->denominator));\
abs_mdec_manually(__ ## var ## _abs_argument1, var);

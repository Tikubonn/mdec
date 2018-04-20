#pragma once
#include <mdec.h>

#define abs_tmp_mdec(var, num)\
mdec *__ ## var ## _abs_argument1 = num;\
make_tmp_mint(__ ## var ## _abs_numerator,\
size_mint(__ ## var ## _abs_argument1->numerator));\
make_tmp_mint(__ ## var ## _abs_denominator,\
size_mint(__ ## var ## _abs_argument1->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _abs_numerator,\
__ ## var ## _abs_denominator);\
abs_mdec_manually(__ ## var ## _abs_argument1, var);

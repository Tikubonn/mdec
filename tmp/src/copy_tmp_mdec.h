#pragma once
#include <mdec.h>

#define copy_tmp_mdec(var, num)\
mdec *__ ## var ## _copy_argument1 = num;\
make_tmp_mint(__ ## var ## _copy_numerator,\
size_mint(__ ## var ## _copy_argument1->numerator));\
make_tmp_mint(__ ## var ## _copy_numerator,\
size_mint(__ ## var ## _copy_argument1->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _copy_numerator,\
__ ## var ## _copy_denominator);\
copy_mdec_manually(__ ## var ## _copy_argument1, var);

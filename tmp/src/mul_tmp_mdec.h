#pragma once
#include <mdec.h>

#define mul_tmp_mdec(var, numa, numb)\
mdec *__ ## var ## _mul_argument1 = numa;\
mdec *__ ## var ## _mul_argument2 = numb;\
make_tmp_mint(__ ## var ## _mul_numerator,\
size_mint(numa->numerator)+\
size_mint(numb->numerator));\
make_tmp_mint(__ ## var ## _mul_denominator,\
size_mint(numa->denominator)+\
size_mint(numb->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _mul_numerator,\
__ ## var ## _mul_denominator);\
mul_mdec_manually(\
__ ## var ## _mul_argument1,\
__ ## var ## _mul_argument2, var);

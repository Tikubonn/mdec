#pragma once
#include <mdec.h>

#define div_tmp_mdec(var, numa, numb)\
mdec *__ ## var ## _div_argument1 = numa;\
mdec *__ ## var ## _div_argument2 = numb;\
make_tmp_mint(__ ## var ## _div_numerator,\
size_mint(numa->numerator)+\
size_mint(numb->denominator));\
make_tmp_mint(__ ## var ## _div_denominator,\
size_mint(numb->numerator)+\
size_mint(numa->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _div_numerator,\
__ ## var ## _div_denominator);\
div_mdec_manually(\
__ ## var ## _div_argument1,\
__ ## var ## _div_argument2, var);

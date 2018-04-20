#pragma once
#include <mdec.h>

#define add_tmp_mdec_max(a, b) ((a)<(b)?(b):(a))
#define add_tmp_mdec(var, numa, numb)\
mdec *__ ## var ## _add_argument1 = numa;\
mdec *__ ## var ## _add_argument2 = numb;\
make_tmp_mint(__ ## var ## _add_numerator,\
add_tmp_mdec_max(\
size_mint(numa->numerator)+\
size_mint(numb->denominator),\
size_mint(numb->numerator)+\
size_mint(numa->denominator)) +1);\
make_tmp_mint(__ ## var ## _add_denominator,\
size_mint(numa->denominator)+\
size_mint(numb->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _add_numerator,\
__ ## var ## _add_denominator);\
add_tmp_mdec(\
__ ## var ## _add_argument1,\
__ ## var ## _add_argument2, var);

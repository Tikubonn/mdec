#pragma once
#include <mdec.h>

#define sub_tmp_mdec_max(a, b) ((a)<(b)?(b):(a))
#define sub_tmp_mdec(var, numa, numb)\
mdec *__ ## var ## _sub_argument1 = numa;\
mdec *__ ## var ## _sub_argument2 = numb;\
make_tmp_mint(__ ## var ## _sub_numerator,\
sub_tmp_mdec_max(\
size_mint(numa->numerator)+\
size_mint(numb->denominator),\
size_mint(numb->numerator)+\
size_mint(numa->denominator)) +1);\
make_tmp_mint(__ ## var ## _sub_denominator,\
size_mint(numa->denominator)+\
size_mint(numb->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _sub_numerator,\
__ ## var ## _sub_denominator);\
sub_tmp_mdec(\
__ ## var ## _sub_argument1,\
__ ## var ## _sub_argument2, var);

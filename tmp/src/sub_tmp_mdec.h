#pragma once
#include <mdec.h>

#define sub_tmp_mdec_max(a, b) ((a)<(b)?(b):(a))
#define sub_tmp_mdec(var, numa, numb)\
mdec *__ ## var ## _sub_argument1 = numa;\
mdec *__ ## var ## _sub_argument2 = numb;\
make_tmp_mint(__ ## var ## _sub_numerator1,\
sub_tmp_mdec_max(\
size_mint(__ ## var ## _sub_argument1->numerator)+\
size_mint(__ ## var ## _sub_argument2->denominator),\
size_mint(__ ## var ## _sub_argument2->numerator)+\
size_mint(__ ## var ## _sub_argument1->denominator)) +1);\
make_tmp_mint(__ ## var ## _sub_denominator1,\
size_mint(__ ## var ## _sub_argument1->denominator)+\
size_mint(__ ## var ## _sub_argument2->denominator));\
make_tmp_mdec(var,\
__ ## var ## _sub_argument1->sign,\
__ ## var ## _sub_numerator1,\
__ ## var ## _sub_denominator1);\
make_tmp_mint(__ ## var ## _sub_numerator2,\
size_mint(__ ## var ## _sub_argument2->numerator)+\
size_mint(__ ## var ## _sub_argument1->denominator));\
make_tmp_mint(__ ## var ## _sub_denominator2,\
size_mint(__ ## var ## _sub_argument2->denominator)+\
size_mint(__ ## var ## _sub_argument1->denominator));\
make_tmp_mdec(__ ## var ## _sub_mdec2,\
__ ## var ## _sub_argument2->sign,\
__ ## var ## _sub_numerator2,\
__ ## var ## _sub_denominator2);\
sub_mdec_manually(\
__ ## var ## _sub_argument1,\
__ ## var ## _sub_argument2, var,\
__ ## var ## _sub_mdec2);

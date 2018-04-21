#pragma once
#include <mdec.h>

#define compacted_tmp_mdec_max(a, b) ((a)<(b)?(b):(a))
#define compacted_tmp_mdec(var, num)\
mdec *__ ## var ## _compacted_argument1 = num;\
make_tmp_mint(__ ## var ## _compacted_numerator,\
size_mint(__ ## var ## _compacted_argument1->numerator));\
make_tmp_mint(__ ## var ## _compacted_denominator,\
size_mint(__ ## var ## _compacted_argument1->denominator));\
make_tmp_mdec(var, 0,\
__ ## var ## _compacted_numerator,\
__ ## var ## _compacted_denominator); {\
make_tmp_mint(__ ## var ## _compacted_tmp1,\
compacted_tmp_mdec_max(\
size_mint(__ ## var ## _compacted_argument1->numerator),\
size_mint(__ ## var ## _compacted_argument1->denominator)));\
make_tmp_mint(__ ## var ## _compacted_tmp2,\
compacted_tmp_mdec_max(\
size_mint(__ ## var ## _compacted_argument1->numerator),\
size_mint(__ ## var ## _compacted_argument1->denominator)));\
compacted_mdec_manually(\
__ ## var ## _compacted_argument1, var,\
__ ## var ## _compacted_tmp1,\
__ ## var ## _compacted_tmp2); }

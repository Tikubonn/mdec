#pragma once
#include <mdec.h>

#define cast_mdec_to_tmp_mint(var, num)\
mdec *__ ## var ## _cast_argument1 = num;\
make_tmp_mint(var,\
size_mint(__ ## var ## _cast_argument1->numerator) +1); {\
make_tmp_mint(__ ## var ## _cast_tmp,\
size_mint(__ ## var ## _cast_argument1->numerator));\
cast_mdec_to_mint_manually(\
__ ## var ## _cast_argument1, var,\
__ ## var ## _cast_tmp); }

#define cast_mdec_to_tmp_double_max(a, b) ((a)<(b)?(b):(a))
#define cast_mdec_to_tmp_double(var, num)\
mdec *__ ## var ## _cast_argument1 = num;\
double var; {\
make_tmp_mint(__ ## var ## _cast_numerator,\
size_mint(__ ## var ## _cast_argument1->numerator));\
make_tmp_mint(__ ## var ## _cast_denominator,\
size_mint(__ ## var ## _cast_argument1->denominator));\
make_tmp_mdec(__ ## var ## _cast_tmp1, 0,\
__ ## var ## _cast_numerator,\
__ ## var ## _cast_denominator);\
make_tmp_mint(__ ## var ## _cast_tmp2,\
cast_mdec_to_tmp_double_max(\
size_mint(__ ## var ## _cast_argument1->numerator),\
size_mint(__ ## var ## _cast_argument1->denominator)));\
make_tmp_mint(__ ## var ## _cast_tmp3,\
cast_mdec_to_tmp_double_max(\
size_mint(__ ## var ## _cast_argument1->numerator),\
size_mint(__ ## var ## _cast_argument1->denominator)));\
var = cast_mdec_to_double_manually(\
__ ## var ## _cast_argument1,\
__ ## var ## _cast_tmp1,\
__ ## var ## _cast_tmp2,\
__ ## var ## _cast_tmp3); }

#define cast_mdec_to_tmp_float_max(a, b) ((a)<(b)?(b):(a))
#define cast_mdec_to_tmp_float(var, num)\
mdec *__ ## var ## _cast_argument1 = num;\
float var; {\
make_tmp_mint(__ ## var ## _cast_numerator,\
size_mint(__ ## var ## _cast_argument1->numerator));\
make_tmp_mint(__ ## var ## _cast_denominator,\
size_mint(__ ## var ## _cast_argument1->denominator));\
make_tmp_mdec(__ ## var ## _cast_tmp1, 0,\
__ ## var ## _cast_numerator,\
__ ## var ## _cast_denominator);\
make_tmp_mint(__ ## var ## _cast_tmp2,\
cast_mdec_to_tmp_float_max(\
size_mint(__ ## var ## _cast_argument1->numerator),\
size_mint(__ ## var ## _cast_argument1->denominator)));\
make_tmp_mint(__ ## var ## _cast_tmp3,\
cast_mdec_to_tmp_float_max(\
size_mint(__ ## var ## _cast_argument1->numerator),\
size_mint(__ ## var ## _cast_argument1->denominator)));\
var = cast_mdec_to_float_manually(\
__ ## var ## _cast_argument1,\
__ ## var ## _cast_tmp1,\
__ ## var ## _cast_tmp2,\
__ ## var ## _cast_tmp3); }

#define cast_mdec_to_tmp_long(var, num)\
mdec *__ ## var ## _cast_argument1 = num;\
long var; {\
make_tmp_mint(__ ## var ## _cast_tmp1,\
size_mint(__ ## var ## _cast_argument1->numerator));\
make_tmp_mint(__ ## var ## _cast_tmp2,\
size_mint(__ ## var ## _cast_argument1->numerator));\
var = cast_mdec_to_long_manually(\
__ ## var ## _cast_argument1,\
__ ## var ## _cast_tmp1,\
__ ## var ## _cast_tmp2); }

#define cast_mdec_to_tmp_int(var, num)\
mdec *__ ## var ## _cast_argument1 = num;\
int var; {\
make_tmp_mint(__ ## var ## _cast_tmp1,\
size_mint(__ ## var ## _cast_argument1->numerator));\
make_tmp_mint(__ ## var ## _cast_tmp2,\
size_mint(__ ## var ## _cast_argument1->numerator));\
var = cast_mdec_to_int_manually(\
__ ## var ## _cast_argument1,\
__ ## var ## _cast_tmp1,\
__ ## var ## _cast_tmp2); }

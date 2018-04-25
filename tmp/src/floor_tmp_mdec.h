#pragma once
#include <mdec.h>

#define floor_tmp_mdec(var, num)\
mdec *__ ## var ## _floor_argument1 = num;\
mint *var = make_mint(\
size_mint(__ ## var ## _floor_argument1->numerator)); {\
mint *__ ## var ## _floor_tmp = make_mint(\
size_mint(__ ## var ## _floor_argument1->numerator));\
floor_mdec_manually(\
__ ## var ## _floor_argument1, var,\
__ ## var ## _floor_tmp); }

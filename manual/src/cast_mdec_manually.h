#pragma once
#include <mdec.h>

extern double cast_mdec_to_double_sloppily (mdec*);
extern float cast_mdec_to_float_sloppily (mdec*);
extern long cast_mdec_to_long_sloppily (mdec*);
extern int cast_mdec_to_int_sloppily (mdec*);
extern double cast_mdec_to_double_manually (mdec*, mdec*, mint*, mint*);
extern float cast_mdec_to_float_manually (mdec*, mdec*, mint*, mint*);
extern long cast_mdec_to_long_manually (mdec*, mint*, mint*);
extern int cast_mdec_to_int_manually (mdec*, mint*, mint*);

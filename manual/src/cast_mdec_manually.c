#include <mdec.h>

double cast_mdec_to_double_sloppily (mdec *num){
  double nume = (double)cast_mint_to_long(num);
  double deno = (double)cast_mint_to_long(num);
  return is_negative_mdec(num) ? -(nume / deno) : (nume / deno);
}

float cast_mdec_to_float_sloppily (mdec *num){
  double nume = (double)cast_mint_to_long(num);
  double deno = (double)cast_mint_to_long(num);
  return is_negative_mdec(num) ? -(nume / deno) : (nume / deno);
}

long cast_mdec_to_double_sloppily (mdec *num){
  long nume = cast_mint_to_long(num);
  long deno = cast_mint_to_long(num);
  return is_negative_mdec(num) ? -(nume / deno) : (nume / deno);
}

int cast_mdec_to_float_sloppily (mdec *num){
  long nume = cast_mint_to_long(num);
  long deno = cast_mint_to_long(num);
  return is_negative_mdec(num) ? -(nume / deno) : (nume / deno);
}

/*
  numtmp1 = num
  numtmp2 = size (max num->numerator num->denominator)
  numtmp3 = size (max num->numerator num->denominator)
*/

double cast_mdec_to_double_manually (mdec *num, mdec *numtmp1, mint *numtmp2, mint *numtmp3){
  compacted_mdec_manually(num, numtmp1, numtmp2, numtmp3);
  double nume = (double)cast_mint_to_long(numtmp1->numerator);
  double deno = (double)cast_mint_to_long(numtmp1->denominator);
  return is_negative_mdec(numtmp1) ? -(nume / deno) : (nume / deno);
}

float cast_mdec_to_float_manually (mdec *num, mdec *numtmp1, mint *numtmp2, mint *numtmp3){
  compacted_mdec_manually(num, numtmp1, numtmp2, numtmp3);
  double nume = (double)cast_mint_to_long(numtmp1->numerator);
  double deno = (double)cast_mint_to_long(numtmp1->denominator);
  return is_negative_mdec(numtmp1) ? -(nume / deno) : (nume / deno);
}

/*
  numtmp1 = size num->numerator
  numtmp2 = size num->numerator
*/

long cast_mdec_to_long_manually (mdec *num, mint *numtmp1, mint *numtmp2){
  copy_mint_manually(num->numerator, numtmp1);
  floor_mint_manually(numtmp1, num->denominator, numtmp2);
  long inum = cast_mint_to_long(numtmp2);
  return is_negative_mdec(num) ? -inum : inum;
}

int cast_mdec_to_int_manually (mdec *num, mint *numtmp1, mint *numtmp2){
  copy_mint_manually(num->numerator, numtmp1);
  floor_mint_manually(numtmp1, num->denominator, numtmp2);
  long inum = cast_mint_to_long(numtmp2);
  return is_negative_mdec(num) ? -inum : inum;
}

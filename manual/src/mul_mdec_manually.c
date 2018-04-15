#include <mdec.h>

/*
  numout->numerator size = numa->numerator + numb->numerator
  numout->denominator size = numa->denominator + numb->denominator
*/

void mul_mdec_manually (mdec *numa, mdec *numb, mdec *numout){
  if (is_zero_mdec(numa)){
    load_mint_from_int(0, numout->numerator);
    load_mint_from_int(1, numout->denominator);
    numout->sign = MDEC_POSITIVE;
    return;
  }
  if (is_zero_mdec(numb)){
    load_mint_from_int(0, numout->numerator);
    load_mint_from_int(1, numout->denominator);
    numout->sign = MDEC_POSITIVE;
    return;
  }
  mul_mint_manually(numa->numerator, numb->numerator, numout->numerator);
  mul_mint_manually(numa->denominator, numb->denominator, numout->denominator);
  numout->sign = numa->sign == numb->sign ? MDEC_POSITIVE : MDEC_NEGATIVE;
  return;
}

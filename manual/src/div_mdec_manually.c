#include <mdec.h>

/*
  numout->numerator size = numa->numerator + numb->denominator
  numout->denominator size = numa->denominator + numb->numerator 
*/

int div_mdec_manually (mdec *numa, mdec *numb, mdec *numout){
  if (is_zero_mdec(numb))
    return 1; // zero division exception!
  mul_mint_manually(numa->numerator, numb->denominator, numout->numerator);
  mul_mint_manually(numa->denominator, numb->numerator, numout->denominator);
  numout->sign = numa->sign == numb->sign ? MDEC_POSITIVE : MDEC_NEGATIVE;
  return 0;
}

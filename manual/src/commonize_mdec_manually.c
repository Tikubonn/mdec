#include <mdec.h>

/*
  denominator numa = it + numderator numb
  denominator numb = it + numderator numa
  numerator numa = it + numerator numb
  numerator numb = it + numerator numa
*/

void commonize_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbout){
  if (is_equal_mint(numa->denominator, numb->denominator)){
    copy_mdec_manually(numa, numaout);
    copy_mdec_manually(numb, numbout);
  }
  else {
    numaout->sign = numa->sign;
    numbout->sign = numb->sign;
    mul_mint_manually(numa->numerator, numb->denominator, numaout->numerator);
    mul_mint_manually(numb->numerator, numa->denominator, numbout->numerator);    
    mul_mint_manually(numa->denominator, numb->denominator, numaout->denominator);
    mul_mint_manually(numa->denominator, numb->denominator, numbout->denominator);
  }
}

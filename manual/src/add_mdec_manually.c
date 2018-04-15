#include <mdec.h>

/*
  numaout->numerator size = (max numa->numerator numb->numerator) * 2 +1
  numbtmp->numerator size = (max numa->numerator numb->numerator) * 2
  tmp size = (max numa->numerator numb->numerator) * 2
*/

void add_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbtmp){
  commonize_mdec_manually(numa, numb, numaout, numbtmp);
  if (numaout->sign == numbtmp->sign){
    add_mint_manually(
      numaout->numerator,
      numbtmp->numerator,
      numaout->numerator);
    return;
  }
  if (is_positive_mdec(numaout) && is_negative_mdec(numbtmp)){
    if (is_equal_mint(numaout->numerator, numbtmp->numerator)){
      load_mint_from_int(0, numaout->numerator);
      load_mint_from_int(1, numaout->denominator);
      return;
    }
    if (is_lesser_mint(numaout->numerator, numbtmp->numerator)){
      sub_mint_manually(
        numbtmp->numerator,
        numaout->numerator,
        numaout->numerator);
      numaout->sign = MDEC_NEGATIVE;
      return;
    }
    else {
      sub_mint_manually(numaout->numerator, numbtmp->numerator, numaout->numerator);
      return;
    }
  }
  if (is_negative_mdec(numaout) && is_positive_mdec(numbtmp)){
    if (is_equal_mint(numaout->numerator, numbtmp->numerator)){
      load_mint_from_int(0, numaout->numerator);
      load_mint_from_int(1, numaout->denominator);
      return;
    }
    if (is_lesser_mint(numaout->numerator, numbtmp->numerator)){
      sub_mint_manually(
        numbtmp->numerator,
        numaout->numerator,
        numaout->numerator);
      numaout->sign = MDEC_POSITIVE;
      return;
    }
    else {
      sub_mint_manually(
        numaout->numerator,
        numbtmp->numerator,
        numaout->numerator);
      return;
    }
  }
}

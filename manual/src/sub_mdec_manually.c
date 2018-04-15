#include <mdec.h>

/*
  numaout->numerator size = (max numa->numerator numb->numerator) * 2 +1
  numbtmp->numerator size = (max numa->numerator numb->numerator) * 2
  tmp size = (max numa->numerator numb->numerator) * 2
*/

void sub_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbtmp){
  commonize_mdec_manually(numa, numb, numaout, numbtmp);
  if (is_positive_mdec(numaout)){
    if (is_positive_mdec(numbtmp)){
      if (is_equal_mint(numaout->numerator, numbtmp->numerator)){ // n - n = 0
        load_mint_from_int(0, numaout->numerator);
        load_mint_from_int(1, numaout->denominator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      if (is_lesser_mint(numaout->numerator, numbtmp->numerator)){ // n - n = a < 0
        sub_mint_manually(
          numbtmp->numerator, 
          numaout->numerator,
          numaout->numerator);
        numaout->sign = MDEC_NEGATIVE;
        return;
      }
      else { // n - n = 0 <= a
        sub_mint_manually(
          numaout->numerator,
          numbtmp->numerator,
          numaout->numerator);
        return;
      }
    }
    else { // n - (-n)
      add_mint_manually(
        numaout->numerator,
        numbtmp->numerator,
        numaout->numerator);
      return;
    }
  }
  if (is_negative_mdec(numaout)){
    if (is_negative_mdec(numbtmp)){
      if (is_equal_mint(numaout->numerator, numbtmp->numerator)){ // (-n) - (-n) = 0
        load_mint_from_int(0, numaout->numerator);
        load_mint_from_int(1, numaout->denominator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      if (is_lesser_mint(numaout->numerator, numbtmp->numerator)){ // (-n) - (-n) = a < 0
        sub_mint_manually(
          numbtmp->numerator,
          numaout->numerator,
          numaout->numerator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      else { // (-n) - (-n) = 0 <= a
        sub_mint_manually(
          numaout->numerator,
          numbtmp->numerator,
          numaout->numerator);
        return;
      }
    }
    else { // (-n) - n
      add_mint_manually(
        numaout->numerator,
        numbtmp->numerator,
        numaout->numerator);
      return;
    }
  }
}

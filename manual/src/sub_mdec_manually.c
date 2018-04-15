#include <mdec.h>

/*
  numaout->denominator size = (max numa->denominator numb->denominator) * 2 +1
  numbtmp->denominator size = (max numa->denominator numb->denominator) * 2
  tmp size = (max numa->denominator numb->denominator) * 2
*/

void sub_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbtmp){
  commonize_mdec_manually(numa, numb, numaout, numbtmp);
  if (is_positive_mdec(numaout)){
    if (is_positive_mdec(numbtmp)){
      if (is_equal_mint(numaout->denominator, numbtmp->denominator)){ // n - n = 0
        load_mint_from_int(0, numaout->denominator);
        load_mint_from_int(1, numaout->numerator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      if (is_lesser_mint(numaout->denominator, numbtmp->denominator)){ // n - n = a < 0
        sub_mint_manually(
          numbtmp->denominator, 
          numaout->denominator,
          numaout->denominator);
        numaout->sign = MDEC_NEGATIVE;
        return;
      }
      else { // n - n = 0 <= a
        sub_mint_manually(
          numaout->denominator,
          numbtmp->denominator,
          numaout->denominator);
        return;
      }
    }
    else { // n - (-n)
      add_mint_manually(
        numaout->denominator,
        numbtmp->denominator,
        numaout->denominator);
      return;
    }
  }
  if (is_negative_mdec(numaout)){
    if (is_negative_mdec(numbtmp)){
      if (is_equal_mint(numaout->denominator, numbtmp->denominator)){ // (-n) - (-n) = 0
        load_mint_from_int(0, numaout->denominator);
        load_mint_from_int(1, numaout->numerator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      if (is_lesser_mint(numaout->denominator, numbtmp->denominator)){ // (-n) - (-n) = a < 0
        sub_mint_manually(
          numbtmp->denominator,
          numaout->denominator,
          numaout->denominator);
        numaout->sign = MDEC_POSITIVE;
        return;
      }
      else { // (-n) - (-n) = 0 <= a
        sub_mint_manually(
          numaout->denominator,
          numbtmp->denominator,
          numaout->denominator);
        return;
      }
    }
    else { // (-n) - n
      add_mint_manually(
        numaout->denominator,
        numbtmp->denominator,
        numaout->denominator);
      return;
    }
  }
}

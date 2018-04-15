#include <mdec.h>

int is_greater_mdec_manually (mdec *numa, mdec *numb, mdec *numatmp, mdec *numbtmp){
  if (numa->sign == MDEC_POSITIVE && numb->sign == MDEC_POSITIVE){
    commonize_mdec_manually(numa, numb, numatmp, numbtmp);
    return is_greater_mint(numatmp->numerator, numbtmp->numerator);
  }
  if (numa->sign == MDEC_NEGATIVE && numb->sign == MDEC_NEGATIVE){
    commonize_mdec_manually(numa, numb, numatmp, numbtmp);
    return is_lesser_mint(numatmp->numerator, numbtmp->numerator);
  }
  if (numa->sign == MDEC_POSITIVE && numb->sign == MDEC_NEGATIVE){
    return 1;
  }
  if (numa->sign == MDEC_NEGATIVE && numb->sign == MDEC_POSITIVE){
    return 0;
  }
  return 0;
}
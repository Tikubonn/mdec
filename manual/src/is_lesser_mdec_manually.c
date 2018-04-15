#include <mdec.h>

int is_lesser_mdec_manually (mdec *numa, mdec *numb, mdec *numatmp, mdec *numbtmp){
  if (numa->sign == MDEC_POSITIVE && numb->sign == MDEC_POSITIVE){
    commonize_mdec_manually(numa, numb, numatmp, numbtmp);
    return is_lesser_mint(numatmp->numerator, numbtmp->numerator);
  }
  if (numa->sign == MDEC_NEGATIVE && numb->sign == MDEC_NEGATIVE){
    commonize_mdec_manually(numa, numb, numatmp, numbtmp);
    return is_greater_mint(numatmp->numerator, numbtmp->numerator);
  }
  if (numa->sign == MDEC_POSITIVE && numb->sign == MDEC_NEGATIVE){
    return 0;
  }
  if (numa->sign == MDEC_NEGATIVE && numb->sign == MDEC_POSITIVE){
    return 1;
  }
  return 0;
}

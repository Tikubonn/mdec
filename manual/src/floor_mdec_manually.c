#include <mdec.h>

/*
  numout = sizeof num->numerator 
  numtmp = sizeof num->numerator
*/

void floor_mdec_manually (mdec *num, mint *numout, mint *numtmp){
  copy_mint_manually(num->numerator, numtmp);
  floor_mint_manually(numtmp, num->denominator, numout);
}

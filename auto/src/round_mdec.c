#include <mdec.h>

mint *round_mdec (mdec *num){
  mint *numout = make_mint(size_mint(num->numerator) +2);
  mint *numtmp = make_mint(size_mint(num->numerator) +1);
  round_mdec_manually(num, numout, numtmp);
  free_mint(numtmp);
  return numout;
}

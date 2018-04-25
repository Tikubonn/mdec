#include <mdec.h>

mint *floor_mdec (mdec *num){
  mint *numout = make_mint(size_mint(num->numerator));
  mint *numtmp = make_mint(size_mint(num->numerator));
  floor_mdec_manually(num, numout, numtmp);
  free_mint(numtmp);
  return numout;
}

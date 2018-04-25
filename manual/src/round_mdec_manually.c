#include <mdec.h>

/*
  numtmp = sizeof num->numerator +1
  numout = sizeof num->numerator +1
*/

void round_mdec_manually (mdec *num, mint *numout, mint *numtmp){
  copy_mint_manually(num->numerator, numtmp);
  floor_mint_manually(numtmp, num->denominator, numout);
  add_mint_manually(numtmp, numtmp, numtmp);
  if (is_greater_or_equal_mint(numtmp, num->denominator)){
    make_tmp_mint_from_int(num1, 1);
    add_mint_manually(numout, num1, numout);
  }
}

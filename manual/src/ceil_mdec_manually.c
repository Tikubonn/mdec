#include <mdec.h>

/*
  numout = sizeof num->numerator +2
  numtmp = sizeof num->numerator
*/

void ceil_mdec_manually (mdec *num, mint *numout, mint *numtmp){
  copy_mint_manually(num->numerator, numtmp);
  floor_mint_manually(numtmp, num->denominator, numout);
  if (!is_zero_mint(numtmp)){
    make_tmp_mint_from_int(num1, 1);
    add_mint_manually(numout, num1, numout);
  }
  if (is_negative_mdec(num)){
    make_tmp_mint_from_int(num0, 0);
    sub_mint_manually(num0, numout, numout);
  }
}

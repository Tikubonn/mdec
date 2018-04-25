#include <mdec.h>

void ceil_mdec_manually (mdec *num, mint *numout, mint *numtmp){
  copy_mint_manually(num->numerator, numtmp);
  floor_mint_manually(numtmp, num->denominator, numout);
  if (!is_zero_mint(numtmp)){
    make_tmp_mint_from_int(num1, 1);
    add_mint_manually(numout, num1, numout);
  }
}

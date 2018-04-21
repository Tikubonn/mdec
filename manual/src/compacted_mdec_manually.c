#include <mdec.h>

mint *common_divisor_in (mint *numtmp1, mint *numtmp2){
  make_tmp_mint(emp, 1);
  while (1){
    floor_mint_manually(numtmp1, numtmp2, emp);
    if (is_zero_mint(numtmp1))
      return numtmp2;
    floor_mint_manually(numtmp2, numtmp1, emp);
    if (is_zero_mint(numtmp2))
      return numtmp1;
  }
}

mint *common_divisor (mdec *num, mint *numtmp1, mint *numtmp2){
  copy_mint_manually(num->numerator, numtmp1);
  copy_mint_manually(num->denominator, numtmp2);
  if (is_greater_mint(numtmp1, numtmp2))
    return common_divisor_in(numtmp1, numtmp2);
  return common_divisor_in(numtmp2, numtmp1);
}

/*
  numout = sizeof num
  numtmp1 = sizeof (max num->numerator num->denominator)
  numtmp2 = sizeof (max num->numerator num->denominator) 
*/

void compacted_mdec_manually (mdec *num, mdec *numout, mint *numtmp1, mint *numtmp2){
  if (is_zero_mdec(num)){
    copy_mdec_manually(num, numout);
    return;
  }
  mint *commd = common_divisor(num, numtmp1, numtmp2);
  if (commd == numtmp1){
    numout->sign = num->sign;
    copy_mint_manually(num->numerator, numtmp2);
    floor_mint_manually(numtmp2, commd, numout->numerator);
    copy_mint_manually(num->denominator, numtmp2);
    floor_mint_manually(numtmp2, commd, numout->denominator);
    return;
  }
  if (commd == numtmp2){
    numout->sign = num->sign;
    copy_mint_manually(num->numerator, numtmp1);
    floor_mint_manually(numtmp1, commd, numout->numerator);
    copy_mint_manually(num->denominator, numtmp1);
    floor_mint_manually(numtmp1, commd, numout->denominator);
    return;
  }
}

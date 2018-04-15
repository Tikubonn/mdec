#include <mdec.h>

mint *cast_mdec_to_mint (mdec *num){
  if (is_negative_mdec(num)){
    mint *num0 = make_mint_from_int(0);
    mint *numd = div_mint(num->denominator, num->numerator);
    mint *numn = sub_mint(num0, numd);
    free_mint(num0);
    free_mint(numd);
    return numn;
  }
  else {
    mint *numd = div_mint(num->denominator, num->numerator);
    return numd;
  }
}

int cast_mdec_to_int (mdec *num){
  mint *numc = cast_mdec_to_mint(num);
  int inumc = cast_mint_to_int(numc);
  free_mint(numc);
  return inumc;
}

long cast_mdec_to_long (mdec *num){
  mint *numc = cast_mdec_to_mint(num);
  int inumc = cast_mint_to_long(numc);
  free_mint(numc);
  return inumc;
}

#include <mdec.h>
#include <stdlib.h>

mdec *make_mdec (int sign, mint *denominator, mint *numerator){
  mdec *md = malloc(sizeof(mdec));
  md->sign = sign;
  md->denominator = denominator;
  md->numerator = numerator;
  return md;
}

mdec *make_mdec_from_int (int num){
  if (num < 0){
    mint *denominator = make_mint_from_int(-num);
    mint *numerator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, denominator, numerator);
    return md;
  }
  else {
    mint *denominator = make_mint_from_int(num);
    mint *numerator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, denominator, numerator);
    return md;
  }
}

mdec *make_mdec_from_long (long num){
  if (num < 0){
    mint *denominator = make_mint_from_int(-num);
    mint *numerator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, denominator, numerator);
    return md;
  }
  else {
    mint *denominator = make_mint_from_int(num);
    mint *numerator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, denominator, numerator);
    return md;
  }
}

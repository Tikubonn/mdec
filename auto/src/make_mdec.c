#include <mdec.h>
#include <stdlib.h>

mdec *make_mdec (int sign, mint *numerator, mint *denominator){
  mdec *md = malloc(sizeof(mdec));
  md->sign = sign;
  md->numerator = numerator;
  md->denominator = denominator;
  return md;
}

mdec *make_mdec_from_int (int num){
  if (num < 0){
    mint *numerator = make_mint_from_int(-num);
    mint *denominator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, numerator, denominator);
    return md;
  }
  else {
    mint *numerator = make_mint_from_int(num);
    mint *denominator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, numerator, denominator);
    return md;
  }
}

mdec *make_mdec_from_long (long num){
  if (num < 0){
    mint *numerator = make_mint_from_int(-num);
    mint *denominator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, numerator, denominator);
    return md;
  }
  else {
    mint *numerator = make_mint_from_int(num);
    mint *denominator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, numerator, denominator);
    return md;
  }
}

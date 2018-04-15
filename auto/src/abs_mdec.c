#include <mdec.h>

mdec *abs_mdec (mdec *num){
  mint *numerator = make_mint(
    size_mint(num->numerator));
  mint *denominator = make_mint(
    size_mint(num->denominator));
  mdec *md = make_mdec(0, numerator, denominator);
  abs_mdec_manually(num, md);
  return md;
}

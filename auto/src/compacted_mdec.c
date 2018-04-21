#include <mdec.h>
#define max(a, b) ((a)<(b)?(b):(a))

mdec *compacted_mdec (mdec *num){
  mint *numerator = make_mint(size_mint(num->numerator));
  mint *denominator = make_mint(size_mint(num->denominator));
  mdec *numout = make_mdec(0, numerator, denominator);
  mint *numtmp1 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  mint *numtmp2 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  compacted_mdec_manually(num, numout, numtmp1, numtmp2);
  free_mint(numtmp1);
  free_mint(numtmp2);
  return numout;
}

/* static mint *common_divisor_in (mint *max, mint *min){
  mint *numa = copy_mint(max);
  mint *numb = copy_mint(min);
  while (1){
    mint *tempa = mod_mint(numa, numb);
    if (is_zero_mint(tempa)){
      free_mint(tempa);
      free_mint(numa);
      return numb;
    }
    free_mint(numa);
    numa = tempa;
    mint *tempb = mod_mint(numb, numa);
    if (is_zero_mint(tempb)){
      free_mint(tempb);
      free_mint(numb);
      return numa;
    }
    free_mint(numb);
    numb = tempb;
  }
} */

/* static mint *common_divisor (mint *numa, mint *numb){
  if (is_greater_mint(numa, numb))
    return common_divisor_in(numa, numb);
  return common_divisor_in(numb, numa);
} */

/* mdec *compacted_mdec (mdec *num){
  if (is_zero_mdec(num)){
    mint *numerator = make_mint_from_int(0);
    mint *denominator = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, numerator, denominator);
    return md;
  }
  else {
    mint *numd = common_divisor(num->numerator, num->denominator);
    mint *numerator = div_mint(num->numerator, numd);
    mint *denominator = div_mint(num->denominator, numd);
    mdec *md = make_mdec(num->sign, numerator, denominator);
    return md;
  }
} */

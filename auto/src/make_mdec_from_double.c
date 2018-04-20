#include <mdec.h>
#define abs(a) ((a)<0?-(a):(a))

static mint *make_denominator (mint *num){
  mint *numb = make_mint_from_int(1);
  mint *num10 = make_mint_from_int(10);
  while (is_lesser_mint(numb, num)){
    mint *numb1 = mul_mint(numb, num10);
    free_mint(numb);
    numb = numb1;
  }
  return numb;
}

static mint *make_numerator_of_fraction (double num){
  mint *numb = make_mint_from_int(1);
  mint *num2 = make_mint_from_int(2);
  mint *num10 = make_mint_from_int(10);
  mint *numsum = make_mint_from_int(0);
  double numdb = 1.0 / 2.0; // 1/2
  while (0.0 < num){
    
    mint *numb1 = mul_mint(numb, num10);
    mint *numb2 = div_mint(numb1, num2);
    free_mint(numb1);
    free_mint(numb);
    numb = numb2;
    
    mint *numsum1 = mul_mint(numsum, num10);
    free_mint(numsum);
    numsum = numsum1;
    
    if (numdb <= num){
      num -= numdb;
      mint *numsum1 = add_mint(numsum, numb);
      free_mint(numsum);
      numsum = numsum1;
    }
    
    numdb /= 2.0;
    
  }
  free_mint(numb);
  free_mint(num2);
  free_mint(num10);
  return numsum;
}

mdec *make_mdec_from_float (float num){
  mdec_sign sign = num < 0 ? MDEC_NEGATIVE : MDEC_POSITIVE;
  mint *numi = make_mint_from_long((long)abs(num));
  mint *numf = make_numerator_of_fraction(abs(num)-(long)abs(num));
  mint *numb = make_denominator(numf);
  mint *num1 = mul_mint(numi, numb);
  mint *num2 = add_mint(num1, numf);
  free_mint(numi);
  free_mint(numf);
  free_mint(num1);
  mdec *md = make_mdec(sign, num2, numb);
  /* compaction_mdec(md);
  return md; */
  mdec *mdc = compacted_mdec(md);
  free_mdec(md);
  return mdc;
}

mdec *make_mdec_from_double (double num){
  mdec_sign sign = num < 0 ? MDEC_NEGATIVE : MDEC_POSITIVE;
  mint *numi = make_mint_from_long((long)abs(num));
  mint *numf = make_numerator_of_fraction(abs(num)-(long)abs(num));
  mint *numb = make_denominator(numf);
  mint *num1 = mul_mint(numi, numb);
  mint *num2 = add_mint(num1, numf);
  free_mint(numi);
  free_mint(numf);
  free_mint(num1);
  mdec *md = make_mdec(sign, num2, numb);
  return md;
  /* compaction_mdec(md);
  return md; */
  mdec *mdc = compacted_mdec(md);
  free_mdec(md);
  return mdc;
}

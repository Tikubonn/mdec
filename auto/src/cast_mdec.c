#include <mdec.h>

mint *cast_mdec_to_mint (mdec *num){
  if (is_negative_mdec(num)){
    mint *num0 = make_mint_from_int(0);
    mint *numd = div_mint(num->numerator, num->denominator);
    mint *numn = sub_mint(num0, numd);
    free_mint(num0);
    free_mint(numd);
    return numn;
  }
  else {
    mint *numd = div_mint(num->numerator, num->denominator);
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

double cast_mdec_to_double (mdec *num){
  /* compaction_mdec(num);
  long numei = cast_mint_to_long(num->numerator);
  long denoi = cast_mint_to_long(num->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  double numd = nume / deno;
  return is_negative_mdec(num) ? 0 - numd : numd; */
  mdec *numc = compacted_mdec(num);
  long numei = cast_mint_to_long(numc->numerator);
  long denoi = cast_mint_to_long(numc->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  double numr = nume / deno;
  free_mdec(numc);
  return is_negative_mdec(num) ? 0 - numr : numr;
}

float cast_mdec_to_float (mdec *num){
  /* compaction_mdec(num);
  long numei = cast_mint_to_long(num->numerator);
  long denoi = cast_mint_to_long(num->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  double numd = nume / deno;
  return is_negative_mdec(num) ? 0 - numd : numd; */
  mdec *numc = compacted_mdec(num);
  long numei = cast_mint_to_long(numc->numerator);
  long denoi = cast_mint_to_long(numc->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  float numr = nume / deno;
  free_mdec(numc);
  return is_negative_mdec(num) ? 0 - numr : numr;
}

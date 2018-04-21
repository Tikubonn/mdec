#include <mdec.h>
#define max(a, b) ((a)<(b)?(b):(a))

mint *cast_mdec_to_mint (mdec *num){
  mint *numout = make_mint(size_mint(num->numerator) +1);
  mint *numtmp = make_mint(size_mint(num->numerator));
  cast_mdec_to_mint_manually(num, numout, numtmp);
  free_mint(numtmp);
  return numout;
}

/* mint *cast_mdec_to_mint (mdec *num){
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
} */

int cast_mdec_to_int (mdec *num){
  mint *numtmp1 = make_mint(size_mint(num->numerator));
  mint *numtmp2 = make_mint(size_mint(num->numerator));
  int inum = cast_mdec_to_int_manually(num, numtmp1, numtmp2);
  free_mint(numtmp1);
  free_mint(numtmp2);
  return inum;
}

/* int cast_mdec_to_int (mdec *num){
  mint *numc = cast_mdec_to_mint(num);
  int inumc = cast_mint_to_int(numc);
  free_mint(numc);
  return inumc;
} */

long cast_mdec_to_long (mdec *num){
  mint *numtmp1 = make_mint(size_mint(num->numerator));
  mint *numtmp2 = make_mint(size_mint(num->numerator));
  long inum = cast_mdec_to_long_manually(num, numtmp1, numtmp2);
  free_mint(numtmp1);
  free_mint(numtmp2);
  return inum;
}

/* long cast_mdec_to_long (mdec *num){
  mint *numc = cast_mdec_to_mint(num);
  int inumc = cast_mint_to_long(numc);
  free_mint(numc);
  return inumc;
} */

double cast_mdec_to_double (mdec *num){
  mint *numerator = make_mint(size_mint(num->numerator));
  mint *denominator = make_mint(size_mint(num->denominator));
  mdec *numtmp1 = make_mdec(0, numerator, denominator);
  mint *numtmp2 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  mint *numtmp3 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  double inum = cast_mdec_to_double_manually(num, numtmp1, numtmp2, numtmp3);
  free_mdec(numtmp1);
  free_mint(numtmp2);
  free_mint(numtmp3);
  return inum;
}

/* double cast_mdec_to_double (mdec *num){
  mdec *numc = compacted_mdec(num);
  long numei = cast_mint_to_long(numc->numerator);
  long denoi = cast_mint_to_long(numc->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  double numr = nume / deno;
  free_mdec(numc);
  return is_negative_mdec(num) ? 0 - numr : numr;
} */

float cast_mdec_to_float (mdec *num){
  mint *numerator = make_mint(size_mint(num->numerator));
  mint *denominator = make_mint(size_mint(num->denominator));
  mdec *numtmp1 = make_mdec(0, numerator, denominator);
  mint *numtmp2 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  mint *numtmp3 = make_mint(max(
    size_mint(num->numerator),
    size_mint(num->denominator)));
  float inum = cast_mdec_to_float_manually(num, numtmp1, numtmp2, numtmp3);
  free_mdec(numtmp1);
  free_mint(numtmp2);
  free_mint(numtmp3);
  return inum;
}

/* float cast_mdec_to_float (mdec *num){
  mdec *numc = compacted_mdec(num);
  long numei = cast_mint_to_long(numc->numerator);
  long denoi = cast_mint_to_long(numc->denominator);
  double nume = (double)numei;
  double deno = (double)denoi;
  float numr = nume / deno;
  free_mdec(numc);
  return is_negative_mdec(num) ? 0 - numr : numr;
} */

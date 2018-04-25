#include <mdec.h>
#define max(a, b) ((a)<(b)?(b):(a))

mint *cast_mdec_to_mint (mdec *num){
  mint *numout = make_mint(size_mint(num->numerator) +1);
  mint *numtmp = make_mint(size_mint(num->numerator));
  cast_mdec_to_mint_manually(num, numout, numtmp);
  free_mint(numtmp);
  return numout;
}

int cast_mdec_to_int (mdec *num){
  mint *numtmp1 = make_mint(size_mint(num->numerator));
  mint *numtmp2 = make_mint(size_mint(num->numerator));
  int inum = cast_mdec_to_int_manually(num, numtmp1, numtmp2);
  free_mint(numtmp1);
  free_mint(numtmp2);
  return inum;
}

long cast_mdec_to_long (mdec *num){
  mint *numtmp1 = make_mint(size_mint(num->numerator));
  mint *numtmp2 = make_mint(size_mint(num->numerator));
  long inum = cast_mdec_to_long_manually(num, numtmp1, numtmp2);
  free_mint(numtmp1);
  free_mint(numtmp2);
  return inum;
}

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

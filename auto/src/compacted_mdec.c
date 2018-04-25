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

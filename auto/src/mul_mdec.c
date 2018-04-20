#include <mdec.h>

mdec *mul_mdec (mdec *numa, mdec *numb){
  mint *numerator = make_mint(
    size_mint(numa->numerator) + 
    size_mint(numb->numerator));
  mint *denominator = make_mint(
    size_mint(numa->denominator) +
    size_mint(numb->denominator));
  mdec *md = make_mdec(0, numerator, denominator);
  mul_mdec_manually(numa, numb, md);
  /* compaction_mdec(md);
  return md; */
  mdec *mdc = compacted_mdec(md);
  free_mdec(md);
  return mdc;
}

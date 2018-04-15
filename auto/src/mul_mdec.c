#include <mdec.h>

mdec *mul_mdec (mdec *numa, mdec *numb){
  mint *denominator = make_mint(
    size_mint(numa->denominator) + 
    size_mint(numb->denominator));
  mint *numerator = make_mint(
    size_mint(numa->numerator) +
    size_mint(numb->numerator));
  mdec *md = make_mdec(0, denominator, numerator);
  mul_mdec_manually(numa, numb, md);
	compaction_mdec(md);
  return md;
}

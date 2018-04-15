#include <mdec.h>
#include <stdlib.h>

mdec *div_mdec (mdec *numa, mdec *numb){
  mint *denominator = make_mint(
    size_mint(numa->denominator) +
    size_mint(numb->numerator));
  mint *numerator = make_mint(
    size_mint(numa->numerator) +
    size_mint(numb->denominator));
  mdec *md = make_mdec(0, denominator, numerator);
  if (div_mdec_manually(numa, numb, md)){
    free_mdec(md);
    return NULL;
  }
	compaction_mdec(md);
  return md;
}

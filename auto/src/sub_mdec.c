#include <mdec.h>
#define max(a,b) ((a)<(b)?(b):(a))

mdec *sub_mdec (mdec *numa, mdec *numb){
  /* mint *numeratora = make_mint(
    size_mint(numa->numerator) + 
    size_mint(numb->denominator) +1); */
  mint *numeratora = make_mint(max(
    size_mint(numa->numerator) +
    size_mint(numb->denominator),
    size_mint(numb->numerator) +
    size_mint(numa->denominator)) +1);
  mint *denominatora = make_mint(
    size_mint(numa->denominator) +
    size_mint(numb->denominator));
  mdec *mda = make_mdec(0, numeratora, denominatora);
  mint *numeratorb = make_mint(
    size_mint(numb->numerator) + 
    size_mint(numa->denominator));
  mint *denominatorb = make_mint(
    size_mint(numb->denominator) +
    size_mint(numa->denominator));
  mdec *mdb = make_mdec(0, numeratorb, denominatorb);
  sub_mdec_manually(numa, numb, mda, mdb);
	compaction_mdec(mda);
  free_mdec(mdb);
  return mda;
}

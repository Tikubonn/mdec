#include <mdec.h>

int is_unequal_mdec (mdec *numa, mdec *numb){
  mint *numeratora = make_mint(
    size_mint(numa->numerator) +
    size_mint(numb->denominator));
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
  int boo = is_unequal_mdec_manually(numa, numb, mda, mdb);
  free_mdec(mda);
  free_mdec(mdb);
  return boo;
}

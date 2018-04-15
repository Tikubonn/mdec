#include <mdec.h>
#include <stdio.h>

int is_equal_mdec (mdec *numa, mdec *numb){
  mint *denominatora = make_mint(
    size_mint(numa->denominator) +
    size_mint(numb->numerator));
  mint *numeratora = make_mint(
    size_mint(numa->numerator) +
    size_mint(numb->numerator));
  mdec *mda = make_mdec(0, denominatora, numeratora);
  mint *denominatorb = make_mint(
    size_mint(numb->denominator) +
    size_mint(numa->numerator));
  mint *numeratorb = make_mint(
    size_mint(numb->numerator) +
    size_mint(numa->numerator));  
  mdec *mdb = make_mdec(0, denominatorb, numeratorb);
  int boo = is_equal_mdec_manually(numa, numb, mda, mdb);
  free_mdec(mda);
  free_mdec(mdb);
  return boo;
}

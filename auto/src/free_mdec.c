#include <mdec.h>
#include <stdlib.h>

void free_mdec (mdec *num){
  free_mint(num->numerator);
  free_mint(num->denominator);
  free(num);
}

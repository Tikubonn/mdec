#include <mdec.h>

int is_unequal_mdec_manually (mdec *numa, mdec *numb, mdec *numatmp, mdec *numbtmp){
  return !is_equal_mdec_manually(numa, numb, numatmp, numbtmp);
}

#include <mdec.h>

int is_greater_or_equal_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbout){
  return !is_lesser_mdec_manually(numa, numb, numaout, numbout);
}

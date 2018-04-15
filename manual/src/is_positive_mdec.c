#include <mdec.h>

int is_positive_mdec (mdec *num){
  return num->sign == MDEC_POSITIVE;
}

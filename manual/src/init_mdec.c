#include <mdec.h>

void init_mdec (mdec_sign sign, mint *numerator, mint *denominator, mdec *num){
  num->sign = sign;
  num->numerator = numerator;
  num->denominator = denominator;
}

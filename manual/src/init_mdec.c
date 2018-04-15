#include <mdec.h>

void init_mdec (int sign, mint *numerator, mint *denominator, mdec *num){
  num->sign = sign;
  num->numerator = numerator;
  num->denominator = denominator;
}

#include <mdec.h>

void init_mdec (int sign, mint *denominator, mint *numerator, mdec *num){
	num->sign = sign;
	num->denominator = denominator;
	num->numerator = numerator;
}

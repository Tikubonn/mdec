#include <mdec.h>

void copy_mdec_manually (mdec *num, mdec *numout){
	numout->sign = num->sign;
	copy_mint_manually(num->denominator, numout->denominator);
	copy_mint_manually(num->numerator, numout->numerator);
}

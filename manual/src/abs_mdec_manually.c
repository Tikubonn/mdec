#include <mdec.h>

void abs_mdec_manually (mdec *num, mdec *numout){
	numout->sign = MDEC_POSITIVE;
	copy_mint_manually(num->denominator, numout->denominator);
	copy_mint_manually(num->numerator, numout->numerator);
}

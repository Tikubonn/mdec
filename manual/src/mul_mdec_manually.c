#include <mdec.h>

/*
	numout->denominator size = numa->denominator + numb->denominator
	numout->numerator size = numa->numerator + numb->numerator
*/

void mul_mdec_manually (mdec *numa, mdec *numb, mdec *numout){
	if (is_zero_mdec(numa)){
		load_mint_from_int(0, numout->denominator);
		load_mint_from_int(1, numout->numerator);
		numout->sign = MDEC_POSITIVE;
		return;
	}
	if (is_zero_mdec(numb)){
		load_mint_from_int(0, numout->denominator);
		load_mint_from_int(1, numout->numerator);
		numout->sign = MDEC_POSITIVE;
		return;
	}
	mul_mint_manually(numa->denominator, numb->denominator, numout->denominator);
	mul_mint_manually(numa->numerator, numb->numerator, numout->numerator);
	numout->sign = numa->sign == numb->sign ? MDEC_POSITIVE : MDEC_NEGATIVE;
	return;
}

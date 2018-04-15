#include <mdec.h>

/*
	numerator numa = it + numderator numb
	numerator numb = it + numderator numa
	denominator numa = it + denominator numb
	denominator numb = it + denominator numa
*/

void commonize_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbout){
	if (is_equal_mint(numa->numerator, numb->numerator)){
		copy_mdec_manually(numa, numaout);
		copy_mdec_manually(numb, numbout);
	}
	else {
		numaout->sign = numa->sign;
		numbout->sign = numb->sign;
		mul_mint_manually(numa->denominator, numb->numerator, numaout->denominator);
		mul_mint_manually(numb->denominator, numa->numerator, numbout->denominator);		
		mul_mint_manually(numa->numerator, numb->numerator, numaout->numerator);
		mul_mint_manually(numa->numerator, numb->numerator, numbout->numerator);
	}
}

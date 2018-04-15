#include <mdec.h>

/*
	numaout->denominator size = (max numa->denominator numb->denominator) * 2 +1
	numbtmp->denominator size = (max numa->denominator numb->denominator) * 2
	tmp size = (max numa->denominator numb->denominator) * 2
*/

void add_mdec_manually (mdec *numa, mdec *numb, mdec *numaout, mdec *numbtmp){
	commonize_mdec_manually(numa, numb, numaout, numbtmp);
	if (numaout->sign == numbtmp->sign){
		add_mint_manually(
			numaout->denominator,
			numbtmp->denominator,
			numaout->denominator);
		return;
	}
	if (is_positive_mdec(numaout) && is_negative_mdec(numbtmp)){
		if (is_equal_mint(numaout->denominator, numbtmp->denominator)){
			load_mint_from_int(0, numaout->denominator);
			load_mint_from_int(1, numaout->numerator);
			return;
		}
		if (is_lesser_mint(numaout->denominator, numbtmp->denominator)){
			sub_mint_manually(
				numbtmp->denominator,
				numaout->denominator,
				numaout->denominator);
			numaout->sign = MDEC_NEGATIVE;
			return;
		}
		else {
			sub_mint_manually(numaout->denominator, numbtmp->denominator, numaout->denominator);
			return;
		}
	}
	if (is_negative_mdec(numaout) && is_positive_mdec(numbtmp)){
		if (is_equal_mint(numaout->denominator, numbtmp->denominator)){
			load_mint_from_int(0, numaout->denominator);
			load_mint_from_int(1, numaout->numerator);
			return;
		}
		if (is_lesser_mint(numaout->denominator, numbtmp->denominator)){
			sub_mint_manually(
				numbtmp->denominator,
				numaout->denominator,
				numaout->denominator);
			numaout->sign = MDEC_POSITIVE;
			return;
		}
		else {
			sub_mint_manually(
				numaout->denominator,
				numbtmp->denominator,
				numaout->denominator);
			return;
		}
	}
}

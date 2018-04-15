#include <mdec.h>

static mint *common_divisor_in (mint *max, mint *min){
	mint *numa = copy_mint(max);
	mint *numb = copy_mint(min);
	while (1){
		mint *tempa = mod_mint(numa, numb);
		if (is_zero_mint(tempa)){
			free_mint(tempa);
			free_mint(numa);
			return numb;
		}
		free_mint(numa);
		numa = tempa;
		mint *tempb = mod_mint(numb, numa);
		if (is_zero_mint(tempb)){
			free_mint(tempb);
			free_mint(numb);
			return numa;
		}
		free_mint(numb);
		numb = tempb;
	}
}

static mint *common_divisor (mint *numa, mint *numb){
	if (is_greater_mint(numa, numb))
		return common_divisor_in(numa, numb);
	return common_divisor_in(numb, numa);
}

void compaction_mdec (mdec *num){
	if (is_zero_mdec(num)){
		return;
	}
	mint *numd = common_divisor(num->denominator, num->numerator);
	mint *denominator = div_mint(num->denominator, numd);
	mint *numerator = div_mint(num->numerator, numd);
	free_mint(num->denominator);
	free_mint(num->numerator);
	num->denominator = denominator;
	num->numerator = numerator;
}

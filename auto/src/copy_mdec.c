#include <mdec.h>

mdec *copy_mdec (mdec *num){
	mint *numerator = copy_mint(num->numerator);
	mint *denominator = copy_mint(num->denominator);
	mdec *md = make_mdec(num->sign, numerator, denominator);
	return md;
}

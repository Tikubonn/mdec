#include <mdec.h>

mdec *copy_mdec (mdec *num){
	mint *denominator = copy_mint(num->denominator);
	mint *numerator = copy_mint(num->numerator);
	mdec *md = make_mdec(num->sign, denominator, numerator);
	return md;
}

#include <mdec.h>

mdec *abs_mdec (mdec *num){
	mint *denominator = make_mint(
		size_mint(num->denominator));
	mint *numerator = make_mint(
		size_mint(num->numerator));
	mdec *md = make_mdec(0, denominator, numerator);
	abs_mdec_manually(num, md);
	return md;
}

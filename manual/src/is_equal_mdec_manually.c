#include <mdec.h>

int is_equal_mdec_manually (mdec *numa, mdec *numb, mdec *numatmp, mdec *numbtmp){
	if (numa->sign == numb->sign){
		commonize_mdec_manually(numa, numb, numatmp, numbtmp);
		return is_equal_mint(numatmp->denominator, numbtmp->denominator);
	}
	return 0;
}

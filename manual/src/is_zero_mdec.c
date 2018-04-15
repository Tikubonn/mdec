#include <mdec.h>

int is_zero_mdec (mdec *num){
	return is_zero_mint(num->denominator);
}

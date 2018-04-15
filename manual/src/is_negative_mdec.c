#include <mdec.h>

int is_negative_mdec (mdec *num){
	return num->sign == MDEC_NEGATIVE;
}

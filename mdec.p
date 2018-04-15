#pragma once
#define MDEC_NEGATIVE 0
#define MDEC_POSITIVE 1

struct mdec {
	int sign;
	mint *denominator;
	mint *numerator;
};

typedef struct mdec mdec;

#pragma once
#define MDEC_NEGATIVE 0
#define MDEC_POSITIVE 1

typedef int mdec_sign;

struct mdec {
  mdec_sign sign;
  mint *numerator;
  mint *denominator;
};

typedef struct mdec mdec;

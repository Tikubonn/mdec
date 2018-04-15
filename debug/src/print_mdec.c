#include <mdec.h>
#include <stdio.h>

static mint *make_nd (unsigned long count){
  mint *numn = make_mint_from_int(1);
  mint *num10 = make_mint_from_int(10);
  while (--count){
    mint *tmp = mul_mint(numn, num10);
    free_mint(numn);
    numn = tmp;
  }
  return numn;
}

static void print_mdec_fraction (mint *numerator, mint *denominator, FILE *stream){
  mint *numn = make_mint_from_int(10);
  mint *num10 = make_mint_from_int(10);
  while (is_lesser_mint(numn, denominator)){
    mint *tmp = mul_mint(numn, num10);
    free_mint(numn);
    numn = tmp;
  }
  mint *deno = mul_mint(numerator, numn);
  mint *numd;
  mint *numm;
  floor_mint(deno, denominator, &numd, &numm);
  mint *numn2 = div_mint(numn, num10);
  while (is_lesser_mint(numd, numn2)){
    mint *tmp = div_mint(numn2, num10);
    numn2 = tmp;
    putc('0', stream);
  }
  if (is_zero_mint(numm)){
    print_mint(numd, stream);
  }
  else {
    mint *numdn = make_nd(8 + 1);
    mint *deno2 = mul_mint(deno, numdn);
    mint *numd2 = div_mint(deno2, denominator);
    print_mint(numd2, stream);
    free_mint(numdn);
    free_mint(deno2);
    free_mint(numd2);
  }
  free_mint(numn);
  free_mint(numn2);
  free_mint(num10);
  free_mint(deno);
  free_mint(numd);
}

static void print_mdec_int (mint *numerator, mint *denominator, FILE *stream){
  mint *numd;
  mint *numm;
  floor_mint(numerator, denominator, &numd, &numm);
  print_mint(numd, stream);
  putc('.', stream);
  if (is_zero_mint(numm)){
    free_mint(numd);
    free_mint(numm);
    putc('0', stream);
    return;
  }
  free_mint(numd);
  print_mdec_fraction(numm, denominator, stream);
  free_mint(numm);
}

void print_mdec (mdec *num, FILE *stream){
  if (is_zero_mdec(num)){
    fputs("0.0", stream);
    return;
  }
  print_mdec_int(num->numerator, num->denominator, stream);
}

void print_mdec_ln (mdec *num, FILE *stream){
  print_mdec(num, stream);
  putc('\n', stream);
}

void print_mdec_as_fraction (mdec *num, FILE *stream){
  print_mint(num->numerator, stream);
  putc('/', stream);
  print_mint(num->denominator, stream);
}

void print_mdec_as_fraction_ln (mdec *num, FILE *stream){
  print_mdec_as_fraction(num, stream);
  putc('\n', stream);
}

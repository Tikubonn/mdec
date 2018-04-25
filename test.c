#include <mdec.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define test(code)\
if (code){ printf("success: %s\n", #code); }\
else { printf("failed: %s\n", #code); exit(1); }

#define test2(codea, codeb)\
if ((codea) == (codeb)){ printf("success: %s %s\n", #codea, #codeb); }\
else { printf("failed: %s %s\n", #codea, #codeb); exit(1); }

int main (){
  
  /* test print */
  
  { // (3/1) = 3.0
    mint *deno = make_mint_from_int(3);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    print_mdec_ln(md, stdout);
  }
  
  { // (1/2) = 0.5
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(2);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    print_mdec_ln(md, stdout);
  }
  
  { // (1/3) = 0.33333...
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(3);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    print_mdec_ln(md, stdout);
  }

  /* test make from double */
  
  {
    mdec *mda = make_mdec_from_double(3.0);
    mint *numa = make_mint_from_int(3);
    mint *numb = make_mint_from_int(1);
    mdec *mdb = make_mdec(MDEC_POSITIVE, numa, numb);
    test(is_equal_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  {
    mdec *mda = make_mdec_from_double(-3.0);
    mint *numa = make_mint_from_int(3);
    mint *numb = make_mint_from_int(1);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, numa, numb);
    test(is_equal_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  {
    mdec *mda = make_mdec_from_double(1.5);
    mint *numa = make_mint_from_int(3);
    mint *numb = make_mint_from_int(2);
    mdec *mdb = make_mdec(MDEC_POSITIVE, numa, numb);
    test(is_equal_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  /* test round */
  
  {
    mint *numerator = make_mint_from_int(4);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = round_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
    free_mdec(numa);
    free_mint(numb);
  }
    
  {
    mint *numerator = make_mint_from_int(5);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = round_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
    free_mdec(numa);
    free_mint(numb);
  }
    
  /* test floor */
  
  {
    mint *numerator = make_mint_from_int(4);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = floor_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
    free_mdec(numa);
    free_mint(numb);
  }
    
  {
    mint *numerator = make_mint_from_int(5);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = floor_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
    free_mdec(numa);
    free_mint(numb);
  }
  
  /* test ceil */
  
  {
    mint *numerator = make_mint_from_int(4);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = ceil_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
    free_mdec(numa);
    free_mint(numb);
  }
    
  {
    mint *numerator = make_mint_from_int(5);
    mint *denominator = make_mint_from_int(10);
    mdec *numa = make_mdec(MDEC_POSITIVE, numerator, denominator);
    mint *numb = ceil_mdec(numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
    free_mdec(numa);
    free_mint(numb);
  }
  
  /* test cast */
  
  {
    mdec *md = make_mdec_from_double(3.0);
    double num = cast_mdec_to_double(md);
    test(num == 3.0);
    free_mdec(md);
  }
  
  {
    mdec *md = make_mdec_from_double(-3.0);
    double num = cast_mdec_to_double(md);
    test(num == -3.0);
    free_mdec(md);
  }
  
  {
    mdec *md = make_mdec_from_double(1.5);
    double num = cast_mdec_to_double(md);
    test(num == 1.5);
    free_mdec(md);
  }
  
  /* test cast */
  
  {
    mdec *md = make_mdec_from_double(3.0);
    int num = cast_mdec_to_double(md);
    test(num == 3);
    free_mdec(md);
  }
  
  {
    mdec *md = make_mdec_from_double(-3.0);
    int num = cast_mdec_to_double(md);
    test(num == -3);
    free_mdec(md);
  }
  
  {
    mdec *md = make_mdec_from_double(1.5);
    int num = cast_mdec_to_double(md);
    test(num == 1);
    free_mdec(md);
  }
  
  /* test =0 */
  
  { // (0/n) = (0/1)
    mint *deno = make_mint_from_int(0);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test(is_zero_mdec(md));
    free_mdec(md);
  }
  
  { // (1/3) = (0/1) = false
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(3);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test2(is_zero_mdec(md), false);
    free_mdec(md);
  }
  
  /* test n<0 */
  
  { // -(1/1)
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, deno, nume);
    test(is_negative_mdec(md));
    free_mdec(md);
  }
  
  { // (0/1)
    mint *deno = make_mint_from_int(0);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test2(is_negative_mdec(md), false);
    free_mdec(md);
  }
  
  { // (1/1)
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test2(is_negative_mdec(md), false);
    free_mdec(md);
  }
  
  /* test 0<=n */
  
  { // -(1/1)
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_NEGATIVE, deno, nume);
    test2(is_positive_mdec(md), false);
    free_mdec(md);
  }
  
  { // (0/1)
    mint *deno = make_mint_from_int(0);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test(is_positive_mdec(md));
    free_mdec(md);
  }
  
  { // (1/1)
    mint *deno = make_mint_from_int(1);
    mint *nume = make_mint_from_int(1);
    mdec *md = make_mdec(MDEC_POSITIVE, deno, nume);
    test(is_positive_mdec(md));
    free_mdec(md);
  }
  
  /* test = */
  
  { // (1/3) = (1/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test(is_equal_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // (1/3) = (2/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(2);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test(is_equal_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // (1/3) = (1/6) = false
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test2(is_equal_mdec(mda, mdb), false);
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  /* test < */
  
  { // (1/3) < (1/3) = false
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test2(is_lesser_mdec(mda, mdb), false);
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // -(1/3) < (1/3) = false
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_NEGATIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test(is_lesser_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // (1/6) < (1/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(6);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test(is_lesser_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  /* > */
  
  { // (1/3) > (1/3) = false
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test2(is_greater_mdec(mda, mdb), false);
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // (1/3) > -(1/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, denob, numeb);
    test(is_greater_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  { // (1/3) > (1/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    test(is_greater_mdec(mda, mdb));
    free_mdec(mda);
    free_mdec(mdb);
  }
  
  /* test + */
  
  { // (1/3) + (1/3) = (2/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = add_mdec(mda, mdb);
    mint *denod = make_mint_from_int(2);
    mint *numed = make_mint_from_int(3);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/3) + (1/6) = (2/6) + (1/6) = (3/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = add_mdec(mda, mdb);
    mint *denod = make_mint_from_int(3);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/3) - (1/6) = (2/6) - (1/6) = (1/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, denob, numeb);
    mdec *mdc = add_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/6) - (1/3) = (1/6) - (2/6) = -(1/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(6);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, denob, numeb);
    mdec *mdc = add_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_NEGATIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  /* test - */
  
  { // (1/3) - (1/6) = (2/6) - (1/6) = (1/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(6);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = sub_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/6) - (1/3) = (1/6) - (2/6) = -(1/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(6);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = sub_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_NEGATIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/6) + (1/3) = (1/6) + (2/6) = (3/6)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(6);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, denob, numeb);
    mdec *mdc = sub_mdec(mda, mdb);
    mint *denod = make_mint_from_int(3);
    mint *numed = make_mint_from_int(6);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  /* test * */
  
  { // (1/3) * (1/3) = (1/9)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = mul_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(9);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/3) * -(1/3) = -(1/9)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_NEGATIVE, denob, numeb);
    mdec *mdc = mul_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(9);
    mdec *mdd = make_mdec(MDEC_NEGATIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (3/1) * (1/3) = (3/3)
    mint *denoa = make_mint_from_int(3);
    mint *numea = make_mint_from_int(1);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = mul_mdec(mda, mdb);
    mint *denod = make_mint_from_int(3);
    mint *numed = make_mint_from_int(3);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  /* test / */
  
  { // (1/1) / (1/3) = (1/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(1);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = mul_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(3);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/3) / (1/3) = (3/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(3);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(1);
    mint *numeb = make_mint_from_int(3);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = div_mdec(mda, mdb);
    mint *denod = make_mint_from_int(3);
    mint *numed = make_mint_from_int(3);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  { // (1/1) / (3/1) = (1/3)
    mint *denoa = make_mint_from_int(1);
    mint *numea = make_mint_from_int(1);
    mdec *mda = make_mdec(MDEC_POSITIVE, denoa, numea);
    mint *denob = make_mint_from_int(3);
    mint *numeb = make_mint_from_int(1);
    mdec *mdb = make_mdec(MDEC_POSITIVE, denob, numeb);
    mdec *mdc = div_mdec(mda, mdb);
    mint *denod = make_mint_from_int(1);
    mint *numed = make_mint_from_int(3);
    mdec *mdd = make_mdec(MDEC_POSITIVE, denod, numed);
    test(is_equal_mdec(mdc, mdd));
    free(mda);
    free(mdb);
    free(mdc);
    free(mdd);
  }
  
  /* test tmp + */
  
  {
    make_tmp_mdec_from_int(numa, 2525);
    make_tmp_mdec_from_int(numb, 2828);
    add_tmp_mdec(numc, numa, numb);
    mdec *numd = make_mdec_from_int(2525);
    mdec *nume = make_mdec_from_int(2828);
    mdec *numf = add_mdec(numd, nume);
    test(is_equal_mdec(numc, numf));
    free_mdec(numd);
    free_mdec(nume);
    free_mdec(numf);
  }
  
  /* test tmp - */
  
  {
    make_tmp_mdec_from_int(numa, 2525);
    make_tmp_mdec_from_int(numb, 2828);
    sub_tmp_mdec(numc, numa, numb);
    mdec *numd = make_mdec_from_int(2525);
    mdec *nume = make_mdec_from_int(2828);
    mdec *numf = sub_mdec(numd, nume);
    test(is_equal_mdec(numc, numf));
    free_mdec(numd);
    free_mdec(nume);
    free_mdec(numf);
  }
  
  /* test tmp * */
  
  {
    make_tmp_mdec_from_int(numa, 2525);
    make_tmp_mdec_from_int(numb, 2828);
    mul_tmp_mdec(numc, numa, numb);
    mdec *numd = make_mdec_from_int(2525);
    mdec *nume = make_mdec_from_int(2828);
    mdec *numf = mul_mdec(numd, nume);
    test(is_equal_mdec(numc, numf));
    free_mdec(numd);
    free_mdec(nume);
    free_mdec(numf);
  }
  
  /* test tmp / */
  
  {
    make_tmp_mdec_from_int(numa, 2525);
    make_tmp_mdec_from_int(numb, 2828);
    div_tmp_mdec(numc, numa, numb);
    mdec *numd = make_mdec_from_int(2525);
    mdec *nume = make_mdec_from_int(2828);
    mdec *numf = div_mdec(numd, nume);
    test(is_equal_mdec(numc, numf));
    free_mdec(numd);
    free_mdec(nume);
    free_mdec(numf);
  }
  
  /* test abs */
  
  {
    make_tmp_mdec_from_int(numa, -2525);
    abs_tmp_mdec(numb, numa);
    mdec *numc = make_mdec_from_int(-2525);
    mdec *numd = abs_mdec(numc);
    test(is_equal_mdec(numb, numd));
    free_mdec(numc);
    free_mdec(numd);
  }
  
  /* test cast */
  
  {
    mint *numerator = make_mint_from_int(3);
    mint *denominator = make_mint_from_int(2);
    mdec *num = make_mdec(MDEC_POSITIVE, numerator, denominator);
    cast_mdec_to_tmp_double(numd, num);
    test(numd == 1.5);
    free_mdec(num);
  }
  
  {
    mint *numerator = make_mint_from_int(3);
    mint *denominator = make_mint_from_int(2);
    mdec *num = make_mdec(MDEC_POSITIVE, numerator, denominator);
    cast_mdec_to_tmp_float(numd, num);
    test(numd == 1.5);
    free_mdec(num);
  }
  
  {
    mint *numerator = make_mint_from_int(3);
    mint *denominator = make_mint_from_int(2);
    mdec *num = make_mdec(MDEC_POSITIVE, numerator, denominator);
    cast_mdec_to_tmp_mint(numi, num);
    make_tmp_mint_from_int(num1, 1);
    test(is_equal_mint(num1, numi));
    free_mdec(num);
  }
  
  {
    mint *numerator = make_mint_from_int(3);
    mint *denominator = make_mint_from_int(2);
    mdec *num = make_mdec(MDEC_POSITIVE, numerator, denominator);
    cast_mdec_to_tmp_long(numi, num);
    test(numi == 1);
    free_mdec(num);
  }
  
  {
    mint *numerator = make_mint_from_int(3);
    mint *denominator = make_mint_from_int(2);
    mdec *num = make_mdec(MDEC_POSITIVE, numerator, denominator);
    cast_mdec_to_tmp_int(numi, num);
    test(numi == 1);
    free_mdec(num);
  }
  
  /* test round */
  
  {
    make_tmp_mint_from_int(numerator, 4);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    round_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
  }
    
  {
    make_tmp_mint_from_int(numerator, 5);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    round_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
  }
    
  /* test floor */
  
  {
    make_tmp_mint_from_int(numerator, 4);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    floor_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
  }
    
  {
    make_tmp_mint_from_int(numerator, 5);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    floor_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 0);
  }
  
  /* test ceil */
  
  {
    make_tmp_mint_from_int(numerator, 4);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    ceil_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
  }
    
  {
    make_tmp_mint_from_int(numerator, 5);
    make_tmp_mint_from_int(denominator, 10);
    make_tmp_mdec(numa, MDEC_POSITIVE, numerator, denominator);
    ceil_tmp_mdec(numb, numa);
    int inumb = cast_mint_to_int(numb);
    test(inumb == 1);
  }

  
  return 0;
}

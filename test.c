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
  
  /*  */
  
  return 0;
}

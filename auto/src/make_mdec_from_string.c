#include <mdec.h>
#include <stdlib.h>

static mdec_sign read_sign (char *source, char **sourceout){
  if (*source == '-'){
    source++;
    *sourceout = source;
    return MDEC_NEGATIVE;
  }
  if (*source == '+'){
    source++;
    *sourceout = source;
    return MDEC_POSITIVE;
  }
  *sourceout = source;
  return MDEC_POSITIVE;
}

static mint *read_integer_number (char *source, char **sourceout){
  if (*source == '0'){ 
    source++;
    if (*source == '.'){
      source++;
      *sourceout = source;
      return make_mint_from_int(0);
    }
    if (*source == '\0'){
      *sourceout = source;
      return make_mint_from_int(0);
    }
    return NULL;
  }
  if (*source < '0'){
    return NULL;
  }
  if (*source > '9'){
    return NULL;
  }
  mint *num = make_mint_from_int(0);
  mint *num10 = make_mint_from_int(10);
  for (; *source; source++){
    if (*source == '.'){
      source++;
      break;
    }
    if (*source < '0'){
      free_mint(num);
      free_mint(num10);
      return NULL;
    }
    if (*source > '9'){
      free_mint(num);
      free_mint(num10);
      return NULL;
    }
    mint *num1 = mul_mint(num, num10);
    mint *numc = make_mint_from_int(*source - '0');
    mint *num2 = add_mint(num1, numc);
    free_mint(num1);
    free_mint(numc);
    free_mint(num);
    num = num2;
  }
  free_mint(num10);
  *sourceout = source;
  return num;
}

static int read_fraction_number (char *source, mint **numout, mint **numbout){
  if (*source == '\0'){
    mint *num = make_mint_from_int(0);
    mint *numb = make_mint_from_int(1);
    *numout = num;
    *numbout = numb;
    return 0;
  }
  mint *num = make_mint_from_int(0);
  mint *numb = make_mint_from_int(1);
  mint *num10 = make_mint_from_int(10);
  for (; *source; source++){
    if (*source < '0'){
      free_mint(num);
      free_mint(numb);
      free_mint(num10);
      return 1;
    }
    if (*source > '9'){
      free_mint(num);
      free_mint(numb);
      free_mint(num10);
      return 1;
    }
    
    mint *numb1 = mul_mint(numb, num10);
    free_mint(numb);
    numb = numb1;
    
    mint *num1 = mul_mint(num, num10);
    mint *numc = make_mint_from_int(*source - '0');
    mint *num2 = add_mint(num1, numc);
    free_mint(num1);
    free_mint(numc);
    free_mint(num);
    num = num2;
  }
  free_mint(num10);
  *numout = num;
  *numbout = numb;
  return 0;
}

mdec *make_mdec_from_string (char *source){
  mdec_sign sign = read_sign(source, &source);
  mint *numi = read_integer_number(source, &source);
  if (numi == NULL){
    return NULL;
  }
  mint *numf;
  mint *numb;
  if (read_fraction_number(source, &numf, &numb)){
    free_mint(numi);
    return NULL;
  }
  mint *num1 = mul_mint(numi, numb);
  mint *num2 = add_mint(num1, numf);
  free_mint(numi);
  free_mint(num1);
  free_mint(numf);
  mdec *md = make_mdec(sign, num2, numb);
  /* compaction_mdec(md);
  return md; */
  mdec *mdc = compacted_mdec(md);
  free_mdec(md);
  return mdc;
}

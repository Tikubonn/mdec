# mdec
mdec provide multiple-precise decimal for C. becareful! this is not speedy and safety!  
this depends on library of [mint](https://github.com/tikubonn/mint) that provide multiple length integer. so you should get it first if you want to build this library.
in this library, decimal structure similar as the fractional format.
so you can calculate a decimal without missing part of data :D

```c
mdec *num1 = make_mdec_from_int(1);
mdec *num2 = make_mdec_from_int(3000);
mdec *num3 = div_mdec(num1, num2); // (1/3000)
mdec *num4 = mul_mdec(num3, num2); // (3000/3000)
int inumd = cast_mdec_to_int(num4); // 1
```

## Build Library
move to this package's directory then execute the make command :D  
if you did not append path of [mint](https://github.com/tikubonn/mint) to environment variable, you should tell a path to directory that contain necessary files to makefile. like this code.

```bash
make MINT_INCLUDE="path to mint" MINT_LIBRARY="path to mint/dist"
```

# API
## Manual Fcuntions 
those functions does not allocate memory automatically.  
so you should prepare working memory yourself.
for example if calculate the multiplication, you should allocate a memory space that size is double. 
if you want to management mdec by GC, those functions are useful.
but normally [Automatic Functions](#automatic-functions) are easier to use than those.

```c
mdec num1;
mint *numerator1 = make_mint_from_int(1);
mint *denominator1 = make_mint_from_int(3);
init_mdec(MDEC_POSITIVE, numerator1, denominator1, &num1); // 3/2
mdec num2;
mint *numerator2 = make_mint_from_int(1);
mint *denominator2 = make_mint_from_int(6);
init_mdec(MDEC_POSITIVE, numerator2, denominator2, &num2); // 2/3
mdec num3;
mint *numerator3 = make_mint(4);
mint *denominator3 = make_mint(4);
init_mdec(0, numerator3, denominator3, &num3);
mul_mdec(&num1, &num2, &num3); // 3/2 * 2/3 = 6/6
```

| Function | Description |
---- | ----
| `void init_mdec (int sign, mint *numerator, mint *denominator, mdec*)` | construct an instance by arguments. an argument of `sign` must be `MDEC_POSITIVE` or `MDEC_NEGATIVE`. `denominator` and `numerator` must be a positive number. | 
| `void copy_mdec_manually (mdec*, mdec *numout)` | copy value of first argument to `numout`. | 
| `void add_mdec_manually (mdec*, mdec*, mdec* numout, mdec *numtmp)` | calculate `+` by arguments then write a result to `numout`. | 
| `void sub_mdec_manually (mdec*, mdec*, mdec* numout, mdec *numtmp)` | calculate `-` by arguments then write a result to `numout`. | 
| `void mul_mdec_manually (mdec*, mdec*, mdec* numout)` | calculate `*` by arguments then write a result to `numout`. | 
| `void div_mdec_manually (mdec*, mdec*, mdec* numout)` | calculate `/` by arguments then write a result to `numout`. | 
| `void abs_mdec_manually (mdec*, mdec* numout)` | write an absolute decimal of first argument to `numout`. | 
| `int is_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first and second arguments are equal. otherwise this return `0`. |
| `int is_unequal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first and second arguments are not equal. otherwise this return `0`. |
| `int is_lesser_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first argument is lesser than second argument. otherwise this return `0`. |
| `int is_lesser_or_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first argument is lesser or equal than second argument. otherwise this return `0`. |
| `int is_greater_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first argument is greater than second argument. otherwise this return `0`. |
| `int is_greater_or_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | return an integer that is `1` if first argument is greater or equal than second argument. otherwise this return `0`. |
| `int is_positive_mdec (mdec*, mdec*)` | return an integer that is `1` if argument is positive number. otherwise this function return `0`. |
| `int is_negative_mdec (mdec*, mdec*)` | return an integer that is `1` if argument is negative number. otherwise this function return `0`. |
| `int is_zero_mdec (mdec*, mdec*)` | return an integer that is `1` if argument is `0`. otherwise this function return `0`. | 
| `int commonize_mdec_manually (mdec*, mdec*, mdec* numout1, mdec* numout2)` | write adjusted instances to `numout1` and `numout2`. those value are multiplied by denominator of mutual. |
| `void cast_mdec_to_mint_manually (mdec*, mint *numout, mint *tmp)` | cast an instance to `mint` instance then write to `numout`. |
| `double cast_mdec_to_double_manually (mdec*, mdec *tmp1, mint *tmp2, mint *tmp3)` | cast an instance to `double`. this function has a possibility what parts of data will be missing. |
| `float cast_mdec_to_float_manually (mdec*, mdec *tmp1, mint *tmp2, mint *tmp3)` | cast an instance to `float`. this function has a possibility what parts of data will be missing. |
| `long cast_mdec_to_long_manually (mdec*, mint *tmp1, mint *tmp2)` | cast an instance to `long`. if instance value is greater than C int, some parts of data will be missing. |
| `int cast_mdec_to_int_manually (mdec*, mint *tmp1, mint *tmp2)` | cast an instance to `int`. this if instance value is greater than C int, some parts of data will be missing. | 
| `void compacted_mdec_manually (mdec*, mdec *numout, mint *tmp1, mint *tmp2)` | write a compacted instance to `numout`. that numerator and denominator are divided by least common divisor. | 
| `void round_mdec_manually (mdec*, mint *numout, mint *tmp)` | write a rounded off integer to `numout`. |
| `void floor_mdec_manually (mdec*, mint *numout, mint *tmp)` | write a rounded down integer to `numout`. |
| `void ceil_mdec_manually (mdec*, mint *numout, mint *tmp)` | write a rounded up integer to `numout`. |

## Automatic Functions 
those functions allocate memory automatically with `malloc`.  
so those are more useful than manual functions.
but this library does not have GC, so you should release manually the unnecessary memory.
if you want to make a temporary instance, you can use [Temporary Macros](#temporary-macros).

```c
mdec *num1 = make_mdec_from_double(1.5);
mdec *num2 = make_mdec_from_int(3);
mdec *num3 = add_mdec(num1, num2);
free_mdec(num1); // free manually
free_mdec(num2); // free manually
return num3;
```

| Function | Description |
---- | ---- 
| `mdec *make_mdec (int sign, mint *numerator, mint *denominator)` | make a new instance that is constructed by arguments. an argument of `sign` must be `MDEC_POSITIVE` or `MDEC_NEGATIVE`. `denominator` and `numerator` must be a positive number. |
| `mdec *make_mdec_from_double (double)` | make a new instance from C double. | 
| `mdec *make_mdec_from_float (float)` | make a new instance from C float. | 
| `mdec *make_mdec_from_string (char*)` | make a new instance from ASCII string what like as `"123.456"`. if string value is invalid, this function return a `NULL`. |
| `mdec *copy_mdec (mdec*)` | create a copied instance from argument. |
| `void free_mdec (mdec*)` | free a memory space that is used for instance. |
| `mdec *add_mdec (mdec*, mdec*)` | return a calculation result of `+` as new instance. | 
| `mdec *sub_mdec (mdec*, mdec*)` | return a calculation result of `-` as new instance. | 
| `mdec *mul_mdec (mdec*, mdec*)` | return a calculation result of `*` as new instance. | 
| `mdec *div_mdec (mdec*, mdec*)` | return a calculation result of `/` as new instance. if second argument is `0`, this function cause zero division exception then return the `NULL` immediately. | 
| `mdec *abs_mdec (mdec*)` | return a absolute decimal of argument. | 
| `int is_equal_mdec (mdec*, mdec*)` | return an integer that is `1` if first and second argument are equal. otherwise this return `0`. | 
| `int is_unequal_mdec (mdec*, mdec*)` | return an integer that is `1` if first and second argument are not equal. otherwise this return `0`. | 
| `int is_lesser_mdec (mdec*, mdec*)` | return an integer that is `1` if first argument is lesser than second argument. otherwise this return `0`. | 
| `int is_lesser_or_equal_mdec (mdec*, mdec*)` | return an integer that is `1` if first argument is lesser or equal than second argument. otherwise this return `0`. | 
| `int is_greater_mdec (mdec*, mdec*)` | return an integer that is `1` if first argument is greater than second argument. otherwise this return `0`. | 
| `int is_greater_or_equal_mdec (mdec*, mdec*)` | return an integer that is `1` if first argument is greater or equal than second argument. otherwise this return `0`. | 
| `mint *cast_mdec_to_mint (mdec*)` | cast an instance to `mint` instance. | 
| `int cast_mdec_to_int (mdec*)` | cast an instance to `int`. if instance value is greater than C int, some parts of data will be missing. |
| `long cast_mdec_to_long (mdec*)` | cast an instance to `long`. if instance value is greater than C long, some parts of data will be missing. | 
| `double cast_mdec_to_double (mdec*)` | cast an instance to `double`. this function has a possibility what parts of data will be missing. | 
| `float cast_mdec_to_float (mdec*)` | cast an instance to `float`. this function has a possibility what parts of data will be missing. | 
| `mdec *compacted_mdec (mdec*)` | return a compacted instance that numerator and denominator are divided by least common divisor. |
| `mint *round_mdec_manually (mdec*)` | return a rounded off integer. |
| `mint *floor_mdec_manually (mdec*)` | return a rounded down integer. |
| `mint *ceil_mdec_manually (mdec*)` | return a rounded up integer. |

## Temporary Macros 
those macros allocate memory from stack frame.  
so created instance will be released automatically when exit from current scope. 
it is useful for management of temporary instance.
but those function has possibility that cause segmentation error when not enough memory.

```c
make_tmp_mdec_from_int(num1, 3);
make_tmp_mdec_from_int(num2, 2);
div_tmp_mdec(num3, num1, num2);
mint *numexp = copy_mdec(num3); // if you want to keep calculation result after exit from current stack frame, you should copy with automatic or manual function.
return numexp;
```

| Macro | Description |
---- | ---- 
| `make_tmp_mdec (var, sign, mint*, mint*)` | assign a new instance to `var`. that is constructed by arguments. |
| `make_tmp_mdec_from_int (var, int)` | assign a new instance to `var`. that is made from C int. |
| `make_tmp_mdec_from_long (var, long)` | assign a new instance to `var`. that is made from C long. |
| `copy_tmp_mdec(var, mdec*)` | assign a copied instance to `var`. |
| `add_tmp_mdec(var, mdec*, mdec*)` | assign a new instance to `var`. that is a calculation result of `+` by arguments. |
| `add_tmp_mdec(var, mdec*, mdec*)` | assign a new instance to `var`. that is a calculation result of `-` by arguments. |
| `add_tmp_mdec(var, mdec*, mdec*)` | assign a new instance to `var`. that is a calculation result of `*` by arguments. |
| `add_tmp_mdec(var, mdec*, mdec*)` | assign a new instance to `var`. that is a calculation result of `/` by arguments. |
| `abs_tmp_mdec(var, mdec*, mdec*)` | assign a new instance to `var`. that is an absolute decimal of argument. | 
| `cast_mdec_to_tmp_double(var, mdec*)` | assign a `double` to `var`. that is casted from second argument. |
| `cast_mdec_to_tmp_float(var, mdec*)` | assign a `float` to `var`. that is casted from second argument. |
| `cast_mdec_to_tmp_mint(var, mdec*)` |  assign a new `mint` instance to `var`. that is casted from second argument. |
| `cast_mdec_to_tmp_long(var, mdec*)` | assign a `long` to `var`. that is casted from second argument. |
| `cast_mdec_to_tmp_int(var, mdec*)` | assign a `int` to `var`. that is casted from second argument. |
| `compacted_tmp_mdec(var, mdec*)` | assign a new instance to `var`. that is compacted that numerator and denominator are divided by least common divisor. |
| `round_mdec_manually (var, mdec*)` | assign a rounded off integer to `var`. |
| `floor_mdec_manually (var, mdec*)` | assign a rounded down integer to `var`. |
| `ceil_mdec_manually (var, mdec*)` | assign a rounded up integer to `var`. |

## Debug Functions (not recommended)
I defined some print out functions for debugging.  
but those functions has a possibility that is redefined or changed.
at the last, those functions will not return a state that is success or not!
so you cannot use those functions to your safety application!

```c
mint *num = make_mdec_from_double(1.5);
print_mdec_ln(num, stdout); // 1.5
print_mdec_as_fraction_ln(num, stdout); // 3/2
```

| Function | Description | 
---- | ---- 
| `void print_mdec (mdec*, FILE*)` | print out instance to stream as decimal format. | 
| `void print_mdec_ln (mdec*, FILE*)` | this similar as `print_mdec`. but this put a line break after print out. |
| `void print_mdec_as_fraction (mdec*, FILE*)` | print out mdec instance to stream as fractional format. | 
| `void print_mdec_as_fraction_ln (mdec*, FILE*)` | this similar as `print_mdec_as_fraction`. but this put a line break after print out. |

# License 
this library released under the MIT License.

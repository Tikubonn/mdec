# mdec
mdec provide multiple length decimal number for C. becareful! this is not speedy and safety!  
this depends on library of [mint](https://github.com/tikubonn/mint) that provide multiple length integer. so you should get it first if you want to build this library.
in this library, decimal structure similar as the fraction.
so you can calculate a decimal number without missing part of data :D

```c
mdec *numa = make_mdec_from_int(1);
mdec *numb = make_mdec_from_int(3000);
mdec *numc = div_mdec(numa, numb); // (1/3000)
mdec *numd = mul_mdec(numc, numb); // (3000/3000)
int inumd = cast_mdec_to_int(numd); // 1
```

## Build Library
move to this package's directory then execute the make command :D  
if you did not append path of mint to environment variable, you should tell a path to directory that contain necessary files to makefile. like this code.

```bash
make MINT_INCLUDE="path to mint" MINT_LIBRARY="path to mint/dist"
```


# API
## Manual Fcuntions 
those functions does not allocate memory automatically.  
so you should prepare working memory yourself.
for example if calculate the multiplication, you should allocate a memory space that size is double. 
if you want to management mdec by GC, those functions are useful.

| Function | Description |
---- | ----
| `void init_mdec (int sign, mint *numerator, mint *denominator, mdec*)` | this function construct a mdec instance by arguments. | 
| `void copy_mdec_manually (mdec*, mdec*)` | this function copy content of first argument to second argument. | 
| `void add_mdec_manually (mdec*, mdec*, mdec* numout, mdec *numtmp)` | this function calculate `+` by arguments then write a result to `numout`. | 
| `void sub_mdec_manually (mdec*, mdec*, mdec* numout, mdec *numtmp)` | this function calculate `-` by arguments then write a result to `numout`. | 
| `void mul_mdec_manually (mdec*, mdec*, mdec* numout)` | this function calculate `*` by arguments then write a result to `numout`. | 
| `void div_mdec_manually (mdec*, mdec*, mdec* numout)` | this function calculate `/` by arguments then write a result to `numout`. | 
| `void abs_mdec_manually (mdec*, mdec* numout)` | this function write an absolute decimal number of first argument to `numout`. | 
| `int is_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first and second arguments are equal. otherwise this return `0`. |
| `int is_unequal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first and second arguments are not equal. otherwise this return `0`. |
| `int is_lesser_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first argument is lesser than second argument. otherwise this return `0`. |
| `int is_lesser_or_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first argument is lesser or equal than second argument. otherwise this return `0`. |
| `int is_greater_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first argument is greater than second argument. otherwise this return `0`. |
| `int is_greater_or_equal_mdec_manually (mdec*, mdec*, mdec* numtmp1, mdec *numtmp2)` | this function return an integer that is `1` if first argument is greater or equal than second argument. otherwise this return `0`. |
| `int is_positive_mint (mdec*, mdec*)` | this return an integer that is `1` if argument is positive number. otherwise this function return `0`. |
| `int is_negative_mint (mdec*, mdec*)` | this return an integer that is `1` if argument is negative number. otherwise this function return `0`. |
| `int is_zero_mint (mdec*, mdec*)` | this return an integer that is `1` if argument is `0`. otherwise this function return `0`. | 
| `int commonize_mint_manualy (mdec*, mdec*, mdec* numout1, mdec* numout2)` | this function adjust denominator of first and second argument then write to instances those are last two arguments. |

## Automatic Functions 
those functions allocate memory automatically with `malloc`.  
so those are more useful than manual functions.
but this library does not have GC, so you should release manually the unnecessary memory.

| Function | Description |
---- | ---- 
| `mdec *make_mdec (int sign, mint *numerator, mint *denominator)` | this function make a new mdec instance from arguments. an argument of `sign` must be `MDEC_POSITIVE` or `MDEC_NEGATIVE`. denominator and numerator must be positive integer. |
| `void free_mdec (mdec*)` | this function release the memory that is used for mdec instance. |
| `mdec *add_mdec (mdec*, mdec*)` | return a calculation result of `+` as new instance. | 
| `mdec *sub_mdec (mdec*, mdec*)` | return a calculation result of `-` as new instance. | 
| `mdec *mul_mdec (mdec*, mdec*)` | return a calculation result of `*` as new instance. | 
| `mdec *div_mdec (mdec*, mdec*)` | return a calculation result of `/` as new instance. if second argument is `0`, this function cause zero division exception then return the `NULL` immediately. | 
| `mdec *abs_mdec (mdec*)` | return a absolute number from argument. | 
| `int is_equal_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first and second argument are equal. otherwise this return `0`. | 
| `int is_unequal_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first and second argument are not equal. otherwise this return `0`. | 
| `int is_lesser_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first argument is lesser than second argument. otherwise this return `0`. | 
| `int is_lesser_or_equal_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first argument is lesser or equal than second argument. otherwise this return `0`. | 
| `int is_greater_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first argument is greater than second argument. otherwise this return `0`. | 
| `int is_greater_or_equal_mdec (mdec*, mdec*)` | this function return an integer that is `1` if first argument is greater or equal than second argument. otherwise this return `0`. | 
| `mint *cast_mdec_to_mint (mdec*)` | return a new `mint` instance that is a multiple length integer from argument. | 
| `int cast_mdec_to_int (mdec*)` | return a `int` that is converted integer from argument. |
| `long cast_mdec_to_long (mdec*)` | return a `long` that is converted integer from argument. | 

## Debug Functions (not recommended)
I defined some printout functions for debugging.  
but those functions has a possibility that is redefined or changed.
at the last, those functions will not return a state that is success or not!
so you cannot use those functions to your safety application!

| Function | Description | 
---- | ---- 
| `void print_mdec (mdec*, FILE*)` | this function printout mdec instance to stream as decimal number. | 
| `void print_mdec_ln (mdec*, FILE*)` | this similar as `print_mdec`. but this put line break after printout. |
| `void print_mdec_as_fraction (mdec*, FILE*)` | this function printout mdec instance to stream as fraction. | 
| `void print_mdec_as_fraction_ln (mdec*, FILE*)` | this similar as `print_mdec_as_fraction`. but this put line break after printout. |

# License 
this library released under the MIT License.

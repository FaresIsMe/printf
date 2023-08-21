#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024 /* max size of the buffer */
#define BUFFER_FLUSH_CONDITION -1 /* the condition when we flush */

#define IS_UNSIGNED 1 /* unsigned condition */
#define IS_LOWERCASE 2 /* lowercase condition */

#define DEFAULT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  /* A default init */


/**
 * struct Params - A struct that will store the conditions
 * that our function will encounter
 * @IsUnSigned: Unsigned contidtion
 * @isShort: short condition
 * @isLong: long condition
 * @isPlusFlag: plus condition
 * @isMinusFlag: minus condition
 * @isHashtagFlag: # condition
 * @isZeroFlag: 0 condition
 * @isSpaceFlag: space condition
 * @width: The value of the width that was inputed to printf
 * @precision: The value of the precision that was inputed to printf
*/

typedef struct Params
{
	bool IsUnSigned;
	bool isShort;
	bool isLong;
	bool isPlusFlag;
	bool isMinusFlag;
	bool isHashtagFlag;
	bool isZeroFlag;
	bool isSpaceFlag;

	unsigned int width;
	unsigned int precision;
} specifier_params;

/**
 * struct MyStruct - A struct to manipulate opeartions and functions
 * @op: The specifier of the printf function
 * @myFunc: Pointer to the function that will be called
 * after checking the op
*/

typedef struct MyStruct
{
	char *op;
	int (*myFunc)(va_list, specifier_params *);
} op_t;

/* functions to handle chars */
int _putchar(char);
int _puts(char *);
/* initilzation function */
void init_params(specifier_params *, va_list);
/* strings printing functions */
int printingMyStringReveresed(va_list, specifier_params *);
int printingMyChar(va_list, specifier_params *);
int printMyPercent(va_list, specifier_params *);
int printROT13(va_list, specifier_params *);
int printS(va_list, specifier_params *);
int print_string(va_list, specifier_params *);
/* specifier functions */
int mySpecifier(char);
int print_function_call(char, va_list, specifier_params);
/* function to handle numbers */
int printAddress(va_list, specifier_params *);
int printBinary(va_list, specifier_params *);
int printHEX(va_list, specifier_params *);
int printhex(va_list, specifier_params *);
int printOctal(va_list, specifier_params *);
int printUnsigned(va_list, specifier_params *);
int print_numbers(char *, specifier_params *);
/* convertor function */
char *convertor(long int, int, int, specifier_params *);
/* getters functions */
int myFlags(char *, specifier_params *);
char *myPrecision(char *, specifier_params *, va_list);
char *myWidth(char *, specifier_params *, va_list);
int myModifier(char *, specifier_params *);
/* printing shifting function */
int printMyNumberWithRightShift(char *, specifier_params *);
int printMyNumberWithLeftShift(char *, specifier_params *);
/* utils functions */
int isDigit(char);
int _strlen(char *);
int print_from_to(char *, char *, char *);
int printMyPercent(va_list, specifier_params *);
/* main printf function */
int _printf(const char *format, ...);
#endif

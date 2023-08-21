#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define BUFFER_FLUSH_CONITION -1


#define IS_UNSIGNED 1
#define IS_LOWERCASE 2

#define DEFAULT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct MyStruct - A struct to manipulate opeartions and functions
 * @op: The specifier of the printf function
 * @myFunc: Pointer to the function that will be called
 * after checking the op
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


typedef struct MyStruct
{
	char *op;
	int (*myFunc) (va_list, specifier_params *);
} op_t;


//functions to handle chars
int _putchar(char);
int _puts(char *);
//initilzation function
void init_params(specifier_params *, va_list);
//strings printing functions
int printingMyStringReveresed(va_list);
int printingMyChar(va_list, specifier_params *);
int printMyPercent(va_list, specifier_params *);
int printROT13(va_list, specifier_params *);
int printS(va_list, specifier_params *);
//specifier functions
int mySpecifier(char);
int print_function_call(char, va_list, specifier_params);
//function to handle numbers
int printAddress(va_list, specifier_params *);
int printBinary(va_list, specifier_params *);
int printHEX(va_list, specifier_params *);
int printhex(va_list, specifier_params *);
int printOctal(va_list, specifier_params *);
//convertor function
char *convertor(long int, int, int);
//getters functions
int myFlags(char *, specifier_params *);
char *myPrecision(char *, specifier_params *, va_list); 
char *myWidth(char *, specifier_params *, va_list);
//utils functions
int isDigit(char);
int _strlen(char *);
// main printf function
int _printf(const char *format, ...);
#endif

#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


#define MAX_BUFFER_SIZE 1024
#define BUFFER_FLUSH_CONITION -1

#define DEFAULT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct MyStruct - A struct to manipulate opeartions and functions
 * @op: The specifier of the printf function
 * @myFunc: Pointer to the function that will be called
 * after checking the op
*/

typedef struct Params
{
	bool isUnsigned;
	bool isShort;
	bool isLong;
	bool isPlusFlag;
	bool isMinusFlag;
	bool isHashtagFlag;
	bool isZeroFlag;

	unsigned int width;
	unsigned int precision;
} specifier_params;


typedef struct MyStruct
{
	char *op;
	int (*myFunc) (va_list, function_params*);
} op_t;


//functions to handle chars
int _putchar(char);
int _puts(char *):

//functions to print numbers

// main printf function
int _printf(const char *format, ...);

#endif

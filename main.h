#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct MyStruct - A struct to manipulate opeartions and functions
 * @op: The specifier of the printf function
 * @myFunc: Pointer to the function that will be called
 * after checking the op
*/

typedef struct MyStruct
{
	char *op;
	int (*myFunc);
} op_t;



int _printf(const char *format, ...);

#endif

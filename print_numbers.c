#include "main.h"
/**
 * printAddress - it passes the to covertor
 * @Input: the Input
 * @myParams: something idk
 * Return:what print_numbers return on success
*/
int printAddress(va_list Input, specifier_params *myParams)
{
	unsigned long int num = va_arg(Input, unsigned int);
	char *s;

	if (num == 0)
	return (_puts("(nil)"));
	else
	s = convertor(num, 16, IS_LOWERCASE | IS_UNSIGNED, myParams);
	*--s = 'X';
	*--s = '0';
	return (print_numbers(s, myParams));
}
/**
 * printBinary - prints in o & 1
 * @Input: the Input
 * @myParams: something idk
 * Return: what print_numbers return on success
*/
int printBinary(va_list Input, specifier_params *myParams)
{
	unsigned long int num = va_arg(Input, unsigned long int);
	char *s = convertor(num, 2, IS_UNSIGNED, myParams);
	int n = 0;

	if (myParams->isHashtagFlag && num)
	*--s = '0';
	myParams->IsUnSigned = 1;
	return (n += print_numbers(s, myParams));
}
/**
 * printHEX - it does what it does
 * @Input: the input
 * @myParams: something idk
 * Return:what print_numbers return on success
*/
int printHEX(va_list Input, specifier_params *myParams)
{
	unsigned long int num;
	char *s;
	int n = 0;

	if (myParams->isLong)
	num = (unsigned long int)va_arg(Input, unsigned int);
	else if (myParams->isShort)
	num = (unsigned short int)va_arg(Input, unsigned int);
	else
	num = va_arg(Input, unsigned int);

	s = convertor(num, 16, IS_UNSIGNED, myParams);
	if (myParams->isHashtagFlag && num)
	{
		*--s = 'X';
		*--s = '0';
	}
	myParams->IsUnSigned = 1;
	return (n += print_numbers(s, myParams));
}
/**
 * printhex - it does what it does
 * @Input: the input
 * @myParams: something idk
 * Return:what print_numbers return on success
*/
int printhex(va_list Input, specifier_params *myParams)
{
	unsigned long int num;
	char *s;
	int n = 0;

	if (myParams->isLong)
	num = (unsigned long int)va_arg(Input, unsigned int);
	else if (myParams->isShort)
	num = (unsigned short int)va_arg(Input, unsigned int);
	else
	num = va_arg(Input, unsigned int);

	s = convertor(num, 16, IS_UNSIGNED | IS_LOWERCASE, myParams);
	if (myParams->isHashtagFlag && num)
	{
		*--s = 'X';
		*--s = '0';
	}
	myParams->IsUnSigned = 1;
	return (n += print_numbers(s, myParams));
}
/**
 * printOctal - it does what it does
 * @Input: the input
 * @myParams: something idk
 * Return:what print_numbers return on success
*/
int printOctal(va_list Input, specifier_params *myParams)
{
	unsigned long int num;
	char *s;
	int n = 0;

	if (myParams->isLong)
	num = (unsigned long int)va_arg(Input, unsigned int);
	else if (myParams->isShort)
	num = (unsigned short int)va_arg(Input, unsigned int);
	else
	num = va_arg(Input, unsigned int);

	s = convertor(num, 8, IS_UNSIGNED | IS_LOWERCASE, myParams);
	if (myParams->isHashtagFlag && num)
	{
		*--s = '0';
	}
	myParams->IsUnSigned = 1;
	return (n += print_numbers(s, myParams));
}

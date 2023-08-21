#include "main.h"

/**
 * mySpecifier - it chooses what specifier should be used
 * @s: the specifier letter
 * Return: pointer to the required function that printf function
 * will use to determine which data type will be printed
*/

int (*mySpecifier(char *s))(va_list arg, specifier_params *myParams)
{
		op_t Specifiers[] = {
				{"c", printingMyChar},
				{"s", print_string},
				{"d", printInt},
				{"i", printInt},
				{"%", printMyPercent},
				{"b", printBinary},
				{"o", printOctal},
				{"u", printUnsigned},
				{"x", printhex},
				{"X", printHEX},
				{"p", printAddress},
				{"S", printS},
				{"r",  printingMyStringReveresed},
				{"R", printROT13},
				{NULL, NULL}
	};
	int i = 0;

	while (Specifiers[i].op)
	{
		if (Specifiers[i].op[0] == s)
			return (Specifiers[i].myFunc);
		i++;
	}
	return (NULL);
}

/**
 * print_function_call - responsible for retrieving the
 * appropriate printing function
 * @s: the specifier character
 * @Input: for repeated variables
 * @p: A pointer to a structure of type specifier_params
 * Return: The right function on success (myFunc), 0 if (myFunc is null)
*/

int print_function_call(char s, va_list Input, specifier_params p)
{
	int (*myFunc)(va_list, specifier_params*) = mySpecifier(s);

	if (myFunc != NULL)
		return (myFunc(Input, &p));
	else
		return (0);
}
/**
 * printInt - integers it prints
 * @Input:idk
 * @myParams: something idk
 * Return:what print_numbers return on success
*/
int printInt(va_list Input, specifier_params *myParams)
{
		long integer;

	if (myParams->isLong)
		integer = va_arg(Input, long);
	else if (myParams->isShort)
		integer = (short int)va_arg(Input, int);
	else
		integer = (int)va_arg(Input, int);
	return (print_number(convert(integer, 10, 0, myParams), myParams));
}

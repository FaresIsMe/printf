#include "main.h"
/**
 * mySpecifier - it chooses what specifier should be used
 * @s; the specifier letter
 * Return: pointer to the required function that printf function will use to determine which data type will be printed
*/
int mySpecifier(char s)
{
	op_t Specifiers[] =
	{
		{"c", printChar},
		{"s", printString},
		{"d", printInt},
		{"i", printInt},
		{"%", printPercent},
		{"b", printBinary},
		{"o", printOctal},
		{"u", PrintUnsigned},
		{"x", printhex},
		{"X", printHEX},
		{"p", printAddress},
		{"S", printSTRING},
		{"r", printRev},
		{"R", printRot13},
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

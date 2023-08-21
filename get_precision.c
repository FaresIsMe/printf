#include "main.h"

/**
 * myPrecision - A function to get the precision of the specifier
 * @myChar: Pointer to the current char that we are reading in the format
 * @myPPointer: A pointer to a precision variable
 * @Input: Pointer to the inputed variadic function input
 *
 * Return: It returns a pointer to the place that we got after in the format
 * after reading the precision
*/

char *myPrecision(char *myChar, specifier_params *myPPointer, va_list Input)
{
	int theLastResult = 0;

	if (*myChar != '.')
		return (myChar);
	myChar = myChar + 1;
	if (*myChar == '*')
	{
		theLastResult = va_arg(Input, int);
		myChar = myChar + 1;
	}
	else
	{
		while (isDigit(*myChar) == 1)
		{
			theLastResult = theLastResult * 10 + (*myChar - '0');
			myChar = myChar + 1;
		}
	}
	(*myPPointer).precision = theLastResult;
	return (myChar);
}

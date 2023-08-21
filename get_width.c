#include "main.h"

/**
 * myWidth - A function to get the width of a specifier
 * @myChar: A pointer to the place where we reached in our format
 * @myPPointer: It's a pointer to a specfier_params variable
 * @Input: It's the input of the variadic function
 *
 * Return: It returns a pointer to the place where we reached
 * in the format after getting the width
*/

char *myWidth(char *myChar, specifier_params *myPPointer, va_list Input)
{
	int theLastResult = 0;

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
	(*myPPointer).width = theLastResult;
	return (myChar);
}

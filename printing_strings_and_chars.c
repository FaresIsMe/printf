#include "main.h"


/**
 * printingMyChar - A function that prints the chars that are passed into
 * _printf function when there is a c specifier
 * @myChars: The chars that are passed
 * @myParams: The parameters of my chars
 *
 * Return: It returns the numbers of chars printed including padding
*/

int printingMyChar(va_list myChars, specifier_params *myParams)
{
	char myPad = ' ';
	unsigned int paddingNum = 1, sum = 0, myCh;

	myCh = va_arg(myChars, int);
	if ((*myParams).isMinusFlag == 1)
	{
		_putchar(myCh);
		sum = sum + 1;
	}
	while (paddingNum < (*myParams).width)
	{
		_putchar(myPad);
		sum = sum + 1;
	}
	if ((*myParams).isMinusFlag != 1)
	{
		_putchar(myCh);
		sum = sum + 1;
	}
	return (sum);
}

/**
 * printingMyStringReveresed - A function to print the string in reverse order
 * @strPtr: Pointer to the passed string to _printf function
 *
 * Return: It returns the sum of printed chars
*/

int printingMyStringReveresed(va_list strPtr)
{
	unsigned len = 0, sum = 0;
	char *myString = va_arg(strPtr);

	if (myString != NULL)
	{
		for(; *myString; myString++)
			len = len + 1;
		myString = myString - 1;
		
		for(; len > 0; len = len - 1, myString = myString - 1)
		{
			_putchar(*myString);
			sum = sum + 1;
		}
	}
	return (sum);
}



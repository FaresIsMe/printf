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
 * @myParams: Pointer to the parameters of my input
 *
 * Return: It returns the sum of printed chars
*/

int printingMyStringReveresed(va_list strPtr, specifier_params *myParams)
{
	unsigned int len = 0, sum = 0;
	char *myString = va_arg(strPtr);
	(void)myParams;
	if (myString != NULL)
	{
		for (; *myString; myString++)
			len = len + 1;
		myString = myString - 1;
		for (; len > 0; len = len - 1, myString = myString - 1)
		{
			_putchar(*myString);
			sum = sum + 1;
		}
	}
	return (sum);
}

/**
 * printMyPercent - A function to print % using printf
 * @myPtr: A pointer to the list of parameters
 * @myParams: The parameters of myPtr
 *
 * Return: It returns 1
*/
int printMyPercent(va_list myPtr, specifier_params *myParams)
{
	(void)myParams;
	(void)myPtr;
	_putchar('%');
	return (1);
}

/**
 * printROT13 - A function to print the string in rot13 cipher
 * @myPtr: Pointer to the passed string
 * @myParams: The parameters of my string (It will not be used anyway)
 *
 * Return: It returns the number of printed chars
*/

int printROT13(va_list myPtr, specifier_params *myParams)
{
	unsigned int sum = 0, i = 0, myIndex = 0;

	void (myParams);
	char *myString;
	char myArray[] = "NOPQRSTUVWXYZABCDEFGHIJKLM   nopqrstuvwxyzabcdefghijklm";

	myString = va_arg(myPtr, char *);
	while (myString[i] != '\0')
	{
		if ((myString[i] >= 'A' && myString[i] <= 'Z')
			|| (myString[i] >= 'a' && myString[i] <= 'z'))
		{
			myIndex = myString[i] - 65;
			_putchar(myString[i]);
			sum = sum + 1;
		}
		else
		{
			_putchar(myString[i]);
			sum  = sum + 1;
		}
		i = i + 1;
	}
	return (sum);
}




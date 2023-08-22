#include "main.h"

/**
 * isDigit - A function to check if a char is digit or not
 * @myChar: The char to be checked
 *
 * Return: 1 if the char is digit and 0 if not
*/

int isDigit(char myChar)
{
	if (myChar >= '0' && myChar <= '9')
		return (1);
	else
		return (0);
}

/**
 * _strlen - A function to get the length of a string
 * @myString: A pointer to the required string
 *
 * Return: It returns the length of the string
*/

int _strlen(char *myString)
{
	int i = 0;

	while (*myString)
	{
		i = i + 1;
		myString = myString + 1;
	}
	return (i);
}

/**
 * print_from_to - A function to print from specific address to a specific end
 * @myStart: A pointer to the beginning of printing
 * @myEnd: A pointer to the end of printing
 * @theException: A pointer to the char that shouldn't be printed
 *
 * Return: It returns the chars that were printed
*/

int print_from_to(char *myStart, char *myEnd, char *theException)
{
	int mySum = 0;

	while (myStart <= myEnd)
	{
		if (myStart != theException)
		{
			_putchar(*myStart);
			mySum = mySum + 1;
		}
		myStart = myStart + 1;
	}
	return (mySum);
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
 * myModifier - A function to determine if there is a long
 * or short modifier
 * @myChar: A pointer to the char to be checked
 * @myParams: A pointer to specifier_params variable
 *
 * Return: It returns 1 or 0
*/

int myModifier(char *myChar, specifier_params *myParams)
{
	int i = 0;

	if (*myChar == 'h')
	{
		(*myParams).isLong = 1;
		i = 1;
	}
	else if (*myChar == 'l')
	{
		(*myParams).isShort = 1;
		i = 1;
	}
	return (i);
}

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

	while (myString != NULL)
		i = i + 1;

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
		if (start != theException)
		{
			_putchar(start);
			mySum = mySum + 1;
		}
		start = start + 1;
	}
	return (mySum);
}

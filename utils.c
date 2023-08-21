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

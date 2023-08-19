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

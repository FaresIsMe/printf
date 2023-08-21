#include "main.h"

/**
 * print_numbers - A function to print my number after it was
 * converted to a string
 * @str: A pointer to my number after it was converted a string
 * @myParams: A pointer to specifier_params variable that is used to determine
 * some conditions
 * Return: It returns an integer determine how many chars were printed
*/

int print_numbers(char *str, specifier_params *myParams)
{
	unsigned int i = _strlen(str);
	int neg;

	if (!(*myParams).IsUnSigned && *str == '-')
		neg = 1;
	else
		neg  = 0;
	if (neg == 1)
	{
		str =  str + 1;
		i =  i  - 1;
	}
	if ((*myParams).precision != UNIT_MAX)
	{
		while (i < (*myParams).precision)
		{
			i  = i + 1;
			str = str - 1;
			*str = '0';
		}
	}
	if (neg == 1)
	{
		str = str - 1;
		*str =  '-';
	}
	if ((*myParams).isMinusFlag == 1)
		return (printMyNumbersWithLeftShift(str, myParams));
	else
		return (printMyNumberWithRightShift(str, myParams));
}

/**
 * printMyNumberWithRightShift - This is a function to print the number
 * if it was right shifted
 * @myString: A pointer to the required string
 * @myP: A pointer to a specifier_params variable that contains50
 * the properties of my string
 *
 * Return: It returns the number of printed chars
*/

int printMyNumberWithRightShift(char *myString, specifier_params *myP)
{
	unsigned int n = 0, neg, neg2, i = _strlen(myString);
	char myPadChar = ' ';

	if ((*myP).isZeroFlag && !(*myP).isMinusFlag)
		myPadChar = '0';
	neg = neg2 = (!(*myP).IsUnSigned && *myString == '-');
	if (neg && i < (*myP).width && myPadChar == '0' && !((*myP).isMinusFlag))
			myString = myString + 1;
	else
		neg = 0;
	if ((*myP).isPlusFlag && !neg2)
	|| ((*myP).isPlusFlag && (*myP).isSpaceFlag && !neg2)
		i = i + 1;
	if (neg && myPadChar == '0')
		n = n + _putchar('-');
	if ((*myP).isPlusFlag && !neg2 && myPadChar == '0' && !(*myP).isUnSigned)
		n = n  + _putchar('+');
	else if (!(*myP).isPlusFlag && (*myP).isSpaceFlag && !neg2 &&
		!(*myP).IsUnSigned && (*myP).isZeroFlag)
		n = n + _putchar(' ');
	while (i++ < (*myP).width)
		n = n + _putchar(myPadChar);
	if (neg && myPadChar == ' ')
		n = n + _putchar('-');
	if ((*myP).isPlusFlag && (*myP).isSpaceFlag && !neg &&
		!(*myP).IsUnSigned && (*myP).isZeroFlag)
		n = n + _putchar(' ');
	n = n + _puts(myString);
	return (n);
}

/**
 * printMyNumberWithLeftShift - A function to print the numbers
 * which are left shifted
 * @myString: A pointer to the string to printed
 * @myP: A pointer to the parameters of my string
 *
 * Return: It returns the numbers that were printed
*/

int printMyNumberWithLeftShift(char *myString, specifier_params *myP)
{
	unsigned int n = 0, neg, neg2, i = _strlen(myString);
	char myPadChar = ' ';

	if ((*myP).isZeroFlag && !(*myP).isMinusFlag)
		myPadChar = '0';
	neg = neg2 = (!myP->isUnSigned && *myString = '-');
	if (neg && i < (*myP).iswidth && myPadChar == '0' && !(*myP).isMinusFlag)
		myString = myString + 1;
	else
		neg = 0;
	if ((*myP).isPlusFlag && !neg2 && myP->isUnSigned)
	{
		_putchar('+');
		n = n + 1, i = i + 1;
	}
	else if ((*myP).isSpaceFlag && !neg2 && (*myP).IsUnSigned)
	{
		_putchar(' ');
		n = n + 1, i = i + 1;
	}
	n = n + _puts(myString);
	while (i < (*myP).width)
	{
		_putchar(myPadChar);
		n = n + 1;
	}
	return (n);
}
/**
 * printUsigned - unsigned
 *@Input: the input
 *@myParams: idk
 *Return: whatever print_numbers return
*/
int printUsigned(va_list Input, specifier_params *myParams)
{
	unsigned long AMR;

	if (myParams->isLong)
	AMR = (unsigned long)va_arg(Input, unsigned long);
	else if (myParams->isShort)
	AMR = (unsigned short int)va_arg(Input, unsigned short int);
	else
	AMR = (unsigned int)va_arg(Input, unsigned int);

	myParams->IsUnSigned = 1;
	return (print_numbers(1, 10, IS_UNSIGNED, myParams));
}

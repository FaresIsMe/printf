#include "main.h"

/**
 * print_numbers - A function to print my number after it was
 * converted to a string
 * @myString: A pointer to my number after it was converted a string
 * @myParams: A pointer to specifier_params variable that is used to determine
 * some conditions
 * Return: It returns an integer determine how many chars were printed
*/

int print_numbers(char *myString, specifier_params *myParams)
{
	unsigned int i = _strlen(str);
	int neg;

	if(!((*myParams).isUnsigned ) && *myString == '-')
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
		while(i < (*myParams).precision)
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
	if ((*myParams).isisMinusFlag == 1)
		return (printMyNumbersWithLeftShift(myString, myParams);
	else
		return (printMyNumberWithRightShift(myString, myParams);
}


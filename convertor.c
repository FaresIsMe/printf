#include "main.h"

/**
 * convertor - A function to convert any number in any base to a string
 * @num: The inputed number
 * @myBase: The base of the inputed number
 * @myFlags: An integer that represents if some flags are
 * included in the inputed number
*/

char* convertor(long int num, int myBase,int myFlags)
{
	char *numbersArray;
	static char myBuffer[50];
	char theSign = 0;
	char *ptr;
	unsigned long conditionNum = num;
	
	numbersArray = (char*)malloc(17 * sizeof(char));
	if (!(myFlags & IS_UNSIGNED) && num < 0)
	{
		conditionNum = -1 * num;
		theSign = '-';
	}
	if (myFlags & IS_LOWERCASE)
		strcpy(numbersArray, "0123456789abcdef");
	else
		strcpy(numbersArray, "0123456789ABCDEF");

	ptr = &myBuffer[49];
	*ptr = '\0';
	do
	{
		ptr = ptr - 1;
		*ptr = numbersArray[num % myBase];
		num = num / 10;
	}(num)

	if (sign != 0)
	{
		ptr = ptr - 1;
		*ptr = sign;
	}
	free (numbersArray);
	return (ptr);
}

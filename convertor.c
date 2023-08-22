#include "main.h"

/**
 * convertor - A function to convert any number in any base to a string
 * @num: The inputed number
 * @myBase: The base of the inputed number
 * @myFlag: An integer that represents if some flags are
 * included in the inputed number
 * @myP: A pointer that will not be used here
 * Return: It returns a pointer to the num after conversion to a string
*/

char *convertor(long int num, int myBase, int myFlags, specifier_params *myP)
{
	char *numbersArray;
	static char myBuffer[50];
	char theSign = 0;
	char *ptr;
	unsigned long conditionNum = num;
	(void)myP;

	numbersArray = (char *)malloc(17 * sizeof(char));
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
	do {
		ptr = ptr - 1;
		*ptr = numbersArray[conditionNum % myBase];
		conditionNum = conditionNum / 10;
	} while(num);

	if (theSign != 0)
	{
		ptr = ptr - 1;
		*ptr = theSign;
	}
	free(numbersArray);
	return (ptr);
}

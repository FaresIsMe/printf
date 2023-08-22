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
	char *myString = va_arg(strPtr, char *);
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
 * printROT13 - A function to print the string in rot13 cipher
 * @myPtr: Pointer to the passed string
 * @myParams: The parameters of my string (It will not be used anyway)
 *
 * Return: It returns the number of printed chars
*/

int printROT13(va_list myPtr, specifier_params *myParams)
{
	unsigned int sum = 0, i = 0, myIndex = 0;
	char *myString;
	char myArray[] = "NOPQRSTUVWXYZABCDEFGHIJKLM   nopqrstuvwxyzabcdefghijklm";
	
	(void)myParams;
	myString = va_arg(myPtr, char *);
	while (myString[i] != '\0')
	{
		if ((myString[i] >= 'A' && myString[i] <= 'Z')
			|| (myString[i] >= 'a' && myString[i] <= 'z'))
		{
			myIndex = myString[i] - 65;
			_putchar(myArray[myIndex]);
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
/**
 *printS - prints the non printable :)
 *@Input: the input
 *@myParams: idk
 *Return: the bytes_sum on success
*/
int printS(va_list Input, specifier_params *myParams)
{
	char *string = va_arg(Input, char *);
	char *X;
	int bytes_sum = 0;

	if (string == NULL)
	return (_puts(NULL));

	for (; *string != '\0'; string++)
	{
		if ((*string < 32 && *string > 0) || *string >= 127)
		{
			bytes_sum += _putchar('\\');
			bytes_sum += _putchar('x');
			X = convertor(*string, 16, 0, myParams);
			if (!X[1])
				bytes_sum += _putchar('0');
			bytes_sum += _puts(X);
		}
		else
			bytes_sum += _putchar(*string);
	}
	return (bytes_sum);
}

/**
 * print_string - A function to print the string that was passed
 * to printf
 * @myString: This is a pointer to the string that
 * should be printed
 * @myParams: A pointer to a specifier_params variable
 *
 * Return: It returns the number of chars that were printed
*/

int print_string(va_list myString, specifier_params *myParams)
{
	char *myStr = va_arg(myString, char *);
	char myPadChar = ' ';
	unsigned int pad = 0, mySum = 0, i = 0, j;

	(void)myParams;
	if ((int)!myStr)
		strcpy(myStr,MY_NULL_STRING);

	j = _strlen(myStr);
	pad = _strlen(myStr);

	if ((*myParams).precision < pad)
		j = pad = (*myParams).precision;
	if ((*myParams).isMinusFlag)
	{
		if ((*myParams).precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
				mySum = mySum + _putchar(*myStr++);
		}
		else
			mySum = mySum + _puts(myStr);
	}
	while (j++ < (*myParams).width)
		mySum = mySum + _putchar(myPadChar);
	if (!(*myParams).isMinusFlag)
	{
		if ((*myParams).precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
			{
				mySum = mySum + _putchar(*myStr);
				myStr = myStr + 1;
			}
		}
		else
			mySum = mySum + _puts(myStr);
	}
	return (mySum);
}

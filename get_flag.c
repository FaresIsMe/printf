#include "main.h"


/**
 * myFlags - A function to get flas for my prinf
 * @theChar: A pointer to the flag char
 * @mySpec: A pointer to a specifier_parmas variable
 *
 * Return: It returns 1 if a flag was set and 0 if wasn't
*/

int myFlags(char *theChar, specifier_params *mySpec)
{
	int myCond = 0;

	if (*theChar == '-')
	{
		(*mySpec).isMinusFlag = 1;
		myCond = 1;
	}
	else if (*theChar == '+')
	{
		(*mySpec).isPlusFlag = 1;
		myCond = 1;
	}
	else if (*theChar == '#')
	{
		(*mySpec).isHashtagFlag = 1;
		myCond = 1;
	}
	else if (*theChar == '0')
	{
		(*mySpec).isZeroFlag = 1;
		myCond = 1;
	}
	else if (*theChar == ' ')
	{
		(*mySpec).isSpaceFlag = 1;
		myCond = 1;
	}
	return (myCond);
}

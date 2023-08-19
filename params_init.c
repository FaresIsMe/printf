#include "main.h"
/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @arg: the argument pointer
 *
 * Return: void
 */
void init_params(specifier_params *params, va_list arg)
{
	params->isUnsigned = 0;
	params->isPlusFlag = 0;
	params->isMinusFlag = 0;
	params->isHashtagFlag = 0;
	params->isZeroFlag = 0;
	params->isSpace = 0;
	params->isShort = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->isLong = 0;
	(void)arg;
}

#include "main.h"
/**
 * _printf - prints anything
 * @format: the format of the string
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list arg;
	char *s, *start;
	specifier_params params;

	va_start(arg, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = (char *)format; *s; s++)
	{
		init_params(&params, arg);
		if (*s != '%')
		{
			sum = sum + _putchar(*s);
			continue;
		}
		start = s;
		s++;
		while (myFlags(s, &params))
		{
			s++;
		}
		s = myWidth(s, &params, arg);
		s = myPrecision(s, &params, arg);
		if (myModifier(s, &params))
			s++;
		if (!mySpecifier(s))
			sum += print_from_to(start, s,
				params.isShort || params.isLong ? s - 1 : 0);
		else
			sum += print_function_call(s, arg, &params);
	}
	_putchar(BUFFER_FLUSH_CONDITION);
	va_end(arg);
	return (sum);
}

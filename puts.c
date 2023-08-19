#include "main.h"
/**
 * _puts - prints a string
 * @s: the string to be printed
 * Description: It loops on -putchar to print a string
 * Return:
*/
int _puts(char *s)
{
	char *c = s;

	while (*s)
	{
		_putchar(*s++);
	}
	return (s - c);
}
/**
 * _putschar - it prints a single character
 * @c: the character to be printed
 * Return: 1 on success
*/
int _putchar(char c)
{
	static int i;
	static char buffer[MAX_BUFFER_SIZE];

	if (c == BUFFER_FLUSH_CONITION || MAX_BUFFER_SIZE <= i)
	{
		write (1, buffer, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH_CONITION)
	{
		buffer[i++];
	}
	return (1);
}

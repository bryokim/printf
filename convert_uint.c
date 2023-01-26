#include "main.h"
#include <stdio.h>
/**
*convert_uint - copies an unsigned integer.
*@n: integer to copy.
*@s: pointer to stirng.
*@base: base to convert the int
*
*Return: None.
*/
void convert_uint(unsigned int n, char *s, int base)
{
	unsigned int digit;
	char *str = s;

	while (n)
	{
		digit = n % base;
		*str++ = '0' + digit;
		n /= base;
	}
	_strrev(s);
}


/**
 * copy_uint - convert unsigned int to string and copy into s
 * @c: format specifier
 * @n: integer to convert to string and copy
 * @s: string to strore convertes int
 *
 * Return: void
*/
void copy_uint(char c, unsigned int n, char *s)
{
	if (c == 'b')
	{
		convert_uint(n, s, 2);
	}
	else if (c == 'u')
	{
		convert_uint(n, s, 10);
	}
	else if (c == 'o')
	{
		print_uint_base(n, s, 8);
	}
	else
	{
		print_uint_base(n, s, 16);
		if (c == 'X')
			capital_hex(s);
	}
}

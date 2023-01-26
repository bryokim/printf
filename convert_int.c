#include "main.h"
#include <stdio.h>


/**
 * copy_int - converts int n to string and copies it to string s
 * @c: format specifier
 * @d: next character after format specifier. Needed when handling specifier h
 * @n: integer to convert and copy
 * @i: pointer to index of format string
 * @s: string to copy integer to
 * @buf: buffer containing output to be printed.
 * @ap: va_list containing variadic arguments.
 *
 * Description: string buf and va_list ap are required so as to safely exit
 * when an error occurs by freeing buf and va_end ap.
 *
 * Return: void
*/
void copy_int(char c, char d, int n, int *i, char *s, char *buf, va_list ap)
{
	if (!convert_int(c, d, n, s))
	{
		va_end(ap);
		free(s);
		free(buf);
		exit(1);
	}
	if (c == 'h')
		(*i)++;
}

/**
*print_int_base10 - print number of base 10.
*@n: number to print to base 10.
*@s: stores integer after conversion.
*@base: base to convert number to.
*Return: None.
*/
void print_int_base10(int n, char *s, int base)
{
	int digit, sign;
	char *str = s;

	if (n == 0)
	{
		_strcpy(str, "0");
		return;
	}
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}

	while (n)
	{
		digit = n % base;
		*str++ = (digit > 9) ? ('a' + digit - 10) : (digit + '0');
		n /= base;
	}
	if (sign)
		*str++ = '-';

	*str = '\0';
	_strrev(s);
}
/**
*convert_int - converts integer to the format specified
*@c: format specifier.
*@d: next character after the format specifier h.
*@n: intger to print to the provided base
*@s: stores integer after conversion.
*Return: 1.
*/
int convert_int(char c, char d, int n, char *s)
{
	int base;

	base = find_base(c);
	if (c == 'c')
	{
		*s = n;
	}
	else if (c == 'd' || c == 'i')
	{
		print_int_base10(n, s, base);
	}
	else if (c == 'h')
	{
		base = find_base(d);
		if (base)
		{
			if (base == 10)
				find_short(n, s, base, print_int_base10);
			else
				find_short(n, s, base, print_int_base);
			if (d == 'X')
				capital_hex(s);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

#include "main.h"

/**
 * print_int - converts int n to string and copies it to string s
 * @c: format specifier
 * @d: next character after format specifier. Needed when handling specifier h
 * @n: integer to convert and copy
 * @i: pointer to index of format string
 * @flags: pointer to a flag_t struct
 * @ap: va_list containing variadic arguments.
 *
 * Description: string buf and va_list ap are required so as to safely exit
 * when an error occurs by freeing buf and va_end ap.
 *
 * Return: number of characters written.
*/
int print_int(char c, char d, int n, int *i, flag_t *flags, va_list ap)
{
	int result;

	result = convert_int(c, d, n, flags);

	if (c == 'h')
		(*i)++;

	if (!result)
	{
		va_end(ap);
		exit(1);
	}
	else
	{
		return (result);
	}
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
*@flags: pointer to a flag_t struct.
*Return: 1.
*/
int convert_int(char c, char d, int n, flag_t *flags)
{
	int base, len;
	char *s, *str;

	s = initialize_s(1024);
	str = initialize_s(1024);
	if (!s || !str)
		return (0);
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
			free(s);
			free(str);
			return (0);
		}
	}
	apply_flags(str, s, flags, base);
	len = write(1, str, _strlen(str));
	free(s);
	free(str);
	return (len);
}

#include "main.h"
#include <stdio.h>
/**
*convert_uint - copies an unsigned integer.
*@n: integer to copy.
*@base: base to convert the int
*@s: string to store the unsigned int
*@c: character showing format specifier
*@flags: pointer to a flag_t struct.
*
*Return: pointer to a string containing the unsigned int.
*/
char *convert_uint(unsigned int n, int base, char *s, char c, flag_t *flags)
{
	unsigned int digit;
	char *str = s, *str1;

	str1 = initialize_s(100);
	if (!str1)
		return (NULL);

	if (n == 0)
		_strcpy(str, "0");

	while (n)
	{
		digit = n % base;
		*str++ = (digit > 9) ? ('a' + digit - 10) : (digit + '0');
		n /= base;
	}

	_strrev(s);

	if (c == 'X')
		capital_hex(s);

	apply_flags(str1, s, flags, base);
	free(s);
	return (str1);
}


/**
 * print_uint - convert unsigned int to string and copy into s
 * @c: format specifier
 * @n: integer to convert to string and copy
 * @flags: pointer to a flag_t struct
 *
 * Return: number of bytes written.
*/
int print_uint(char c, unsigned int n, flag_t *flags)
{
	int base, len;
	char *s;

	s = initialize_s(13);
	if (!s)
		return (0);

	base = find_base(c);
	s = convert_uint(n, base, s, c, flags);

	len = write(1, s, _strlen(s));
	free(s);
	return (len);
}

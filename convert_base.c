#include "main.h"

/**
 * print_int_base - prints an integer to given base
 * @n: integer to convert to given base
 * @s: string to store converted integer
 * @base: Integer showing base to convert n to
 *
 * Return: void
*/
void print_int_base(int n, char *s, int base)
{
	char *str = s;
	unsigned int digit, ones_comp, i;

	i = 0;
	if (n == 0)
	{
		_strcpy(str, "0");
		return;
	}

	if (n < 0)
	{
		ones_comp = ~((n * -1) - 1);
		while (ones_comp && i < 11)
		{
			digit = ones_comp % base;
			*str++ = (digit > 0) ? ('a' + digit - 10) : (digit + '0');
			ones_comp /= base;
			i++;
		}
	}
	else
	{
		while (n)
		{
			digit = n % base;
			*str++ = (digit > 9) ? ('a' + digit - 10) : (digit + '0');
			n /= base;
		}
	}
	*str = '\0';
	_strrev(s);
}

/**
 * print_uint_base - prints an unsigned integer to given base
 * @n: unsigned integer to convert to given base
 * @s: string to store converted integer
 * @base: Integer showing base to convert n to
 *
 * Return: void
*/
void print_uint_base(unsigned int n, char *s, int base)
{
	char *str = s;
	unsigned int digit;

	if (n == 0)
	{
		_strcpy(str, "0");
		return;
	}
	while (n)
	{
		digit = n % base;
		*str++ = (digit > 9) ? ('a' + digit - 10) : (digit + '0');
		n /= base;
	}
	*str = '\0';
	_strrev(s);
}

/**
 * print_long_base - prints an unsigned integer to given base
 * @n: unsigned long integer to convert to given base
 * @s: string to store converted integer
 * @base: Integer showing base to convert n to
 *
 * Return: void
*/
void print_long_base(unsigned long int n, char *s, int base)
{
	char *str = s;
	unsigned long int digit;

	if (n == 0)
	{
		_strcpy(str, "0");
		return;
	}
	while (n)
	{
		digit = n % base;
		*str++ = (digit > 9) ? ('a' + digit - 10) : (digit + '0');
		n /= base;
	}
	*str = '\0';
	_strrev(s);
}

/**
 * capital_hex - Capitalizes letters in a hexadecimal number
 * @s: String containing the hexadecimal number
 *
 * Return: Void
*/
void capital_hex(char *s)
{
	char *str = s;

	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') && *str != 'x')
			*str = *str + 'A' - 'a';
		str++;
	}
}

/**
 * find_base - Finds base to which given format specifier matches
 * @c: Character showing the format specifier
 *
 * Return: base which character c matches
*/
int find_base(char c)
{
	int base;

	switch (c)
	{
	case 'b':
		base = 2;
		break;
	case 'o':
		base = 8;
		break;
	case 'd': case 'i':
		base = 10;
		break;
	case 'x': case 'X':
		base = 16;
		break;
	default:
		base = 0;
		break;
	}
	return (base);
}

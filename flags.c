#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * initialize - initializes a flag_t structure elements to zero
 *
 * Return: pointer to flags
*/
flag_t *initialize(void)
{
	flag_t *flags = malloc(sizeof(flag_t));

	if (!flags)
		return (NULL);

	flags->pound = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;

	return (flags);
}

/**
 * check_flag - checks flag modifier
 * @i: pointer to index of character
 * @format: string format being printed
 * @flags: pointer to flags_t structure
 *
 * Return: void
*/
void check_flag(int *i, const char *format, flag_t *flags)
{
	if (*(format + (*i)) == '#')
	{
		increment(&flags->pound, i);
		check_flag(i, format, flags);
	}
	else if (*(format + (*i)) == ' ')
	{
		increment(&flags->space, i);
		check_flag(i, format, flags);
	}
	else if (*(format + (*i)) == '+')
	{
		increment(&flags->plus, i);
		check_flag(i, format, flags);
	}
	else if (*(format + (*i)) == '-')
	{
		increment(&flags->minus, i);
		check_flag(i, format, flags);
	}
	else if (*(format + (*i)) == '0')
	{
		increment(&flags->zero, i);
		check_flag(i, format, flags);
	}
	else if (isdigit(*(format + (*i))))
	{
		flags->width = *(format + (*i)) - '0';
		(*i)++;
		check_flag(i, format, flags);
	}
	else
	{
		return;
	}
}

/**
 * increment - increments i and n
 * @i: pointer to index
 * @n: pointer to a flag_t struct element
 *
 * Return: void
*/
void increment(int *n, int *i)
{
	*n += 1;
	*i += 1;
}

/**
 * apply_flags - adds the side required output to the formatted string
 * @flags: pointer to a flag_t structure
 * @base: base of the current format
 * @s: string to store the formatted string
 * @str: string containing text to be formatted
 *
 * Return: void
*/
void apply_flags(flag_t *flags, int base, char *s, char *str)
{
	int sign, i;
	char s1[20] = {0};

	if (flags->minus && flags->zero)
		return;
	i = sign = 0;
	sign = check_pound(flags->pound, flags->space, base, s, str);
	if (flags->width > _strlen(str))
	{
		if (flags->minus && !flags->zero)
		{
			add_space(&flags->width, flags->space, base, &i, str, s);
			prefix_spaces(&flags->width, s, s1);
		}
		else if (flags->zero && !flags->minus)
		{
			add_space(&flags->width, flags->space, base, &i, str, s);
			prefix_zero(&flags->width, s, s1);
			_strcpy(s, s1);
		}
		else if (flags->space && *str != '-' && base == 10)
		{
			s1[i] = ' ';
			_strcat(s1, s);
			_strcpy(s, s1);
		}
		else
		{
			prefix_spaces(&flags->width, s, s1);
			_strcpy(s, s1);
		}
	}
	if (!sign)
	{
		_strcpy(s, str);
	}
}

/**
 * check_pound - checks for presence of poind in the flags
 * @pound: flags->pound
 * @space: flags->space
 * @base: base of the format
 * @s: string to store formatted output
 * @str: string containing output to be formatted
 *
 * Return: void
*/
int check_pound(int pound, int space, int base, char *s, char *str)
{
	int sign;

	sign = 0;
	if (pound && (base == 16 || base == 8) && !space)
	{
		if (base == 16)
		{
			_strcpy(s, "0x");
			_strcat(s + 2, str);
		}
		else if (base == 8)
		{
			_strcpy(s, "0");
			_strcat(s + 1, str);
		}
		sign = 1;
	}
	else if (pound && space)
	{
		exit(1);
	}
	else
	{
		_strcpy(s, str);
	}

	return (sign);
}

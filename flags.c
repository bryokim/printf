#include "main.h"
#include <ctype.h>

/**
 * initialize_flag - initializes a flag_t structure elements to zero
 *
 * Return: pointer to flags
*/
flag_t *initialize_flag(void)
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
	static int d;

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
	else if (*(format + (*i)) == '0' && !isdigit(*(format + (*(i) - 1))))
	{
		increment(&flags->zero, i);
		check_flag(i, format, flags);
	}
	else if (isdigit(*(format + (*i))))
	{
		d = d * 10 + (*(format + (*i)) - '0');
		flags->width = d;
		(*i)++;
		check_flag(i, format, flags);
	}
	else
	{
		d = 0;
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
 * apply_flags - formats string as required by the flags.
 * @flags: pointer to a flag_t structure
 * @base: base of the current format
 * @dest: string to store the formatted string
 * @src: string containing text to be formatted
 *
 * Return: void
*/
void apply_flags(char *dest, char *src, flag_t *flags, int base)
{
	int sign;
	char *s;

	s = initialize_s(1024);
	if (!s)
		free_mem(s, dest, src, flags);

	if ((flags->minus && flags->zero) || flags == NULL)
		free_mem(s, dest, src, flags);

	sign = 0;
	sign = check_pound(dest, src, flags->pound, flags->space, base);
	(sign == 1) ? (_strcpy(s, dest)) : (_strcpy(s, src));

	if (flags->width > _strlen(src))
	{
		if (flags->minus)
			postfix_space(dest, s, flags, base);
		else if (flags->zero)
			prefix_zero(dest, s, flags, base);
		else
			prefix_spaces(dest, s, flags, base);
	}
	else if (flags->plus)
	{
		add_plus(dest, s, flags, base);
		_strcat(dest, s);
	}
	else if (flags->space)
	{
		add_space(dest, s, flags, base);
		_strcat(dest, s);
	}

	if (!sign && _strlen(dest) == 0)
		_strcpy(dest, src);

	free(s);
}

/**
 * check_pound - checks for presence of poind in the flags
 * @pound: flags->pound
 * @space: flags->space
 * @base: base of the format
 * @dest: string to store formatted output
 * @src: string containing output to be formatted
 *
 * Return: void
*/
int check_pound(char *dest, char *src, int pound, int space, int base)
{
	int sign;

	sign = 0;
	if (pound && (base == 16 || base == 8) && !space)
	{
		if (base == 16)
		{
			_strcpy(dest, "0x");
			_strcat(dest + 2, src);
		}
		else if (base == 8)
		{
			_strcpy(dest, "0");
			_strcat(dest + 1, src);
		}
		sign = 1;
	}
	else if (pound && space)
	{
		exit(1);
	}

	return (sign);
}

#include "main.h"

/**
*postfix_space - adds space to a string.
*@base: holds the base.
*@src: pointer to string.
*@dest: temporary string holder.
*@flags: flag_t struct
*
*Return: None.
*/
void postfix_space(char *dest, char *src, flag_t *flags, int base)
{
	char *s1;
	int i;

	s1 = initialize_s(flags->width);
	if (!s1)
		exit(1);

	add_plus(dest, src, flags, base);
	add_space(dest, src, flags, base);

	if (_strlen(dest) < 2)
		_strcat(dest, src);

	for (i = 0; i < (flags->width - _strlen(src)); i++)
		s1[i] = ' ';

	_strcat(dest, s1);
	free(s1);
}

/**
 * prefix_spaces - prepends spaces.
 * @flags: flag_t structure
 * @src: pointer to temporary string.
 * @dest: string to hold the spaces.
 * @base: base specifier
 * Return: None.
*/
void prefix_spaces(char *dest, char *src, flag_t *flags, int base)
{
	int i, len, j;

	add_plus(dest, src, flags, base);

	len = _strlen(dest);
	if (len > 1)
	{
		for (i = 0; i < len; i++)
			dest[i] = '\0';
	}

	j = (len == 1) ? (1) : (0);
	for (i = 0; i < (flags->width - _strlen(src)); i++)
		dest[i + j] = ' ';
	_strrev(dest);
	_strcat(dest, src);
}

/**
 * prefix_zero - prepends zero.
 * @flags: flag_t struct.
 * @src: pointer to temporary string.
 * @dest: pointer to zero to be prepended.
 * @base: base of the src
 *
 * Return: None.
*/
void prefix_zero(char *dest, char *src,  flag_t *flags, int base)
{
	int i, j, len;

	add_plus(dest, src, flags, base);
	add_space(dest, src, flags, base);

	len = _strlen(dest);
	if (len > 1)
	{
		for (i = 0; i < len; i++)
			dest[i] = '\0';
	}
	j = (len == 1) ? (1) : (0);

	for (i = 0 ; i < (flags->width - _strlen(src)); i++)
		dest[i + j] = '0';

	_strcat(dest, src);
}

/**
 * add_space - adds single space at start of string
 * @dest: string to strore formatted string
 * @src: source string
 * @flags: flag_t structure
 * @base: base of source if it's a number
 *
 * Return: void
*/
void add_space(char *dest, char *src, flag_t *flags, int base)
{
	if (flags->space && *src != '-' && base == 10)
	{
		*dest = ' ';
		flags->width -= 1;
	}
}

/**
 * add_plus - adds single positive sign at start of string
 * @dest: string to strore formatted string
 * @src: source string
 * @flags: flag_t structure
 * @base: base of source if it's a number
 *
 * Return: void
*/
void add_plus(char *dest, char *src, flag_t *flags, int base)
{
	if (flags->plus && !flags->space && *src != '-' && base == 10)
	{
		*dest = '+';
		flags->width -= 1;
	}
}

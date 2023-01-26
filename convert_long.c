#include "main.h"
#include <stdio.h>
/**
 * copy_long - copies a long int.
 * @c: holds the format specifier.
 * @n: holds the unsigned long integer.
 * @s: pointer to temporary string.
 * Return: none.
*/
void copy_long(char c, unsigned long int n, char *s)
{
	if (c == 'p')
		print_pointer(n, s);
}
/**
 * print_pointer - prints the pointer.
 * @n: holds an unsigned int.
 * @s: temporary string.
 * Return: none.
*/
void print_pointer(unsigned long int n, char *s)
{
	char str[20] = {0};
	flag_t *flags = initialize();

	flags->pound = 1;

	print_long_base(n, s, 16);
	apply_flags(flags, 16, str, s);
	_strcpy(s, str);
	free(flags);
}

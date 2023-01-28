#include "main.h"


/**
 * print_long - copies a long int.
 * @c: holds the format specifier.
 * @n: holds the unsigned long integer.
 *
 * Return: number of bytes written.
*/
int print_long(char c, unsigned long int n)
{
	char *s;
	int len;

	if (c == 'p')
		s = print_pointer(n);
	len = write(1, s, _strlen(s));
	free(s);
	return (len);
}
/**
 * print_pointer - prints the pointer.
 * @n: holds an unsigned int.
 *
 * Return: pointer to a string containing address.
*/
char *print_pointer(unsigned long int n)
{
	char *dest, *src;
	flag_t *flags = initialize_flag();

	src = initialize_s(20);
	dest = initialize_s(100);
	if (!dest || !src)
		return (NULL);

	flags->pound = 1;

	print_long_base(n, src, 16);
	apply_flags(dest, src, flags, 16);

	free(src);
	free(flags);
	return (dest);
}

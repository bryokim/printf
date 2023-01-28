#include "main.h"


/**
 * print_str - prints string str according to given format specifier
 * @c: format specifier
 * @str: buffer holding string to be printed
 * @flags: pointer to a flag_t struct
 *
 * Description: function to convert str is chosen here. Either print
 * custom string or normal string or reversed string
 *
 * Return: number of bytes writtens
*/
int print_str(char c, char *str, flag_t *flags)
{
	int len, i;

	len = 0;
	if (str == NULL)
		return (0);

	if (c == 's')
		len = normal_str(str, flags);
	else if (c == 'S')
		len = custom_str(str);
	else
	{
		for (i = (_strlen(str) - 1); i >= 0; i--)
			len += _putchar(str[i]);
	}
	return (len);
}

/**
 * custom_str - converts given string to a custom string
 * @str: string to convert to custom string
 *
 * Description: custom string contains all escape sequences
 * expressed in hex and prefixes with \x
 *
 * Return: number of bytes written
*/
int custom_str(char *str)
{
	char *s, *hex;
	int j, n, len;

	s = initialize_s(1024);
	hex = initialize_s(13);
	if (!s || !hex)
		exit(1);

	j = 0;
	while (*str)
	{
		n = 13;
		while (n > 0)
			hex[--n] = '\0';

		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			_strcpy(s + j, "\\x");
			j += 2;

			print_int_base(*str, hex, 16);
			capital_hex(hex);

			if (_strlen(hex) < 2)
				s[j++] = '0';

			_strcpy(s + j, hex);
			j += _strlen(hex);
		}
		else
		{
			s[j++] = *str;
		}
		str++;
	}
	free(hex);
	len = write(1, s, _strlen(s));
	free(s);
	return (len);
}

/**
 * initialize_s - creates a string of size and initializes it to 0
 * @size: size of the string
 *
 * Return: string initialized to zero
*/
char *initialize_s(int size)
{
	char *s;
	int i;

	s = malloc(size * sizeof(char));
	if (!s)
		return (NULL);

	for (i = 0; i < size; i++)
		s[i] = '\0';

	return (s);
}

/**
 * normal_str - prints a string normally
 * @str: string to be printed
 * @flags: pointer to a flag_t struct
 *
 * Return: number of bytes written
*/
int normal_str(char *str, flag_t *flags)
{
	char *s;
	int len;

	s = initialize_s(1024);
	if (!s)
		return (0);

	apply_flags(s, str, flags, 0);

	len = write(1, s, _strlen(s));
	free(s);
	return (len);
}

#include "main.h"

/**
 * copy_str - prints string str according to given format specifier
 * @c: format specifier
 * @s: string to store the string to be printed
 * @str: buffer holding string to be printed
 *
 * Description: function to convert str is chosen here. Either print
 * custom string or normal string
 *
 * Return: void
*/
void copy_str(char c, char *s, char *str)
{
	if (c == 's')
		_strcpy(s, str);
	else if (c == 'S')
		custom_str(s, str);
	else
		print_rev(s, str);
}

/**
 * custom_str - converts given string to a custom string
 * @s: string to store the custom string
 * @str: string to convert to custom string
 *
 * Description: custom string contains all escape sequences
 * expressed in hex and prefixes with \x
 *
 * Return: void
*/
void custom_str(char *s, char *str)
{
	char hex[4];
	int j, n;

	j = 0;
	while (*str)
	{
		n = 4;
		while (n > 0)
			hex[--n] = '\0';

		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			_strcpy(s + j, "\\x");
			j += 2;

			print_uint_base((unsigned int)*str, hex, 16);
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
}

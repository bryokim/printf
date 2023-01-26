#include "main.h"

/**
 * create_buffer - creates buffer to be printed
 * @format: string to be printed
 * @buf: buffer to be printed
 * @ap: va_list containing arguments to replace format specifiers
 *
 * Description: pupulates buf with the output to be printed
 * by calling other functions to convert specific types to string
 *
 * Return: void
*/
void create_buffer(const char *format, char *buf, va_list ap)
{
	int i, j;
	char s[1024] = {0};

	for (i = j = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%')
		{
			buf[j++] = format[i++];
			if (format[i] == '\0')
				return;
		}
		if (format[++i] == '%')
			buf[j++] = '%';
		else if (check(format[i]) == 1)
			copy_str(format[i], s, va_arg(ap, char*));
		else if (check(format[i]) == 2)
			copy_int(format[i], format[i + 1], va_arg(ap, int), &i, s, buf, ap);
		else if (check(format[i]) == 3)
			copy_uint(format[i], va_arg(ap, unsigned int), s);
		else if (check(format[i]) == 5)
			rot13(s, va_arg(ap, char *));
		else
			exit(1);
		_append(buf, s, &j);
	}
	buf[j] = '\0';
}

/**
 * copy_int - converts int n to string and copies it to string s
 * @c: format specifier
 * @d: next character after format specifier. Needed when handling specifier h
 * @n: integer to convert and copy
 * @i: pointer to index of format string
 * @s: string to copy integer to
 * @buf: buffer containing output to be printed.
 * @ap: va_list containing variadic arguments.
 *
 * Description: string buf and va_list ap are required so as to safely exit
 * when an error occurs by freeing buf and va_end ap.
 *
 * Return: void
*/
void copy_int(char c, char d, int n, int *i, char *s, char *buf, va_list ap)
{
	if (!convert_int(c, d, n, s))
	{
		va_end(ap);
		free(buf);
		exit(1);
	}
	if (c == 'h')
		(*i)++;
}

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
	int i, j, base;
	char *s, str[100] = {0};
	flag_t *flags;

	s = malloc(1024 * sizeof(char));
	for (i = 0; i < 1024; i++)
		s[i] = '\0';
	for (i = j = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%')
		{
			buf[j++] = format[i++];
			if (format[i] == '\0')
				return;
		}
		i++;
		flags = initialize();
		check_flag(&i, format, flags);
		if (format[i] == '%')
			buf[j++] = '%';
		else if (check(format[i]) == 1)
			copy_str(format[i], s, va_arg(ap, char*));
		else if (check(format[i]) == 2)
			copy_int(format[i], format[i + 1], va_arg(ap, int), &i, s, buf, ap);
		else if (check(format[i]) == 3)
			copy_uint(format[i], va_arg(ap, unsigned int), s);
		else if (check(format[i]) == 4)
			copy_long(format[i], va_arg(ap, long int), s);
		else if (check(format[i]) == 5)
			rot13(s, va_arg(ap, char *));
		else
			exit(1);
		base = find_base(format[i]);
		apply_flags(flags, base, str, s);
		_append(buf, str, &j);
		free(flags);
	}
	free(s);
}

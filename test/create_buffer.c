#include "main.h"

/**
 * print_buffers - creates buffer to be printed
 * @format: string to be printed
 * @ap: va_list containing arguments to replace format specifiers
 *
 * Description: calls functions that print buffers created from
 * the arguments read
 *
 * Return: void
*/
int print_buffers(const char *format, va_list ap)
{
	int i, len;
	flag_t *flags;

	for (i = len = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%')
		{
			len += _putchar(format[i++]);
			if (format[i] == '\0')
				return (len);
		}
		i++;

		flags = initialize_flag();
		check_flag(&i, format, flags);
		if (format[i] == '%')
			len += _putchar('%');
		else if (check(format[i]) == 1)
			len += print_str(format[i], va_arg(ap, char *), flags);
		else if (check(format[i]) == 2)
			len += print_int(format[i], format[i + 1], va_arg(ap, int), &i, flags, ap);
		else if (check(format[i]) == 3)
			len += print_uint(format[i], va_arg(ap, unsigned int), flags);
		else if (check(format[i]) == 4)
			len += print_long(format[i], va_arg(ap, long int));
		else if (check(format[i]) == 5)
			len += rot13(va_arg(ap, char *));
		else
			exit(1);
		free(flags);
	}
	return (len);
}

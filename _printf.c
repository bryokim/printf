#include <unistd.h>
#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 * @format: Buffer containing the string to be printed
 *
 * Return: Number of bytes written
*/
int _printf(const char *format, ...)
{
	va_list ap;
	char *buf;
	int len;

	buf = malloc(1024 * sizeof(char));
	if (!buf)
		return (-1);

	va_start(ap, format);

	create_buffer(format, buf, ap);

	va_end(ap);

	len = write(1, buf, _strlen(buf));
	free(buf);
	return (len);
}

#include "main.h"

/**
 * _putchar - puts a character to stdout
 * @c: character to be printed
 *
 * Return: 1
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

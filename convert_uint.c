#include "main.h"
#include <stdio.h>
/**
*copy_uint - copies an unsigned integer.
*@n: integer to copy.
*@s: pointer to stirng.
*Return: None.
*/
void copy_uint(unsigned int n, char *s)
{
	unsigned int digit;
	char *str = s;

	while (n)
	{
		digit = n % 10;
		*str++ = '0' + digit;
		n /= 10;
	}
	_strrev(s);
}

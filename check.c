#include <stdio.h>
/**
 * check - checks for the specifier.
 * @c: holds the specifier.
 * Return: specifier indentifier.
 */
int check(char c)
{
	int n;

	switch (c)
	{
		case 's': case 'S':
			n = 1;
			break;
		case 'd': case 'i': case 'o': case 'x': case 'X':
		case 'c': case 'h':
			n = 2;
			break;
		case 'u': case 'b':
			n = 3;
			break;
		case 'l':
			n = 4;
			break;
		default:
			n = -1;
			break;
	}
	return (n);
}

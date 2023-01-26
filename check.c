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
		case 's': case 'S': case 'r':
			n = 1;
			break;
		case 'd': case 'i': case 'c': case 'h':
			n = 2;
			break;
		case 'u': case 'b': case 'o': case 'x': case 'X':
			n = 3;
			break;
		case 'l':
			n = 4;
			break;
		case 'R':
			n = 5;
			break;
		default:
			n = -1;
			break;
	}
	return (n);
}

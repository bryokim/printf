#include "main.h"
/**
*add_space - adds space to a string.
*@width: pointer to width specifier.
*@space: holds space.
*@base: holds the base.
*@i: pointer to index.
*@str: pointer to string.
*@s: temporary string holder.
*Return: None.
*/
void add_space(int *width, int space, int base, int *i, char *str, char *s)
{
	if (space && *str != '-' && base == 10)
	{
		*(s + *(i)) = ' ';
		*(width) = *(width) - 1;
	}
}
/**
 * prefix_spaces - prepends spaces.
 * @width: pointer to width specifier.
 * @s: pointer to temporary string.
 * @s1: string to hold the spaces.
 * Return: None.
*/
void prefix_spaces(int *width, char *s, char *s1)
{
	int i;

	for (i = 0; i < (*(width) - _strlen(s)); i++)
		s1[i] = ' ';
	_strcat(s, s1);
}
/**
 * prefix_zero - prepends zero.
 * @width: pointer to width specifier.
 * @s: pointer to temporary string.
 * @s1: pointer to zero to be prepended.
 * Return: None.
*/
void prefix_zero(int *width, char *s, char *s1)
{
	int i;

	for (i = 0; i < (*(width) - _strlen(s)); i++)
		s1[i] = '0';
	_strcat(s1 + i, s);
}

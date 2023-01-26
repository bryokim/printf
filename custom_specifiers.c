#include "main.h"
/**
*rot13 - encodes a string using rot13.
*@str: main string.
*@s: string to encode.
*Return: none.
*/
void rot13(char *str, char *s)
{
	int i;

	i = 0;
	if (s == NULL)
	{
		str[i] = '\0';
		return;
	}

	for ( ; s[i] != '\0'; i++)
	{
		while ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
		{
			str[i] = s[i] + 13;
			i++;
		}

		if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			str[i] = s[i] - 13;
	}
}

/**
*print_rev - gives reverse of a string.
*@s: string to reverse.
*@str: main string.
*Return: none.
*/
void print_rev(char *s, char *str)
{
	_strcpy(s, str);
	_strrev(s);
}

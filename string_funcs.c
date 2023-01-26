#include "main.h"
/**
*_strcpy - copy a given string to a destination string.
*@dest: pointer to destination string.
*@src: source string
*Return: None.
*/
void  _strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}
/**
*_strlen - checks length of string.
*@s: pointer to string whose length is being checked.
*Return: lenght of string.
*/
int _strlen(const char *s)
{
	int n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}
/**
*_strcat - concatenates two strings.
*@dest: pointer to destination string.
*@src: pointer to source string
*Return: none
*/
void _strcat(char *dest, char *src)
{
	int dest_len;

	dest == NULL ? dest_len = 0 : (dest_len = _strlen(dest));

	_strcpy(dest + dest_len, src);
}
/**
*_strrev - reverses a string.
*@s: pointer to string to reverse.
*Return: none.
*/
void _strrev(char *s)
{
	int len, lo, hi;
	char temp;

	len = _strlen(s);
	for (lo = 0, hi = (len - 1); lo < hi; lo++, hi--)
	{
		temp = s[lo];
		s[lo] = s[hi];
		s[hi] = temp;
	}
}
/**
*_append - appends a string to another.
*@str: destination for the appended string.
*@s: string to be appended.
*@j: index
*Return: none
*/
void _append(char *str, char *s, int *j)
{
	_strcat(str + (*j), s);
	*j += _strlen(s);
}

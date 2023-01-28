#include "main.h"

/**
*rot13 - encodes a string using rot13.
*@s: string to encode.
*Return: none.
*/
int rot13(char *s)
{
	int i, len;
	char *str;

	str = initialize_s(_strlen(s) + 1);
	if (!str)
		return (0);

	i = 0;
	if (s == NULL)
	{
		str[i] = '\0';
		return (0);
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

	len = write(1, str, _strlen(str));
	free(str);

	return (len);
}


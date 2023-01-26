#include "main.h"
#include <stdio.h>

#define SIZE_SHORT (1 << (sizeof(short) << 3))
#define SHORT_MAX ((SIZE_SHORT >> 1) - 1)
#define SHORT_MIN (-(SIZE_SHORT >> 1))

/**
 * find_short - Finds the short equivalent of a given integer
 * @n: integer to convert to short
 * @s: string to store short
 * @base: base to which to represent the short
 * @f: function to convert short to required base
 *
 * Description: Takes an integer and finds its short equvalent
 * which is then passed to a function that converts it to required base
 *
 * Return: void
*/
void find_short(int n, char *s, int base, void (*f)(int, char *, int))
{
	int div;

	if (n > 0)
	{
		div = n / (SHORT_MAX + 1);

		if (div % 2 == 0)
		{
			n = (n % (SHORT_MAX + 1));
		}
		else
		{
			n = SHORT_MIN - div + (n % SHORT_MAX);
			if (n < SHORT_MIN)
				n %= SHORT_MAX;
		}
	}
	else
	{
		if (n == SHORT_MIN)
		{
			f(n, s, base);
			return;
		}

		div = n / (SHORT_MIN);
		if (div % 2 == 0)
		{
			n = (n % (SHORT_MIN));
		}
		else
		{
			if (div > (n % SHORT_MIN))
				n = SHORT_MAX + (n % SHORT_MIN + 1);
			else
				n = SHORT_MAX + div + (n % SHORT_MIN);
		}
	}
	f(n, s, base);
}

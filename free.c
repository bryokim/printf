#include "main.h"

/**
 * free_mem - free memory before exiting
 * @s: string
 * @dest: string
 * @src: string
 * @flags: flag_t struct
 *
 * Return: void
*/
void free_mem(char *s, char *dest, char *src, flag_t *flags)
{
	free(s);
	free(dest);
	free(src);
	free(flags);

	exit(1);
}

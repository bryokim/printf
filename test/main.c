#include "main.h"
#include <stdio.h>

int main(void)
{
        int m;
        unsigned int n;

        n = _printf("My name is %s %s\n", "Brian", "Kimathi");
        m = printf("My name is %s %s\n", "Brian", "Kimathi");

        _printf("\n%hd %ho %hx %hX\n",n, n, n, n);
        printf("%hd %ho %hx %hX\n", m, m, m, m);

        m = -199993949;
        n = 4294000000;
        _printf("\n%hd %ho %hx %hX\n", 1000000, m, m, m);
        printf("%hd %ho %hx %hX\n", 1000000, m, m, m);

        _printf("\n%c\n", 'c');
        printf("%c\n", 'c');

        _printf("\n%hd\n", 100000);
        printf("%hd\n", 100000);

        _printf("\n%u\n", m);
        printf("%u\n", m);

        _printf("\n%S\n", "Tab\t New-line\n");

        return (0);
}
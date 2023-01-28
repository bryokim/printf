#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Short:[%hd]\n", -762534);
    printf("Short:[%hd]\n", -762534);
    _printf("Unsigned:[%-67u]\n", ui);
    printf("Unsigned:[%-67u]\n", ui);
    _printf("Unsigned octal:[%#-20o]\n", ui);
    printf("Unsigned octal:[%#-20o]\n", ui);
    _printf("Unsigned hexadecimal:[%#20x, %#-20X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%#20x, %#-20X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%4d]\n", len);
    printf("Len:[%4d]\n", len2);
    _printf("Unknown:[%r]\n", "Brian");
    _printf("%R\n", "Brian");
    _printf("%S\n", "Brian\nKimathi");
    return (0);
}
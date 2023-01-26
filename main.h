#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int check(char c);
void create_buffer(const char *format, char *buf, va_list ap);

int convert_int(char c, char d, int n, char *s);
void print_int_base10(int n, char *s, int base);
void copy_int(char c, char d, int n, int *i, char *s, char *buf, va_list ap);
void convert_uint(unsigned int n, char *s, int base);
void copy_uint(char c, unsigned int n, char *s);

void custom_str(char *s, char *str);
void copy_str(char c, char *s, char *str);

void  _strcpy(char *dest, char *src);
void _strrev(char *s);
int _strlen(const char *s);
void _strcat(char *dest, char *src);
void _append(char *str, char *s, int *j);

void print_to_base(int n, char *s, int base);
void capital_hex(char *s);
int find_base(char c);

void find_short(int n, char *s, int base, void (*f)(int, char *, int));

#endif

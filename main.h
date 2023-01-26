#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flag - Struct flag
 * @pound: pound flag
 * @space: space flag
 * @plus: plus flag
 * @minus: minus flag
 * @zero: zero flag
 * @width: width flag
*/
typedef struct flag
{
	int pound;
	int space;
	int plus;
	int minus;
	int zero;
	int width;
} flag_t;

int _printf(const char *format, ...);
int check(char c);
void create_buffer(const char *format, char *buf, va_list ap);

int convert_int(char c, char d, int n, char *s);
void print_int_base10(int n, char *s, int base);
void copy_int(char c, char d, int n, int *i, char *s, char *buf, va_list ap);
void convert_uint(unsigned int n, char *s, int base);
void copy_uint(char c, unsigned int n, char *s);

void check_flag(int *i, const char *format, flag_t *flags);
void apply_flags(flag_t *flags, int base, char *s, char *str);
int check_pound(int pound, int space, int base, char *s, char *str);
void add_space(int *width, int space, int base, int *j, char *str, char *s);
void prefix_spaces(int *width, char *s, char *s1);
void prefix_zero(int *width, char *s, char *s1);
void increment(int *n, int *i);
flag_t *initialize(void);

void custom_str(char *s, char *str);
void copy_str(char c, char *s, char *str);

void  _strcpy(char *dest, const char *src);
void _strrev(char *s);
int _strlen(const char *s);
void _strcat(char *dest, char *src);
void _append(char *str, char *s, int *j);

void print_int_base(int n, char *s, int base);
void print_uint_base(unsigned int n, char *s, int base);
void print_long_base(unsigned long int n, char *s, int base);
void capital_hex(char *s);
int find_base(char c);

void copy_long(char c, unsigned long int n, char *s);
void print_pointer(unsigned long int n, char *s);

void find_short(int n, char *s, int base, void (*f)(int, char *, int));

void rot13(char *str, char *s);
void print_rev(char *s, char *str);

#endif

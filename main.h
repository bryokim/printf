#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

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
int print_buffers(const char *format, va_list ap);

int convert_int(char c, char d, int n, flag_t *flags);
void print_int_base10(int n, char *s, int base);
int print_int(char c, char d, int n, int *i, flag_t *flags, va_list ap);
char *convert_uint(unsigned int n, int base, char *s, char c, flag_t *flags);
int print_uint(char c, unsigned int n, flag_t *flags);

void check_flag(int *i, const char *format, flag_t *flags);
void apply_flags(char *dest, char *src, flag_t *flags, int base);
void free_mem(char *s, char *dest, char *src, flag_t *flags);
int check_pound(char *dest, char *src, int pound, int space, int base);
void postfix_space(char *dest, char *src, flag_t *flags, int base);
void add_space(char *dest, char *src, flag_t *flags, int base);
void add_plus(char *dest, char *src, flag_t *flags, int base);
void prefix_spaces(char *dest, char *src, flag_t *flags, int base);
void prefix_zero(char *dest, char *src, flag_t *flags, int base);
void increment(int *n, int *i);
flag_t *initialize_flag(void);

char *initialize_s(int size);
int custom_str(char *str);
int print_str(char c, char *str, flag_t *flags);
int normal_str(char *str, flag_t *flags);

int _putchar(char c);
void  _strcpy(char *dest, const char *src);
void _strrev(char *s);
int _strlen(const char *s);
void _strcat(char *dest, char *src);
void _append(char *str, char *s, int *j);

void print_int_base(int n, char *s, int base);
void print_long_base(unsigned long int n, char *s, int base);
void capital_hex(char *s);
int find_base(char c);

int print_long(char c, unsigned long int n);
char *print_pointer(unsigned long int n);

void find_short(int n, char *s, int base, void (*f)(int, char *, int));

int rot13(char *s);
int print_rev(char *str);

#endif

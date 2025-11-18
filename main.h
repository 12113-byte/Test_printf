#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(char *s);
int print_a_str(va_list *args);
int print_special(va_list *args);
int print_a_char(va_list *args);
int print_an_int(va_list *args);
int print_binary(va_list *args);

typedef struct specifier
{
	char specifier;
	int (*print_func)(va_list *);
} specifier_t;

#endif


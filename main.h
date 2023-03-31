#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*check_conv_specifier(const char *))(va_list);

/**
 * struct func - struct containing capsules of a conv specifier and its
 * associated function
 * @t: character to check that looks at the conversion specifier
 * @f: pointer to specific print functions per conv specifier
 */
typedef struct func
{
        char *t;
        int (*f)(va_list);
} func_t;

int print_char(va_list);
int print_str(va_list);
int print_perc(va_list);
int print_int(va_list);
int print_dec(va_list);

#endif

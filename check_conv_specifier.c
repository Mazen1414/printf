#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * check_conv_specifier - check that the char is a valid conversion specifier
 * and assigns appropriate function for its printing given the specifier
 * @format: the specifier type, all (char *)
 * Return: pointer to the appropriate function
 */
int (*check_conv_specifier(const char *format))(va_list)
{
        int i;

        func_t func_array[6] = {
                {"c", print_char},
                {"s", print_str},
                {"%", print_perc},
		("d", print_int},
		{"i", print_dec},
                {NULL, NULL}};

        for (i = 0; func_array[i].t != NULL; i++)
        {
                if (*(func_array[i].t) == *format)
                {
                        return (func_array[i].f);
                }
        }
        return (NULL);
}

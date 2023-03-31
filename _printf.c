#include "main.h"

/**
 * _printf - function that produces outpiut according to the specified format
 * @format: char string composed of directives
 * @...: variadic arguments
 * Return: count of printed chars
 */
int _printf(const char *format, ...)
{
        int i = 0;
        int char_count = 0;
        int value = 0;
        va_list args;
        int (*f)(va_list);

        va_start(args, format);
        if (format == NULL)
                return (-1);
        while (format[i])
        {
                if (format[i] != '%')
                {
                        value = write(1, &format[i], 1);
                        char_count += value;
                        i++;
                        continue;
                }
                if (format[i] == '%')
                {
                        f = check_conv_specifier(&format[i + 1]);
                        if (f != NULL)
                        {
                                value = f(args);
                                char_count = char_count + value;
                                i = i + 2;
                                continue;
                        }
                        if (format[i + 1] == '\0')
                                break;
                        if (format[i + 1] != '\0')
                        {
                                value = write(1, &format[i + 1], 1);
                                char_count += value;
                                i = i + 2;
                                continue;
                        }
                }
        }
        return (char_count);
}

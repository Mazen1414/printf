#include "main.h"

/**
 * print_str - prints a variadic string each per time to stdout
 * @args: variadic parameter
 *
 * Return: number of characters printed on Success
 * upon failure -1
 */

int print_str(va_list args)
{
        size_t i = 0;
        int count = 0;
        const char *str;

        str = va_arg(args, const char *);

        if (str == NULL)
                return (-1);

        while (str[i])
        {
                count = write(1, &str[i], 1);
                if (count == -1)
			return (-1);
		i++;
        }

        return ((int)i);
}

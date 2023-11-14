#include "main.h"

/* Prints a character */
int print_char(va_list arg)
{
    return _putchar(va_arg(arg, int));
}

/* Prints a string */
int print_string(va_list arg)
{
    int count = 0;
    char *str = va_arg(arg, char *);

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _putchar(*str++);
        count++;
    }

    return count;
}

/* Prints a percent sign */
int print_percent(__attribute__((unused))va_list arg)
{
    return _putchar('%');
}

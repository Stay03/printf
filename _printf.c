#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * 
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    int (*function)(va_list);

    if (!format)
        return (-1);

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    function = print_char;
                    count += function(args);
                    break;
                case 's':
                    function = print_string;
                    count += function(args);
                    break;
                case '%':
                    count += print_percent();
                    break;
                default:
                    write(1, format - 1, 2);
                    count += 2;
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return (count);
}

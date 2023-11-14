#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing the characters and the specifiers.
 *          This function can handle the following conversion specifiers:
 *          c - character
 *          s - string
 *          % - percent
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent(args);
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(*format);
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

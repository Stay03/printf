#include "main.h"

/**
 * print_char - Prints a character
 * @args: The character to print
 * 
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: The string to print
 * 
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    int count = 0;
    char *str = va_arg(args, char *);

    if (str == NULL)
        str = "(null)";

    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    
    return (count);
}

/**
 * print_percent - Prints a percent sign
 * 
 * Return: Number of characters printed
 */
int print_percent()
{
    return (write(1, "%", 1));
}

/**
 * print_binary - prints an unsigned int in binary
 * @arg: unsigned int to print
 *
 * Return: number of characters printed
 */
int print_binary(va_list arg)
{
    unsigned int n;
    unsigned int mask;
    int count;

    n = va_arg(arg, unsigned int);
    mask = 1 << (sizeof(n) * 8 - 1);
    count = 0;

    while (mask)
    {
        if (n & mask)
        {
            _putchar('1');
            count++;
        }
        else
        {
            _putchar('0');
            count++;
        }

        mask >>= 1;
    }

    return (count);
}

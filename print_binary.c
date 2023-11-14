#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it
 * @args: List of arguments from which to pull the unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buf[33];
    int i = 0;
    int count = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (num > 0)
    {
        buf[i++] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    buf[i] = '\0';

    while (i > 0)
    {
        write(1, &buf[--i], 1);
        count++;
    }

    return (count);
}

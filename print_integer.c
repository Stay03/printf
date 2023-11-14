#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: The list of arguments from which to print the integer
 * 
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    unsigned int num_abs;
    char buf[12];
    int i;

    if (num < 0)
    {
        count += write(1, "-", 1);
        num_abs = (unsigned int)(-num);
    }
    else
    {
        num_abs = (unsigned int)num;
    }

    /* Reverse the number into the buffer */
    for (i = 0; num_abs > 0 || i == 0; ++i)
    {
        buf[i] = (num_abs % 10) + '0';
        num_abs /= 10;
    }
    
    count += i;

    /* Print the number in reverse order (since it was stored reversed) */
    while (i--)
    {
        write(1, &buf[i], 1);
    }

    return (count);
}

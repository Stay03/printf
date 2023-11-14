#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent();
int _putchar(char c);
int print_integer(va_list args);
int print_binary(va_list arg);

#endif /* MAIN_H */

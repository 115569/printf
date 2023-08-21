#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * You don’t have to reproduce the buffer handling of the C library
 * printf function
 * You don’t have to handle the flag characters
 * You don’t have to handle field width
 * You don’t have to handle precision
 * You don’t have to handle the length modifiers
 * @format: A string containing all the desired characters
 *
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)
{

int count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == 'c')
{

char c = va_arg(args, int);

putchar(c);
count++;
}
else if (*format == '')
{

char *s = va_arg(args, char*);

while (*s != '\0')
{
putchar(*s);
count++;
s++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
format++;
}
va_end(args);
return (count);
}

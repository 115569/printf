#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
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
count += putchar(va_arg(args, int));
break;
case 's':
{
const char *str = va_arg(args, const char *);
count += printf("%s", str);
break;
}
case '%':
count += putchar('%');
break;
}
}
else
{
count += putchar(*format);
}
format++;
}

va_end(args);

return (count);
}

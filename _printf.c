#include "main.h"
#include "stdio.h"
#include "stdarg.h"
#include <unistd.h>

/**
 * _printf - function
 * @format: param
 * @...: param
 *
 * Return: 0 success
*/
int _printf(const char *format, ...)
{
	char *string;
	char character;
	int i, j;
	unsigned int count_out = 0;
	va_list args_l;

	if (!format)
		return (-1);
	
	va_start(args_l, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			character = va_arg(args_l, int);
			_putchar(character);
			count_out++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			string = va_arg(args_l, char*);
			count_out += _strlen(string);
			for (j = 0; string[j] != '\0'; j++)
				_putchar(string[j]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar(format[i]);
			count_out++;
			i++;
		}
		else if (format[i] == '%' && (format[i + 1] != 'c' || format[i + 1] == 's' || format[i + 1] != '%'))
		{
			_putchar(format[i + 1]);
			count_out++;
			i++;
		}
		else
		{
			_putchar(format[i]);
			count_out++;
		}
	}

	va_end(args_l);
	write(1, '\0', 1);
	return (count_out);
}

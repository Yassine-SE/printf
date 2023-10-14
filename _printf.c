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
	char specifiers[] = {'c', 's'};
	unsigned int count_sp = 0, count_out = 0;
	va_list args_l;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; i < 2; j++)
			{
				if (format[i + 1] == specifiers[j])
					count_sp++;
			}
		}
	}

	va_start(args_l, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			character = va_arg(args_l, int);
			write(1, &character, 1);
			count_out++;
			i = i + 2;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			string = va_arg(args_l, char*);
			count_out += _strlen(string);
			for (j = 0; string[j] != '\0'; j++)
			{
				write(1, &string[j], 1);
			}
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			count_out++;
		}
	}

	va_end(args_l);
	write(1, '\0', 1);
	return (count_out);
}

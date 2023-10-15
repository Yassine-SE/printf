#include "main.h"

/**
 * _printf - function
 * @format: param
 * @...: param
 *
 * Return: 0 success
*/
int _printf(const char *format, ...)
{
	int count_out = 0;
	va_list args_l;

	if (!format)
		return (-1);

	va_start(args_l, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count_out++;
			format++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (count_out);

			if (*format == '%')
			{
				count_out++;
				write(1, format, 1);
			}
			else if (*format == 'c')
			{
				char character = va_arg(args_l, int);
				count_out++;
				write(1, &character, 1);
			}
			else if (*format == 's')
			{
				char *string = va_arg(args_l, char*);
				int str_len = _strlen(string);
				count_out += str_len;
				write(1, string, str_len);
			}
			format++;
		}
	}
	va_end(args_l);
	return (count_out);
}

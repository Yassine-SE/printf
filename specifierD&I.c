#include "main.h"

/**
 * specifier - Function
 * @fmt_str: param
 * @count: param
 * @args_l: param
 *
 * Return: Always 0
 */
int specifierDI(char *fmt_str, int count, va_list args_l)
{
	int count_out = count;

	if (*fmt_str == '%')
	{
		count_out++;
		write(1, fmt_str, 1);
	}
	else if (*fmt_str == 'd')
	{
		char character = va_arg(args_l, int);

		count_out++;
		write(1, &character, 1);
	}
	else if (*fmt_str == 'i')
	{
		char *string = va_arg(args_l, char*);
		int str_len = 0;

		if (!string)
			string = "(null)";
		str_len = strlen(string);
		count_out += str_len;
		write(1, string, str_len);
	}
	else
		write(1, fmt_str, 1);
	return (count_out);
}
#include "main.h"

/**
 * specifier_char - Function
 * @fmt_str: param
 * @count: param
 * @args_l: param
 *
 * Return: Always 0
 */
int specifier_char(char *fmt_str, int count, va_list args_l)
{
	int count_out = count;

	if (*fmt_str == 'c')
	{
		char character = va_arg(args_l, int);

		count_out++;
		write(1, &character, 1);
	}
	else if (*fmt_str == 's')
	{
		char *string = va_arg(args_l, char*);
		int str_len = 0;

		if (!string)
			string = "(null)";
		str_len = strlen(string);
		count_out += str_len;
		write(1, string, str_len);
	}
	else if (*fmt_str == '%')
	{
		count_out++;
		write(1, fmt_str, 1);
	}
	else
		write(1, fmt_str, 1);
	return (count_out);
}

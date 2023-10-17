#include "main.h"

/**
 * 
 * 
 * 
 */

int _printf(const char *format, ...)
{
  int count_out = 0;
	char *fmt_str;
	va_list args_l;

  if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args_l, format);
	fmt_str = (char *)format;
  while (*fmt_str)
  {
		if (*fmt_str != '%')
		{
			write(1, fmt_str, 1);
			count_out++;
		}
    else
		{
			fmt_str++;
			if (!fmt_str)
				return (-1);
			count_out = specifier(fmt_str, count_out, args_l);
		}

}
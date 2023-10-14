#include "main.h"
#include "stdio.h"
#include "stdarg.h"

/**
 * _printf - function
 * @format: param
 * @...: param
 *
 * Return: 0 success
*/
int _printf(const char *format, ...)
{
	int i, j;
	char specifiers[] = {'c', 's'};
	unsigned int count_sp = 0;

	/* Loop through the "format" */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* Check for specifiers "%" */
		if (format[i] == '%')
		{
			/* Count specifiers */
			count_sp++;
		}
	}
}

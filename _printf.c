#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    char *string;
    char character;
    int i, j;
    int count_out = 0;
    va_list args_l;

    if (!format)
        return (-1);

    va_start(args_l, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; // Move past '%'

            if (format[i] == 'c')
            {
                character = va_arg(args_l, int);
                _putchar(character);
                count_out++;
            }
            else if (format[i] == 's')
            {
                string = va_arg(args_l, char *);
                if (string == NULL)
                    string = "(null)";
                while (*string)
                {
                    _putchar(*string);
                    count_out++;
                    string++;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count_out++;
            }
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count_out += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count_out++;
        }
    }

    va_end(args_l);
    return (count_out);
}
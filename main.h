#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int specifier(char *fmt_str, int count, va_list args_l);
//int specifierDI(char *fmt_str, int count, va_list args_l);

#endif

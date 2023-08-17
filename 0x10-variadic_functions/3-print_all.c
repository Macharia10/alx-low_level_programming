#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on format specifiers.
 * @format: A string of format specifiers.
 *
 * @...: The variable arguments list.
 */
void print_all(const char * const format, ...)
{
	int i = 0, printed = 0;
	char c, *s;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				c = (char) va_arg(args, int);
				printf("%c", c);
				printed = 1;
				break;
			case 'i':
				printf("%s%d", printed ? ", " : "", va_arg(args, int));
				printed = 1;
				break;
			case 'f':
				printf("%s%f", printed ? ", " : "", (float) va_arg(args, double));
				printed = 1;
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					printf("%s(nil)", printed ? ", " : "");
				else
				{
					printf("%s%s", printed ? ", " : "", s);
					printed = 1;
					break;
				}
				default:
					break;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

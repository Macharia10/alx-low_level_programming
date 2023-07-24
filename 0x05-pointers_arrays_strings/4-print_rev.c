#include "main.h"

/**
 * print_rev - function that prints a string in reverse, followed by a newline
 * @s: character to check
 */
void print_rev(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	s--;

	for (int i = length; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar("\n");
}
}

#include "main.h"
#include <stdio.h>
/**
 * print_rev - function that prints a string in reverse, followed by a newline
 * @s: character to check
 */
void print_rev(char *s)
{
	int j = 0;

	while (s[j] != '\0')
	{
		j++;
	}

	for (j -= 1; j >= 0; j--)
	{
		_putchar(s[j]);
	}

	_putchar('\n');
}

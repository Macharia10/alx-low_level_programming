#include "main.h"

/**
 * puts2 - a function that prints every character of a string starting
 * with the first charcter
 * @str: input
 * Return: input
 */
void puts2(char *str)
{
	int a;
	int b = 0;

	while (str[b] != '\0')
	{
		b++;
	}

	for (a = 0; a < b; a += 2)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}

#include "main.h"

/**
 * puts2 - a function that prints every character of a string starting
 * with the first charcter
 * @str: input
 * Return: input
 */
void puts2(char *str)
{
	int length = 0;
	int t = 0;
	char *y;

	while (*y != '\0')
	{
		y++;
		length++;
	}
	t = lenth - 1;

	for (int i = 0; i <= t; i++)
	{
		if (i % 2 == 0)
		{
			_putchar(str[0]);
		}
	}
	_putchar('\n');
}

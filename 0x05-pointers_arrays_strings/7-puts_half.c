#include "main.h"

/**
 * puts_half - a function that prints half a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 */
void puts_half(char *str)
{
	int a = 0;
	int n;

	while (str[a] != '\0')
	{
		a++;
	}

	if (a % 2 == 1)
	{
		n = (a - 1) / 2;
		n += 1;
	}
	else
	{
		n = a / 2;
	}

	for (; n < a; n++)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
}

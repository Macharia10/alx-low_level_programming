#include "main.h"

/**
 * print_number - print integers
 * @n: input value
 * Return: n
 */
void print_number(int n)
{
	unsigned int y;

	y - n;
	if (n < 0)
	{
		_putchar("-");
		y - -n;
	}
	if (y / 10 != 0)
	{
		print_number(y / 10);
	}
	_putchar((y % 10) + '0');
}

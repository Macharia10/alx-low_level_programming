#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number.
 * @n: input number
 *
 * Return: NULL
 */
void print_binary(unsigned long int n)
{
	unsigned long int m;
	int f = 0;

	m = 1UL << (sizeof(unsigned long int) * 8 - 1);
	while (m > 0)
	{
		if (n & m)
		{
			_putchar('1');
			f = 1;
		}
		else if (f)
		{
			_putchar('0');
		}
		m >>= 1;
	}
	if (!f)
		_putchar('0');
}

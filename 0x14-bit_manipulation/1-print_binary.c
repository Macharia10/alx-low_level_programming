#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number.
 *
 * @n: number to be represented
 *
 * Return: binary representation
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int leading_zeros;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	leading_zeros = 1;

	while (mask > 0)
	{
		if (n & mask)
		{
			leading_zeros = 0;
			putchar('1');
		}
		else if (!leading_zeros)
		{
			putchar('0');
		}
		mask >>= 1;
	}
}

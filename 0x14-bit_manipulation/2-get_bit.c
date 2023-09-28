#include "main.h"

/**
 * get_bit - func that returns the value of a bit at a given index.
 * @n: number input
 * @index: index to be returned
 *
 * Return: value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index;

	if (n & mask)
		return (1);
	else
		return (0);
}

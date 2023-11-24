#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: input number
 * @index: index, starting from 0 of the bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1UL << index;

	*n |= m;

	if (index >= sizeof(unsigned long int) * 8 || n == NULL)
		return (-1);

	return (1);
}

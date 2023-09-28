#include "main.h"

/**
 * get_endianness - func that checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int val = 1;
	char *byte = (char *)&val;

	if (*byte == 1)
		return (1);
	else
		return (0);
}

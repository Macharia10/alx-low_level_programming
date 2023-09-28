#include "main.h"

/**
 * binary_to_uint - a func that converts a binary number to an unsigned int
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in string
 * b that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int responce = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		responce = responce * 2 + (*b - '0');
		b++;
	}
	return (responce);
}
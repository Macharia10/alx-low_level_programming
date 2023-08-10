#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * *malloc_checked - function that allocates memory using malloc
 * @b: number of bytes
 *
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(98);
	}
	return (ptr);
}

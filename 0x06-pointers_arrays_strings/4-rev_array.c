#include "main.h"

/**
 * reverse_array - reverse the content of an array of integers
 * @a: array
 * @n: number of element in array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int j, b;

	for (j = 0; j < n--; j++)
	{
		b = a[j];
		a[j] = a[n];
		a[n] = b;
	}
}

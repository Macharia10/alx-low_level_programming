#include "function_pointers.h"

/**
 * int_index - function that searches for an integer.
 * @array: array to check
 * @size: size of the array
 * @cmp: pointer function
 *
 * Return: -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

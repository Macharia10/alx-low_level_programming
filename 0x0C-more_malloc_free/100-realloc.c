#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *_realloc - function that reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: old memory
 * @new_size: new memory
 *
 * Return: null
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	copy_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, copy_size);

	free(ptr);

	return (new_ptr);
}

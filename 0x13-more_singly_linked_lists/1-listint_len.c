#include "lists.h"

/**
 * listint_len - function that returns the number of elements
 * in a linked list
 * @h: pointer to nodes
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t no_of_elements = 0;

	while (h != NULL)
	{
		no_of_elements++;
		h = h->next;
	}
	return (no_of_elements);
}

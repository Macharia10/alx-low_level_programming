#include "lists.h"

/**
 * print_listint - function that prints all the elements of a listint_t list.
 * @h: pointer to nodes
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t no_of_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		no_of_nodes++;
	}
	return (no_of_nodes);
}

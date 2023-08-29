#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of a list.
 * @head: pointer to node
 * @index: current index of the linked list
 *
 * Return: nth node of a list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL && i < index; i++)
	{
		current = current->next;
	}
	return (current);
}

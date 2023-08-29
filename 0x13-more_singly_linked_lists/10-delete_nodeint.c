#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index of a list
 * @head: pointer to pointer of head to node
 * @index: index of a node
 *
 * Return: 1 on success -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous, *temp;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	previous = NULL;

	for (i = 0; current != NULL && i < index; i++)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
	{
		return (-1);
	}

	previous->next = current->next;
	free(current);

	return (1);

}

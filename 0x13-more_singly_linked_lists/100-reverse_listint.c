#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: pointer to pointer to head node
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous, *current, *next;

	previous =  NULL;
	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;

	return (*head);
}

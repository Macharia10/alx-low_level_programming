#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t linked
 * list, and returns the head node’s data (n).
 * @head: pointer to pointer to head of a node
 *
 * Return: data of the deleted node
 */
int pop_listint(listint_t **head)
{
	int d;
	listint_t *temp;

	if (*head == NULL)
	{
		return (0);
	}

	d = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (d);
}

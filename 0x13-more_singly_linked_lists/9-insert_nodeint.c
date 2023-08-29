#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 * at a given position
 * @head: pointer to head of node
 * @idx: node index
 * @n: number of nodes
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *n_node, *current;
	unsigned int i;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}
	n_node->n = n;

	if (idx == 0)
	{
		n_node->next = *head;
		*head = n_node;
		return (n_node);
	}

	current = *head;

	for (i = 0; current != NULL && i < idx -  1; i++)
	{
		current = current->next;
	}

	if (current == NULL)
	{
		free(n_node);
		return (NULL);
	}
	n_node->next = current->next;
	current->next = n_node;

	return (n_node);
}

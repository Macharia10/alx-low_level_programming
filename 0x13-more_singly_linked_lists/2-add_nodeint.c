#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning of a list
 * @head: head of a node file
 * @n: number of nodes
 *
 * Return: address of the new element, NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *n_node;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}

	n_node->n = n;
	n_node->next = *head;
	*head = n_node;

	return (n_node);
}

#include "lists.h"

/**
 * add_node_end - add a new node at the end of a list
 * @head: pointer to pointer to the head of the list
 * @str: string to be duplicated
 *
 * Return: address of the new element, or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_nodes;
	list_t *list_nodes;
	size_t len = 0;

	new_nodes = malloc(sizeof(list_t));
	if (new_nodes == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	new_nodes->str = strdup(str);
	new_nodes->len = len;
	new_nodes->next = NULL;
	if (*head == NULL)
	{
		*head = new_nodes;
		return (new_nodes);
	}
	list_nodes = *head;
	while (list_nodes->next != NULL)
	{
		list_nodes = list_nodes->next;
	}
	list_nodes->next = new_nodes;
	return (new_nodes);
}

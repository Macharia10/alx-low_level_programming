#include <stddef.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the head pointer of the list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	char *str_copy;
	list_t *new_node;

	if (str == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	str_copy = strdup(str);
	if (str_copy == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = str_copy;
	new_node->len = 0;
	while (str[new_node->len] != '\0')
	{
		new_node->len++;
	}
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}


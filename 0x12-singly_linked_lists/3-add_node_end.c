#include "lists.h"

/**
* add_node_end - adds node to end of a list
*
* @head: pointer to pointer to head of list
* @str: string to copy to node
* Return: address of new element or NULL if failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nod;
	list_t *copy;
	int i;

	if (!head)
		return (NULL);
	nod = malloc(sizeof(list_t));
	if (!nod)
	return (NULL);
	if (str)
		nod->str = strdup(str);
	nod->next = NULL;
	for (i = 0; *(str + i);)
		i++;
	nod->len = i;
	if (!(*head))
	{
		*head = nod;
		return (nod);
	}
	copy = *head;
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = nod;
	return (nod);
}

#include "lists.h"

/**
* free_list - free a linked list
*
* @head: the head of the list to free
*/
void free_list(list_t *head)
{
	list_t *current;
	list_t *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}

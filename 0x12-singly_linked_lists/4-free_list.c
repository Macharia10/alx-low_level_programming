#include "lists.h"

/**
* free_list - free a linked list
*
* @head: the head of the list to free
* Return: void
*/
void free_list(list_t *head)
{
	list_t *curr;
	list_t *next;

	curr = head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->str);
		free(curr);
		curr = next;
	}
}

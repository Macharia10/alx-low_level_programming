#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: pointer to pointer to head node
 *
 * Return: size of the list free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t s = 0;
	listint_t *loopnode = find_listint_loop(*h);
	listint_t *temp;

	while (*h && ((*h != loopnode) || (loopnode == NULL)))
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		s++;

		if (*h == loopnode)
		{
			if (loopnode == loopnode->next)
			{
				free(*h);
				break;
			}
			s++;
			temp = (*h)->next;
			free(*h);
			*h = temp;
			loopnode = NULL;
		}
	}
	*h = NULL;
	return (s);
}

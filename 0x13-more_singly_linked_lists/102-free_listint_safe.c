#include "lists.h"

/**
 * find_listint_loop_p - find a loop in linked list
 * @head: list to search
 * Return: address where the loop starts or returns, NULL if no loop
 */
listint_t *find_listint_loop_p(listint_t *head)
{
	listint_t *star, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (star = head; star != end; star = star->next)
		{
			if (star == end->next)
				return (end->next);
		}
	}
	return (NULL);
}

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: pointer to pointer to head node
 *
 * Return: size of the list free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t s = 0;
	listint_t *loopnode = find_listint_loop_p(*h);
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

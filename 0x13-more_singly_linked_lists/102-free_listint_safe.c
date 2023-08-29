#include "lists.h"

/**
 * find_listint_loop_p - find a loop in linked list
 * @head: list to search
 * Return: address where the loop starts or returns, NULL if no loop
 */
listint_t *find_listint_loop_p(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (slow);
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
	int loop = 1;

	if (h == NULL || *h == NULL)
		return (0);

	for (s; (*h != loopnode || loop) && *h != NULL; *h = next)
	{
		s++;
		next = (*h)-next;

		if (*h == loopnode && loop)
		{
			if (loopnode == loopnode->next)
			{
				free(*h);
				break;
			}
			s++;
			next = next->next;
			free((*h)->next);
			loop = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (s);
}

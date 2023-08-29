#include "lists.h"

/**
 * find_listint_loop_l - find to loop a linked list
 * @head: linked list to search
 * Return: address of node where loop starts or returns, NULL if no loop
 */
listint_t *find_listint_loop_l(listint_t *head)
{
	listint_t *ptr, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (ptr = head; ptr != end; ptr = ptr->next)
		{
			if (ptr == end->next)
				return (end->next);
		}
	}
	return (NULL);
}

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: pointer to head node
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *loop = find_listint_loop_l((listint_t *)head);
	size_t len = 0;

	while (head && (head != loop || loop == NULL))
	{
		printf("[%p] %d\n", (void *)head, head->n);
		len++;
		head = head->next;
	}
	if (loop)
	{
		printf("->[%p] %d\n", (void *)head, head->n);
		exit(98);
	}
	return (len);
}

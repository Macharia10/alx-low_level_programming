#include "lists.h"

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: pointer to head node
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *loop = find_listint_loop((listint_t *)head);
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

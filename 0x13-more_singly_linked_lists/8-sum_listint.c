#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n) of a list
 * @head: pointer to head node
 *
 * Return: sum of dat(n)
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

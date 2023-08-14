#include <stdio.h>
#include "dog.h"
#include <stddef.h>

/**
 * print_dog - Prints the elements of a struct dog
 * @d: Pointer to the struct dog to be printed
 *
 * If an element is NULL, "(nil)" is printed instead.
 * If d is NULL, nothing is printed.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}


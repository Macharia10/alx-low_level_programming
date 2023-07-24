#include "main.h"
#include <stdio.h>

/**
 * print_rev - function that prints a string in reverse, followed by a newline
 * @s: character to check
 */
void print_rev(char *s)
{
	int length = strlen(s);

	for (int i = length - 1; i >= 0; i--)
		printf("%c", s[i]);

	printf("\n");
}
}

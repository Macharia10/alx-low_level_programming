#include "main.h"
#include <stdio.h>

/**
 * print_rev - function that prints a string in reverse, followed by a newline
 * @s: character to check
 */
void print_rev(char *s)
{
	/*Find the length of the string*/
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	/* Print the string in reverse*/
	for (int i = length - 1; i >= 0; i--)
		printf("%c", s[i]);

	printf("\n");
}
}

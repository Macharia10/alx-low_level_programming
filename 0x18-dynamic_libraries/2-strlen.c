#include "main.h"

/**
 * _strlen - a function that returns the lenght of the string
 * @s: character to check
 * Return: 0 (success)
 */
int _strlen(char *s)
{
	int length = 0;

	/* Loop through the string until the null terminator is reached*/
	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}


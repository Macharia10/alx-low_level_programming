#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *_strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: string input
 *
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	s = (char *)malloc((strlen(str) + 1) * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}

	strcpy(s, str);
	return (s);

}

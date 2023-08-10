#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *string_nconcat - function that concatenates two strings.
 * @s1: input string
 * @s2: input string
 * @n: number of bytes
 *
 * Return: concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int s1_len, s2_len;

	if (s1 == NULL && s2 == NULL)
		return ("");

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	if (n >= s2_len)
	{
		n = s2_len;
	}
	result = (char *)malloc(s1_len + n + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	strncpy(result, s1, s1_len);
	strncpy(result + s1_len, s2, n);

	result[s1_len + n] = '\0';

	return (result);
}

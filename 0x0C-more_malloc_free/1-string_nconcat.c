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
	char *res = NULL;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i, j;

	while (s1 == NULL)
		s1 = "";
	while (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	if (n >= len2)
		n = len2;
	res = malloc(sizeof(char) * (len1 + n + 1));

	if (res == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		res[i] = s1[i];
	}
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

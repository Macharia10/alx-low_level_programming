#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *str_concat - function that concatenates two strings.
 * @s1: input string
 * @s2: input string
 *
 * Return: reult
 */
char *str_concat(char *s1, char *s2)
{
	size_t len_s1, len_s2, length;
	char *str;

	if (s1 == NULL || s2 == NULL)
	{
		return ("");
	}
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	length = len_s1 + len_s2 + 1;
	str = (char *)malloc(length * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	strcpy(str, s1);
	strcpy(str, s2);

	return (str);

}

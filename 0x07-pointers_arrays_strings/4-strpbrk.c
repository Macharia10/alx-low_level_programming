#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: input
 * @accept: input
 * Return: pointer in bytes
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		for (char *a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				return (s);
			}
		}
		s++;
	}
	return (NULL);
}

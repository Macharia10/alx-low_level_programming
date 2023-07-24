#include "main.h"

/**
 * rev_string - a function that reverses a string
 * @s: input string
 * Return: string in reverse
 */
void rev_string(char *s)
{
	char rev;
	int len = 0;
	int index = 0;

	while (s[index++])
		len++;
	for (index = len - 1; index >= len / 2; index--)
	{
		rev = s[index];
		s[index] = s[len - index - 1];
		s[len - index - 1] = rev;
	}
}

#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *argstostr - function that concatenates all the arguments of your program.
 * @ac: input
 * @**av: pointer char
 *
 * Return: concatenated argument
 */
char *argstostr(int ac, char **av)
{
	char *res;
	int length = 0;
	int i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		length += strlen(av[i]) + 1;
	}
	res = (char *)malloc(length * sizeof(char));

	if (res == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			res[k++] = av[i][j];
		res[k++] = '\n';
	}

	res[k] = '\0';

	return (res);
}

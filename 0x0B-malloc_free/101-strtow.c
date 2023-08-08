#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * **strtow - function that splits a string into words.
 * @str: string input
 *
 * Return: pointer to array
 */
char **strtow(char *str)
{
	int count = 0;
	int word = 0;
	int i;
	char *ptr = str;
	char **words;
	char *token;

	if (str == NULL || *str == '\0')
		return (NULL);
	/*word count*/
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		ptr++;
	}
	/*allocate memory*/
	words = (char **)malloc((count + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);
	/*extract words and store them in an array*/
	token = strtok(str, " ");

	while (token != NULL)
	{
		words[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	/*set last element to null*/
	words[i] = NULL;

	return (words);
}

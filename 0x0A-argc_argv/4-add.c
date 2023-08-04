#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - program that adds positive numbers.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int m;
	unsigned int j, sum = 0;
	char *h;

	if (argc > 1)
	{
		for (m = 1; m < argc; m++)
		{
			h = argv[m];

			for (j = 0; j < strlen(h); j++)
			{
				if (h[j] < 48 || h[j] > 57)
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(h);
			h++;
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}

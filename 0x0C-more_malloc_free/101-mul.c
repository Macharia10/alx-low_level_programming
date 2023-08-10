#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * is_number - checks if input is a number
 * @num: input integer
 *
 * Return: boolean
 */
bool is_number(const char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}

/**
 * multiply - function to multiply the numbers
 * @num1: pointer to integer
 * @num2: pointer to integer
 *
 * Return: result
 */
void multiply(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int res_len = len1 + len2;
	int *result;
	int start = 0;
	int i, j;

	result = (int *)calloc(sizeof(int), res_len);

	if (result == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}
	while (start < res_len - 1 && result[start] == 0)
	{
		start++;
	}

	for (i = start; i < res_len; i++)
	{
		printf("%d", result[i]);
	}

	printf("\n");
	free(result);

}

#include <stdio.h>

/**
 * main - a program that prints alphabet in lowerC and then upperC
 * Return: 0 (Success)
 */
int main(void)
{
	int n = 97;
	int j = 65;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	while (j <= 90)
	{
		putchar(j);
		j++;
	}
	putchar('\n');
	return (0);
}

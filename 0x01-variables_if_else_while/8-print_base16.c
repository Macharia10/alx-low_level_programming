#include <stdio.h>

/**
 * main - a program that prints all numbers of base 16 in lowercase
 * Return: 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 15; i++)
	{
	if (i < 10)
	{
		putchar('0' + i);
	}
	else
	{
		putchar('a' + i - 10);
	}
	}
	putchar('\n');
	return (0);
}

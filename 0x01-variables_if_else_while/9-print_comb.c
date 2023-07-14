#include <stdio.h>

/**
 * main - a program that prints all combinations of single digits
 * Return: 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 9; i++)
	{
		putchar('0' + i);
		putchar(',');
		putchar(' ');
	}

	putchar('9');
	putchar('\n');
	return (0);
}

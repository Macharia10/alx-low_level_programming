#include <stdio.h>

/**
 * main - a program that prints lowercase alphabet in reverse
 * Return: 0 (success)
 */
int main(void)
{
	int a = 97;
	int z = 122;
	int i;

	for (i = z; i >= a; i--)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}

#include <stdio.h>

/**
 * main - a program that prints alphabet in lC except q and e
 * Return: 0 (success)
 */
int main(void)
{
	int a = 97;

	while (a <= 122)
	{
		if (a == 101 || a == 113)
		{
			a++;
			continue;
		}
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}

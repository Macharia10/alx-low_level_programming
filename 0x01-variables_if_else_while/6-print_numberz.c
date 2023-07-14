#include <stdio.h>

/**
 * main - a program that print all single digits of base 10
 * Return: 0 (success)
 */
int main(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
		/*convert number to character and print*/
		putchar('0' + a);
	}
	putchar('\n');
	return (0);
}

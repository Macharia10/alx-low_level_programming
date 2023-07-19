#include <stdio.h>

/**
 * main - a program that prints the first 98 fibonacci
 * starting with 1 and 2
 * Return: Fibonacci numbers
 */
int main(void)
{
	int n = 98;
	int fibonacci[n];

	fibonacci[0] = 1;
	fibonacci[1] = 2;

	for (int i = 2; i < n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	printf("The first %d Fibonacci numbers are:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("%d", fibonacci[i]);
	}
	return (0);
}

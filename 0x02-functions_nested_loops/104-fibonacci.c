#include <stdio.h>

/**
 * printFibonacci - a function that calculates and prints the first n
 * fib numbers separated with a comma and space
 * @n: character to check
 */
void printFibonacci(int n)
{
	int a = 1, b = 2;

	printf("%d, %d, ", a, b);

	for (int i = 2; i < n; i++)
	{
		int c = a + b;

		printf("%d%s", c, (i == n - 1) ? "\n" : ", ");
		a = b;
		b = c;
	}
}
/**
 * main - a function that calls printFibonacci function.
 * Return: 0 (success)
 */
int main(void)
{
	int n = 98;

	printFibonacci(n);

	return (0);
}

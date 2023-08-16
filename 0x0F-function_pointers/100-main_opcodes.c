#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - print the opcodes of this program
 * @a: address of the  main function
 * @n: number of bytes to print
 *
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	int a;

	for (a = 0; a < n; a++)
	{
		printf("%.2hhx", a[i]);
		if (a < n - 1)
			printf(" ");
	}
	printf("\n");

}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 or 2 on failure
 */
int main(int argc, char **argv)
{
	int j;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	j = atoi(argv[1]);

	if (j < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, j);
	return (0);
}

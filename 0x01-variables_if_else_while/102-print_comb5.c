#include <stdio.h>

/**
 * main - a program that prints all combinations of two two-digit numbers
 * Return: 0 (success)
 */
int main(void)
{
	int i;
	int j;
	int comma = 0;

	for (i = 0; i < 100; i++)
	{
		for (j = i; j < 100; j++)
		{
			int a = i / 10;
			int b = i % 10;
			int c = j / 10;
			int d = j % 10;

			if (a != c || b != d)
			{
				/*check if you nedd command and space*/
				if (comma)
				{
					putchar(',');
					putchar(' ');
				}
				else
				{
					comma = 1;
				}
				/*print the first digit of the first number*/
				putchar(a + '0');
				/*print the second digit of the first number*/
				putchar(b + '0');
				/*print space*/
				putchar(' ');
				/*print the first digit of the second numbe*/
				putchar(c + '0');
				/*print the second digit of the second number*/
				putchar(d + '0');

			}
		}
	}
	return (0);
}

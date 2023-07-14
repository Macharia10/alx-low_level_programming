#include <stdio.h>

/**
 * main - a program that prints alphabet in lowercase followed by newline
 * Return: 0 (Success)
 */
int main(void)
{
	/*ASCII value of 'a'*/
	int start = 97;

	/*ASCII value of 'z'*/
	int end = 122;
	int i;

	for (i = start; i <= end; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}

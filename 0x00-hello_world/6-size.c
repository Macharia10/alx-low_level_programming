#include <stdio.h>

/**
 * main - A program that prints the size of various types on the computer
 * Return: 0 (Success)
 */
int main(void)
{
	char a;
	int i;
	long int c;
	long long int l;
	float f;

printf("Size of char: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("Size of int: %lu byte(s)\n", (unsigned long)sizeof(i));
printf("Size of long int: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("Size of long long int: %lu byte(s)\n", (unsigned long)sizeof(l));
printf("Size of float: %lu byte(s)\n", (unsigned long)sizeof(f));

return (0);
}

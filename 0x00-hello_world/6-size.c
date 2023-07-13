#include <stdio.h>

/**
 * main - A program that prints the size of various types on the computer
 * Return: 0 (Success)
 */
int main(void)
{
printf("Size of char: %zu bytes\n", (unsigned long)sizeof(char));
printf("Size of int: %zu bytes\n", (unsigned long)sizeof(int));
printf("Size of long int: %zu bytes\n", (unsigned long)sizeof(long int));
printf("Size of long long int: %zu bytes\n", (unsigned long)sizeof(long long int));
printf("Size of float: %zu bytes\n", (unsiged long)sizeof(float));

return (0);
}

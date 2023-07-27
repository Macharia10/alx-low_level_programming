#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints buffer
 * @b: buffer
 * @size: size
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int offset, i, j;

	offset = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (offset < size)
	{
		printf("%08x: ", offset);
		for (i = 0; i < 10; i++)
		{
			if (offset + i < size)
				printf("%02x", *(b + offset + i));
			else
				printf(" ");
			if (i % 2)
			{
				printf(" ");
			}
		}
		for (i = 0; i < 10; i++)
		{
			if (offset + i >= size)
				break;

			int c = *(b + offset + i);

			if (c >= 32 && c <= 126)
				printf("%c", c);
			else
				print(".");
	}
	printf("\n");
	offset += 10;
	}
}

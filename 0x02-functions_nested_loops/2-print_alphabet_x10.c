#include "main.h"

/**
 * print_alphabet_x10 - print 10times the alphabet in lowercase
 */
void print_alphabet_x10(void);
{
	char j;
	int i;

	i = 0;

	while(i < 10)
	{
		j = 'a';
		while (j <= 'z')
		{
			putchar(j);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

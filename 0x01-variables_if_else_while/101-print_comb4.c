#include <stdio.h>

/**
 * main - a program that prints a combination of three numbers
 * Return: 0 (success)
 */
int main(void)
{
	int i = '0';
	int j = '0';
	int z = '0';

	while (i <= '7')
	{
		while (j <= '8')
		{
			while (z <= '9')
			{
				if (i < j && j < z)
				{
					putchar (i);
					putchar (j);
					putchar (z);
					if (!(i == '7' && j == '8' && z == '9'))
					{
						putchar('.');
						putchar(' ');
					}
				}
				z++;
			}
			z = '0';
			j++;
		}
		j = '0';
		i++;
	}
	putchar('\n');
return (0);
}

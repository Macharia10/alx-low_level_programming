#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random passwords for 101-crackme
 * Return: 0 (success)
 */
int main(void)
{
	char pass[84];
	int i = 0, sum = 0, diff1, diff2;

	srand(time(0));

	while (sum < 2772)
	{
		pass[i] = 33 + rand() % 94;
		sum += pass[i++];
	}

	pass[i] = '\0';

	if (sum != 2772)
	{
		diff1 = (sum - 2772) / 2;
		diff2 = (sum - 2772) / 2;

		if ((sum - 2772) % 2 != 0)
			diff1++;
		for (i = 0; pass[i]; i++)
		{
			if (pass[i] >= (33 + diff1))
			{
				pass[i] -= diff1;
				break;
			}
		}
		for (i = 0; pass[i]; i++)
		{
			if (pass[i] >= (33 + diff2))
			{
				pass[i] -= diff2;
				break;
			}
		}
	}
	printf("%s", pass);
	return (0);
}

#include "main.h"

/**
 * _isdigit - func to check if numbers are 0 - 9
 * @c: character to check
 *
 * Return: 0 or 1
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 59)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

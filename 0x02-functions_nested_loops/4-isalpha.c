#include "main.h"

/**
 * int _isalpha - function that checks for alphabet character
 * Return: 1 if lowercase, letter or uppercase 0 otherwise
 */
int _isalpha(int c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

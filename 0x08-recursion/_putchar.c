#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: charcter to print
 * Return: 1 (sucess)
 * On error, -1 is returned 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

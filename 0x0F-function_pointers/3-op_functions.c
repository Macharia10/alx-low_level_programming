#include "3-calc.h"

/**
 * op_add - return the sum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of the integers
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns the difference of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: Difference of two integers
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns the multiplication of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: Multiplication of two integers
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns the division of two integers
 * @a: first integers
 * @b: second integer
 *
 * Return: division
 */
int op_div(int a, int b)
{
	if (b == 0)
		return (-1);

	return (a / b);
}
/**
 * op_mod - returns the modulus of two numbers
 * @a: first integer
 * @b: second integer
 *
 * Return: modulus of two integers
 */
int op_mod(int a, int b)
{
	if (b == 0)
		return (-1);

	return (a % b);
}

#include "main.h"

/**
 * helpers - function to loop new second variables
 *
 * @n: int args
 * @result: int args
 *
 * Returns: sqaure root
 */

int helpers(int n, int result)
{
	if (result * result == n)
	{
		return (result);
	}
	else if (result * result > n)
	{
		return (-1);
	}
	else
		return (helpers(n, result + 1));
}

/**
 * _sqrt_recursion - naturals squares root of a number
 *
 * @n: int arg
 *
 * Returns: int
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (helpers(n, 0));
}

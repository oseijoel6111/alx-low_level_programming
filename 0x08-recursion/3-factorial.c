#include "main.h"

/**
 * factorial - return the len of a string
 *
 * @n: int args
 *
 * Returns: int
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n > 0)
	{
		return (n * factorial(n - 1));
	}
	return (1);
}


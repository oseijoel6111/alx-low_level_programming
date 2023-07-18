#include "main.h"

/**
 * print_last_digit - Write a function that prints the last digit of a number.
 * @n: argument to be check
 *
 * Return: absolute value of n
 */
int print_last_digit(int n)
{
	int abs;

	abs = n % 10;

	if (abs < 0)
	{
		abs = abs * -1;
	}
	_putchar(abs + '0');
	return (abs);
}


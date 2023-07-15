#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function of the program.
 * It display numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	int num2;

	for (num = 0; num < 10; num++)
	{
		for (num2 = 1; num2 < 10; num2++)
		{
			if (num == num2)
				continue;
			putchar((num % 10) + '0');
			putchar((num2 % 10) + '0');
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}


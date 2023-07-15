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
			if (num < num2)
			{
				putchar(num + '0');
				putchar(num2 + '0');
				if (num == 8 && num2 == 9)
					continue;
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}


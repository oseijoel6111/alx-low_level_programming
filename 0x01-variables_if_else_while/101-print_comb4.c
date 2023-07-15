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
	int num3;

	for (num = 0; num < 10; num++)
	{
		for (num2 = 0; num2 < 10; num2++)
		{
			for (num3 = 0; num3 < 10; num3++)
			{
				if (num < num2 && num2 < num3)
				{
					putchar(num + '0');
					putchar(num2 + '0');
					putchar(num3 + '0');

					if (num == 7 && num2 == 8 && num3 == 9)
						continue;
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}


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

	int fTens, fOnes, sTens, sOnes;

	for (fTens = 0; fTens <= 9; fTens++)
	{
		for (fOnes = 0; fOnes <= 9; fOnes++)
		{
			for (sTens = fTens; sTens <= 9; sTens++)
			{
				int startOnes = (sTens == fTens) ? fOnes + 1 : 0;

				for (sOnes = startOnes; sOnes <= 9; sOnes++)
				{

					if (!(fTens == 9 && fOnes == 9 && sTens == 9 && sOnes == 9))
					{
						putchar(',');
						putchar(' ');
					}

					putchar(fTens + '0');
					putchar(fOnes + '0');
					putchar(' ');
					putchar(sTens + '0');
					putchar(sOnes + '0');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}


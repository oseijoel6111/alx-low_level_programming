#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function of the program.
 * It generates a random number and determines the last digit.
 * Then it prints whether the last digit is greater than 5,
 * less than 6 and not 0, or 0.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}


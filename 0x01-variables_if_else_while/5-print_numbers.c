#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function of the program.
 * prints all single digit numbers of base 10 starting from 0.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	for (letter = 0; letter < 10; letter++)
	{
		printf("%d", letter);
	}
	putchar('\n');

	return (0);
}


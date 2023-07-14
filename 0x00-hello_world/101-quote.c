#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Description: This program writes a string to the standard error stream.
 *
 * Return: 1 (Failure)
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - DoraKorpar, 2015-10-19\n", 59);
	return (1);
}


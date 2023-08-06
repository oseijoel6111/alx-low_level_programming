#include <stdio.h>

/**
 * main - Prints name of program
 *
 * @argc: size of argv array and number of command line arguments
 *
 * @argv: An arrays of sizes argc
 *
 * Returns: 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}


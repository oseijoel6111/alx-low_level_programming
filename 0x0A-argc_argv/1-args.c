#include <stdio.h>

/**
 * main -  Numbers of argument passed
 *
 * @argc: sizes of argv array and number of command line arguments
 *
 * @argv: An arrays of sizes argc
 *
 * Returns: 0
 */

int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", argc - 1);

	return (0);
}


#include <stdio.h>

/**
 * main - Prints all arguments it receives.
 *
 * @argc: size of argv array and number of command line arguments
 *
 * @argv: An arrays of size argc
 *
 * Returns: 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
	printf("%s\n", argv[i]);
	}

	return (0);
}


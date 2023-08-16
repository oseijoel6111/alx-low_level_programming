#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Prints the opcodes of its own main function
 *
 * @argc: The number of arguments
 * @argv: The array of argument strings
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Check if the given byte count is valid */
	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}

	i = 0;
	while (i < atoi(argv[1]))
	{
		printf("%02x", *((unsigned char *)main + i));
		i++;

		/* Print a space between bytes except for the last byte */
		if (i < atoi(argv[1]))
			putchar(' ');
	}
	putchar('\n');

	return (0);
}


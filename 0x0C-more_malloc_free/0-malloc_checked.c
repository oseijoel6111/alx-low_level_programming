#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * *malloc_checked - Allocates memory using malloc.
 * @b: Number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
    void *ptr = malloc(b);

    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}


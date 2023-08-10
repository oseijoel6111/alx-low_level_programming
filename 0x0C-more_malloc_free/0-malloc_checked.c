#include <stdio.h>
#include <stdlib.h>

/**
 * safe_malloc - Allocates memory using malloc with error handling
 * @size: The size of the memory block to allocate
 *
 * This function allocates memory using malloc and checks for allocation success.
 * If memory allocation fails, the function terminates the program with a status value of 98.
 *
 * Return: A pointer to the allocated memory
 */
void *safe_malloc(unsigned int size)
{
    void *ptr;

    /* Attempt to allocate memory */
    ptr = malloc(size);

    /* Check if allocation was successful */
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(98);
    }

    return ptr;
}


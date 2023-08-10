#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails or nmemb/size is 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    size_t total_size;
    void *ptr;

    if (nmemb == 0 || size == 0)
        return NULL;

    total_size = nmemb * size;
    ptr = malloc(total_size);

    if (ptr == NULL)
        return NULL;

    memset(ptr, 0, total_size);

    return ptr;
}


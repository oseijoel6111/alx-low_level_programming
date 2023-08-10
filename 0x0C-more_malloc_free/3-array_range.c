#include <stdlib.h>

/**
 * array_range - Creates an array of integers in the given range.
 *
 * @min: The minimum value of the range (inclusive).
 * @max: The maximum value of the range (inclusive).
 *
 * Return: Pointer to the newly created array of integers, or NULL on failure
 *         or if min > max.
 */
int *array_range(int min, int max)
{
    int *result;
    int size, i;

    if (min > max)
        return NULL;

    size = max - min + 1;
    result = malloc(size * sizeof(int));
    if (result == NULL)
        return NULL;

    for (i = 0; i < size; i++)
        result[i] = min + i;

    return result;
}


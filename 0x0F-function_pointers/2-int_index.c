#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - Searches for an integer in an array.
 *
 * @array: Pointer to an array of integers.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the comparison function.
 *
 * Return: Index of the first element for which the comparison function returns non-zero,
 *         or -1 if no such element is found or if array is NULL.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return -1;

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			return i;
		}
	}

	return -1;
}


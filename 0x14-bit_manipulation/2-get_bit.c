#include "main.h"
#include <stdio.h>

/**
 * get_bit - Get the value of a bit at a given index.
 * @n: Number to evaluate.
 * @index: Index (starting from 0) of the bit we want to get.
 * Return: Value of the bit at the given index, or -1 if error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned long int hold;

    if (index > 64)
        return -1;

    hold = n >> index;

    return (int)(hold & 1);
}


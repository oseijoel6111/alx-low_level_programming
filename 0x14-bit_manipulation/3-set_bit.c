#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the decimal number.
 * @index: Index position to change, starting from 0.
 * Return: 1 if it worked, -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int p;

    if (index > 64)
        return -1;

    for (p = 1; index > 0; index--, p *= 2)
        ;
    *n += p;

    return 1;
}


#include "main.h"
/**
 * swap_int - Swaps two given numbers
 * @a: int pointer
 * @b: int pointer
 * Return: void.
 */
void swap_int(int *a, int *b)
{
int e = *b;
*b = *a;
*a = e;
}


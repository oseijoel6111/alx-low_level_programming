#include "lists.h"
#include <stdio.h>

/**
 * list_len - Return number of elements
 * @h: Points to struct
 * Return: Num of elements
 */
size_t list_len(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return count;
}


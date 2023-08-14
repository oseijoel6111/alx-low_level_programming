/*
 * File: 5-free_dog_alternative.c
 * Auth: Joel
 */

#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees dogs.
 * @d: The dog to be freed.
 */
void free_dog(dog_t *d)
{
    if (d == NULL)
        return;

    if (d->owner != NULL)
    {
        free(d->owner);
        d->owner = NULL;
    }

    if (d->name != NULL)
    {
        free(d->name);
        d->name = NULL;
    }

    free(d);
}


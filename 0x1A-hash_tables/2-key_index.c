#include <stdlib.h>
#include "hash_tables.h"

/**
 * key_index - Get the index of a key in the hash table's array
 * @key: The key to be hashed
 * @size: The size of the array in the hash table
 *
 * Return: The index at which the key/value pair should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_value;

    if (key == NULL || size == 0)
        return (0);

    hash_value = hash_djb2(key);
    return (hash_value % size);
}

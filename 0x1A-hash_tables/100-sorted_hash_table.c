#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table = NULL;
    unsigned long int i = 0;

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = malloc(sizeof(shash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    new_table->shead = NULL;
    new_table->stail = NULL;

    for (i = 0; i < size; i++)
        new_table->array[i] = NULL;

    return (new_table);
}

/**
 * shash_table_set - Add an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key (can be an empty string)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->shead;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            if (current->value == NULL)
                return (0);
            return (1);
        }
        current = current->snext;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->sprev = NULL;
    new_node->snext = ht->shead;

    if (new_node->snext)
        new_node->snext->sprev = new_node;
    else
        ht->stail = new_node;

    ht->shead = new_node;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key from the sorted hash table
 * @ht: The sorted hash table to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element, or NULL if the key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current = ht->shead;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    while (current)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", current->key, current->value);
        first = 0;
        current = current->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current = ht->stail;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    while (current)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", current->key, current->value);
        first = 0;
        current = current->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Delete the sorted hash table and free all allocated memory
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current, *temp;

    if (ht == NULL)
        return;

    current = ht->shead;
    while (current)
    {
        temp = current;
        current = current->snext;
        free(temp->key);
        free(temp->value);
        free(temp);
    }

    free(ht->array);
    free(ht);
}

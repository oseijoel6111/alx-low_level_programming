#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds node to linked list
 * @head: Double Pointer
 * @str: Pointer to struct pointer
 * Return: Address of the new element, or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node = malloc(sizeof(list_t));
    
    if (new_node == NULL)
    {
        return (NULL);
    }

    new_node->len = 0;
    
    while (str[new_node->len] != '\0')
    {
        new_node->len++;
    }
    
    new_node->str = malloc((new_node->len + 1) * sizeof(char));
    
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    
    strcpy(new_node->str, str);
    new_node->next = *head;
    *head = new_node;
    return new_node;
}


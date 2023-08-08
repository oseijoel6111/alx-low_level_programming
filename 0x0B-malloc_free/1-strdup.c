#include <stdlib.h>
#include <string.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory, containing a copy of the string.
 *
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
    char *duplicate;

    if (str == NULL)
        return NULL;

    duplicate = (char *)malloc(strlen(str) + 1);
    if (duplicate == NULL)
        return NULL;

    strcpy(duplicate, str);

    return duplicate;
}


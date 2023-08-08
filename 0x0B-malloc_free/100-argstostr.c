#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *argstostr(int ac, char **av)
{
    int total_length;
    int i, index;
    char *result;

    if (ac == 0 || av == NULL)
        return NULL;

    total_length = 0;
    for (i = 0; i < ac; i++) {
        total_length += strlen(av[i]) + 1; 
    }

    result = (char *)malloc(total_length + 1); 
    if (result == NULL)
        return NULL;

    index = 0;
    for (i = 0; i < ac; i++) {
        strcpy(result + index, av[i]);
        index += strlen(av[i]);
        result[index] = '\n';
        index++;
    }

    result[total_length] = '\0';
    return result;
}


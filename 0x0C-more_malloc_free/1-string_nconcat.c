#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes from s2 to concatenate
 *
 * Return: Pointer to the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len_s1 = 0, len_s2 = 0, i, j;
	char *concatenated;

	/* Treat NULL strings as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;

	/* Adjust n if necessary */
	if (n >= len_s2)
		n = len_s2;

	/* Allocate memory for concatenated string */
	concatenated = malloc(len_s1 + n + 1); /* +1 for null terminator */

	if (concatenated == NULL)
		return (NULL);

	/* Copy s1 to concatenated */
	for (i = 0; i < len_s1; i++)
		concatenated[i] = s1[i];

	/* Concatenate n bytes of s2 to concatenated */
	for (j = 0; j < n; j++, i++)
		concatenated[i] = s2[j];

	/* Add null terminator */
	concatenated[i] = '\0';

	return (concatenated);
}


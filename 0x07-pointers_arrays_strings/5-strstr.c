#include "main.h"

/**
 * _strstr - function that locate a substrings.
 *
 * @needle: char pointers
 * @haystack: char pointers
 *
 * Return: s
 */

char *_strstr(char *haystack, char *needle)
{
	int count;

	for (; haystack[0]; haystack++)
	{
		for (count = 0; haystack[count] == needle[count]; count++)
			;
		if (!(needle[count]))
			return (haystack);
	}
	return (0);
}


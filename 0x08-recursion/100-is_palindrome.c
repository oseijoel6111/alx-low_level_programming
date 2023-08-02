#include "main.h"

/**
 * strlen_rec - Strings lengths
 *
 * @str: chars
 *
 * Return: the integers len
 */

int strlen_rec(char *str)
{
	if (*str)
	{
		str++;

		return (1 + strlen_rec(str));
	}
	return (0);
}

/**
 * helpers_pals - Returns Palindrones
 *
 * @str: char
 *
 * @length: int
 *
 * @count: int
 *
 * Returns: the integer length
 */

int helpers_pals(char *str, int length, int count)
{
	if (count >= length)
	{
		return (1);
	}
	if (str[length] == str[count])
	{
		return (helpers_pals(str, length - 1, count + 1));
	}
	return (0);
}

/**
 * is_palindrome - returs 1 if a string is a palindrome and 0 if not
 *
 * @s: char
 *
 * Return: the integer length
 */

int is_palindrome(char *s)
{
	int length = strlen_rec(s);
	int count = 0;

	return (helpers_pals(s, length - 1, count));
}


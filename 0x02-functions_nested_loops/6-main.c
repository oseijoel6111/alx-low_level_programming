#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function of the program.
 *              It will bsolute value of an integer.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int r;

r = _abs(-1);
printf("%d\n", r);
r = _abs(0);
printf("%d\n", r);
r = _abs(1);
printf("%d\n", r);
r = _abs(-98);
printf("%d\n", r);

return (0);
}


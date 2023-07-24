#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 80

/**
 * main - Generates a random valid password for the program 101-crackme.
 *
 * Description: This program finds a random password whose checksum value
 *              equals 2772. The password is a string of ASCII characters
 *              with values between 48 ('0') and 126 ('~').
 *
 * Return: Always 0 (success).
 */
int main(void)
{
    int sum = 0;        /* Stores the current checksum */
    int random;         /* Holds a randomly generated ASCII character value */
    int counter = 0;    /* Keeps track of the number of characters in the password */

    char password[PASSWORD_LENGTH + 1]; /* The generated password +1 for the null terminator '\0' */

    srand(time(NULL)); /* Seed the random number generator with the current time */

    while (sum < 2772 && counter < PASSWORD_LENGTH)
    {
        /* Generate a random character between ASCII 48 ('0') and ASCII 126 ('~') */
        random = rand() % (126 - 48 + 1) + 48;

        if (random == 127) /* Skip DEL (ASCII 127) as it's not printable */
            continue;

        /* Add the random character to the password and update the checksum */
        if (sum + random <= 2772)
        {
            password[counter++] = random;
            sum += random;
        }
    }

    password[counter] = '\0'; /* Null-terminate the password */

    printf("%s\n", password);

    return 0;
}


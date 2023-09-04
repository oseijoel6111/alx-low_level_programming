#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
    FILE *file;
    char *buffer;
    size_t bytesRead, bytesWritten;

    if (filename == NULL)
        return 0;

    file = fopen(filename, "r");
    if (file == NULL)
        return 0;

    buffer = (char *)malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL)
    {
        fclose(file);
        return 0;
    }

    bytesRead = fread(buffer, sizeof(char), letters, file);
    if (bytesRead == 0)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    buffer[bytesRead] = '\0';

    bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);
    if (bytesWritten != bytesRead)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    free(buffer);
    fclose(file);

    return bytesRead;
}


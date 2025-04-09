/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_catchar
*/

#include <fcntl.h>
#include <stdlib.h>
#include "unistd.h"
#include <sys/stat.h>

char *my_catchar(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    int size = stat(filepath, &sb);
    char *buffer = malloc(sizeof(char) * (sb.st_size + 1));

    if (fd == -1 || size == -1)
        return NULL;
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    close(fd);
    return buffer;
}

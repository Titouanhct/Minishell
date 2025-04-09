/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_cat
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <my.h>

int my_cat(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 4096);

    if (fd == -1)
        return 84;
    read(fd, buffer, 4095);
    write(1, buffer, my_strlen(buffer));
    close(fd);
    return 0;
}

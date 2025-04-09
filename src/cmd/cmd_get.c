/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** get_input
*/

#include "sh.h"

int command_get(char **buffer, size_t *buff_size)
{
    char *shellband = "\033[31m";
    char *tmp;
    char *path = getcwd(NULL, 0);

    *buffer = NULL;
    tmp = my_strcatdup(shellband, path);
    free(path);
    shellband = my_strcatdup(tmp, " | $-> \033[0m");
    free(tmp);
    if (isatty(STDIN_FILENO))
        write(1, shellband, my_strlen(shellband));
    free(shellband);
    return (getline(buffer, buff_size, stdin));
}

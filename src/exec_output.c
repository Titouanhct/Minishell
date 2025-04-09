/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** exec_output
*/

#include "sh.h"

int exec_simple_output(char *file_name)
{
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return -1;
    }
    dup2(fd, STDOUT_FILENO);
    return fd;
}

int exec_double_output(char *file_name)
{
    int fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        perror("open");
        return -1;
    }
    dup2(fd, STDOUT_FILENO);
    return fd;
}

int exec_simple_input(char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("open");
        return -1;
    }
    dup2(fd, STDIN_FILENO);
    return fd;
}

int check_for_redirection(char **args)
{
    int fd = -1;

    for (int x = 0; args[x] != NULL; x++) {
        if (my_strcmp(args[x], ">") == 0 && args[x + 1]) {
            fd = exec_simple_output(args[x + 1]);
            args[x] = NULL;
            break;
        }
        if (my_strcmp(args[x], ">>") == 0 && args[x + 1]) {
            fd = exec_double_output(args[x + 1]);
            args[x] = NULL;
            break;
        }
        if (my_strcmp(args[x], "<") == 0 && args[x + 1]) {
            fd = exec_simple_input(args[x + 1]);
            args[x] = NULL;
            break;
        }
    }
    return fd;
}

void write_in_file(int fd)
{
    int fd2 = -1;
    char buff[1024];
    ssize_t size = read(STDIN_FILENO, buff, sizeof(buff));

    dup2(fd2, STDIN_FILENO);
    close(fd);
    close(fd2);
    while (size > 0) {
        write(fd, buff, size);
        size = read(STDIN_FILENO, buff, sizeof(buff));
    }
}

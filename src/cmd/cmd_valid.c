/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** cmd_valid
*/

#include "sh.h"
#include <sys/stat.h>

static int malloc_buffer(char *dir_name)
{
    DIR *dirp;
    struct dirent *dp;
    int count = 0;

    dirp = opendir(dir_name);
    if (!dirp)
        return 84;
    dp = readdir(dirp);
    while (dp) {
        count++;
        dp = readdir(dirp);
    }
    count++;
    closedir(dirp);
    return count;
}

static char **open_dir(char *dir_name, char **buffer)
{
    DIR *dirp;
    struct dirent *dp;
    int j = 0;

    dirp = opendir(dir_name);
    if (dirp == NULL)
        return buffer;
    dp = readdir(dirp);
    while (dp != NULL) {
        if (dp->d_name[0] != '.') {
            buffer[j] = my_strdup(dp->d_name);
            j++;
        }
        dp = readdir(dirp);
    }
    buffer[j] = NULL;
    closedir(dirp);
    return buffer;
}

static int compare(char **buffer, char **command, char *path)
{
    char *temp;

    for (int i = 0; buffer[i] != NULL; i++) {
        if (my_strcmp(buffer[i], *command) == 0) {
            temp = my_strcatdup(path, "/");
            *command = my_strcatdup(temp, buffer[i]);
            free(temp);
            return 1;
        }
    }
    return 0;
}

static void not_found(char **command)
{
    char *err = my_strcatdup(*command, ": Command not found.\n");

    write(STDERR_FILENO, err, my_strlen(err));
    free(err);
    exit(1);
}

static int not_path(char **command)
{
    char *err;
    struct stat sb;

    if (access(*command, F_OK) != 0)
        not_found(command);
    if (stat(*command, &sb) != 0)
        return 1;
    if (access(*command, X_OK) != 0 || S_ISDIR(sb.st_mode) != 0) {
        err = my_strcatdup(*command, ": Permission denied.\n");
        write(STDERR_FILENO, err, my_strlen(err));
        free(err);
        exit(1);
        }
    return 0;
}

void check_command_valid(shell_t *shell, char **commands)
{
    char **buffer;
    int size;

    for (int i = 0; shell->cmd_path[i]; i++) {
        size = malloc_buffer(shell->cmd_path[i]);
        buffer = malloc(sizeof(char *) * size);
        buffer[0] = NULL;
        buffer = open_dir(shell->cmd_path[i], buffer);
        if (compare(buffer, commands, shell->cmd_path[i]) == 1) {
            destroy_array(buffer);
            return;
        }
        destroy_array(buffer);
    }
    if (not_path(commands) == 0)
        return;
    not_found(commands);
}

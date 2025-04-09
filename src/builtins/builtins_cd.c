/*
** EPITECH PROJECT, 2025
** minishel2
** File description:
** exec_cd
*/

#include "sh.h"
#include <sys/stat.h>
#include <errno.h>

static void change_oldpath(char **env, int i, char *special)
{
    char *actual;

    if (i == 1)
        actual = my_strdup(special);
    else
        actual = getcwd(NULL, 0);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp("OLDPWD=", env[i], 7) == 0) {
            env[i] = my_strcatdup("OLDPWD=", actual);
        }
    }
    free(actual);
}

static void change_pwd(char **env)
{
    char *tmp = getcwd(NULL, 0);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp("PWD=", env[i], 4) == 0) {
            free(env[i]);
            env[i] = my_strcatdup("PWD=", tmp);
        }
    }
    free(tmp);
}

void after_home(char *command)
{
    char **tab;

    if (command != NULL) {
        tab = my_str_to_word_array(command, "/");
        for (int i = 1; tab[i]; i++)
            chdir(tab[i]);
    }
}

static int home(char **env, char *command)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp("HOME=", env[i], 5) == 0) {
            change_oldpath(env, 0, "");
            chdir(env[i] + 5);
            change_pwd(env);
            after_home(command);
            return 1;
        }
    }
    write(STDERR_FILENO, "cd: No home directory.\n", 24);
    return 1;
}

void clear_backing(char *tmp, char **tab)
{
    free(tmp);
    destroy_array(tab);
}

void backing(char **env, char *command)
{
    char *tmp = getcwd(NULL, 0);
    int done = 0;
    char **tab = my_str_to_word_array(command, "/");

    for (int i = 0; env[i]; i++) {
        if (my_strncmp("OLDPWD=", env[i], 7) == 0) {
            chdir(env[i] + 7);
            done = 1;
        }
    }
    if (done == 0)
        write(2, ": No such file or directory.\n", 30);
    for (int i = 1; tab[i]; i++)
        chdir(tab[i]);
    change_oldpath(env, 1, tmp);
    clear_backing(tmp, tab);
    change_pwd(env);
}

static int special_case(char **command, char **env)
{
    char *tmp;

    if (command[1] == NULL || command[1][0] == '~')
        return home(env, command[1]);
    if (command[2]) {
        tmp = "cd: Too many arguments.\n";
        write(2, tmp, my_strlen(tmp));
        return 1;
    }
    if (command[1][0] == '-') {
        backing(env, command[1]);
        return 1;
    }
    return 0;
}

int error(char *path)
{
    char *tmp;
    struct stat sb;

    stat(path, &sb);
    if (errno == EACCES)
        tmp = my_strcatdup(path, ": Permission denied\n");
    else if (access(path, F_OK) == 0)
        tmp = my_strcatdup(path, ": Not a directory.\n");
    else
        tmp = my_strcatdup(path, ": No such file or directory.\n");
    write(STDOUT_FILENO, tmp, my_strlen(tmp));
    free(tmp);
    return 1;
}

int exec_cd(shell_t *shell, char **args)
{
    char *tmp = getcwd(NULL, 0);
    char **path;
    int result;

    if (special_case(args, shell->env) == 1)
        return 1;
    path = my_str_to_word_array(args[1], "/");
    for (int i = 0; path[i]; i++)
        result = chdir(path[i]);
    if (result == -1)
        return error(args[1]);
    change_oldpath(shell->env, 1, tmp);
    free(tmp);
    tmp = getcwd(NULL, 0);
    change_pwd(shell->env);
    free(tmp);
    destroy_array(path);
    return 1;
}

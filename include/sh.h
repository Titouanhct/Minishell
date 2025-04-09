/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** sh
*/

#include <my.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

#ifndef SH_H_
    #define SH_H_

struct shell_s;

typedef struct data_cmd_s {
    char **args;
    int position;
    bool piped;
    list_t *l_pipe;
} data_cmd_t;

typedef struct builtin_s {
    char *builtin_name;
    int (*f_builtin)(struct shell_s *, char **);
} builtin_t;

typedef struct shell_s {
    char **env;
    list_t *l_commands;
    char **commands;
    char **cmd_path;
    int r_value;
    bool cond;
} shell_t;

shell_t *init_shell(char **env_p);
int exec_loop(shell_t *shell);
int exec_cd(shell_t *shell, char **args);
int unset_env(shell_t *shell, char **args);
int builtins_command(shell_t *shell, char **args);
int env(shell_t *shell, char **args);
int builtins_exit(shell_t *shell, char **args);
int set_env(shell_t *shell, char **args);
int command_parser(char *buffer, shell_t *shell);
int command_get(char **buffer, size_t *buff_size);
int command_exec(shell_t *shell);
void check_command_valid(shell_t *shell, char **commands);
void signals(int *r_value);
void exec_pipe(shell_t *shell, list_t *list_pipe);
void destroy_all(shell_t *shell);
int check_for_redirection(char **args);
void write_in_file(int fd);

#endif /* !SH_H_ */

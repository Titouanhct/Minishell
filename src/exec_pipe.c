/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** main
*/

#include "sh.h"

static int count_to_malloc(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            count++;
    }
    return count;
}

static char *del_spaces(char *str)
{
    int count = count_to_malloc(str);
    char *string = malloc(sizeof(char) * (count + 1));

    if (string == NULL) {
        perror("malloc error");
        exit(84);
    }
    count = 0;
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] != ' ') {
            string[count] = str[x];
            count++;
        }
    }
    string[count] = '\0';
    return string;
}

static void create_pipes(int pipes[][2], int num_pipes)
{
    for (int i = 0; i < num_pipes - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe error");
            exit(84);
        }
    }
}

void close_pipes(int pipes[][2], int num_pipes)
{
    for (int i = 0; i < num_pipes - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
}

void exec_child(node_t *current, shell_t *shell)
{
    char **args = my_str_to_word_array(current->data, " ");
    int fd = -1;

    for (int x = 0; args[x]; x++)
        args[x] = del_spaces(args[x]);
    if (builtins_command(shell, args) == -1)
        exit(shell->r_value);
    check_command_valid(shell, args);
    fd = check_for_redirection(args);
    if (execve(args[0], args, shell->env) == -1) {
        perror("execve error");
        exit(84);
    }
    if (fd != -1)
        write_in_file(fd);
}

void dup_and_close(int pipes[][2], int i, list_t *list_pipe)
{
    if (i > 0)
        dup2(pipes[i - 1][0], STDIN_FILENO);
    if (i < list_pipe->size - 1)
        dup2(pipes[i][1], STDOUT_FILENO);
    close_pipes(pipes, list_pipe->size);
}

static void check_fork_error(int pid)
{
    if (pid == -1) {
        perror("fork error");
        exit(84);
    }
}

static void wait_child(list_t *list_pipe)
{
    for (int i = 0; i < list_pipe->size; i++) {
        wait(NULL);
    }
}

void exec_pipe(shell_t *shell, list_t *list_pipe)
{
    int pipes[list_pipe->size - 1][2];
    node_t *current = list_pipe->head;
    pid_t pid;

    create_pipes(pipes, list_pipe->size);
    for (int i = 0; i < list_pipe->size; i++) {
        pid = fork();
        check_fork_error(pid);
        if (pid == 0) {
            dup_and_close(pipes, i, list_pipe);
            exec_child(current, shell);
        }
        if (i > 0)
            close(pipes[i - 1][0]);
        if (i < list_pipe->size - 1)
            close(pipes[i][1]);
        current = current->next;
    }
    wait_child(list_pipe);
}

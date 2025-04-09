/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** cmd_exec
*/

#include "sh.h"
#include "errno.h"

static void error_exec(char **commands)
{
    char *sign;

    if (errno == 8)
            sign = my_strcatdup(commands[0], ": Exec format error. "
            "Binary file not executable.\n");
    write(2, sign, my_strlen(sign));
    free(sign);
}

int exec_one_cmd(shell_t *shell, char **commands)
{
    __pid_t pid;
    int error;

    pid = fork();
        if (pid == -1)
            exit(84);
        if (pid == 0) {
            check_command_valid(shell, commands);
            check_for_redirection(commands);
            error = execve(commands[0], commands, shell->env);
            error_exec(commands);
            exit(error);
        }
        wait(&shell->r_value);
    signals(&shell->r_value);
    return shell->r_value;
}

int command_exec(shell_t *shell)
{
    data_cmd_t *data;

    for (node_t *c = shell->l_commands->head; c; c = c->next) {
        data = c->data;
        if (data->piped == false && builtins_command(shell, data->args) != 1){
            shell->r_value = exec_one_cmd(shell, data->args);
        }
        if (data->piped == true) {
            exec_pipe(shell, data->l_pipe);
        }
    }
        return shell->r_value;
}

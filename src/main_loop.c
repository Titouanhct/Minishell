/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** exec_loop
*/

#include "sh.h"

int exec_loop(shell_t *shell)
{
    size_t buff_size = 0;
    char *buffer;

    while (shell->cond) {
        if (command_get(&buffer, &buff_size) == -1)
            break;
        if (buffer[0] == '\0')
                continue;
        if (command_parser(buffer, shell) == 84)
            continue;
        shell->r_value = command_exec(shell);
    }
    return shell->r_value;
}

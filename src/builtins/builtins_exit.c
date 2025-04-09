/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** builtins_exit
*/

#include "sh.h"

int builtins_exit(shell_t *shell, char **args)
{
    (void)args;
    shell->cond = 0;
    return 0;
}

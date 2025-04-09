/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** builtins_env
*/

#include "sh.h"

int env(shell_t *shell, char **args)
{
    (void)args;
    my_show_word_array(shell->env);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** destroy_at_end
*/

#include "sh.h"

void destroy_all(shell_t *shell)
{
    destroy_array(shell->cmd_path);
    destroy_array(shell->env);
    free(shell);
}

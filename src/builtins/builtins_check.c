/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** builtins_check
*/

#include "sh.h"

static const builtin_t builtin[] = {
    {"unsetenv", &unset_env},
    {"setenv", &set_env},
    {"env", &env},
    {"cd", &exec_cd},
    {"exit", &builtins_exit},
    {NULL, NULL},
};

int builtins_command(shell_t *shell, char **args)
{
    for (int i = 0; builtin[i].builtin_name != NULL; i++) {
        if (my_strcmp(args[0], builtin[i].builtin_name) == 0) {
                shell->r_value = builtin[i].f_builtin(shell, args);
                return 1;
        }
    }
    return 0;
}

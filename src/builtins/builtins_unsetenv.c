/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** builtins_unsetenv
*/

#include "sh.h"

int unset_env(shell_t *shell, char **args)
{
    list_t *list;
    info_t *data;
    node_t *next;

    list = array_to_list(shell->env);
    for (node_t *cur = list->head; cur; cur = next) {
        next = cur->next;
        data = cur->data;
        if (my_strcmp(data->left, args[1]) == 0) {
            free(data->left);
            free(data->right);
            free(data);
            destroy_node(list, cur);
            break;
        }
    }
    shell->env = list_to_array(list);
    shell->cond = 1;
    return 0;
}

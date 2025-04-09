/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** builtins_setenv
*/

#include "sh.h"
#include <ctype.h>

static int check_left(char *left)
{
    if (!isalpha(*left)) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 1;
    }
    if (my_str_isalpha(left) != 0) {
        write(2, "setenv: Variable name must contain alphanumeric"
            " characters.\n", 61);
        return 1;
    }
    return 0;
}

static list_t *add_to_env(list_t *list, shell_t *shell, char **args)
{
    info_t *data = malloc(sizeof(info_t));

    if (!list)
        list = array_to_list(shell->env);
    if (check_left(args[1]) == 1)
        return list;
    if (!args[2])
        data->right = NULL;
    else
        data->right = my_strdup(args[2]);
    data->left = my_strdup(args[1]);
    pushback(list, data);
    return list;
}

int set_env(shell_t *shell, char **args)
{
    list_t *list;
    info_t *data;
    int done = 0;

    if (!args[1]) {
        my_show_word_array(shell->env);
        return 1;
    }
    list = array_to_list(shell->env);
    for (node_t *cur = list->head; cur; cur = cur->next) {
        data = cur->data;
        if (my_strcmp(data->left, args[1]) == 0) {
            data->right = args[2];
            done = 1;
        }
    }
    if (done == 0)
        list = add_to_env(list, shell, args);
    shell->env = list_to_array(list);
    return 0;
}

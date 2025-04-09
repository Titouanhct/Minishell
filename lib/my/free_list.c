/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** free_list
*/

#include "my.h"
#include <stdlib.h>

void free_list(list_t *list)
{
    info_t *data;
    node_t *next;

    for (node_t *cur = list->head; cur; cur = next) {
        next = cur->next;
        data = cur->data;
        free(data->left);
        free(data->right);
        free(data);
        free(cur);
    }
    free(list);
}

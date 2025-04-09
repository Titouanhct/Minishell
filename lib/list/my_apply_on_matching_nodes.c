/*
** EPITECH PROJECT, 2024
** my_apply_on_matching_nodes.c
** File description:
** ..
*/

#include "my.h"
#include <stdlib.h>

int my_apply_on_matching_nodes(list_t *list, void *(*f)(),
    void const *data_ref, int (*cmp)())
{
    node_t *tmp;

    tmp = list->head;
    while (tmp != NULL) {
        if (cmp(tmp->data, data_ref) == 0)
            f(tmp->data);
        tmp = tmp->next;
    }
    return 0;
}

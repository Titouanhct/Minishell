/*
** EPITECH PROJECT, 2024
** my_apply_on_nodes.c
** File description:
** ..
*/


#include "my.h"
#include <stdlib.h>

int my_apply_on_nodes(list_t *list, void *(*f)(void *))
{
    node_t *tmp;

    tmp = list->head;
    while (tmp != NULL) {
        f(tmp->data);
        tmp = tmp->next;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** pushback
** File description:
** pushback
*/

#include "my.h"
#include <stdlib.h>

static node_t *fill_node(node_t *node, void *data, node_t *prev)
{
    node->prev = prev;
    node->data = data;
    node->next = NULL;
    return node;
}

void pushback(list_t *list, void *data)
{
    node_t *to_add = malloc(sizeof(node_t));

    if (!list || !data)
        return;
    to_add = fill_node(to_add, data, list->tail);
    if (list->tail)
        list->tail->next = to_add;
    list->tail = to_add;
    if (!list->head)
        list->head = to_add;
    list->size++;
}

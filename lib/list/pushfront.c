/*
** EPITECH PROJECT, 2024
** pushback
** File description:
** pushback
*/

#include "my.h"
#include <stdlib.h>

static node_t *fill_node(node_t *node, void *data, node_t *next)
{
    node->next = next;
    node->data = data;
    node->prev = NULL;
    return node;
}

void pushfront(list_t *list, void *data)
{
    node_t *to_add = malloc(sizeof(node_t));

    if (!list || !data)
        return;
    to_add = fill_node(to_add, data, list->head);
    if (list->head)
        list->head->prev = to_add;
    list->head = to_add;
    if (!list->tail)
        list->tail = to_add;
    list->size++;
}

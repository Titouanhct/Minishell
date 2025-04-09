/*
** EPITECH PROJECT, 2024
** My_Linked_List_lib
** File description:
** function to destroy a node passed in parameter
*/

#include "my.h"
#include <stdlib.h>

void destroy_node(list_t *list, node_t *node)
{
    if (!list)
        return;
    if (node) {
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (list->head == node)
            list->head = node->next;
        if (list->tail == node)
            list->tail = node->prev;
        free(node);
    }
}

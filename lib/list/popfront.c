/*
** EPITECH PROJECT, 2024
** my_Linked_list
** File description:
** popfront
*/

#include "my.h"
#include <stdlib.h>

void popfront(list_t *list)
{
    node_t *first;

    if (!list || !list->head)
        return;
    first = list->head;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(first);
    list->size--;
}

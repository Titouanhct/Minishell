/*
** EPITECH PROJECT, 2024
** my_Linked_list
** File description:
** popback
*/

#include "my.h"
#include <stdlib.h>

void popback(list_t *list)
{
    node_t *last;

    if (!list || !list->tail)
        return;
    last = list->tail;
    if (list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(last);
    list->size--;
}

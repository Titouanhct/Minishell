/*
** EPITECH PROJECT, 2024
** create_list
** File description:
** Function that creates the empty linked list
*/

#include "my.h"
#include <stdlib.h>

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

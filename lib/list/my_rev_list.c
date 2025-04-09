/*
** EPITECH PROJECT, 2024
** lib_list
** File description:
** my_rev_list
*/

#include "my.h"
#include <stdlib.h>

int my_list_size(node_t *begin)
{
    node_t *tmp;
    int count = 0;

    tmp = begin;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

node_t *reverse(node_t **begin, node_t *tmp, int len)
{
    node_t *tmp2;
    void *tempo;

    tmp2 = *begin;
    for (int i2 = 1; i2 < len; i2++) {
        tmp2 = tmp2->next;
    }
    tempo = tmp->data;
    tmp->data = tmp2->data;
    tmp2->data = tempo;
    return tmp;
}

void my_rev_list(node_t **begin)
{
    int len = my_list_size(*begin);
    node_t *tmp;

    tmp = *begin;
    for (int i = 1; i < len; i++) {
        tmp = reverse(begin, tmp, len);
        tmp = tmp->next;
        len--;
    }
}

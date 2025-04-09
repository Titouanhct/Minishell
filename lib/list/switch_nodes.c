/*
** EPITECH PROJECT, 2024
** lib_list
** File description:
** switch_nodes
*/

#include "my.h"

void switch_nodes(node_t *node1, node_t *node2)
{
    info_t *data = node1->data;

    node1->data = node2->data;
    node2->data = data;
}

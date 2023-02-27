/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** insert_node
*/

#include "my_linkedlist.h"

void insert_node(node_t *prev_node, node_t *node)
{
    node->next = prev_node->next;
    node->prev = prev_node;
    prev_node->next->prev = node;
    prev_node->next = node;
}

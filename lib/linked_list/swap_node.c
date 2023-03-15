/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** swap_node
*/

#include "my_linkedlist.h"
#include <stdlib.h>

void swap_node_1_prev_of_node_2(node_t **head, node_t *node_1, node_t *node_2)
{
    node_t *node_1_prev = node_1->prev;
    node_t *node_2_next = node_2->next;

    node_1->next = node_2_next;
    node_1->prev = node_2;
    node_2->next = node_1;
    node_2->prev = node_1_prev;
    node_1_prev->next = node_2;
    node_2_next->prev = node_1;
    if (*head == node_1) {
        *head = node_2;
    }
}

void swap_node_2_prev_of_node_1(node_t **head, node_t *node_1, node_t *node_2)
{
    node_t *node_1_next = node_1->next;
    node_t *node_2_prev = node_2->prev;

    node_2->next = node_1_next;
    node_2->prev = node_1;
    node_1->next = node_2;
    node_1->prev = node_2_prev;
    node_2_prev->next = node_1;
    node_1_next->prev = node_2;
    if (*head == node_2) {
        *head = node_1;
    }
}

void swap_node_1_and_node_2(node_t **head, node_t *node_1, node_t *node_2)
{
    node_t *node_1_next = node_1->next;
    node_t *node_1_prev = node_1->prev;
    node_t *node_2_next = node_2->next;
    node_t *node_2_prev = node_2->prev;

    node_1->next = node_2_next;
    node_1->prev = node_2_prev;
    node_2->next = node_1_next;
    node_2->prev = node_1_prev;
    node_1_prev->next = node_2;
    node_1_next->prev = node_2;
    node_2_prev->next = node_1;
    node_2_next->prev = node_1;
    if (*head == node_1) {
        *head = node_2;
    } else if (*head == node_2) {
        *head = node_1;
    }
}

void swap_node(node_t **head, node_t *node_1, node_t *node_2)
{
    if (*head == NULL || node_1 == node_2) {
        return;
    }
    if (node_1->next == node_2 && node_1->prev == node_2) {
        *head = (*head)->next;
        return;
    }
    if (node_1->next == node_2) {
        swap_node_1_prev_of_node_2(head, node_1, node_2);
    } else if (node_2->next == node_1) {
        swap_node_2_prev_of_node_1(head, node_1, node_2);
    } else {
        swap_node_1_and_node_2(head, node_1, node_2);
    }
}

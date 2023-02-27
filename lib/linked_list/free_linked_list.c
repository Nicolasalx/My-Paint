/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** free_linked_list
*/

#include "my_linkedlist.h"
#include <stdlib.h>

void free_linked_list(node_t **head)
{
    node_t *current = *head;
    node_t *next;

    if (*head == NULL) {
        return;
    }
    do {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    } while (current != *head);
    *head = NULL;
}

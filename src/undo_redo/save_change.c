/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** save_change
*/

#include "layer.h"
#include <stdlib.h>

void remove_all_node_after(node_t **head, node_t *node)
{
    node_t *current = node->next;
    node_t *next;
    node_t *removed_node;

    while (current != *head) {
        next = current->next;
        removed_node = remove_node(head, current);
        sfTexture_destroy(removed_node->data);
        free(removed_node);

        current = next;
    }
}

void save_change(void)
{
    if (GET_DATA(selected_layer, layer_t)->current_version !=
    GET_DATA(selected_layer, layer_t)->head_undo->prev) {
        remove_all_node_after(&GET_DATA(selected_layer, layer_t)->head_undo, GET_DATA(selected_layer, layer_t)->current_version);
    }
    append_node(&GET_DATA(selected_layer, layer_t)->head_undo,
    create_node(create_screen_shot(
    GET_DATA(selected_layer, layer_t)->texture_render_texture)));
    GET_DATA(selected_layer, layer_t)->current_version = GET_DATA(selected_layer, layer_t)->head_undo->prev;
}

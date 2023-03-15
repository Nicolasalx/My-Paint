/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** delete_layer
*/

#include "layer.h"
#include <stdlib.h>

void delete_current_layer(void)
{
    if (selected_layer->next == selected_layer) {
        return;
    }
    selected_layer = selected_layer->next;
    node_t *node_to_delete = remove_node(&head_layer, selected_layer->prev);
    sfSprite_destroy(GET_DATA(node_to_delete, layer_t)->render_sprite);
    sfRenderTexture_destroy(GET_DATA(node_to_delete, layer_t)->render_texture);
    sfRectangleShape_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.box_ui_layer.box);
    sfText_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.box_ui_layer.text);
    sfFont_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.box_ui_layer.font);
    sfRectangleShape_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.eye_ui_layer.box);
    sfSprite_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.eye_ui_layer.sprite);
    sfTexture_destroy(GET_DATA(node_to_delete, layer_t)->ui_layer.eye_ui_layer.texture);
    free(node_to_delete);
}

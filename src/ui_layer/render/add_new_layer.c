/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** add_new_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void add_new_layer(void)
{
    char layer_name[MAX_LAYER_NAME_SIZE];

    create_new_layer(create_layer_name(layer_name));
    sfRenderTexture_clear(GET_DATA(head_layer->prev, layer_t)->render_texture, sfTransparent);
    sfRenderTexture_display(GET_DATA(head_layer->prev, layer_t)->render_texture);

    append_node(&GET_DATA(head_layer->prev, layer_t)->head_undo,
    create_node(create_screen_shot(
        GET_DATA(head_layer->prev, layer_t)->texture_render_texture)));
    GET_DATA(head_layer->prev, layer_t)->current_version = GET_DATA(head_layer->prev, layer_t)->head_undo;
}

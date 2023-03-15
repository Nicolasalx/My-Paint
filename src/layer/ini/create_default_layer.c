/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_default_layer
*/

#include "my.h"
#include "layer.h"

void create_default_layer(void)
{
    char new_layer_name[MAX_LAYER_NAME_SIZE];

    background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(background, sfTransparent);
    sfRectangleShape_setOutlineColor(background,
        (sfColor) BACKGROUND_OUTLINE_COLOR);

    create_new_layer(create_layer_name(new_layer_name));

    sfRenderTexture_clear(GET_DATA(head_layer, layer_t)->render_texture,
        (sfColor) DEFAULT_LAYER_COLOR);

    append_node(&GET_DATA(head_layer, layer_t)->head_undo,
    create_node(create_screen_shot(
        GET_DATA(head_layer, layer_t)->texture_render_texture)));
    GET_DATA(head_layer, layer_t)->current_version =
        GET_DATA(head_layer, layer_t)->head_undo;
    selected_layer = head_layer;
}

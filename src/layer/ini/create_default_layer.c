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
    create_new_layer("layer_1");

    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape_setSize(background,
        (sfVector2f) {SIZE_IMAGE_X, SIZE_IMAGE_Y});
    sfRectangleShape_setFillColor(background,
        (sfColor) DEFAULT_LAYER_COLOR);

    sfRenderTexture_drawRectangleShape
        (GET_DATA(head_layer, layer_t)->render_texture, background, NULL);

    sfRectangleShape_destroy(background);

    append_node(&GET_DATA(head_layer, layer_t)->head_undo,
    create_node(create_screen_shot
        (GET_DATA(head_layer, layer_t)->texture_render_texture)));
    selected_layer = head_layer;
}

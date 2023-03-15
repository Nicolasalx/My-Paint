/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** undo
*/

#include "my.h"
#include "layer.h"

void undo(void)
{
    GET_DATA(selected_layer, layer_t)->current_version =
        GET_DATA(selected_layer, layer_t)->current_version->prev;
    sfSprite *tmp_strite = sfSprite_create();
    sfSprite_setTexture(tmp_strite, GET_DATA(
        selected_layer, layer_t)->current_version->data, sfTrue);

    sfRenderStates states = {
        .blendMode = sfBlendNone,
        .transform = sfTransform_Identity,
        .texture = NULL,
        .shader = NULL
    };

    sfRenderTexture_drawSprite(GET_DATA(
        selected_layer, layer_t)->render_texture, tmp_strite, &states);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    sfSprite_destroy(tmp_strite);
}

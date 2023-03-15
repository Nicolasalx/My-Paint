/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_new_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"
#include "my_malloc.h"
#include "my_string.h"

void create_new_layer(char *layer_name)
{
    layer_t *new_layer = my_malloc(sizeof(layer_t));
    new_layer->render_texture = sfRenderTexture_create(
        render_sheet_res.x, render_sheet_res.y, sfFalse);

    sfRenderTexture_setSmooth(new_layer->render_texture, sfTrue);

    my_strcpy(new_layer->layer_name, layer_name);
    new_layer->hidden = false;
    new_layer->head_undo = NULL;
    new_layer->texture_render_texture = (sfTexture *)
        sfRenderTexture_getTexture(new_layer->render_texture);
    new_layer->render_sprite = sfSprite_create();
    append_node(&head_layer, create_node(new_layer));
    create_ui_layer(new_layer);
}

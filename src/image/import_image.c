/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** import_image
*/

#include "my.h"
#include "layer.h"
#include "my_graphical.h"
#include "header.h"

void import_image(char *image_path)
{
    char new_layer_name[MAX_LAYER_NAME_SIZE];

    create_new_layer(create_layer_name(new_layer_name));
    selected_layer = head_layer->prev;

    sfTexture *loaded_image = resize_texture(sfTexture_createFromFile
        (image_path, NULL), render_sheet_res);

    sfSprite_setTexture(GET_DATA(selected_layer, layer_t)->render_sprite,
        loaded_image, sfFalse);

    sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->
    render_texture, GET_DATA(selected_layer, layer_t)->render_sprite, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);

    append_node(&GET_DATA(selected_layer, layer_t)->head_undo,
    create_node(create_screen_shot(
        GET_DATA(selected_layer, layer_t)->texture_render_texture)));
}

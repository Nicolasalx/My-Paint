/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** load_image
*/

#include "my.h"
#include "layer.h"

bool load_image(char *image_path)
{
    sfTexture *loaded_image = sfTexture_createFromFile(image_path, NULL);

    if (loaded_image == NULL) {
        return FAIL;
    }
    render_sheet_res = sfTexture_getSize(loaded_image);

    create_default_layer();

    sfSprite_setTexture(GET_DATA(selected_layer, layer_t)->render_sprite,
        loaded_image, sfFalse);

    sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->
    render_texture, GET_DATA(selected_layer, layer_t)->render_sprite, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);

    append_node(&GET_DATA(selected_layer, layer_t)->head_undo,
    create_node(create_screen_shot(
        GET_DATA(selected_layer, layer_t)->texture_render_texture)));
    GET_DATA(selected_layer, layer_t)->current_version = GET_DATA(selected_layer, layer_t)->head_undo->prev;
    return SUCCESS;
}

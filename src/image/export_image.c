/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** export_image
*/

#include "my.h"
#include "layer.h"

void export_image(char *image_name)
{
    node_t *current = head_layer;
    sfRenderTexture *result_render_texture =
    sfRenderTexture_create(render_sheet_res.x, render_sheet_res.y, sfFalse);
    sfSprite *result_sprite;

    do {
        result_sprite = sfSprite_create();
        sfSprite_setPosition(result_sprite, (sfVector2f) {0, 0});
        sfSprite_setTexture(result_sprite, sfRenderTexture_getTexture(
            GET_DATA(current, layer_t)->render_texture), sfFalse);
        sfRenderTexture_drawSprite(result_render_texture, result_sprite, NULL);
        sfRenderTexture_display(result_render_texture);
        sfSprite_destroy(result_sprite);
        current = current->next;
    } while (current != head_layer);
    sfImage *image = sfTexture_copyToImage(
        sfRenderTexture_getTexture(result_render_texture));
    sfImage_saveToFile(image, image_name);
    sfImage_destroy(image);
    sfRenderTexture_destroy(result_render_texture);
}

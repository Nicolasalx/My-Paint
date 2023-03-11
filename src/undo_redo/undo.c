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
    GET_DATA(selected_layer, layer_t)->current_version = GET_DATA(selected_layer, layer_t)->current_version->prev;
//    sfRenderWindow_drawSprite(window, GET_DATA(selected_layer, layer_t)->current_version->data, NULL);
//    sfRenderWindow_display(window);
//    printf("%d\n", my_listlen(&GET_DATA(selected_layer, layer_t)->head_undo));
//    sfSleep((sfTime) {1000000});
    sfSprite *tmp_strite = sfSprite_create();
    sfSprite_setTexture(tmp_strite, GET_DATA(selected_layer, layer_t)->current_version->data, sfTrue);
    sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->render_texture, tmp_strite, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    sfSprite_destroy(tmp_strite);
//    GET_DATA(selected_layer, layer_t)->texture_render_texture = sfRenderTexture_getTexture(GET_DATA(selected_layer, layer_t)->render_texture);
}

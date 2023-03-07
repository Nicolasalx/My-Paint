/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_overview
*/

#include "my.h"
#include "layer.h"

void render_overview(sfRenderWindow *window)
{
    sfSprite_setPosition(GET_DATA(selected_layer, layer_t)->render_sprite, (sfVector2f) OVERVIEW_POS);
    sfSprite_setScale(GET_DATA(selected_layer, layer_t)->render_sprite, (sfVector2f) OVERVIEW_SCALE);
    sfRenderWindow_drawSprite(window, GET_DATA(selected_layer, layer_t)->render_sprite, NULL);
}

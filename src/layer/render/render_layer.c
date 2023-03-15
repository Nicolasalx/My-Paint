/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void render_layer(sfRenderWindow *window)
{
    node_t *current = head_layer;

    render_background(window);

    do {
        sfSprite_setTexture(GET_DATA(current, layer_t)->render_sprite,
            GET_DATA(current, layer_t)->texture_render_texture, sfFalse);

        sfSprite_setPosition(GET_DATA(current, layer_t)->render_sprite,
            render_sheet_pos);
        sfSprite_setScale(GET_DATA(current, layer_t)->render_sprite,
            render_sheet_scale);

        if (GET_DATA(current, layer_t)->hidden == false) {
            sfRenderWindow_drawSprite(window, GET_DATA(current, layer_t)->render_sprite, NULL);
        }
        current = current->next;
    } while (current != head_layer);
}

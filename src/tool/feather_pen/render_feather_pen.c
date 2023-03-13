/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_brush
*/

#include "my.h"
#include "my_graphical.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void render_feather_pen(void)
{
    if (mouse_button_maintain == true) {
        sfVector2f sprite_draw_pos = get_mouse_pos_on_sheet();
        sprite_draw_pos.x -=
        (((float) feather_pen.texture_size.x / feather_pen.texture_size.y) *
        (feather_pen.radius * BRUSH_SIZE_MULT)) / 2.0f;
        sprite_draw_pos.y -= (feather_pen.radius * BRUSH_SIZE_MULT) / 2.0f;
        sfSprite_setPosition(feather_pen.sprite, sprite_draw_pos);
        sfSprite_setScale(feather_pen.sprite, (sfVector2f) {
            (float) (feather_pen.radius * BRUSH_SIZE_MULT) /
                feather_pen.texture_size.y,
            (float) (feather_pen.radius * BRUSH_SIZE_MULT) /
                feather_pen.texture_size.y});
        sfSprite_setColor(feather_pen.sprite, feather_pen.color);
        sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->
            render_texture, feather_pen.sprite, NULL);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->
            render_texture);
    } else if (mouse_button_released) {
        save_change();
    }
}

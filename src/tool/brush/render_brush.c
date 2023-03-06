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

void render_brush(void)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
        sfVector2f sprite_draw_pos = get_mouse_pos_on_sheet();

        sprite_draw_pos.x -= brush.radius / 2.0f;
        sprite_draw_pos.y -= brush.radius / 2.0f;

        sfSprite_setPosition(brush.sprite, sprite_draw_pos);
        sfSprite_setScale(brush.sprite, (sfVector2f)
            {(float) brush.radius / brush.texture_size.x,
            (float) brush.radius / brush.texture_size.y});
        sfSprite_setColor(brush.sprite, brush.color);
        sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->render_texture, brush.sprite, NULL);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    }
}

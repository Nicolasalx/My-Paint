/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_pencil
*/

#include "my.h"
#include "my_graphical.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void render_pencil(void)
{
    if (mouse_button_maintain == true) {
        sfVector2f circle_draw_pos = get_mouse_pos_on_sheet();
        circle_draw_pos.x -= pencil.radius;
        circle_draw_pos.y -= pencil.radius;

        sfCircleShape_setPosition(pencil.circle, circle_draw_pos);
        sfCircleShape_setRadius(pencil.circle, pencil.radius);
        sfCircleShape_setFillColor(pencil.circle, pencil.color);
        sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->
            render_texture, pencil.circle, NULL);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->
            render_texture);
    } else if (mouse_button_released) {
        save_change();
    }
}

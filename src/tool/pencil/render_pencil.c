/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_pencil
*/

#include "my.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void render_pencil(void)
{
    sfVector2f circle_pos = {mouse_pos.x, mouse_pos.y};

    sfVector2f render_texture_pos = {(circle_pos.x - render_window_pos.x) / render_window_scale.x,
                                     (circle_pos.y - render_window_pos.y) / render_window_scale.y};

    sfVector2f render_texture_size = {(float) window_size.x / render_window_scale.x,
                                      (float) window_size.y / render_window_scale.y};

    sfVector2f circle_draw_pos = {
        render_texture_pos.x + (pencil.radius / render_texture_size.x),
        render_texture_pos.y + (pencil.radius / render_texture_size.y)
    };

    circle_draw_pos.x -= pencil.radius;
    circle_draw_pos.y += pencil.radius;

    circle_draw_pos.y = window_size.y - circle_draw_pos.y;

    sfCircleShape_setPosition(pencil.circle, circle_draw_pos);
    sfCircleShape_setRadius(pencil.circle, pencil.radius);
    sfCircleShape_setFillColor(pencil.circle, pencil.color);
    sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->render_texture, pencil.circle, NULL);
}

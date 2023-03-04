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
<<<<<<< HEAD
    sfVector2f circle_draw_pos = get_mouse_pos_on_sheet();
    circle_draw_pos.x -= pencil.radius;
    circle_draw_pos.y -= pencil.radius;

=======
    sfVector2f render_texture_pos = {
        (mouse_pos.x - render_sheet_pos.x) / render_sheet_scale.x,
        (mouse_pos.y - render_sheet_pos.y) / render_sheet_scale.y
    };
    sfVector2f render_texture_size = {
        (float) render_sheet_resolution.x / render_sheet_scale.x,
        (float) render_sheet_resolution.y / render_sheet_scale.y
    };
    sfVector2f circle_draw_pos = {
        render_texture_pos.x + (pencil.radius / render_texture_size.x),
        render_texture_pos.y + (pencil.radius / render_texture_size.y)
    };
    circle_draw_pos.x -= pencil.radius; circle_draw_pos.y -= pencil.radius;
>>>>>>> 6c84b05c86b1550bf35d2dac5a8c11c511be3f00
    sfCircleShape_setPosition(pencil.circle, circle_draw_pos);
    sfCircleShape_setRadius(pencil.circle, pencil.radius);
    sfCircleShape_setFillColor(pencil.circle, pencil.color);
    sfRenderTexture_drawCircleShape(GET_DATA(selected_layer,
        layer_t)->render_texture, pencil.circle, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer,
        layer_t)->render_texture);
}

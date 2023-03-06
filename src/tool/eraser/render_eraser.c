/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_eraser
*/

#include "my.h"
#include "my_graphical.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void render_eraser(void)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
        sfVector2f circle_draw_pos = get_mouse_pos_on_sheet();

        circle_draw_pos.x -= eraser.radius;
        circle_draw_pos.y -= eraser.radius;

        sfCircleShape_setPosition(eraser.circle, circle_draw_pos);
        sfCircleShape_setRadius(eraser.circle, eraser.radius);
        sfCircleShape_setFillColor(eraser.circle, sfTransparent);
        sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->render_texture, eraser.circle, NULL);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    }
}

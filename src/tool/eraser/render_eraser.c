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
    if (mouse_button_maintain == true) {
        sfVector2f circle_draw_pos = get_mouse_pos_on_sheet();

        circle_draw_pos.x -= eraser.radius;
        circle_draw_pos.y -= eraser.radius;

        sfCircleShape_setPosition(eraser.circle, circle_draw_pos);
        sfCircleShape_setRadius(eraser.circle, eraser.radius);
        sfCircleShape_setFillColor(eraser.circle, sfTransparent);

        sfRenderStates states = {
            .blendMode = sfBlendNone,
            .transform = sfTransform_Identity,
            .texture = NULL,
            .shader = NULL
        };

        sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->render_texture, eraser.circle, &states);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    }
}

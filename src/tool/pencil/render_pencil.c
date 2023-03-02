/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_pencil
*/

#include "my.h"
#include "layer.h"
#include "tool.h"

void render_pencil(void)
{
    sfCircleShape_setPosition(pencil.circle, (sfVector2f) {mouse_pos.x, mouse_pos.y});
    sfCircleShape_setRadius(pencil.circle, pencil.radius);
    sfCircleShape_setFillColor(pencil.circle, pencil.color);
    sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->render_texture, pencil.circle, NULL);
}

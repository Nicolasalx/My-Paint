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

void pencile_circle_mode(void)
{
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
}

void pencil_rect_mode(void)
{
    sfVector2f rect_draw_pos = get_mouse_pos_on_sheet();
    rect_draw_pos.x -= pencil.radius;
    rect_draw_pos.y -= pencil.radius;

    sfRectangleShape_setPosition(pencil.rect, rect_draw_pos);
    sfRectangleShape_setSize(pencil.rect, (sfVector2f) {pencil.radius * 2.0f, pencil.radius * 2.0f});
    sfRectangleShape_setFillColor(pencil.rect, pencil.color);
    sfRenderTexture_drawRectangleShape(GET_DATA(selected_layer, layer_t)->
        render_texture, pencil.rect, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->
        render_texture);
}

void pencil_brush_mode(void)
{
    sfVector2f sprite_draw_pos = get_mouse_pos_on_sheet();

    sprite_draw_pos.x -= (pencil.radius * BRUSH_SIZE_MULT) / 2.0f;
    sprite_draw_pos.y -= (pencil.radius * BRUSH_SIZE_MULT) / 2.0f;

    sfSprite_setPosition(pencil.sprite, sprite_draw_pos);
    sfSprite_setScale(pencil.sprite, (sfVector2f)
        {(float) (pencil.radius * BRUSH_SIZE_MULT) / pencil.texture_size.x,
        (float) (pencil.radius * BRUSH_SIZE_MULT) / pencil.texture_size.y});
    sfSprite_setColor(pencil.sprite, pencil.color);
    sfRenderTexture_drawSprite(GET_DATA(selected_layer, layer_t)->render_texture, pencil.sprite, NULL);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
}

void render_pencil(void)
{
    if (mouse_button_maintain == true) {
        switch (pencil.draw_mode) {
            case CIRCLE_DRAW:
                pencile_circle_mode();
                break;
            case RECTANGLE_DRAW:
                pencil_rect_mode();
                break;
            case BRUSH_DRAW:
                pencil_brush_mode();
                break;
            default:
                pencile_circle_mode();
                break;
        }
    } else if (mouse_button_released) {
        save_change();
    }
}

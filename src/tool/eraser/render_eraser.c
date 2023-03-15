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

void eraser_circle_mode(void)
{
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

    sfRenderTexture_drawCircleShape(GET_DATA(
        selected_layer, layer_t)->render_texture, eraser.circle, &states);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
}

void eraser_rect_mode(void)
{
    sfVector2f rect_draw_pos = get_mouse_pos_on_sheet();

    rect_draw_pos.x -= eraser.radius;
    rect_draw_pos.y -= eraser.radius;

    sfRectangleShape_setPosition(eraser.rect, rect_draw_pos);
    sfRectangleShape_setSize(eraser.rect,
        (sfVector2f) {eraser.radius * 2.0f, eraser.radius * 2.0f});
    sfRectangleShape_setFillColor(eraser.rect, sfTransparent);

    sfRenderStates states = {
        .blendMode = sfBlendNone,
        .transform = sfTransform_Identity,
        .texture = NULL,
        .shader = NULL
    };

    sfRenderTexture_drawRectangleShape(GET_DATA(
        selected_layer, layer_t)->render_texture, eraser.rect, &states);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
}

void eraser_brush_mode(void)
{
    sfVector2f sprite_draw_pos = get_mouse_pos_on_sheet();
    sprite_draw_pos.x -= (eraser.radius * BRUSH_SIZE_MULT) / 2.0f;
    sprite_draw_pos.y -= (eraser.radius * BRUSH_SIZE_MULT) / 2.0f;
    sfSprite_setPosition(eraser.sprite, sprite_draw_pos);
    sfSprite_setScale(eraser.sprite, (sfVector2f)
        {(float) (eraser.radius * BRUSH_SIZE_MULT) / eraser.texture_size.x,
        (float) (eraser.radius * BRUSH_SIZE_MULT) / eraser.texture_size.y});
    sfSprite_setColor(eraser.sprite, (sfColor) {255, 255, 255, 255});
    sfRenderStates states = {
        .blendMode = {
            .colorSrcFactor = sfBlendFactorZero,
            .colorDstFactor = sfBlendFactorDstColor,
            .colorEquation = sfBlendEquationAdd,
            .alphaSrcFactor = sfBlendFactorZero,
            .alphaDstFactor = sfBlendFactorOneMinusSrcAlpha,
            .alphaEquation = sfBlendEquationAdd
        }, .transform = sfTransform_Identity, .texture = NULL, .shader = NULL};
    sfRenderTexture_drawSprite(GET_DATA(
        selected_layer, layer_t)->render_texture, eraser.sprite, &states);
    sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
}

void render_eraser(void)
{
    if (mouse_button_maintain == true) {
        switch (eraser.draw_mode) {
            case CIRCLE_DRAW:
                eraser_circle_mode();
                break;
            case RECTANGLE_DRAW:
                eraser_brush_mode();
                break;
            case BRUSH_DRAW:
                eraser_brush_mode();
                break;
            default:
                eraser_brush_mode();
                break;
        }
    } else if (mouse_button_released) {
        save_change();
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_overview
*/

#include "my.h"
#include "layer.h"
#include "color_selection.h"

void compute_overview_pos(void)
{
    sfFloatRect sheet_bound = {render_sheet_pos.x, render_sheet_pos.y,
        render_sheet_res.x, render_sheet_res.y};
    sheet_bound = compute_rect_pos_and_scale(
        sfRectangleShape_getGlobalBounds(selection_color[
        size_selection_color - 1].rectangle), sheet_bound, 10.0f);
    overview_pos.x = sheet_bound.left;
    overview_pos.y = sheet_bound.top;
    overview_scale.x = sheet_bound.width / render_sheet_res.x;
    overview_scale.y = sheet_bound.height / render_sheet_res.y;
}

void render_overview(sfRenderWindow *window)
{
    compute_overview_pos();
    sfSprite_setPosition(GET_DATA(selected_layer, layer_t)->render_sprite, (sfVector2f) overview_pos);
    sfSprite_setScale(GET_DATA(selected_layer, layer_t)->render_sprite, (sfVector2f) overview_scale);
    sfRenderWindow_drawSprite(window, GET_DATA(selected_layer, layer_t)->render_sprite, NULL);
    sfRectangleShape_setOutlineThickness(
        background, OVERVIEW_BACKGROUND_OUTLINE_THICKNESS);
    sfRectangleShape_setPosition(background, (sfVector2f) overview_pos);
    sfRectangleShape_setSize(background, (sfVector2f) {render_sheet_res.x, render_sheet_res.y});
    sfRectangleShape_setScale(background, (sfVector2f) overview_scale);
    sfRenderWindow_drawRectangleShape(window, background, NULL);
    sfRectangleShape_setOutlineThickness(
        background, BACKGROUND_OUTLINE_THICKNESS);
}

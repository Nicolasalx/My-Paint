/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"
#include "my_graphical.h"
#include "tool.h"

void change_color_tool(sfColor color_chromatic)
{
    switch (selected_tool) {
        case PENCIL:
            pencil.color = color_chromatic;
            break;
        case BRUSH:
            brush.color = color_chromatic;
            break;
        case FEATHER_PEN:
            feather_pen.color = color_chromatic;
            break;
        default: break;
    }
}

void select_color_icon(int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_mouse_over_rectangle_shape(selection_color[i].rectangle, mouse_pos)) {
        change_color_tool(selection_color[i].color);
    }
}

void select_color_chromatic_wheel(void)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_mouse_over_sprite(chromatic_wheel.sprite)) {
        sfVector2f render_texture_pos = {
            (mouse_pos.x - chromatic_wheel.pos.x) / chromatic_wheel.size.x,
            (mouse_pos.y - chromatic_wheel.pos.y) / chromatic_wheel.size.y
        };
        sfVector2f render_texture_size = {
            (float) 500.0f / 0.5f,
            (float) 500.0f / 0.5f
        };
        sfVector2f result_pos = {
            render_texture_pos.x + (1.0f / render_texture_size.x),
            render_texture_pos.y + (1.0f / render_texture_size.y)
        };
        sfImage* image_chromatic_wheel = sfImage_createFromFile(chromatic_wheel.path);
        sfColor color_chromatic = sfImage_getPixel(image_chromatic_wheel, result_pos.x, result_pos.y);
        if (color_chromatic.a != sfTransparent.a) {
            change_color_tool(color_chromatic);
        }
        sfImage_destroy(image_chromatic_wheel);
    }
}

void set_thickness_icon(int i, int * index_button_color)
{
    if (mouse_pos.x >= selection_color[i].pos.x && mouse_pos.x <=
        selection_color[i].pos.x + selection_color[i].size.x) {
        if (mouse_pos.y >= selection_color[i].pos.y && mouse_pos.y <=
            selection_color[i].pos.y + selection_color[i].size.y) {
            sfRectangleShape_setOutlineThickness
                (selection_color[* index_button_color].rectangle,
                    SIZE_OUTLINE_BUTTON_SEL_COLOR);

            sfRectangleShape_setOutlineThickness
                (selection_color[i].rectangle, 5);
            * index_button_color = i;
        }
    }
}

void display_color_selection_icon(sfRenderWindow *window, sfEvent event,
    int *index_button_color)
{
    for (int i = 0; i < size_selection_color; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            selection_color[i].rectangle, NULL);
        select_color_icon(i);
    }
    sfRenderWindow_drawSprite(window, chromatic_wheel.sprite, NULL);
    for (int i = 0; i < size_text_selection_color; ++i) {
        sfRenderWindow_drawText(window, text_color_selection[i].text, NULL);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < size_selection_color; ++i) {
            set_thickness_icon(i, index_button_color);
        }
    }
    select_color_chromatic_wheel();
}

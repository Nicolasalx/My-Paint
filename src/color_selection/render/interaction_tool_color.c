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
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_over_rectangle_shape(selection_color[i].rectangle)) {
        change_color_tool(selection_color[i].color);
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

void display_color_selection_icon(sfRenderWindow *window, sfEvent *event)
{
    static int index_button_color = 0;
    for (int i = 0; i < size_selection_color; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            selection_color[i].rectangle, NULL);
        select_color_icon(i);
    }
    sfRenderWindow_drawSprite(window, chromatic_wheel.sprite, NULL);
    for (int i = 0; i < size_text_selection_color; ++i) {
        sfRenderWindow_drawText(window, text_color_selection[i].text, NULL);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < size_selection_color; ++i) {
            set_thickness_icon(i, &index_button_color);
        }
    }
    select_color_chromatic_wheel();
}

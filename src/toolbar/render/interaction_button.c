/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"
#include "tool.h"
#include "my_graphical.h"

void select_tool(int i, button_state_t button_state)
{
    if (button_state == BUTTON_PRESSED) {
        selected_tool = icon_rectangle[i].tool_to_select;
        set_size_tool_selected();
    }
}

void set_color_pressed_button(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) &&
            mouse_button_pressed && icon_rectangle[i].can_draw == true) {
            select_tool(i, BUTTON_PRESSED);
            sfRectangleShape_setFillColor(icon_rectangle
            [front_toolbar.index_button_pressed].rectangle, (sfColor) BG_COLOR);

            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
                (sfColor) {51, 51, 255, 255});
            front_toolbar.index_button_pressed = i;
        }
    }
}

void interaction_set_color_button(int i)
{
    if (front_toolbar.index_button_pressed != i) {
        sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
            (sfColor) {51, 153, 255, 255});
        front_toolbar.index_button_hovered = i;
    } else if (i == 0) {
        sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
            (sfColor) {51, 51, 255, 255});
        front_toolbar.index_button_hovered = i;
    }
}

void set_color_hovered_button(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) &&
            icon_rectangle[i].can_draw == true) {
            interaction_set_color_button(i);
        }
    }
}

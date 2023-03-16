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
#include <stdio.h>

void select_tool(int i, button_state_t button_state)
{
    if (button_state == BUTTON_PRESSED) {
        selected_tool = icon_rectangle[i].tool_to_select;
        set_size_tool_selected();
    }
}

void set_color_button_pressed(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) &&
            mouse_button_pressed && icon_rectangle[i].can_draw == true) {
            select_tool(i, BUTTON_PRESSED);
            sfRectangleShape_setFillColor(icon_rectangle[front_toolbar.
                index_button_pressed].rectangle, (sfColor) {BG_COLOR});
            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
                (sfColor) {51, 51, 255, 255});
            front_toolbar.index_button_pressed = i;
        }
    }
}

void interaction_front_toolbar(void)
{
    set_color_button_pressed();
    set_color_button_hovered();
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (i != front_toolbar.index_button_pressed &&
        is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) ==
            false) {
            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
                (sfColor) {BG_COLOR});
        }
    }
}

void display_toolbar(sfRenderWindow *window, sfEvent *event)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            icon_rectangle[i].rectangle, NULL);
    }
    for (int i = 0; i < size_icon_sprite; ++i) {
        sfRenderWindow_drawSprite(window, icon_sprite[i].sprite, NULL);
    }
    interaction_front_toolbar();

    set_size_pen(window, event);
}

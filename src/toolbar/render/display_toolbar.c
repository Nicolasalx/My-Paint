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
    }
}

void interaction_front_toolbar(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle, mouse_pos) && sfMouse_isButtonPressed(sfMouseLeft) && icon_rectangle[i].can_draw == true) {
            select_tool(i, BUTTON_PRESSED);
            sfRectangleShape_setFillColor(icon_rectangle[front_toolbar.index_button_pressed].rectangle, (sfColor) BG_COLOR);
            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {51, 51, 255, 255});
            front_toolbar.index_button_pressed = i;
        }
    }
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle, mouse_pos) && icon_rectangle[i].can_draw == true) {
            if (front_toolbar.index_button_pressed != i) {
                sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {51, 153, 255, 255});
                front_toolbar.index_button_hovered = i;
            } else if (i == 0) {
                sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {51, 51, 255, 255});
                front_toolbar.index_button_hovered = i;
            }
        }
    }
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (i != front_toolbar.index_button_pressed && is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle, mouse_pos) == false) {
            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) BG_COLOR);
        }
    }
}

void display_toolbar(sfRenderWindow *window, sfEvent event,
    bool is_button_pressed)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        sfRenderWindow_drawRectangleShape(window, icon_rectangle[i].rectangle,
            NULL);
    }
    for (int i = 0; i < size_icon_sprite; ++i) {
        sfRenderWindow_drawSprite(window, icon_sprite[i].sprite, NULL);
    }
    interaction_front_toolbar();

    set_size_pen(window, event, is_button_pressed);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** set_color_button_pressed
*/

#include "my.h"
#include "toolbar.h"
#include "tool.h"
#include "my_graphical.h"
#include <stdio.h>

void change_rect_color(int i)
{
    if (is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) &&
        icon_rectangle[i].can_draw == true) {
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
}

void set_color_button_hovered(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        change_rect_color(i);
    }
}

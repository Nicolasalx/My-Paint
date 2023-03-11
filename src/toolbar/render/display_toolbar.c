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

void interaction_front_toolbar(void)
{
    set_color_pressed_button();
    set_color_hovered_button();
    for (int i = 0; i < size_icon_rectangle; ++i) {
        if (i != front_toolbar.index_button_pressed &&
            is_mouse_over_rectangle_shape(icon_rectangle[i].rectangle) ==
                false) {

            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle,
                (sfColor) BG_COLOR);
        }
    }
}

void display_toolbar(sfRenderWindow *window, sfEvent *event)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        sfRenderWindow_drawRectangleShape(window, icon_rectangle[i].rectangle,
            NULL);
    }
    for (int i = 0; i < size_icon_sprite; ++i) {
        sfRenderWindow_drawSprite(window, icon_sprite[i].sprite, NULL);
    }
    interaction_front_toolbar();

    set_size_pen(window, event);
}

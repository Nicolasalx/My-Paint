/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"

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
    set_size_pen(window, event, is_button_pressed);
}

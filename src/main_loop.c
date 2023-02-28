/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include <stdio.h>

#include "user_interface.h"
#include "color_selection.h"

sfVector2u window_size;

void main_loop()
{
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    "my_paint", sfResize | sfClose, NULL);
    if (!window)
        return;
    sfRenderWindow_setFramerateLimit(window, 60);

    window_size = sfRenderWindow_getSize(window);
    create_all_data();

    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, &event);
        sfRenderWindow_clear(window, BG_COLOR);
        for (int i = 0; i < size_user_interface; ++i) {
            sfRenderWindow_drawSprite(window, ui_sprite[i].sprite, NULL);
        }
        for (int i = 0; i < size_button_color; ++i) {
            sfRenderWindow_drawRectangleShape(window, color_selection_data.selection_color[i].rectangle, NULL);
        }
        sfRenderWindow_drawSprite(window, color_selection_data.chromatic_wheel.sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

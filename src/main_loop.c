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
#include "header.h"

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
        for (int i = 0; i < size_selection_color; ++i) {
            sfRenderWindow_drawRectangleShape(window, selection_color[i].rectangle, NULL);
        }
        sfRenderWindow_drawSprite(window, chromatic_wheel.sprite, NULL);
        
        for (int i = 0; i < size_text_selection_color; ++i) {
            sfRenderWindow_drawText(window, text_color_selection[i].text, NULL);
        }

        for (int i = 0; i < size_button_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, button_header[i].rectangle, NULL);
        }
        for (int i = 0; i < size_text_button_header; ++i) {
            sfRenderWindow_drawText(window, text_button_header[i].text, NULL);
        }

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

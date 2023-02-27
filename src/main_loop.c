/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"

void main_loop(void)
{
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    "my_paint", sfResize | sfClose, NULL);
    if (!window)
        return;

    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, &event);
        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

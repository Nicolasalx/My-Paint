/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** update_window_data
*/

#include "my.h"

void update_window_data(sfRenderWindow *window, sfView *window_view)
{
    mouse_pos = sfMouse_getPositionRenderWindow(window);
    window_pos = sfRenderWindow_getPosition(window);
    window_size = sfRenderWindow_getSize(window);
    sfView_reset(window_view, (sfFloatRect) {0, 0, window_size.x, window_size.y});
    sfRenderWindow_setView(window, window_view);
}

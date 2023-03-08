/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** manage_event
*/

#include "my.h"
#include "toolbar.h"

void manage_event(sfRenderWindow *window, sfEvent *event,
    bool *is_button_pressed, sfView *window_view)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            *is_button_pressed = true;
        }
        if (event->type == sfEvtMouseButtonReleased) {
            *is_button_pressed = false;
        }
        if (event->type == sfEvtResized) {
            window_size = sfRenderWindow_getSize(window);
            sfView_reset(window_view, (sfFloatRect) {0, 0, window_size.x, window_size.y});
            sfRenderWindow_setView(window, window_view);
        }
    }
}

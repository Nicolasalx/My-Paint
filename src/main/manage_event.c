/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** manage_event
*/

#include "my.h"
#include "toolbar.h"

void manage_event(sfRenderWindow *window, sfEvent *event, sfView *window_view)
{
    mouse_button_maintain = sfMouse_isButtonPressed(sfMouseLeft);
    mouse_button_pressed = false;
    mouse_button_released = false;
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            mouse_button_pressed = true;
        }
        if (event->type == sfEvtMouseButtonReleased) {
            mouse_button_released = true;
        }
        if (event->type == sfEvtResized) {
            window_size = sfRenderWindow_getSize(window);
            sfView_reset(window_view, (sfFloatRect) {0, 0, window_size.x, window_size.y});
            sfRenderWindow_setView(window, window_view);
        }
    }
}

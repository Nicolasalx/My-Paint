/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** manage_event
*/

#include "my.h"
#include "toolbar.h"

void manage_event(sfRenderWindow *window, sfEvent *event,
    bool *is_button_pressed)
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
    }
}

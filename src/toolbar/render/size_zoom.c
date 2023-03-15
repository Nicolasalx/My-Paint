/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** size_zoom
*/

#include "my.h"
#include "toolbar.h"
#include "stdio.h"
#include "my_graphical.h"

void zoom_shape_interaction(void)
{
    if (mouse_pos.x >= zoom_shape[1].pos.x &&
        mouse_pos.x <= zoom_shape[1].pos.x + zoom_shape[0].size.x) {
        if (mouse_pos.y >= zoom_shape[1].pos.y &&
            mouse_pos.y <= zoom_shape[1].pos.y + zoom_shape[0].size.y) {
            int size_difference = zoom_shape[1].pos.x - mouse_pos.x;
            sfRectangleShape_setSize(zoom_shape[1].rectangle,
                (sfVector2f) {-size_difference, zoom_shape[1].size.y});
            if (size_difference == 190) {
                ; // Taille = 100;
            } else {
                ; // Taille = (size_difference * 100) / 190
            }
        }
    }
}

void set_zoom_size(sfRenderWindow *window, sfEvent *event)
{
    if (mouse_button_pressed == true || (mouse_button_maintain == true &&
        event->type == sfEvtMouseMoved)) {
        zoom_shape_interaction();
    }
    for (int i = 0; i < size_zoom_shape; ++i) {
        sfRenderWindow_drawRectangleShape(
            window, zoom_shape[i].rectangle, NULL);
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** size_zoom
** Taille = 100;
** Taille = (size_difference * 100) / 190
*/

#include "my.h"
#include "toolbar.h"
#include "stdio.h"
#include "my_graphical.h"

void render_zoom(double zoom_level)
{
    float new_scale = (1 + (zoom_level / 100.0));
    sfVector2f zoom_point = sfRectangleShape_getPosition(edition_zone);

    zoom_point.x += sfRectangleShape_getSize(edition_zone).x / 2.0;
    zoom_point.y += sfRectangleShape_getSize(edition_zone).y / 2.0;
    sfVector2f offset = {
        (render_sheet_pos.x - zoom_point.x) *
        (new_scale / render_sheet_scale.x - 1),
        (render_sheet_pos.y - zoom_point.y) *
        (new_scale / render_sheet_scale.y - 1)
    };
    render_sheet_scale.x = new_scale;
    render_sheet_scale.y = new_scale;
    render_sheet_pos.x += offset.x;
    render_sheet_pos.y += offset.y;
}

void zoom_shape_interaction(void)
{
    if (mouse_pos.x >= zoom_shape[1].pos.x &&
        mouse_pos.x <= zoom_shape[1].pos.x + zoom_shape[0].size.x) {
        if (mouse_pos.y >= zoom_shape[1].pos.y &&
            mouse_pos.y <= zoom_shape[1].pos.y + zoom_shape[0].size.y) {
            int size_difference = zoom_shape[1].pos.x - mouse_pos.x;
            sfRectangleShape_setSize(zoom_shape[1].rectangle,
                (sfVector2f) {-size_difference, zoom_shape[1].size.y});
            render_zoom(
                sfRectangleShape_getSize(zoom_shape[1].rectangle).x - 99.0);
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

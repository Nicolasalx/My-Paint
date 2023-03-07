/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"
#include "stdio.h"

void change_size_tool(int size_tool)
{
    switch (selected_tool) {
        case PENCIL:
            pencil.radius = size_tool;
            break;
        case BRUSH:
            brush.radius = size_tool;
            break;
        case FEATHER_PEN:
            feather_pen.radius = size_tool;
            break;
        case ERASER:
            eraser.radius = size_tool;
            break;
        default: break;
    }
}

void check_pos_mouse(void)
{
    if (mouse_pos.x >= icon_rectangle[size_icon_rectangle].pos.x &&
        mouse_pos.x <= icon_rectangle[size_icon_rectangle].pos.x +
            icon_rectangle[size_icon_rectangle].size.x) {
        if (mouse_pos.y <= icon_rectangle[size_icon_rectangle].pos.y &&
            mouse_pos.y >= icon_rectangle[size_icon_rectangle].pos.y -
                icon_rectangle[size_icon_rectangle - 1].size.y) {
            int size_difference = size_pen.pos.y - mouse_pos.y;
            sfRectangleShape_setSize(size_pen.rectangle,
                (sfVector2f) {40, -size_difference});
            if (size_difference == 190) {
                change_size_tool(100);
            } else {
                change_size_tool((size_difference * 100) / 190);
            }
        }
    }
}

void set_size_pen(sfRenderWindow *window, sfEvent event,
    bool is_button_pressed)
{
    if (is_button_pressed == true || (is_button_pressed == true &&
        event.type == sfEvtMouseMoved)) {
        check_pos_mouse();
    }
    sfRenderWindow_drawRectangleShape(window, size_pen.rectangle, NULL);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"
#include "stdio.h"
#include "my_graphical.h"

void set_size_tool_selected(void)
{
    int radius = 0;
    switch (selected_tool) {
        case PENCIL:
            radius = pencil.radius;
            break;
        case BRUSH:
            radius = brush.radius;
            break;
        case FEATHER_PEN:
            radius = feather_pen.radius;
            break;
        case ERASER:
            radius = eraser.radius;
            break;
        default: break;
    }
    radius = (radius * 190) / 100;
    sfRectangleShape_setSize(size_pen.rectangle, (sfVector2f) {40, -radius});
}

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
    if (is_mouse_over_rectangle_shape
        (icon_rectangle[size_icon_rectangle].rectangle) == true) {
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

void set_size_pen(sfRenderWindow *window, sfEvent *event)
{
    if (mouse_button_pressed == true || (mouse_button_maintain == true &&
        event->type == sfEvtMouseMoved)) {
        check_pos_mouse();
    }
    sfRenderWindow_drawRectangleShape(window, size_pen.rectangle, NULL);
}

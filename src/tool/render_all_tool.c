/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_all_tool
*/

#include "my.h"
#include "my_graphical.h"
#include "tool.h"

void render_all_tool(void)
{
    void (*tool_func_list[])(void) = {render_pencil, render_eraser,
    render_brush, render_feather_pen, render_hand};
    int nb_tool_func = sizeof(tool_func_list) / sizeof(tool_func_list[0]);

    for (int i = 0; i < nb_tool_func; ++i) {
        if (i == (int) selected_tool && is_mouse_over_rectangle_shape
            (edition_zone)) {
            (*tool_func_list[i])();
        }
    }
}

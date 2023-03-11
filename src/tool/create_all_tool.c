/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_all_tool
*/

#include "tool.h"

void create_all_tool(void)
{
    void (*create_tool_func[])(void) = {create_pencil, create_eraser, create_brush, create_feather_pen};
    int nb_create_tool_func = sizeof(create_tool_func) / sizeof(create_tool_func[0]);

    for (int i = 0; i < nb_create_tool_func; ++i) {
        (*create_tool_func[i])();
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** free_all_data
*/

#include "my.h"
#include "color_selection.h"
#include "tool.h"
#include "icon_to_draw.h"

void free_all_data(void)
{
    destroy_color_selection();
    destroy_icon_to_draw();
}

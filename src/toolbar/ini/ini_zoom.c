/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_zoom
*/

#include "my.h"
#include "toolbar.h"

void create_zoom_shape(int i)
{
    zoom_shape[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(zoom_shape[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(zoom_shape[i].rectangle, sfBlack);
    sfRectangleShape_setSize(zoom_shape[i].rectangle, zoom_shape[i].size);
    sfRectangleShape_setFillColor(zoom_shape[i].rectangle, zoom_shape[i].color);
    sfRectangleShape_setPosition(zoom_shape[i].rectangle, zoom_shape[i].pos);
}

void ini_zoom(void)
{
    
    for (int i = 0; i < size_zoom_shape; ++i) {
        create_zoom_shape(i);
    }
}

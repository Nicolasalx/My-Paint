/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_background
*/

#include "my.h"
#include "layer.h"

void render_background(sfRenderWindow *window)
{
    sfRectangleShape_setPosition(background, render_sheet_pos);
    sfRectangleShape_setSize(background, render_sheet_resolution);
    sfRectangleShape_setScale(background, render_sheet_scale);
    sfRenderWindow_drawRectangleShape(window, background, NULL);
}
/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** destroy
*/

#include "my.h"
#include "color_selection.h"

void destroy_color_selection(void)
{
    for (int i = 0; i < size_selection_color; ++i) {
        sfRectangleShape_destroy(selection_color[i].rectangle);
    }
    for (int i = 0; i < size_text_selection_color; ++i) {
        sfText_destroy(text_color_selection[i].text);
    }
    sfTexture_destroy(chromatic_wheel.texture);
    sfSprite_destroy(chromatic_wheel.sprite);
}

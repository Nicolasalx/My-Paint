/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"

void set_thickness_icon(int i, int * index_button_color)
{
    if (mouse_pos.x >= selection_color[i].pos.x && mouse_pos.x <=
        selection_color[i].pos.x + selection_color[i].size.x) {
        if (mouse_pos.y >= selection_color[i].pos.y && mouse_pos.y <=
            selection_color[i].pos.y + selection_color[i].size.y) {
            sfRectangleShape_setOutlineThickness
                (selection_color[* index_button_color].rectangle,
                    SIZE_OUTLINE_BUTTON_SEL_COLOR);

            sfRectangleShape_setOutlineThickness
                (selection_color[i].rectangle, 5);
            * index_button_color = i;
        }
    }
}

void display_color_selection_icon(sfRenderWindow *window, sfEvent event,
    int *index_button_color)
{
    for (int i = 0; i < size_selection_color; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            selection_color[i].rectangle, NULL);
    }
    sfRenderWindow_drawSprite(window, chromatic_wheel.sprite, NULL);
    for (int i = 0; i < size_text_selection_color; ++i) {
        sfRenderWindow_drawText(window, text_color_selection[i].text, NULL);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < size_selection_color; ++i) {
            set_thickness_icon(i, index_button_color);
        }
    }
}

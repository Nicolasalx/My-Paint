/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"

void create_button(int i)
{
    selection_color[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(color_selection_data.selection_color[i].rectangle, 3);
    sfRectangleShape_setOutlineColor(color_selection_data.selection_color[i].rectangle, sfBlack);
    sfRectangleShape_setSize(color_selection_data.selection_color[i].rectangle, (sfVector2f) SIZE_BUTTON);
    sfRectangleShape_setFillColor(color_selection_data.selection_color[i].rectangle, color_selection_data.selection_color[i].color);
    sfRectangleShape_setPosition(color_selection_data.selection_color[i].rectangle, color_selection_data.selection_color[i].pos);
}

void init_all_button_selection()
{
    for (int i = 0; i < size_button_color; ++i) {
        create_button(i);
    }
}

void ini_chromatic_wheel()
{
    color_selection_data.chromatic_wheel.texture = sfTexture_createFromFile("./game_data/color_selection/chromatic_wheel.png", NULL);
    color_selection_data.chromatic_wheel.sprite = sfSprite_create();
    sfSprite_setTexture(color_selection_data.chromatic_wheel.sprite, color_selection_data.chromatic_wheel.texture, sfTrue);
    sfSprite_setScale(color_selection_data.chromatic_wheel.sprite, color_selection_data.chromatic_wheel.size);
    sfSprite_setPosition(color_selection_data.chromatic_wheel.sprite, color_selection_data.chromatic_wheel.pos);
}

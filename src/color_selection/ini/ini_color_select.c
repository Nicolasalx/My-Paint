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
    sfRectangleShape_setOutlineThickness(selection_color[i].rectangle,
        SIZE_OUTLINE_BUTTON_SEL_COLOR);
    sfRectangleShape_setOutlineColor(selection_color[i].rectangle, sfBlack);
    sfRectangleShape_setSize(selection_color[i].rectangle,
        selection_color[i].size);
    sfRectangleShape_setFillColor(selection_color[i].rectangle,
        selection_color[i].color);
    sfRectangleShape_setPosition(selection_color[i].rectangle,
        selection_color[i].pos);
}

void init_all_button_selection(void)
{
    for (int i = 0; i < size_selection_color; ++i) {
        create_button(i);
    }
}

void create_text_selection_color(int i)
{
    text_color_selection[i].font =
        sfFont_createFromFile(text_color_selection[i].font_path);
    text_color_selection[i].text = sfText_create();
    sfText_setFont(text_color_selection[i].text, text_color_selection[i].font);
    sfText_setCharacterSize(text_color_selection[i].text, 25);
    sfText_setColor(text_color_selection[i].text, sfWhite);
    sfText_setPosition(text_color_selection[i].text,
        text_color_selection[i].pos);
    sfText_setString(text_color_selection[i].text,
        text_color_selection[i].path);

}

void init_all_text_selection_color(void)
{
    for (int i = 0; i < size_text_selection_color; ++i) {
        create_text_selection_color(i);
    }
}

void ini_chromatic_wheel(void)
{
    chromatic_wheel.texture = sfTexture_createFromFile
        (chromatic_wheel.path, NULL);
    chromatic_wheel.sprite = sfSprite_create();
    sfSprite_setTexture(chromatic_wheel.sprite,
        chromatic_wheel.texture, sfTrue);
    sfSprite_setScale(chromatic_wheel.sprite, chromatic_wheel.size);
    sfSprite_setPosition(chromatic_wheel.sprite, chromatic_wheel.pos);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_layer_menu_header(int i)
{
    layer_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(layer_menu_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(layer_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(layer_menu_header[i].rectangle,
        layer_menu_header[i].size);
    sfRectangleShape_setFillColor(layer_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(layer_menu_header[i].rectangle,
        layer_menu_header[i].pos);
}

void ini_layer_menu_header_rectangle_icon(void)
{
    for (int i = 0; i < size_layer_menu_header; ++i) {
        create_layer_menu_header(i);
    }
}

void create_layer_text(int i)
{
    text_layer_header[i].font =
        sfFont_createFromFile(text_layer_header[i].font_path);
    text_layer_header[i].text = sfText_create();
    sfText_setFont(text_layer_header[i].text, text_layer_header[i].font);
    sfText_setCharacterSize(text_layer_header[i].text, 25);
    sfText_setColor(text_layer_header[i].text, sfBlack);
    sfText_setPosition(text_layer_header[i].text, text_layer_header[i].pos);
    sfText_setString(text_layer_header[i].text, text_layer_header[i].path);
}

void ini_layer_text(void)
{
    for (int i = 0; i < size_text_layer_header; ++i) {
        create_layer_text(i);
    }
}

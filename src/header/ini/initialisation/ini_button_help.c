/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_help_menu_header(int i)
{
    help_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(help_menu_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(help_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(help_menu_header[i].rectangle,
        help_menu_header[i].size);
    sfRectangleShape_setFillColor(help_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(help_menu_header[i].rectangle,
        help_menu_header[i].pos);
}

void ini_help_menu_header_rectangle_icon(void)
{
    for (int i = 0; i < size_help_menu_header; ++i) {
        create_help_menu_header(i);
    }
}

void create_help_text(int i)
{
    text_help_header[i].font =
        sfFont_createFromFile(text_help_header[i].font_path);
    text_help_header[i].text = sfText_create();
    sfText_setFont(text_help_header[i].text, text_help_header[i].font);
    sfText_setCharacterSize(text_help_header[i].text, 25);
    sfText_setColor(text_help_header[i].text, sfBlack);
    sfText_setPosition(text_help_header[i].text, text_help_header[i].pos);
    sfText_setString(text_help_header[i].text, text_help_header[i].path);
}

void ini_help_text(void)
{
    for (int i = 0; i < size_text_help_header; ++i) {
        create_help_text(i);
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_view_text(int i)
{
    text_view_header[i].font =
        sfFont_createFromFile(text_view_header[i].font_path);
    text_view_header[i].text = sfText_create();
    sfText_setFont(text_view_header[i].text, text_view_header[i].font);
    sfText_setCharacterSize(text_view_header[i].text, 25);
    sfText_setColor(text_view_header[i].text, sfBlack);
    sfText_setPosition(text_view_header[i].text, text_view_header[i].pos);
    sfText_setString(text_view_header[i].text, text_view_header[i].path);
}

void ini_view_text(void)
{
    for (int i = 0; i < size_text_view_header; ++i) {
        create_view_text(i);
    }
}

void create_view_menu_header(int i)
{
    view_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(view_menu_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(view_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(view_menu_header[i].rectangle,
        view_menu_header[i].size);
    sfRectangleShape_setFillColor(view_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(view_menu_header[i].rectangle,
        view_menu_header[i].pos);
}

void ini_edit_menu_header_rectangle_icon(void)
{
    for (int i = 0; i < size_view_menu_header; ++i) {
        create_view_menu_header(i);
    }
}

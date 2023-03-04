/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_edit_menu_header(int i)
{
    edit_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(edit_menu_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(edit_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(edit_menu_header[i].rectangle,
        edit_menu_header[i].size);
    sfRectangleShape_setFillColor(edit_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(edit_menu_header[i].rectangle,
        edit_menu_header[i].pos);
}

void ini_edit_menu_header(void)
{
    for (int i = 0; i < size_edit_menu_header; ++i) {
        create_edit_menu_header(i);
    }
}

void create_edit_text(int i)
{
    text_edit_header[i].font =
        sfFont_createFromFile(text_edit_header[i].font_path);
    text_edit_header[i].text = sfText_create();
    sfText_setFont(text_edit_header[i].text, text_edit_header[i].font);
    sfText_setCharacterSize(text_edit_header[i].text, 25);
    sfText_setColor(text_edit_header[i].text, sfBlack);
    sfText_setPosition(text_edit_header[i].text, text_edit_header[i].pos);
    sfText_setString(text_edit_header[i].text, text_edit_header[i].path);
}

void ini_edit_text(void)
{
    for (int i = 0; i < size_text_edit_header; ++i) {
        create_edit_text(i);
    }
}

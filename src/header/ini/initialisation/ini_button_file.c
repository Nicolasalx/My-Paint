/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_file_menu_header(int i)
{
    file_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(file_menu_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(file_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(file_menu_header[i].rectangle,
        file_menu_header[i].size);
    sfRectangleShape_setFillColor(file_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(file_menu_header[i].rectangle,
        file_menu_header[i].pos);
}

void ini_file_menu_header(void)
{
    for (int i = 0; i < size_file_menu_header; ++i) {
        create_file_menu_header(i);
    }
}

void create_file_text(int i)
{
    text_file_header[i].font =
        sfFont_createFromFile(text_file_header[i].font_path);
    text_file_header[i].text = sfText_create();
    sfText_setFont(text_file_header[i].text, text_file_header[i].font);
    sfText_setCharacterSize(text_file_header[i].text, 25);
    sfText_setColor(text_file_header[i].text, sfBlack);
    sfText_setPosition(text_file_header[i].text, text_file_header[i].pos);
    sfText_setString(text_file_header[i].text, text_file_header[i].path);
}

void ini_file_text(void)
{
    for (int i = 0; i < size_text_file_header; ++i) {
        create_file_text(i);
    }
}

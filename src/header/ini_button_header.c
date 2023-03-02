/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

void create_button_header(int i)
{
    button_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(button_header[i].rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(button_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(button_header[i].rectangle, button_header[i].size);
    sfRectangleShape_setFillColor(button_header[i].rectangle, BG_COLOR);
    sfRectangleShape_setPosition(button_header[i].rectangle, button_header[i].pos);
}

void ini_button_header(void)
{
    for (int i = 0; i < size_button_header; ++i) {
        create_button_header(i);
    }
}

void create_text_button_header(int i)
{
    text_button_header[i].font = sfFont_createFromFile(text_button_header[i].font_path);
    text_button_header[i].text = sfText_create();
    sfText_setFont(text_button_header[i].text, text_button_header[i].font);
    sfText_setCharacterSize(text_button_header[i].text, 25);
    sfText_setColor(text_button_header[i].text, sfWhite);
    sfText_setPosition(text_button_header[i].text, text_button_header[i].pos);
    sfText_setString(text_button_header[i].text, text_button_header[i].path);
}

void ini_text_button_header(void)
{
    for (int i = 0; i < size_text_button_header; ++i) {
        create_text_button_header(i);
    }
}

void create_file_menu_header(int i)
{
    file_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(file_menu_header[i].rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(file_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(file_menu_header[i].rectangle, file_menu_header[i].size);
    sfRectangleShape_setFillColor(file_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(file_menu_header[i].rectangle, file_menu_header[i].pos);
}

void ini_file_menu_header(void)
{
    for (int i = 0; i < size_file_menu_header; ++i) {
        create_file_menu_header(i);
    }
}

void create_file_text(int i)
{
    text_file_header[i].font = sfFont_createFromFile(text_file_header[i].font_path);
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


void create_edit_menu_header(int i)
{
    edit_menu_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(edit_menu_header[i].rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(edit_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(edit_menu_header[i].rectangle, edit_menu_header[i].size);
    sfRectangleShape_setFillColor(edit_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(edit_menu_header[i].rectangle, edit_menu_header[i].pos);
}

void ini_edit_menu_header(void)
{
    for (int i = 0; i < size_edit_menu_header; ++i) {
        create_edit_menu_header(i);
    }
}

void create_edit_text(int i)
{
    text_edit_header[i].font = sfFont_createFromFile(text_edit_header[i].font_path);
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


void create_view_text(int i)
{
    text_view_header[i].font = sfFont_createFromFile(text_view_header[i].font_path);
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
    sfRectangleShape_setOutlineThickness(view_menu_header[i].rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(view_menu_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(view_menu_header[i].rectangle, view_menu_header[i].size);
    sfRectangleShape_setFillColor(view_menu_header[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(view_menu_header[i].rectangle, view_menu_header[i].pos);
}

void ini_edit_menu_header_rectangle_icon(void)
{
    for (int i = 0; i < size_view_menu_header; ++i) {
        create_view_menu_header(i);
    }
}

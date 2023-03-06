/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

// ! BUTTON HEADER

void create_button_header(int i)
{
    button_header[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(button_header[i].rectangle,
        SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(button_header[i].rectangle, sfBlack);
    sfRectangleShape_setSize(button_header[i].rectangle,
        button_header[i].size);
    sfRectangleShape_setFillColor(button_header[i].rectangle, (sfColor) BG_COLOR);
    sfRectangleShape_setPosition(button_header[i].rectangle,
        button_header[i].pos);
}

void ini_button_header(void)
{
    for (int i = 0; i < size_button_header; ++i) {
        create_button_header(i);
    }
}

void create_text_button_header(int i)
{
    text_button_header[i].font =
        sfFont_createFromFile(text_button_header[i].font_path);
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

// ! FIN BUTTON HEADER

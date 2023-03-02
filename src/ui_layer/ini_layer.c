/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "ui_layer.h"

void create_layer_box(int i)
{
    box_icon_layer[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(box_icon_layer[i].rectangle, 3);
    sfRectangleShape_setOutlineColor(box_icon_layer[i].rectangle, sfBlack);
    sfRectangleShape_setSize(box_icon_layer[i].rectangle, box_icon_layer[i].size);
    sfRectangleShape_setFillColor(box_icon_layer[i].rectangle, sfWhite);
    sfRectangleShape_setPosition(box_icon_layer[i].rectangle, box_icon_layer[i].pos);
}

void ini_layer_box(void)
{
    for (int i = 0; i < size_box_icon_layer; ++i) {
        create_layer_box(i);
    }
}

void create_text_layer_box(int i)
{
    text_icon_layer[i].font = sfFont_createFromFile(text_icon_layer[i].font_path);
    text_icon_layer[i].text = sfText_create();
    sfText_setFont(text_icon_layer[i].text, text_icon_layer[i].font);
    sfText_setCharacterSize(text_icon_layer[i].text, 25);
    sfText_setColor(text_icon_layer[i].text, sfBlack);
    sfText_setPosition(text_icon_layer[i].text, text_icon_layer[i].pos);
    sfText_setString(text_icon_layer[i].text, text_icon_layer[i].path);
}

void ini_text_layer_box(void)
{
    for (int i = 0; i < size_text_icon_layer; ++i) {
        create_text_layer_box(i);
    }
}

void create_eye_sprite(int i)
{
    icon_eye_layer[i].texture = sfTexture_createFromFile(icon_eye_layer[i].path, NULL);
    icon_eye_layer[i].sprite = sfSprite_create();
    sfSprite_setTexture(icon_eye_layer[i].sprite, icon_eye_layer[i].texture, sfTrue);
    sfSprite_setScale(icon_eye_layer[i].sprite, icon_eye_layer[i].size);
    sfSprite_setPosition(icon_eye_layer[i].sprite, icon_eye_layer[i].pos);
}

void ini_eye_sprite(void)
{
    for (int i = 0; i < size_icon_eye_layer; ++i) {
        create_eye_sprite(i);
    }
}


void create_button_eye_layer(int i)
{
    button_eye_layer[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(button_eye_layer[i].rectangle, 3);
    sfRectangleShape_setOutlineColor(button_eye_layer[i].rectangle, sfBlack);
    sfRectangleShape_setSize(button_eye_layer[i].rectangle, button_eye_layer[i].size);
    sfRectangleShape_setFillColor(button_eye_layer[i].rectangle, BG_COLOR);
    sfRectangleShape_setPosition(button_eye_layer[i].rectangle, button_eye_layer[i].pos);
}

void ini_button_eye_layer(void)
{
    for (int i = 0; i < size_button_eye_layer; ++i) {
        create_button_eye_layer(i);
    }
}

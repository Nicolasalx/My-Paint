/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "ui_layer.h"

void create_eye_sprite(int i)
{
    icon_eye_layer[i].texture =
        sfTexture_createFromFile(icon_eye_layer[i].path, NULL);
    icon_eye_layer[i].sprite = sfSprite_create();
    sfSprite_setTexture(icon_eye_layer[i].sprite, icon_eye_layer[i].texture,
        sfTrue);
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
    sfRectangleShape_setSize(button_eye_layer[i].rectangle,
        button_eye_layer[i].size);
    sfRectangleShape_setFillColor(button_eye_layer[i].rectangle, BG_COLOR);
    sfRectangleShape_setPosition(button_eye_layer[i].rectangle,
        button_eye_layer[i].pos);
}

void ini_button_eye_layer(void)
{
    for (int i = 0; i < size_button_eye_layer; ++i) {
        create_button_eye_layer(i);
    }
}

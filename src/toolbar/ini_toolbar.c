/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"
#include <stdio.h>

void create_icon_rectangle(int i)
{
    icon_rectangle[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(icon_rectangle[i].rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(icon_rectangle[i].rectangle, sfBlack);
    sfRectangleShape_setSize(icon_rectangle[i].rectangle, icon_rectangle[i].size);
    sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, BG_COLOR);
    sfRectangleShape_setPosition(icon_rectangle[i].rectangle, icon_rectangle[i].pos);
}

void ini_icon_rectangle(void)
{
    for (int i = 0; i < size_icon_rectangle; ++i) {
        create_icon_rectangle(i);
    }
}

void create_icon_sprite(int i)
{
    icon_sprite[i].texture = sfTexture_createFromFile(icon_sprite[i].path, NULL);
    icon_sprite[i].sprite = sfSprite_create();
    sfSprite_setTexture(icon_sprite[i].sprite, icon_sprite[i].texture, sfTrue);
    sfSprite_setScale(icon_sprite[i].sprite, icon_sprite[i].size);
    sfSprite_setPosition(icon_sprite[i].sprite, icon_sprite[i].pos);
}

void ini_icon_sprite(void)
{
    for (int i = 0; i < size_icon_sprite; ++i) {
        create_icon_sprite(i);
    }
}

void ini_size_pen(void)
{
    size_pen.rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(size_pen.rectangle, SIZE_OUTLINE_BUTTON);
    sfRectangleShape_setOutlineColor(size_pen.rectangle, sfBlack);
    sfRectangleShape_setSize(size_pen.rectangle, size_pen.size);
    sfRectangleShape_setFillColor(size_pen.rectangle, size_pen.color);
    sfRectangleShape_setPosition(size_pen.rectangle, size_pen.pos);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_pencil
*/

#include "tool.h"

void create_feather_pen(void)
{
    feather_pen.texture = sfTexture_createFromFile("game_data/tool/feather_pen_texture.png", NULL);
    feather_pen.texture_size = sfTexture_getSize(feather_pen.texture);
    feather_pen.sprite = sfSprite_create();
    sfSprite_setTexture(feather_pen.sprite, feather_pen.texture, sfTrue);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_pencil
*/

#include "tool.h"

void create_brush(void)
{
    brush.texture =
        sfTexture_createFromFile("game_data/tool/brush_texture.png", NULL);
    brush.texture_size = sfTexture_getSize(brush.texture);
    brush.sprite = sfSprite_create();
    sfSprite_setTexture(brush.sprite, brush.texture, sfTrue);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_pencil
*/

#include "tool.h"

void create_pencil(void)
{
    pencil.circle = sfCircleShape_create();
    pencil.rect = sfRectangleShape_create();

    pencil.texture = sfTexture_createFromFile("game_data/tool/brush_texture.png", NULL);
    pencil.texture_size = sfTexture_getSize(pencil.texture);
    pencil.sprite = sfSprite_create();
    sfSprite_setTexture(pencil.sprite, pencil.texture, sfTrue);
}

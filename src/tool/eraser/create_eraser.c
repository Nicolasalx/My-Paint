/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_pencil
*/

#include "tool.h"

void create_eraser(void)
{
    eraser.circle = sfCircleShape_create();
    eraser.rect = sfRectangleShape_create();

    eraser.texture = sfTexture_createFromFile("game_data/tool/brush_texture.png", NULL);
    eraser.texture_size = sfTexture_getSize(eraser.texture);
    eraser.sprite = sfSprite_create();
    sfSprite_setTexture(eraser.sprite, eraser.texture, sfTrue);
}

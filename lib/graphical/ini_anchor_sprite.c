/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_anchor_sprite
*/

#include "my_graphical.h"

void ini_anchor_sprite(sfSprite *sprite, anchor_t anchor)
{
    switch (anchor) {
    case TOP_LEFT:
        sfSprite_setOrigin(sprite, (sfVector2f) {0, 0});
        break;
    case TOP_RIGHT:
        sfSprite_setOrigin(sprite, (sfVector2f) {
            sfTexture_getSize(sfSprite_getTexture(sprite)).x, 0});
        break;
    case BOTTOM_LEFT:
        sfSprite_setOrigin(sprite, (sfVector2f)
            {0, sfTexture_getSize(sfSprite_getTexture(sprite)).y});
        break;
    case BOTTOM_RIGHT:
        sfSprite_setOrigin(sprite, (sfVector2f) {
            sfTexture_getSize(sfSprite_getTexture(sprite)).x,
            sfTexture_getSize(sfSprite_getTexture(sprite)).y
        });
        break;
    }
}

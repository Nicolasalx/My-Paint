/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_anchor_sprite
*/

#include "my_graphical.h"

void ini_anchor_sprite(sfSprite *sprite, anchor_t anchor)
{
    sfVector2u texture_size = sfTexture_getSize(sfSprite_getTexture(sprite));
    switch (anchor) {
    case TOP_LEFT:
        sfSprite_setOrigin(sprite, (sfVector2f) {0, 0});
        break;
    case TOP_RIGHT:
        sfSprite_setOrigin(sprite, (sfVector2f) {
            texture_size.x, 0});
        break;
    case BOTTOM_LEFT:
        sfSprite_setOrigin(sprite, (sfVector2f) {0,
        texture_size.y});
        break;
    case BOTTOM_RIGHT:
        sfSprite_setOrigin(sprite, (sfVector2f) {
            texture_size.x,
            texture_size.y
        });
        break;
    }
}

void ini_anchor_rect(sfRectangleShape *rect, anchor_t anchor)
{
    sfVector2f rect_size = sfRectangleShape_getSize(rect);
    switch (anchor) {
    case TOP_LEFT:
        sfRectangleShape_setOrigin(rect, (sfVector2f) {0, 0});
        break;
    case TOP_RIGHT:
        sfRectangleShape_setOrigin(rect, (sfVector2f) {
            rect_size.x, 0});
        break;
    case BOTTOM_LEFT:
        sfRectangleShape_setOrigin(rect, (sfVector2f) {0,
            rect_size.y
        });
        break;
    case BOTTOM_RIGHT:
        sfRectangleShape_setOrigin(rect, rect_size);
        break;
    }
}

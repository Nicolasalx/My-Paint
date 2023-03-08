/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** set_pos_sprite_with_anchor
*/

#include "my.h"
#include "my_graphical.h"

void set_pos_sprite_with_anchor(sfSprite *sprite, anchor_t anchor)
{
    switch (anchor) {
    case TOP_LEFT:
        break;
    case TOP_RIGHT:
        sfSprite_setPosition(sprite, (sfVector2f) {window_size.x, 0});
        break;
    case BOTTOM_LEFT:
        sfSprite_setPosition(sprite, (sfVector2f) {0, window_size.y});
        break;
    case BOTTOM_RIGHT:
        sfSprite_setPosition(sprite, (sfVector2f) {window_size.x, window_size.y});
        break;
    }
}

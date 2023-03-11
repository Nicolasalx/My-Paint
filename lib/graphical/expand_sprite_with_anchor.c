/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** expand_sprite_with_anchor
*/

#include "my.h"
#include "my_graphical.h"

void expand_sprite_with_anchor(sfSprite *sprite, anchor_t anchor)
{
    if ((anchor == TOP_LEFT || anchor == BOTTOM_LEFT) &&
        window_size.x > 1920) {
        sfSprite_setScale(sprite,
        (sfVector2f) {window_size.x / 1920.0f, 1.0f});
    } else if ((anchor == TOP_RIGHT || anchor == BOTTOM_RIGHT) &&
        window_size.y > 1080) {
        sfSprite_setScale(sprite,
        (sfVector2f) {1.0f, window_size.y / 1080.0f});
    } else {
        sfSprite_setScale(sprite, (sfVector2f) {1.0f, 1.0f});
    }
}

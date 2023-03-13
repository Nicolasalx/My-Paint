/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** set_pos_sprite_with_anchor
*/

#include "my.h"
#include "my_graphical.h"

void set_pos_sprite_with_anchor(sfSprite *sprite, sfVector2f offset,
    anchor_t anchor)
{
    switch (anchor) {
    case TOP_LEFT:
        sfSprite_setPosition(sprite, offset);
        break;
    case TOP_RIGHT:
        sfSprite_setPosition(sprite, (sfVector2f)
            {window_size.x + offset.x, offset.y});
        break;
    case BOTTOM_LEFT:
        sfSprite_setPosition(sprite, (sfVector2f)
            {offset.x, window_size.y + offset.y});
        break;
    case BOTTOM_RIGHT:
        sfSprite_setPosition(sprite, (sfVector2f)
            {window_size.x + offset.x, window_size.y + offset.y});
        break;
    }
}

void set_pos_rect_with_anchor(sfRectangleShape *rect, sfVector2f offset,
    anchor_t anchor)
{
    switch (anchor) {
    case TOP_LEFT:
        sfRectangleShape_setPosition(rect, offset);
        break;
    case TOP_RIGHT:
        sfRectangleShape_setPosition(rect, (sfVector2f)
            {window_size.x + offset.x, offset.y});
        break;
    case BOTTOM_LEFT:
        sfRectangleShape_setPosition(rect, (sfVector2f)
            {offset.x, window_size.y + offset.y});
        break;
    case BOTTOM_RIGHT:
        sfRectangleShape_setPosition(rect, (sfVector2f)
            {window_size.x + offset.x, window_size.y + offset.y});
        break;
    }
}

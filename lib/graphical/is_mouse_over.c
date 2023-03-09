/*
** EPITECH PROJECT, 2022
** mouse_is_over
** File description:
** mouse_is_over
*/

#include "my_graphical.h"
#include "my.h"
#include <stdbool.h>

sfBool is_mouse_over_rectangle_shape(sfRectangleShape* rectangle_shape)
{
    sfFloatRect rectangle_bound =
    sfRectangleShape_getGlobalBounds(rectangle_shape);
    return sfFloatRect_contains(&rectangle_bound, mouse_pos.x, mouse_pos.y);
}

sfBool is_mouse_over_sprite(sfSprite *sprite)
{
    sfFloatRect sprite_bound =
    sfSprite_getGlobalBounds(sprite);
    return sfFloatRect_contains(&sprite_bound, mouse_pos.x, mouse_pos.y);
}

/*
** EPITECH PROJECT, 2022
** mouse_is_over
** File description:
** mouse_is_over
*/

#include "my_graphical.h"
#include <stdbool.h>

sfBool is_mouse_over_rectangle_shape(sfRectangleShape* rectangle_shape, sfVector2i mouse)
{
    sfFloatRect rectangle_bound = sfRectangleShape_getGlobalBounds(rectangle_shape);
    return sfFloatRect_contains(&rectangle_bound, mouse.x, mouse.y);
}

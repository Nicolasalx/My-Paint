/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** compute_pos_and_scale_rectangle_shape
*/

#include "my_graphical.h"

sfFloatRect compute_rect_pos_and_scale(sfFloatRect parent_rect,
    sfFloatRect child_rect, float padding)
{
    parent_rect.left += padding;
    parent_rect.top += padding;
    parent_rect.width -= padding * 2;
    parent_rect.height -= padding * 2;

    float scale_x = parent_rect.width / child_rect.width;
    float scale_y = parent_rect.height / child_rect.height;
    float scale = scale_x < scale_y ? scale_x : scale_y;

    child_rect.width *= scale;
    child_rect.height *= scale;

    child_rect.left = parent_rect.left +
    (parent_rect.width - child_rect.width) / 2;
    child_rect.top = parent_rect.top +
    (parent_rect.height - child_rect.height) / 2;
    return child_rect;
}

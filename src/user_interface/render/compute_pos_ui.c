/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** compute_pos_ui
*/

#include "my.h"
#include "user_interface.h"

sfVector2f compute_anchor_pos(sfVector2f offset, sfVector2f size, anchor_t anchor)
{
    sfVector2f position = {0, 0};

    switch (anchor) {
        case TOP_LEFT:
            position.x = offset.x;
            position.y = offset.y;
            break;
        case TOP_RIGHT:
            position.x = window_size.x - offset.x - size.x;
            position.y = offset.y;
            break;
        case BOTTOM_LEFT:
            position.x = offset.x;
            position.y = window_size.y - offset.y - size.y;
            break;
        case BOTTOM_RIGHT:
            position.x = window_size.x - offset.x - size.x;
            position.y = window_size.y - offset.y - size.y;
            break;
    }
    return position;
}

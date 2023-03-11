/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** is_window_resize
*/

#include "my.h"

sfBool is_window_resized(void)
{
    static sfVector2u last_window_size = {0, 0};
    if (last_window_size.x != window_size.x ||
        last_window_size.y != window_size.y) {
        last_window_size.x = window_size.x;
        last_window_size.y = window_size.y;
        return true;
    }
    return false;
}

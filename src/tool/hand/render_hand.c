/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_hand
*/

#include "my.h"
#include "my_graphical.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void render_hand(void)
{
    static bool was_pressed = false;
    bool is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    static sfVector2i last_pressed_pos = {0, 0};

    if (was_pressed == false && is_pressed == true) {
        last_pressed_pos = mouse_pos;
    }

    was_pressed = is_pressed;
}

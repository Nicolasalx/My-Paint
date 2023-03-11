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
#include "my_number.h"

void render_hand(void)
{
    static bool was_pressed = false;
    static bool was_clicked = false;
    static sfVector2i last_pressed_pos = {0, 0};

    if (is_mouse_over_sprite(GET_DATA(selected_layer, layer_t)->render_sprite) &&
        (mouse_button_pressed || was_clicked)) {
        was_clicked = true;
        if (was_pressed == false && mouse_button_maintain == true) {
            last_pressed_pos = mouse_pos;
        }
        if (mouse_button_maintain == true) {
            render_sheet_pos.x += my_delta(last_pressed_pos.x, mouse_pos.x);
            render_sheet_pos.y += my_delta(last_pressed_pos.y, mouse_pos.y);
            last_pressed_pos = mouse_pos;
        }
        was_pressed = mouse_button_maintain;
    } else {
        was_clicked = false;
    }
}

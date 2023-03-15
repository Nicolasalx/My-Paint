/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_button_ui_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void render_button_ui_layer(sfRenderWindow *window)
{
    for (int i = 0; i < size_button_ui_layer; ++i) {
        set_pos_rect_with_anchor(button_ui_layer[i].box,
            button_ui_layer[i].offset, button_ui_layer[i].anchor);
        set_pos_sprite_with_anchor(button_ui_layer[i].sprite,
            button_ui_layer[i].offset_sprite, button_ui_layer[i].anchor);
        if (is_mouse_over_rectangle_shape(button_ui_layer[i].box)) {
            sfRectangleShape_setFillColor(button_ui_layer[i].box,
                (sfColor) {170, 255, 170, 255});
            if (mouse_button_pressed)
                button_ui_layer[i].redirect();
        } else {
            sfRectangleShape_setFillColor(button_ui_layer[i].box,
                (sfColor) {150, 150, 150, 255});
        }
        sfRenderWindow_drawRectangleShape(
            window, button_ui_layer[i].box, NULL);
        sfRenderWindow_drawSprite(window, button_ui_layer[i].sprite, NULL);
    }
}

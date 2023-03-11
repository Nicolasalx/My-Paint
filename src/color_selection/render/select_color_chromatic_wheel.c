/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"
#include "my_graphical.h"
#include "tool.h"

sfVector2f render_texture_size = {
    (float) 500.0f / 0.5f,
    (float) 500.0f / 0.5f
};

void select_color_chromatic_wheel(void)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_over_sprite(chromatic_wheel.sprite)) {
        sfVector2f render_texture_pos = {
            (mouse_pos.x - chromatic_wheel.pos.x) / chromatic_wheel.size.x,
            (mouse_pos.y - chromatic_wheel.pos.y) / chromatic_wheel.size.y
        };
        sfVector2f result_pos = {
            render_texture_pos.x + (1.0f / render_texture_size.x),
            render_texture_pos.y + (1.0f / render_texture_size.y)
        };
        sfImage* image_chromatic_wheel =
            sfImage_createFromFile(chromatic_wheel.path);
        sfColor color_chromatic = sfImage_getPixel(image_chromatic_wheel,
            result_pos.x, result_pos.y);
        if (color_chromatic.a != sfTransparent.a) {
            change_color_tool(color_chromatic);
        }
        sfImage_destroy(image_chromatic_wheel);
    }
}

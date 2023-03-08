/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** get_mouse_pos_on_render_texture
*/

#include "my.h"

sfVector2f get_mouse_pos_on_sheet(void)
{
    sfVector2f render_texture_pos = {
        (mouse_pos.x - render_sheet_pos.x) / render_sheet_scale.x,
        (mouse_pos.y - render_sheet_pos.y) / render_sheet_scale.y
    };
    sfVector2f render_texture_size = {
        (float) render_sheet_res.x / render_sheet_scale.x,
        (float) render_sheet_res.y / render_sheet_scale.y
    };
    sfVector2f result_pos = {
        render_texture_pos.x + (1.0f / render_texture_size.x),
        render_texture_pos.y + (1.0f / render_texture_size.y)
    };
    return result_pos;
}

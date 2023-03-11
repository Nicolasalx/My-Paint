/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "layer.h"
#include "my_graphical.h"

void check_undo_redo_possibility(void)
{
    if (GET_DATA(selected_layer, layer_t)->current_version ==
    GET_DATA(selected_layer, layer_t)->head_undo) {
        icon_undo_redo[UNDO].enable = false;
    } else {
        icon_undo_redo[UNDO].enable = true;
    }
    if (GET_DATA(selected_layer, layer_t)->head_undo->prev ==
    GET_DATA(selected_layer, layer_t)->current_version) {
        icon_undo_redo[REDO].enable = false;
    } else {
        icon_undo_redo[REDO].enable = true;
    }
}

void render_undo_redo(sfRenderWindow *window)
{
    check_undo_redo_possibility();
    button_anim_t button_anim = {
        .disable = UNDO_REDO_DISABLE_COLOR,
        .idle = UNDO_REDO_ENABLE_COLOR,
        .overed = UNDO_REDO_OVERED_COLOR,
        .maintain = UNDO_REDO_MAINTAIN_COLOR,
        .move = {0, 5}
    };
    for (int i = 0; i < size_icon_undo_redo; ++i) {
        handle_sprite_button_state(icon_undo_redo[i].sprite, &button_anim, icon_undo_redo[i].enable);
        if (icon_undo_redo[i].enable && is_mouse_over_sprite(icon_undo_redo[i].sprite) && mouse_button_pressed) {
            icon_undo_redo[i].redirect();
        }
        sfRenderWindow_drawSprite(window, icon_undo_redo[i].sprite, NULL);
        if (window_size.x > 1050) {
            set_pos_sprite_with_anchor(icon_undo_redo[i].sprite,
            icon_undo_redo[i].offset, icon_undo_redo[i].anchor);
        }
    }
}

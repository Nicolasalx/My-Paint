/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "layer.h"
#include "my_graphical.h"

typedef struct {
    sfColor disable;
    sfColor idle;
    sfColor overed;
    sfColor maintain;
} button_state_color_t;

void handle_button_state(sfSprite *sprite, sfColor *state_color, bool enable)
{
    bool is_mouse_over = is_mouse_over_sprite(sprite);
    if (enable == false) {
        sfSprite_setColor(sprite, (sfColor) UNDO_REDO_DISABLE_COLOR);
    } else if (is_mouse_over == false) {
        sfSprite_setColor(sprite, (sfColor) UNDO_REDO_ENABLE_COLOR);
    } else if (is_mouse_over && mouse_button_maintain == false) {
        sfSprite_setColor(sprite, (sfColor) UNDO_REDO_OVERED_COLOR);
    } else if (is_mouse_over && mouse_button_maintain) {
        sfSprite_move(sprite, (sfVector2f) {0.f, 5.f});
        sfSprite_setColor(sprite, (sfColor) UNDO_REDO_MAINTAIN_COLOR);
    }
}

void render_undo_redo(sfRenderWindow *window)
{
    for (int i = 0; i < size_icon_undo_redo; ++i) {

        if (is_mouse_over_sprite(icon_undo_redo[i].sprite) && mouse_button_pressed) {
            printf("CALL ! \n");
            icon_undo_redo[i].redirect();
        }
        sfRenderWindow_drawSprite(window, icon_undo_redo[i].sprite, NULL);
        set_pos_sprite_with_anchor(icon_undo_redo[i].sprite, icon_undo_redo[i].offset, icon_undo_redo[i].anchor);
    }
}

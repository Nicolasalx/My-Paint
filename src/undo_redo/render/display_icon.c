/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "layer.h"
#include "my_graphical.h"

void undo(void)
{
    return;
}

void redo(void)
{
    return;
}

void select_redirect(int i, button_state_t button_state)
{
    if (button_state == BUTTON_PRESSED) {
        icon_undo_redo[i].redirect();
    }
}

void display_undo_redo(sfRenderWindow *window)
{
    for (int i = 0; i < size_icon_undo_redo; ++i) {
        sfRenderWindow_drawSprite(window, icon_undo_redo[i].sprite, NULL);
        if (is_mouse_over_sprite(icon_undo_redo[i].sprite) && sfMouse_isButtonPressed(sfMouseLeft)) {
            select_redirect(i, BUTTON_PRESSED);
        }
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_ui
*/

#include "my.h"
#include "user_interface.h"

void display_ui(sfRenderWindow *window)
{
    for (int i = 0; i < size_ui_sprite; ++i) {
        set_pos_sprite_with_anchor(ui_sprite[i].sprite, ui_sprite[i].pos, ui_sprite[i].anchor);
        if (ui_sprite[i].expand == true) {
            expand_sprite_with_anchor(ui_sprite[i].sprite, ui_sprite[i].anchor);
        }
        sfRenderWindow_drawSprite(window, ui_sprite[i].sprite, NULL);
    }
}

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
        set_pos_sprite_with_anchor(ui_sprite[i].sprite, ui_sprite[i].anchor);
        if ((ui_sprite[i].anchor == TOP_LEFT || ui_sprite[i].anchor == BOTTOM_LEFT) && window_size.x > 1920) {
            sfSprite_setScale(ui_sprite[i].sprite, (sfVector2f) {window_size.x / 1920.0f, 1.0f});
        } else if ((ui_sprite[i].anchor == TOP_RIGHT || ui_sprite[i].anchor == BOTTOM_RIGHT) && window_size.y > 1080) {
            sfSprite_setScale(ui_sprite[i].sprite, (sfVector2f) {1.0f, window_size.y / 1080.0f});
        } else {
            sfSprite_setScale(ui_sprite[i].sprite, (sfVector2f) {1.0f, 1.0f});
        }
        sfRenderWindow_drawSprite(window, ui_sprite[i].sprite, NULL);
    }
}

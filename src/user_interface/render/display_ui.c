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
    sfSprite_setPosition(ui_sprite[0].sprite, (sfVector2f) {0, 0});
    sfSprite_setPosition(ui_sprite[1].sprite, (sfVector2f) {0, window_size.y});
    sfSprite_setPosition(ui_sprite[2].sprite, (sfVector2f) {0, 0});
    sfSprite_setPosition(ui_sprite[3].sprite, (sfVector2f) {window_size.x, 0});
    for (int i = 0; i < size_ui_sprite; ++i) {
        sfRenderWindow_drawSprite(window, ui_sprite[i].sprite, NULL);
    }
}

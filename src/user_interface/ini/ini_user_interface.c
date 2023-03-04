/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_user_interface
*/

#include "my.h"
#include "user_interface.h"

void ini_bg_user_interface(void)
{
    for (int i = 0; i < size_ui_sprite; ++i) {
        ui_sprite[i].sprite = sfSprite_create();
        ui_sprite[i].texture =
            sfTexture_createFromFile(ui_sprite[i].path, NULL);
        sfSprite_setTexture(ui_sprite[i].sprite, ui_sprite[i].texture, sfTrue);
        sfSprite_setPosition(ui_sprite[i].sprite, ui_sprite[i].pos);
    }
}

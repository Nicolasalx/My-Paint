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
    for (int i = 0; i < size_user_interface; ++i) {
        ui_sprite[i].sprite = sfSprite_create();
        ui_sprite[i].texture = sfTexture_createFromFile(ui_sprite[i].path, NULL);
        sfSprite_setTexture(ui_sprite[i].sprite, ui_sprite[i].texture, sfTrue);
        sfSprite_setPosition(ui_sprite[i].sprite, ui_sprite[i].pos);
    }
}

void ini_draw_img_user_interface()
{
    user_interface->background_draw = sfRectangleShape_create();
    sfRectangleShape_setSize(user_interface->background_draw, user_interface->size);
    sfRectangleShape_setFillColor(user_interface->background_draw, sfWhite);
    sfRectangleShape_setOutlineThickness(user_interface->background_draw, 2.f);
    sfRectangleShape_setOutlineColor(user_interface->background_draw, sfWhite);
    sfVector2f background_draw_position = {
        (float)window_size.x * 0.42f - 0.5f * sfRectangleShape_getSize(user_interface->background_draw).x,
        (float)window_size.y * 0.52f - 0.5f * sfRectangleShape_getSize(user_interface->background_draw).y
    };
    sfRectangleShape_setPosition(user_interface->background_draw, background_draw_position);
}

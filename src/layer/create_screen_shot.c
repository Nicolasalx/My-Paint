/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_screen_shot
*/

#include "my.h"
#include "layer.h"

sfSprite *create_screen_shot(sfTexture *texture_render_texture)
{
    sfSprite *screen_shot = sfSprite_create();
    sfSprite_setTexture(screen_shot, texture_render_texture, sfFalse);
    return screen_shot;
}

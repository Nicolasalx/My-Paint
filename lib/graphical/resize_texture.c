/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** resize_texture
*/

#include "my_graphical.h"

sfTexture *resize_texture(sfTexture *texture, sfVector2u new_size)
{
    sfTexture *tmp_texture = sfTexture_create(new_size.x, new_size.y);
    sfTexture_updateFromTexture(tmp_texture, texture, 0, 0);
    sfTexture_destroy(texture);
    texture = tmp_texture;
    return texture;
}

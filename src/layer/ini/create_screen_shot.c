/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_screen_shot
*/

#include "my.h"
#include "layer.h"

sfTexture *create_screen_shot(sfTexture *texture_render_texture)
{
    return sfTexture_copy(texture_render_texture);
}

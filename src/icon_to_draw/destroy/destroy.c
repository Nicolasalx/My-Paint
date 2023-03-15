/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** destroy
*/

#include "icon_to_draw.h"
#include "tool.h"

void destroy_icon_to_draw(void)
{
    for (int i = 0; i < size_icon_to_draw; ++i) {
        sfCircleShape_destroy(icon_to_draw[i].circle);
        sfTexture_destroy(icon_to_draw[i].texture);
        sfSprite_destroy(icon_to_draw[i].sprite);
    }
}

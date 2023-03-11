/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** get_button_state
*/

#include "my_graphical.h"
#include "my.h"

void handle_sprite_button_state(sfSprite *sprite, button_anim_t *button_anim, bool enable)
{
    bool is_mouse_over = is_mouse_over_sprite(sprite);
    if (enable == false) {
        sfSprite_setColor(sprite, button_anim->disable);
    } else if (is_mouse_over == false) {
        sfSprite_setColor(sprite, button_anim->idle);
    } else if (is_mouse_over && mouse_button_maintain == false) {
        sfSprite_setColor(sprite, button_anim->overed);
    } else if (is_mouse_over && mouse_button_maintain) {
        sfSprite_move(sprite, button_anim->move);
        sfSprite_setColor(sprite, button_anim->maintain);
    }
}

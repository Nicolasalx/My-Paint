/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** get_button_state
*/

#include "my_graphical.h"
#include "my.h"

button_state_t get_button_state(sfRectangleShape *button)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);
    if (sfFloatRect_contains(&bound, mouse_pos.x, mouse_pos.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            return BUTTON_PRESSED;
        }
        return BUTTON_HOVERED;
    }
    return BUTTON_IDLE;
}

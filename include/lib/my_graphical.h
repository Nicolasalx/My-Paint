/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_graphical
*/

#ifndef MY_GRAPHICAL
    #define MY_GRAPHICAL

    #include <SFML/Graphics.h>

typedef enum {
    BUTTON_IDLE,
    BUTTON_HOVERED,
    BUTTON_PRESSED
} button_state_t;

sfBool is_mouse_over_rectangle_shape(sfRectangleShape *rectangle_shape,
    sfVector2i mouse);
sfBool is_mouse_over_sprite(sfSprite *sprite);
button_state_t get_button_state(sfRectangleShape *button);
sfVector2f get_mouse_pos_on_sheet(void);

#endif /* !MY_GRAPHICAL */

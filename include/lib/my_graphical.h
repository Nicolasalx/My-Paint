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

typedef enum {
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
} anchor_t;

typedef enum {
    RIGHT,
    BOTTOM
} expand_direction_t;

sfBool is_mouse_over_rectangle_shape(sfRectangleShape *rectangle_shape,
    sfVector2i mouse);
sfBool is_mouse_over_sprite(sfSprite *sprite);
button_state_t get_button_state(sfRectangleShape *button);
sfVector2f get_mouse_pos_on_sheet(void);
sfTexture *resize_texture(sfTexture *texture, sfVector2u new_size);
void set_render_window_icon(sfRenderWindow* window, char *icon_path);
void ini_anchor_sprite(sfSprite *sprite, anchor_t anchor);
void set_pos_sprite_with_anchor(sfSprite *sprite, sfVector2f offset, anchor_t anchor);
void expand_sprite_with_anchor(sfSprite *sprite, anchor_t anchor);

#endif /* !MY_GRAPHICAL */

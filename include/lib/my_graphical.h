/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_graphical
*/

#ifndef MY_GRAPHICAL
    #define MY_GRAPHICAL

    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef enum {
    BUTTON_IDLE,
    BUTTON_HOVERED,
    BUTTON_PRESSED,
    BUTTON_MAINTAIN,
    BUTTON_RELEASED
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

typedef struct {
    sfColor disable;
    sfColor idle;
    sfColor overed;
    sfColor maintain;
    sfVector2f move;
} button_anim_t;

sfBool is_mouse_over_rectangle_shape(sfRectangleShape *rectangle_shape);
sfBool is_mouse_over_sprite(sfSprite *sprite);
sfBool is_mouse_over_text(sfText* text);
sfVector2f get_mouse_pos_on_sheet(void);
sfTexture *resize_texture(sfTexture *texture, sfVector2u new_size);
void set_render_window_icon(sfRenderWindow* window, char *icon_path);
void ini_anchor_sprite(sfSprite *sprite, anchor_t anchor);
void set_pos_sprite_with_anchor(sfSprite *sprite, sfVector2f offset, anchor_t anchor);
void expand_sprite_with_anchor(sfSprite *sprite, anchor_t anchor);
sfFloatRect compute_rect_pos_and_scale(sfFloatRect parent_rect,
    sfFloatRect child_rect, float padding);
sfBool is_window_resized(void);
button_state_t get_sprite_button_state(sfSprite *button);
button_state_t get_rectangle_shape_button_state(sfRectangleShape *button);
void handle_sprite_button_state(sfSprite *sprite, button_anim_t *button_anim, bool enable);

#endif /* !MY_GRAPHICAL */

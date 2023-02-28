/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** user_interface
*/

#ifndef USER_INTERFACE_H_
    #define USER_INTERFACE_H_

#include <SFML/Graphics.h>

typedef struct ui_sprite_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    char *path;
} ui_sprite_t;

typedef struct user_interface {
    sfSprite *user_interface;
    sfRectangleShape* background_draw;
    sfVector2u windowSize;
    sfVector2f size;
} user_interface_t;

typedef struct color_selection {
    sfSprite *sprite;
} color_selection_t;

extern ui_sprite_t ui_sprite[];

extern user_interface_t user_interface[];

extern const int size_user_interface;



#endif /* !USER_INTERFACE_H_ */

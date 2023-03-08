/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** user_interface
*/

#ifndef USER_INTERFACE_H_
    #define USER_INTERFACE_H_

    #include "my_graphical.h"

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    char *path;
    anchor_t anchor;
} ui_sprite_t;

extern ui_sprite_t ui_sprite[];
extern const int size_ui_sprite;

void display_ui(sfRenderWindow *window);
void ini_bg_user_interface(void);

#endif /* !USER_INTERFACE_H_ */

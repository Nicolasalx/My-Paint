/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** toolbar
*/

#ifndef TOOLBAR_H_
    #define TOOLBAR_H_
    #define SIZE_OUTLINE_BUTTON 2

typedef struct icon_rectangle_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} icon_rectangle_t;

typedef struct icon_sprite_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path;
} icon_sprite_t;

extern icon_rectangle_t icon_rectangle[];
extern const int size_icon_rectangle;

extern icon_sprite_t icon_sprite[];
extern const int size_icon_sprite;

#endif /* !TOOLBAR_H_ */

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** toolbar
*/

#ifndef TOOLBAR_H_

    #define TOOLBAR_H_
    #define SIZE_OUTLINE_BUTTON 2
    #include "tool.h"

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
    bool can_draw;
    tool_t tool_to_select;
} icon_rectangle_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path;
} icon_sprite_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} size_pen_t;

typedef struct {
    int index_button_pressed;
    int index_button_hovered;
    bool verif;
} front_toolbar_t;

extern front_toolbar_t front_toolbar;

extern icon_rectangle_t icon_rectangle[];
extern const int size_icon_rectangle;

extern icon_sprite_t icon_sprite[];
extern const int size_icon_sprite;

extern size_pen_t size_pen;

void set_size_pen(sfRenderWindow *window, sfEvent *event);
void display_toolbar(sfRenderWindow *window, sfEvent *event);
void ini_icon_rectangle(void);
void ini_icon_sprite(void);
void ini_size_pen(void);
void interaction_front_toolbar(void);
void set_size_tool_selected(void);
void set_color_pressed_button(void);
void set_color_hovered_button(void);

#endif /* !TOOLBAR_H_ */

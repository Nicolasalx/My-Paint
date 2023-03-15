/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** icon_to_draw
*/

#ifndef ICON_TO_DRAW_H_
    #define ICON_TO_DRAW_H_
    #include "tool.h"

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color_rectangle;
    sfVector2f pos_rectangle;
    sfVector2f size_rectangle;

    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos_sprite;
    sfVector2f size_sprite;
    char *path_img;

    sfCircleShape *circle;
    sfColor color_circle;
    sfVector2f pos_circle;
    sfVector2f size_circle;

    tool_t tool_to_select;
} icon_to_draw_t;

extern icon_to_draw_t icon_to_draw[];
extern const int size_icon_to_draw;

void create_all_icon_to_draw(void);
void display_icon_to_draw(sfRenderWindow *window);
void destroy_icon_to_draw(void);

#endif /* !ICON_TO_DRAW_H_ */

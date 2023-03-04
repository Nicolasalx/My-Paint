/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include "SFML/Graphics.h"

    #define RED {255, 0, 0, 255}
    #define MAGENTA {255, 0, 255, 255}
    #define BLUE {0, 0, 255, 255}
    #define CYAN {0, 255, 255, 255}
    #define YELLOW {255, 255, 0, 255}
    #define GREEN {0, 128, 0, 255}
    #define BLACK {0, 0, 0, 255}
    #define WHITE {255, 255, 255, 255}

    #define SIZE_BUTTON {30, 30}

    #define SIZE_OUTLINE_BUTTON_SEL_COLOR 2


typedef struct selection_color_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} selection_color_t;

typedef struct chromatic_wheel_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
} chromatic_wheel_t;

typedef struct text_color_selection_t {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_color_selection_t;

extern selection_color_t selection_color[];
extern const int size_selection_color;

extern chromatic_wheel_t chromatic_wheel;

extern text_color_selection_t text_color_selection[];
extern const int size_text_selection_color;

#endif /* !BUTTON_H_ */

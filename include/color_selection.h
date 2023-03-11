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

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} selection_color_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path;
} chromatic_wheel_t;

typedef struct {
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

void display_color_selection_icon(sfRenderWindow *window, sfEvent *event);
void init_all_button_selection(void);
void ini_chromatic_wheel(void);
void init_all_text_selection_color(void);
void create_button(int i);
void change_color_tool(sfColor color_chromatic);
void select_color_chromatic_wheel(void);

#endif /* !BUTTON_H_ */

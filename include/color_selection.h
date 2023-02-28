/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #define RED { .r = 255, .g = 0, .b = 0, .a = 255}
    #define MAGENTA { .r = 255, .g = 0, .b = 255, .a = 255}
    #define BLUE { .r = 0, .g = 0, .b = 255, .a = 255}
    #define CYAN { .r = 0, .g = 255, .b = 255, .a = 255}
    #define YELLOW { .r = 255, .g = 255, .b = 0, .a = 255}
    #define GREEN { .r = 0, .g = 128, .b = 0, .a = 255}
    #define BLACK { .r = 0, .g = 0, .b = 0, .a = 255}
    #define WHITE { .r = 255, .g = 255, .b = 255, .a = 255}

    #define SIZE_BUTTON {30, 30}

extern const sfColor button_color[];
extern const int size_button_color;

typedef struct selection_color_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
} selection_color_t;

typedef struct chromatic_wheel_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
} chromatic_wheel_t;

extern chromatic_wheel_t chromatic_wheel;

extern selection_color_t sel_color[];


extern const int size_selection_color;


#endif /* !BUTTON_H_ */

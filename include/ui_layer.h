/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ui_layer
*/

#ifndef UI_LAYER_H_
    #define UI_LAYER_H_

typedef struct box_icon_layer_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} box_icon_layer_t;

typedef struct text_icon_layer_t {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_icon_layer_t;

typedef struct icon_eye_layer_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path;
} icon_eye_layer_t;

typedef struct button_eye_layer_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} button_eye_layer_t;

extern box_icon_layer_t box_icon_layer[];
extern const int size_box_icon_layer;

extern text_icon_layer_t text_icon_layer[];
extern const int size_text_icon_layer;

extern icon_eye_layer_t icon_eye_layer[];
extern const int size_icon_eye_layer;

extern button_eye_layer_t button_eye_layer[];
extern const int size_button_eye_layer;

void layer_display(sfRenderWindow *window, sfEvent *event);
void ini_text_layer_box(void);
void ini_layer_box(void);
void ini_eye_sprite(void);
void ini_button_eye_layer(void);

#endif /* !UI_LAYER_H_ */

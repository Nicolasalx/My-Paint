/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ui_layer
*/

#ifndef UI_LAYER_H_
    #define UI_LAYER_H_

    #include "SFML/Graphics.h"
    #include "my_graphical.h"
    #include "layer.h"

    #define UI_LAYER_OFFSET -40, 905
    #define UI_LAYER_SIZE 270, 50
    #define UI_LAYER_THICKNESS 3
    #define UI_LAYER_TEXT_SIZE 25
    #define UI_LAYER_FONT_PATH "game_data/font/JetBrainsMono-Regular.ttf"
    #define UI_LAYER_EYE_PATH "game_data/ui_layer/eye_layer.png"
    #define SPACE_BETWEEN_UI_LAYER 60
    #define SELECTED_LAYER_COLOR 170, 170, 255, 255

typedef enum {
    NEW_LAYER,
    PUSH_UP,
    PUSH_DOWN
} button_ui_layer_enum;

typedef struct {
    sfRectangleShape *box;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
} box_ui_layer_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *box;
} eye_ui_layer_t;

typedef struct {
    box_ui_layer_t box_ui_layer;
    eye_ui_layer_t eye_ui_layer;
} ui_layer_t;

typedef struct {
    sfRectangleShape *box;
    anchor_t anchor;
    sfVector2f size;
    sfVector2f offset;
    sfVector2f offset_sprite;
    sfSprite *sprite;
    sfTexture *texture;
    char *path;
    sfVector2f scale;
    void (*redirect)(void);
} button_ui_layer_t;

extern sfRectangleShape *background_ui_layer;
extern button_ui_layer_t button_ui_layer[];
extern int size_button_ui_layer;

void render_ui_layer(sfRenderWindow *window, sfEvent *event);
void create_background_ui_layer(void);
void create_button_ui_layer(void);
void render_button_ui_layer(sfRenderWindow *window);
void push_layer_up(void);
void push_layer_down(void);
void add_new_layer(void);
void delete_current_layer(void);

#endif /* !UI_LAYER_H_ */

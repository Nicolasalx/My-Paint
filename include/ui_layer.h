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

    #define UI_LAYER_OFFSET -310, 905
    #define UI_LAYER_SIZE 270, 50
    #define UI_LAYER_THICKNESS 3
    #define UI_LAYER_TEXT_SIZE 25
    #define UI_LAYER_FONT_PATH "game_data/font/JetBrainsMono-Regular.ttf"
    #define UI_LAYER_EYE_PATH "game_data/ui_layer/eye_layer.png"
    #define SPACE_BETWEEN_UI_LAYER 0, 80

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

void render_ui_layer(sfRenderWindow *window, sfEvent *event);

#endif /* !UI_LAYER_H_ */

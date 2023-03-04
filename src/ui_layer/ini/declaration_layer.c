/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "ui_layer.h"

box_icon_layer_t box_icon_layer [] = {
    {.color = {255, 255, 255}, .pos = {1610, 765}, .size = {270, 50}},
    {.color = {255, 255, 255}, .pos = {1610, 825}, .size = {270, 50}},
    {.color = {255, 255, 255}, .pos = {1610, 885}, .size = {270, 50}}
};

const int size_box_icon_layer =
    sizeof(box_icon_layer) / sizeof(box_icon_layer_t);

text_icon_layer_t text_icon_layer [] = {
    {.pos = {1670, 775}, .path = "Calque 3",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {1670, 835}, .path = "Calque 2",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {1670, 895}, .path = "Calque 1",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_icon_layer =
    sizeof(text_icon_layer) / sizeof(text_icon_layer_t);

icon_eye_layer_t icon_eye_layer [] = {
    {.pos = {1619, 770}, .size = {1, 1},
        .path = "game_data/ui_layer/eye_layer.png"},
    {.pos = {1619, 830}, .size = {1, 1},
        .path = "game_data/ui_layer/eye_layer.png"},
    {.pos = {1619, 890}, .size = {1, 1},
        .path = "game_data/ui_layer/eye_layer.png"}
};

const int size_icon_eye_layer =
    sizeof(icon_eye_layer) / sizeof(icon_eye_layer_t);

button_eye_layer_t button_eye_layer [] = {
    {.color = {255, 255, 255}, .pos = {1624, 775}, .size = {33, 33}},
    {.color = {255, 255, 255}, .pos = {1624, 835}, .size = {33, 33}},
    {.color = {255, 255, 255}, .pos = {1624, 895}, .size = {33, 33}}
};

const int size_button_eye_layer =
    sizeof(button_eye_layer) / sizeof(button_eye_layer_t);

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_button_ui_layer
*/

#include "layer.h"
#include "ui_layer.h"
#include "my_graphical.h"

sfRectangleShape *background_ui_layer;

button_ui_layer_t button_ui_layer[] = {
    {
        .path = "game_data/ui_layer/new_layer.png",
        .size = {40, 40},
        .scale = {0.3, 0.3},
        .anchor = TOP_RIGHT,
        .offset = {-200 - 28, 975},
        .offset_sprite = {-205 - 28, 980},
        .redirect = add_new_layer
    }, {
        .path = "game_data/ui_layer/push_up.png",
        .size = {40, 40},
        .scale = {0.3, 0.3},
        .anchor = TOP_RIGHT,
        .offset = {-150 - 28, 975},
        .offset_sprite = {-155 - 28, 985},
        .redirect = push_layer_up
    }, {
        .path = "game_data/ui_layer/push_down.png",
        .size = {40, 40},
        .scale = {0.3, 0.3},
        .anchor = TOP_RIGHT,
        .offset = {-100 - 28, 975},
        .offset_sprite = {-105 - 28, 985},
        .redirect = push_layer_down
    }, {
        .path = "game_data/ui_layer/delete_layer.png",
        .size = {40, 40},
        .scale = {0.3, 0.3},
        .anchor = TOP_RIGHT,
        .offset = {-50 - 28, 975},
        .offset_sprite = {-57 - 28, 980},
        .redirect = delete_current_layer
    }
};

int size_button_ui_layer = sizeof(button_ui_layer) / sizeof(button_ui_layer_t);

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_ui
*/

#include "my.h"
#include "user_interface.h"

ui_sprite_t ui_sprite [] = {
    {.path = "./game_data/user_interface/left_bar.png",
        .pos = {0, 0}, .anchor = TOP_LEFT, .expand = true},
    {.path = "./game_data/user_interface/bottom_bar.png",
        .pos = {0, 0}, .anchor = BOTTOM_LEFT, .expand = true},
    {.path = "./game_data/user_interface/top_bar.png",
        .pos = {0, 0}, .anchor = TOP_LEFT, .expand = true},
    {.path = "./game_data/user_interface/top_right_bar.png",
        .pos = {0, 0}, .anchor = TOP_RIGHT, .expand = false},
    {.path = "./game_data/user_interface/bottom_right_bar.png",
        .pos = {0, 750}, .anchor = TOP_RIGHT, .expand = true}
};

const int size_ui_sprite = sizeof(ui_sprite) / sizeof(ui_sprite_t);

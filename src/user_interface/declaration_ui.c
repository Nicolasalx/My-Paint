/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_ui
*/

#include "my.h"
#include "user_interface.h"

ui_sprite_t ui_sprite [] = {
    {.path = "./game_data/user_interface/left_bar.png", .pos = {0, 0}},
    {.path = "./game_data/user_interface/bottom_bar.png", .pos = {0, DEFAULT_WINDOW_SIZE_Y - 81}},
    {.path = "./game_data/user_interface/top_bar.png", .pos = {0, 0}},
    {.path = "./game_data/user_interface/right_bar_back.png", .pos = {DEFAULT_WINDOW_SIZE_X - 350, 0}},
    {.path = "./game_data/user_interface/right_bar_front.png", .pos = {DEFAULT_WINDOW_SIZE_X - 350, 0}}
};

const int size_ui_sprite = sizeof(ui_sprite) / sizeof(ui_sprite_t);

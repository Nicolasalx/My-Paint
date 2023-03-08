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
        .pos = {0, 0}, .anchor = TOP_LEFT},
    {.path = "./game_data/user_interface/bottom_bar.png",
        .pos = {0, 0}, .anchor = BOTTOM_LEFT},
    {.path = "./game_data/user_interface/top_bar.png",
        .pos = {0, 0}, .anchor = TOP_LEFT},
    {.path = "./game_data/user_interface/right_bar.png",
        .pos = {0, 0}, .anchor = TOP_RIGHT}
};

const int size_ui_sprite = sizeof(ui_sprite) / sizeof(ui_sprite_t);

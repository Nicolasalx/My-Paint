/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "layer.h"

icon_undo_redo_t icon_undo_redo [] = {
    {.pos = {1400, 15}, .size = {0.5, 0.5}, .path = "game_data/header/arrow_undo.png", .redirect = undo},
    {.pos = {1470, 15}, .size = {0.5, 0.5}, .path = "game_data/header/arrow_redo.png", .redirect = redo}
};

const int size_icon_undo_redo =
    sizeof(icon_undo_redo) / sizeof(icon_undo_redo_t);
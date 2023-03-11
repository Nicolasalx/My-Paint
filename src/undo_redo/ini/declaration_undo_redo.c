/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "layer.h"
#include "my_graphical.h"

icon_undo_redo_t icon_undo_redo [] = {
    {
        .offset = {-450, 18},
        .scale = {0.5, 0.5},
        .anchor = TOP_RIGHT,
        .path = "game_data/header/arrow_undo.png",
        .redirect = undo,
        .enable = true
    }, {
        .offset = {-380, 18},
        .scale = {0.5, 0.5},
        .anchor = TOP_RIGHT,
        .path = "game_data/header/arrow_redo.png",
        .redirect = redo,
        .enable = true
    }
};

const int size_icon_undo_redo = sizeof(icon_undo_redo) / sizeof(icon_undo_redo_t);

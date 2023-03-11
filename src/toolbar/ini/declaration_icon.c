/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"

icon_sprite_t icon_sprite [] = {
    {.pos = {5, 87}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/mouse_cursor.png"},

    {.pos = {3, 147}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/pencil.png"},

    {.pos = {3, 197}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/eraser.png"},

    {.pos = {3, 247}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/brush.png"},

    {.pos = {3, 297}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/pen.png"},

    {.pos = {3, 357}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/rectangle_form.png"},

    {.pos = {3, 407}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/circle_form.png"},

    {.pos = {3, 468}, .size = {0.45, 0.45},
    .path = "game_data/toolbar/draw_line.png"},

    {.pos = {4, 680}, .size = {0.4, 0.4},
    .path = "game_data/toolbar/pipette.png"},

    {.pos = {4, 739}, .size = {0.4, 0.4},
    .path = "game_data/toolbar/zoom_tool.png"}
};

front_toolbar_t front_toolbar = {
    .index_button_hovered = 0,
    .index_button_pressed = 0,
    .verif = false
};

const int size_icon_sprite = sizeof(icon_sprite) /
    sizeof(icon_sprite_t);

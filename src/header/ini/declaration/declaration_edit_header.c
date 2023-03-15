/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "tool.h"

edit_menu_header_t edit_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {160, 70},
    .size = {220, 30}, .tool_to_select = PENCIL, .tool_draw_shape = false},

    {.color = {255, 255, 255}, .pos = {160, 100},
    .size = {220, 30}, .tool_to_select = ERASER, .tool_draw_shape = false},

        {.color = {255, 255, 255}, .pos = {160, 130},
    .size = {220, 30}, .draw_mode = CIRCLE_DRAW, .tool_draw_shape = true},

    {.color = {255, 255, 255}, .pos = {160, 160},
    .size = {220, 30}, .draw_mode = RECTANGLE_DRAW, .tool_draw_shape = true},

    {.color = {255, 255, 255}, .pos = {160, 190},
    .size = {220, 30}, .draw_mode = BRUSH_DRAW, .tool_draw_shape = true}
};

const int size_edit_menu_header =
    sizeof(edit_menu_header) / sizeof(edit_menu_header_t);

text_edit_header_t text_edit_header [] = {
    {.pos = {170, 70}, .path = "Choose Pen",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {170, 100}, .path = "Choose Eraser",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},

    {.pos = {170, 130}, .path = "Draw cirle",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},

    {.pos = {170, 160}, .path = "Draw rectangle",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},

    {.pos = {170, 190}, .path = "Draw Brush",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_edit_header =
    sizeof(text_edit_header) / sizeof(text_edit_header_t);

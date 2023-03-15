/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"

selection_color_t selection_color [] = {
    {.color = {RED}, .pos = {1630, 300}, .size = {30, 30}, .can_draw = true},
    {.color = {MAGENTA}, .pos = {1630, 350}, .size = {30, 30}, .can_draw = true},
    {.color = {BLUE}, .pos = {1700, 300}, .size = {30, 30}, .can_draw = true},
    {.color = {CYAN}, .pos = {1700, 350}, .size = {30, 30}, .can_draw = true},
    {.color = {YELLOW}, .pos = {1770, 300}, .size = {30, 30}, .can_draw = true},
    {.color = {GREEN}, .pos = {1770, 350}, .size = {30, 30}, .can_draw = true},
    {.color = {BLACK}, .pos = {1840, 300}, .size = {30, 30}, .can_draw = true},
    {.color = {WHITE}, .pos = {1840, 350}, .size = {30, 30}, .can_draw = true},
    {.color = BG_COLOR, .pos = {1600, 500}, .size = {290, 200}, .can_draw = false}
};

const int size_selection_color =
    sizeof(selection_color) / sizeof(selection_color_t);

chromatic_wheel_t chromatic_wheel = {.pos = {1620, 30},
.size = {0.5, 0.5}, .path = "./game_data/color_selection/chromatic_wheel.png"};

text_color_selection_t text_color_selection [] = {
    {.pos = {1630, 10}, .path = "Color Selector",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {1680, 460}, .path = "Overview",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {1700, 710}, .path = "Layers",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_selection_color =
    sizeof(text_color_selection) / sizeof(text_color_selection_t);

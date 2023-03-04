/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

view_menu_header_t view_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {260, 70}, .size = {140, 30}},
    {.color = {255, 255, 255}, .pos = {260, 100}, .size = {140, 30}}
};

const int size_view_menu_header =
    sizeof(view_menu_header) / sizeof(view_menu_header_t);

text_view_header_t text_view_header [] = {
    {.pos = {270, 70}, .path = "Zoom in",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {270, 100}, .path = "Zoom out",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_view_header =
    sizeof(text_view_header) / sizeof(text_view_header_t);

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

help_menu_header_t help_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {460, 70}, .size = {210, 30}},
    {.color = {255, 255, 255}, .pos = {460, 100}, .size = {210, 30}}
};

const int size_help_menu_header =
    sizeof(help_menu_header) / sizeof(help_menu_header_t);

text_help_header_t text_help_header [] = {
    {.pos = {470, 70}, .path = "Description",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {470, 100}, .path = "About",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_help_header =
    sizeof(text_help_header) / sizeof(text_help_header_t);

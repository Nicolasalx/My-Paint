/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

button_header_t button_header [] = {
    {.color = BG_COLOR, .pos = {60, 15}, .size = {75, 50}},
    {.color = BG_COLOR, .pos = {160, 15}, .size = {75, 50}},
    {.color = BG_COLOR, .pos = {260, 15}, .size = {75, 50}},
    {.color = BG_COLOR, .pos = {360, 15}, .size = {75, 50}},
    {.color = BG_COLOR, .pos = {460, 15}, .size = {75, 50}}
};

const int size_button_header = sizeof(button_header) / sizeof(button_header_t);

text_button_header_t text_button_header [] = {
    {.pos = {65, 25}, .path = "File",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {165, 25}, .path = "Edit",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {265, 25}, .path = "View",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {360, 25}, .path = "Layer",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {465, 25}, .path = "Help",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_button_header =
    sizeof(text_button_header) / sizeof(text_button_header_t);

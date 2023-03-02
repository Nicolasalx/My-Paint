/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

edit_menu_header_t edit_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {160, 70}, .size = {210, 30}},
    {.color = {255, 255, 255}, .pos = {160, 100}, .size = {210, 30}}
};

const int size_edit_menu_header = sizeof(edit_menu_header) / sizeof(edit_menu_header_t);

text_edit_header_t text_edit_header [] = {
    {.pos = {170, 70}, .path = "Choose Pen", .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {170, 100}, .path = "Choose Eraser", .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_edit_header = sizeof(text_edit_header) / sizeof(text_edit_header_t);

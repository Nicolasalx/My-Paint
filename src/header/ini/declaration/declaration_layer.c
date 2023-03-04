/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

layer_menu_header_t layer_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {360, 70}, .size = {140, 30}},
    {.color = {255, 255, 255}, .pos = {360, 100}, .size = {140, 30}}
};

const int size_layer_menu_header =
    sizeof(layer_menu_header) / sizeof(layer_menu_header_t);

text_layer_header_t text_layer_header [] = {
    {.pos = {370, 70}, .path = "Layer",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {370, 100}, .path = "Layer",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_layer_header =
    sizeof(text_layer_header) / sizeof(text_layer_header_t);

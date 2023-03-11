/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

file_menu_header_t file_menu_header [] = {
    {.color = {255, 255, 255}, .pos = {60, 70}, .size = {190, 30},
    .redirect = new_file},

    {.color = {255, 255, 255}, .pos = {60, 100}, .size = {190, 30},
    .redirect = import_from_files},

    {.color = {255, 255, 255}, .pos = {60, 130}, .size = {190, 30},
    .redirect = save_img_file},

    {.color = {255, 255, 255}, .pos = {60, 160}, .size = {190, 30},
    .redirect = exit_file}
};

const int size_file_menu_header =
    sizeof(file_menu_header) / sizeof(file_menu_header_t);

file_name_t *file_name;

text_file_header_t text_file_header [] = {
    {.pos = {70, 70}, .path = "New file",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {70, 100}, .path = "Import image",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {70, 130}, .path = "Save image",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"},
    {.pos = {70, 160}, .path = "Exit",
        .font_path = "game_data/font/JetBrainsMono-Regular.ttf"}
};

const int size_text_file_header =
    sizeof(text_file_header) / sizeof(text_file_header_t);

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"

button_header_t button_header [] = {
    {.color = {BG_COLOR}, .pos = {60, 15}, .size = {75, 50}},
    {.color = {BG_COLOR}, .pos = {160, 15}, .size = {75, 50}},
    {.color = {BG_COLOR}, .pos = {260, 15}, .size = {75, 50}},
    {.color = {BG_COLOR}, .pos = {360, 15}, .size = {75, 50}},
    {.color = {BG_COLOR}, .pos = {460, 15}, .size = {75, 50}}
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

char content_text_description[] = "\n\n\n\n My_paint is a software application "
    "that allows users to\n create and edit digital images on their computers."
    "\n\n"
    " The main features of our logiciel include the ability to\n draw, paint, "
    "and manipulate shapes, lines, and text.\n\n"
    " Paint provides a range of tools and brushes for users\n to use, including"
    " a pencil, brush, and eraser,\n as well as a range of fill and gradient "
    "options.\n There is also a color palette that allows users to select\n and"
    " customize their preferred colors. \n Additionally, the program includes a"
    " zoom function,\n making it easier to work on detailed areas of an image.";

char content_text_about[] = "\n\n\n\n\t\t\t   Thibaud CATHALA\t\t  Nicolas "
    "ALEXANDRE\n\n \t\t\t  Epitech Paris\t\t\tEpitech Paris\n"
    "\t\t\t   07 83 63 34 31\t\t   07 83 11 94 55"
    "\n\n\n\n\tthibaud.cathala@epitech.eu|nicolas1.alexandre@epitech.eu\n\n"
    " Hello, we are two computer software developers at epitech\n paris in the"
    " class of 2027.\n We carried out this graphic project in 3 weeks."
    "\n\n\t\t\t\t\tEnjoy our software!";


option_text_menu_help_t option_text_menu_help [] = {
    {.content_text = "\t\tDescritpion\n", .size_text = 50 ,
    .choose_option = DESCRIPTION},

    {.content_text = content_text_description, .size_text = 22,
    .choose_option = DESCRIPTION},

    {.content_text = "\t\t  About\n", .size_text = 50 ,
    .choose_option = ABOUT},

    {.content_text = content_text_about, .size_text = 22,
    .choose_option = ABOUT}
};

const int size_option_text_menu_help =
    sizeof(option_text_menu_help) / sizeof(option_text_menu_help_t);

img_about_option_help_t img_about_option_help [] = {
    {.path_img = "game_data/creator/thibaud_creator.png",
    .pos = {70, 100}, .size = {2, 2}},
    {.path_img = "game_data/creator/nicolas_creator.png",
    .pos = {400, 100}, .size = {2, 2}},
};

const int size_img_about_option_help =
    sizeof(img_about_option_help) / sizeof(img_about_option_help_t);

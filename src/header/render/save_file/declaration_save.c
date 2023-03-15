/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_save
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "header.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"
#include <SFML/Graphics.h>
#include "save_image.h"


selection_extension_button_t selection_extension_button [] = {
    {.color = (sfColor) {COLOR_BG}, .pos = {60, 80}, .size = {600, 100},
    .content_text = "Enter un nom de file", .pos_text = {220, 30},
    .can_click = false},

    {.color = (sfColor) {COLOR_BG}, .pos = {70, 300}, .size = {SIZE_BUTTON},
    .content_text = "png", .pos_text = {100, 335}, .can_click = true},

    {.color = (sfColor) {COLOR_BG}, .pos = {315, 300}, .size = {SIZE_BUTTON},
    .content_text = "jpg", .pos_text = {340, 335}, .can_click = true},

    {.color = (sfColor) {COLOR_BG}, .pos = {575, 300}, .size = {SIZE_BUTTON},
    .content_text = "bmp", .pos_text = {600, 335}, .can_click = true},

    {.color = (sfColor) {COLOR_BG}, .pos = {225, 450}, .size = {300, 70},
    .content_text = "Valider", .pos_text = {320, 470}, .validate = true},
};

const int size_selection_extension_button =
    sizeof(selection_extension_button) / sizeof(selection_extension_button_t);

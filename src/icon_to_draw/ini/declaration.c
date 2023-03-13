/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"
#include <SFML/Graphics.h>
#include "save_image.h"
#include "icon_to_draw.h"
#include "tool.h"

icon_to_draw_t icon_to_draw [] = {
    {.color_circle = {0, 0, 0, 0}, .pos_circle = {100, 100},
    .path_img = "game_data/toolbar/pencil.png",
    .size_sprite = {0.5, 0.5}, .tool_to_select = PENCIL},

    {.color_circle = {0, 0, 0, 0}, .pos_circle = {100, 100},
    .path_img = "game_data/toolbar/eraser.png",
    .size_sprite = {0.5, 0.5}, .tool_to_select = ERASER},

    {.color_circle = {0, 0, 0, 0}, .pos_circle = {100, 100},
    .path_img = "game_data/toolbar/brush.png",
    .size_sprite = {0.5, 0.5}, .tool_to_select = BRUSH}
};

const int size_icon_to_draw =
    sizeof(icon_to_draw) / sizeof(icon_to_draw_t);

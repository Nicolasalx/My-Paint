/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_color_select
*/

#include "my.h"
#include "color_selection.h"

selection_color_t sel_color [] = {
    {.color = RED, .pos = {1620, 300}},
    {.color = MAGENTA, .pos = {1620, 350}},
    {.color = BLUE, .pos = {1690, 300}},
    {.color = CYAN, .pos = {1690, 350}},
    {.color = YELLOW, .pos = {1760, 300}},
    {.color = GREEN, .pos = {1760, 350}},
    {.color = BLACK, .pos = {1830, 300}},
    {.color = WHITE, .pos = {1830, 350}}
};

chromatic_wheel_t chromatic_wheel[] = {
    {.pos = {1500, 50}, .size = {0.8, 0.8}}
};


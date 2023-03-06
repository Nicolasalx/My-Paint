/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"

icon_rectangle_t icon_rectangle [] = {
    {.color = BG_COLOR, .pos = {5, 90},
    .size = {40, 40}, .can_draw = true, .tool_to_select = MOUSE}, // Souris -> 0

    {.color = BG_COLOR, .pos = {5, 150},
    .size = {40, 40}, .can_draw = true, .tool_to_select = PENCIL}, // Stylo -> 1

    {.color = BG_COLOR, .pos = {5, 200},
    .size = {40, 40}, .can_draw = true, .tool_to_select = ERASER}, // Gomme -> 1

    {.color = BG_COLOR, .pos = {5, 250},
    .size = {40, 40}, .can_draw = true, .tool_to_select = BRUSH}, // Pencil -> 1

    {.color = BG_COLOR, .pos = {5, 300},
    .size = {40, 40}, .can_draw = true}, // Sceau -> 1

    {.color = BG_COLOR, .pos = {5, 360},
    .size = {40, 40}, .can_draw = true}, // Rond pour dessiner -> 2

    {.color = BG_COLOR, .pos = {5, 410},
    .size = {40, 40}, .can_draw = true}, // Rectangle pour dessiner -> 2




    {.color = BG_COLOR, .pos = {5, 470},
    .size = {40, 40}, .can_draw = true}, // Ligne Forme -> 3

    {.color = BG_COLOR, .pos = {5, 520},
    .size = {40, 40}, .can_draw = true}, // Rectangle Forme -> 3

    {.color = BG_COLOR, .pos = {5, 570},
    .size = {40, 40}, .can_draw = true}, // Cercle Forme -> 3

    {.color = BG_COLOR, .pos = {5, 620},
    .size = {40, 40}, .can_draw = true}, // Triangle Forme -> 3


    {.color = BG_COLOR, .pos = {5, 680},
    .size = {40, 40}, .can_draw = true}, // Pipette -> 4



    {.color = BG_COLOR, .pos = {5, 740},
    .size = {40, 40}, .can_draw = true}, // Loupe -> 5


    {.color = BG_COLOR, .pos = {5, 800},
    .size = {40, 190}, .can_draw = false} // Taille Stylo
};

const int size_icon_rectangle =
    sizeof(icon_rectangle) / sizeof(icon_rectangle_t);

size_pen_t size_pen = {.pos = {5, 992}, .size = {40, 0},
    .color = {255, 102, 102, 255}};

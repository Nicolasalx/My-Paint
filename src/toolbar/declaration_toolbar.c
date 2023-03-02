/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "toolbar.h"

icon_rectangle_t icon_rectangle [] = {
    {.color = BG_COLOR, .pos = {5, 90}, .size = {40, 40}}, // Souris -> 0
    {.color = BG_COLOR, .pos = {0, 140}, .size = {47, 1}}, // Séparation -> 0

    {.color = BG_COLOR, .pos = {5, 150}, .size = {40, 40}}, // Stylo -> 1
    {.color = BG_COLOR, .pos = {5, 200}, .size = {40, 40}}, // Gomme -> 1
    {.color = BG_COLOR, .pos = {5, 250}, .size = {40, 40}}, // Pencil -> 1
    {.color = BG_COLOR, .pos = {5, 300}, .size = {40, 40}}, // Sceau -> 1
    {.color = BG_COLOR, .pos = {0, 350}, .size = {47, 1}}, // Séparation -> 1

    {.color = BG_COLOR, .pos = {5, 360}, .size = {40, 40}}, // Rond pour dessiner -> 2
    {.color = BG_COLOR, .pos = {5, 410}, .size = {40, 40}}, // Rectangle pour dessiner -> 2
    {.color = BG_COLOR, .pos = {0, 460}, .size = {47, 1}}, // Séparation -> 2

    {.color = BG_COLOR, .pos = {5, 470}, .size = {40, 40}}, // Ligne Forme -> 3
    {.color = BG_COLOR, .pos = {5, 520}, .size = {40, 40}}, // Rectangle Forme -> 3
    {.color = BG_COLOR, .pos = {5, 570}, .size = {40, 40}}, // Cercle Forme -> 3
    {.color = BG_COLOR, .pos = {5, 620}, .size = {40, 40}}, // Triangle Forme -> 3
    {.color = BG_COLOR, .pos = {0, 670}, .size = {47, 1}}, // Séparation -> 3

    {.color = BG_COLOR, .pos = {5, 680}, .size = {40, 40}}, // Pipette -> 4
    {.color = BG_COLOR, .pos = {0, 730}, .size = {47, 1}}, // Séparation -> 3

    {.color = BG_COLOR, .pos = {5, 740}, .size = {40, 40}}, // Loupe -> 5
    {.color = BG_COLOR, .pos = {0, 790}, .size = {47, 1}}, // Séparation -> 3

    {.color = BG_COLOR, .pos = {5, 800}, .size = {40, 190}} // Taille Stylo
};

const int size_icon_rectangle = sizeof(icon_rectangle) / sizeof(icon_rectangle_t);

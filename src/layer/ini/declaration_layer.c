/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_layer
*/

#include "my_linkedlist.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfRectangleShape *background;
node_t *head_layer;
node_t *selected_layer;
sfVector2f overview_pos = {1611, 524};
sfVector2f overview_scale = {0.14, 0.14};

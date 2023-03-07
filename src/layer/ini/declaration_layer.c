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
node_t *head_layer = NULL;
node_t *selected_layer = NULL;

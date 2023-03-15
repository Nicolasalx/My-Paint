/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** push_layer_down
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void push_layer_down(void)
{
    if (selected_layer == head_layer) {
        return;
    }
    swap_node(&head_layer, selected_layer, selected_layer->prev);
}

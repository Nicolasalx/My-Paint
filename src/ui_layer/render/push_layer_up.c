/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** push_layer_up
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void push_layer_up(void)
{
    if (selected_layer->next == head_layer) {
        return;
    }
    swap_node(&head_layer, selected_layer, selected_layer->next);
}

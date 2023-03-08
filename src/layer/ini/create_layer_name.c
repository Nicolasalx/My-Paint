/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** get_layer_name
*/

#include "layer.h"
#include "my_number.h"
#include "my_string.h"

char *create_layer_name(char *layer_name_str)
{
    static int layer_nb = 0;
    char layer_nb_str[SIZE_STR_TO_STORE_INT];

    my_strcpy(layer_name_str, DEFAULT_LAYER_NAME);
    my_strcat(layer_name_str, my_nb_to_str(layer_nb, layer_nb_str));
    ++ layer_nb;
    return layer_name_str;
}

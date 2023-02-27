/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** free_x
*/

#include <stdlib.h>
#include <stdarg.h>

void free_x(int nb_free, ...)
{
    va_list list;

    va_start(list, nb_free);
    for (int i = 0; i < nb_free; ++i) {
        free(va_arg(list, void *));
    }
    va_end(list);
}

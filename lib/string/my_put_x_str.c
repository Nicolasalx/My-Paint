/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_put_x_str
*/

#include "my_string.h"

void my_put_x_str(char *str[])
{
    for (int i = 0; str[i] != NULL; ++i) {
        my_putstr(str[i]);
    }
}

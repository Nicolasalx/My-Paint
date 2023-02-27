/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_put_x_error
*/

#include "my_error.h"
#include <stdlib.h>

void my_put_x_error(char *str[])
{
    for (int i = 0; str[i] != NULL; ++i) {
        my_puterror(str[i]);
    }
}

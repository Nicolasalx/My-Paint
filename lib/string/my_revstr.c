/*
** EPITECH PROJECT, 2022
** my_strrev
** File description:
** my_strrev
*/

#include "my_string.h"

char *my_revstr(char *str)
{
    int j = (my_strlen(str) - 1);

    for (int i = 0; i < j; ++i) {
        my_swap_char(&str[i], &str[j]);
        -- j;
    }
    return str;
}

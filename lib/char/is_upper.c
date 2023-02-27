/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_upper
*/

#include <stdbool.h>

bool is_upper(char c)
{
    if (65 <= (int) c && (int) c <= 90) {
        return true;
    } else {
        return false;
    }
}

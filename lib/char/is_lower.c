/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_lower
*/

#include <stdbool.h>

bool is_lower(char c)
{
    if (97 <= (int) c && (int) c <= 122) {
        return true;
    } else {
        return false;
    }
}

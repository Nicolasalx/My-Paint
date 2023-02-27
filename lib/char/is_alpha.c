/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_alpha
*/

#include <stdbool.h>

bool is_alpha(char c)
{
    if ((65 <= (int) c && (int) c <= 90) ||
        (97 <= (int) c && (int) c <= 122)) {
        return true;
    } else {
        return false;
    }
}

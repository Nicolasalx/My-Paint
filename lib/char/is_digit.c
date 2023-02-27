/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_digit
*/

#include <stdbool.h>

bool is_digit(char c)
{
    if (48 <= (int) c && (int) c <= 57) {
        return true;
    } else {
        return false;
    }
}

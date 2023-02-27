/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_alphanum
*/

#include <stdbool.h>

bool is_alphanum(char c)
{
    if ((65 <= (int) c && (int) c <= 90) ||
        (97 <= (int) c && (int) c <= 122) ||
        (48 <= (int) c && (int) c <= 57)) {
        return true;
    } else {
        return false;
    }
}

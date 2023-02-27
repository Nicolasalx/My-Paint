/*
** EPITECH PROJECT, 2022
** count_nb_word
** File description:
** count_nb_word
*/

#include "my_string.h"

int count_nb_word(const char *str, const char *delimiter)
{
    int count_word = 0;
    int already_count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter) == 0 && already_count == 0) {
            ++ count_word;
            ++ already_count;
        }
        if (is_in_str(str[i], delimiter) == 1) {
            already_count = 0;
        }
    }
    return count_word;
}

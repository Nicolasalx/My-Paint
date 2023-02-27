/*
** EPITECH PROJECT, 2022
** count_size_word
** File description:
** count_size_word
*/

#include "my_string.h"
#include "my_malloc.h"

int *count_size_word(const char *str, const char *delimiter, int nb_word)
{
    int *size_word = malloc_array(nb_word);
    int count_size_word = 0;
    int end_word = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter) == 0) {
            ++ count_size_word;
            end_word = 1;
        }
        if (is_in_str(str[i], delimiter) == 1 && end_word == 1) {
            end_word = 0;
            size_word[index] = count_size_word;
            ++ index;
            count_size_word = 0;
        }
    }
    if (end_word == 1)
        size_word[index] = count_size_word;
    return size_word;
}

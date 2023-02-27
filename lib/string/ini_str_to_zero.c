/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ini_str_to_zero
*/

void ini_str_to_zero(char *str, int size_str)
{
    for (int i = 0; i < size_str; ++i) {
        str[i] = '\0';
    }
}

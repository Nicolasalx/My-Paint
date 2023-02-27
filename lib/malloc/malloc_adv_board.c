/*
** EPITECH PROJECT, 2022
** adv_board
** File description:
** adv_board
*/

#include "my_malloc.h"

char **malloc_adv_board(int nb_line, const int *lines_size)
{
    int i;
    char **board = my_malloc(sizeof(char *) * (nb_line + 1));

    for (i = 0; i < nb_line; ++i) {
        board[i] = my_malloc(sizeof(char) * (lines_size[i] + 1));
        board[i][lines_size[i]] = '\0';
    }
    board[i] = NULL;
    return board;
}

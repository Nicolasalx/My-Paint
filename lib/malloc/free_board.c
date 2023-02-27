/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** free_board
*/

#include <stdlib.h>

void free_board(char **board)
{
    for (int i = 0; board[i] != NULL; ++i) {
        free(board[i]);
    }
    free(board);
}

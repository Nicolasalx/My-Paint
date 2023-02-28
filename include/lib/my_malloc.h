/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_malloc
*/

#ifndef MY_MALLOC
    #define MY_MALLOC

    #include <stddef.h>

void *my_malloc(size_t size);
char **malloc_board(int nb_line, int size_line);
void free_board(char **board);
char *malloc_str(int size_str);
char **my_str_to_board(const char *str, int nb_line, const int *lines_size);
int *malloc_array(int size_array);
int *count_size_word(const char *str, const char *delimiter, int nb_word);
char **my_str_to_word(const char *str, const char *delimiter,
    int nb_word, const int *size_word);
char **malloc_adv_board(int nb_line, const int *lines_size);
char *my_adv_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
char **my_boarddup(char **board);
char *my_adv_strcpy(char *dest, const char *src);
void free_x(int nb_free, ...);

#endif /* !MY_MALLOC */

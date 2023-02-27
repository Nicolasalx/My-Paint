/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_string
*/

#ifndef MY_STRING
    #define MY_STRING

    #include <stdbool.h>
    #include <stddef.h>

    #define print(...) my_put_x_str((char *[]) {__VA_ARGS__, NULL})

void my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
int my_strlen(const char *str);
bool is_in_str(char c, const char *str);
bool my_str_only_cont(const char *str, const char *characters);
int count_occur(const char *str, char c);
bool my_str_cont_atleast(const char *str, const char *characters);
int count_nb_word(const char *str, const char *delimiter);
void my_swap_char(char *char_1, char *char_2);
char *my_revstr(char *str);
void my_putboard(char **board, const char *separator, const char *last_char);
void my_putchar(char c);
void ini_str_to_zero(char *str, int size_str);
int my_strncmp(const char *str1, const char *str2, int n);
void shift_str_to_left(char *str, int nb_shift);
int my_boardlen(char **board);
void my_put_x_str(char *str[]);

#endif /* !MY_STRING */

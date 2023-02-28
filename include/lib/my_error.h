/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_error
*/

#ifndef MY_ERROR
    #define MY_ERROR

    #include <stdbool.h>

    #define GET_ERROR_VALUE 0

    #define print_error(...) my_put_x_str((char *[]) {__VA_ARGS__, NULL})

typedef enum error_code_enum {
    NO_ERROR,
    MALLOC_FAIL,
    STAT_FAIL,
    READ_FAIL
} error_code_enum;

typedef struct error_t {
    int code;
    const char *message;
    int return_value;
} error_t;

extern const error_t error_info[];
extern const int size_error_info;

int error_manager(int error_detected);
void my_puterror(const char *str);
void my_put_x_error(char *str[]);
void print_fatal_error_and_exit(int error);

void my_exit(long int exit_value);

#endif /* !MY_ERROR */

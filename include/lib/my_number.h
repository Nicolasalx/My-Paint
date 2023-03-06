/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_number
*/

#ifndef MY_NUMBER
    #define MY_NUMBER

    #define MAX_INT 2147483647
    #define MIN_INT -2147483648

    #define SIZE_STR_TO_STORE_INT 12

    #define CHAR_TO_DIGIT(char) ((value) - '0')
    #define DIGIT_TO_CHAR(digit) ((value) + '0')

    #define _1_000 1000
    #define _10_000 10000
    #define _100_000 100000
    #define _1_000_000 1000000

    #define INT(nb) my_nb_to_str(nb, (char[12]){0})

double my_pow(double nb, int power);
int my_abs(int nb);
int max_value(int value_1, int value_2);
int min_value(int value_1, int value_2);
int my_delta(int value_1, int value_2);

int my_get_nb(const char *str);
int get_min_value(int *array, int size_array);
int get_max_value(int *array, int size_array);
int count_nb_digit(int nb);
int get_max_value(int *array, int size_array);
int get_min_value(int *array, int size_array);
void my_swap(int *value_a, int *value_b);
int *my_sort(int *array, int size_array);
void my_put_array(const int *array, int size_array,
    const char *separator, const char *last_char);
void my_put_nb(int nb);
long int sum_array(int *array, int size_array);
char *my_nb_to_str(int nb, char *str);
void ini_array(int *array, int value, int size_array);
void my_put_double(double nb, int precision);

#endif /* !MY_NUMBER */

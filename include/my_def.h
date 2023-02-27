/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_def
*/

#ifndef MY_DEF_H_
    #define MY_DEF_H_

    #define RESET_COLOR "\e[0m"
    #define BOLD "\e[1m"
    #define RED "\e[91m"
    #define GREEN "\e[92m"
    #define YELLOW "\e[93m"
    #define BLUE "\e[94m"
    #define MAGENTA "\e[95m"
    #define CYAN "\e[96m"

    #define UNUSED(var) (void) (var)

    #define ADD_QUOTE(value) #value
    #define STR(value) ADD_QUOTE(value)

#endif /* !MY_DEF_H_ */

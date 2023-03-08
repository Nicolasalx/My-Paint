/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_def
*/

#ifndef MY_DEF_H_
    #define MY_DEF_H_

    #define BOLD_RED(...) "\e[1;91m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_GREEN(...) "\e[1;92m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_YELLOW(...) "\e[1;93m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_BLUE(...) "\e[1;94m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_MAGENTA(...) "\e[1;95m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_CYAN(...) "\e[1;96m", __VA_ARGS__ ,"\e[0m"

    #define UNUSED(var) (void) (var)

    #define ADD_QUOTE(value) #value
    #define STR(value) ADD_QUOTE(value)

#endif /* !MY_DEF_H_ */

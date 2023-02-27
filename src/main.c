/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv)
{
    ini_all_data();
    create_all_data();

    main_loop();

    free_all_data();

    return 0;
}

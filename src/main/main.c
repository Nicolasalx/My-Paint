/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include "layer.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc != 1) {
        if (load_image(argv[1]) == FAIL) {
            print_error(BOLD_RED(argv[1], ": Invalid file\n"));
            return 84;
        }
    } else {
        create_default_layer();
    }
    create_all_data();
    main_loop();
    free_all_data();
    return 0;
}

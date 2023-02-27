/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_a_dir
*/

#include "my_error.h"
#include <sys/stat.h>
#include <stdbool.h>

bool is_a_dir(const char *path)
{
    struct stat st;

    if (stat(path, &st) != 0) {
        print_fatal_error_and_exit(STAT_FAIL);
    }
    return S_ISDIR(st.st_mode);
}

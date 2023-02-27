/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_malloc
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_error.h"

void *my_malloc(size_t size)
{
    void *data;

    if (size == 0) {
        return NULL;
    }
    data = malloc(size);
    if (data == NULL) {
        print_fatal_error_and_exit(MALLOC_FAIL);
    }
    return data;
}

/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_exit
*/

#include "my_error.h"

void my_exit(long int exit_value)
{
    __asm__ (
        "movq %0, %%rdi;"
        "movq $0x3c, %%rax;"
        "syscall"
        :
        : "r" (exit_value)
        : "%rdi", "%rax"
    );
}

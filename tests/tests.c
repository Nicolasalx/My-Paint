/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

TestSuite(Basic_tests);

Test (Basic_tests, test_cr_assert)
{
    cr_assert(0 == 0, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", 0, 0);
}

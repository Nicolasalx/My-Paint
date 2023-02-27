/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** error_manager
*/

int error_manager(int error_detected)
{
    static int error = 0;

    if (error_detected != 0) {
        error = error_detected;
    }
    return error;
}

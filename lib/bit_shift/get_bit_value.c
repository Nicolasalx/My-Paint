/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** get_bit_value
*/

int get_bit_value(unsigned char c, int index_bit)
{
    return ((c >> index_bit) & 1);
}

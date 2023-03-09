/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"
#include <stdio.h>

void new_file(void)
{
    return;
}

void open_file(void)
{
    return;
}

void save_img_file(void)
{
    return;
}

void exit_file(void)
{
    return;
}

void display_icon_file(sfRenderWindow *window)
{
    for (int i = 0; i < size_file_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape(window, file_menu_header[i].rectangle,
            NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) && is_mouse_over_rectangle_shape(file_menu_header[i].rectangle, mouse_pos)) {
            file_menu_header[i].redirect();
        }
        for (int i = 0; i < size_text_file_header; ++i) {
            sfRenderWindow_drawText(window, text_file_header[i].text, NULL);
        }
    }
}

void close_menu_file(int *verif_close_menu, int i)
{
    if (is_mouse_over_rectangle_shape
        (file_menu_header[i].rectangle, mouse_pos) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape
        (button_header[0].rectangle, mouse_pos) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_file_menu(sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (mouse_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[0].rectangle,
            mouse_pos)) {
                verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_file(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            close_menu_file(&verif_close_menu, i);
        }
    }
    if (verif_close_menu == 0 && mouse_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

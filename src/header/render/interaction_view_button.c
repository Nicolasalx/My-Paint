/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void display_icon_view(sfRenderWindow *window)
{
    for (int i = 0; i < size_view_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape
            (window, view_menu_header[i].rectangle, NULL);
        for (int i = 0; i < size_text_view_header; ++i) {
            sfRenderWindow_drawText(window, text_view_header[i].text, NULL);
        }
    }
}

void close_menu_view(int i, int *verif_close_menu)
{
    if (is_mouse_over_rectangle_shape
        (view_menu_header[i].rectangle, mouse_pos) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape
        (button_header[2].rectangle, mouse_pos) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_view_menu(sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (mouse_button_pressed == true) {
        if (is_mouse_over_rectangle_shape
            (button_header[2].rectangle, mouse_pos)) {
                verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_view(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_view_menu_header; ++i) {
            close_menu_view(i, &verif_close_menu);
        }
    }
    if (verif_close_menu == 0 && mouse_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

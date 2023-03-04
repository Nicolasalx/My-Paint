/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void display_icon_layer(sfRenderWindow *window)
{
    for (int i = 0; i < size_layer_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            layer_menu_header[i].rectangle, NULL);
        for (int i = 0; i < size_text_layer_header; ++i) {
            sfRenderWindow_drawText(window, text_layer_header[i].text, NULL);
        }
    }
}

void close_menu_layer(int i, int *verif_close_menu)
{
    if (is_mouse_over_rectangle_shape
        (layer_menu_header[i].rectangle, mouse_pos) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape
        (button_header[3].rectangle, mouse_pos) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_layer_menu(sfRenderWindow *window, sfVector2i mouse_pos,
    bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[3].rectangle,
            mouse_pos)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_layer(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_layer_menu_header; ++i) {
            close_menu_layer(i, &verif_close_menu);
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

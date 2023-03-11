/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void interaction_menu_component(int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_over_rectangle_shape(help_menu_header[i].rectangle)) {
        help_menu_header[i].redirect();
    }
}

void display_icon_help(sfRenderWindow *window)
{
    for (int i = 0; i < size_help_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape
            (window, help_menu_header[i].rectangle, NULL);
        interaction_menu_component(i);
        for (int i = 0; i < size_text_help_header; ++i) {
            sfRenderWindow_drawText(window, text_help_header[i].text, NULL);
        }
    }
}

void close_menu_help(int i, int *verif_close_menu)
{
    if (is_mouse_over_rectangle_shape(help_menu_header[i].rectangle) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape(button_header[4].rectangle) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_help_menu(sfRenderWindow *window)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (mouse_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[4].rectangle)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_help(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_help_menu_header; ++i) {
            close_menu_help(i, &verif_close_menu);
        }
    }
    if (verif_close_menu == 0 && mouse_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void reset_menu_header(int pressed_min_one_time, bool is_button_pressed,
    int *verif_mouse_in_box)
{
    if (pressed_min_one_time > 0) {
        for (int i = 0; i < size_button_header; ++i) {
            if (is_mouse_over_rectangle_shape(button_header[i].rectangle,
                mouse_pos) == false && is_button_pressed == true) {
                ++ *verif_mouse_in_box;
            }
        }
    }
    if (pressed_min_one_time > 0 && *verif_mouse_in_box ==
        size_button_header) {
        for (int i = 0; i < size_button_header; ++i) {
            sfRectangleShape_setFillColor(button_header[i].rectangle,
                BG_COLOR);
        }
    }
}

void gestion_header_menu(sfVector2i mouse_pos, bool is_button_pressed,
    int *stay_on_icon_header)
{
    int verif_mouse_in_box = 0;
    static int pressed_min_one_time = 0;
    for (int i = 0; i < size_button_header; ++i) {
        if (is_mouse_over_rectangle_shape(button_header[i].rectangle,
            mouse_pos) == true && is_button_pressed == true) {
            sfRectangleShape_setFillColor
                (button_header[*stay_on_icon_header].rectangle, BG_COLOR);
            sfRectangleShape_setFillColor(button_header[i].rectangle, sfBlue);
            * stay_on_icon_header = i;
            ++ pressed_min_one_time;
        }
    }
    reset_menu_header(pressed_min_one_time, is_button_pressed,
        &verif_mouse_in_box);
}

void interaction_file_and_edit_header(sfRenderWindow *window,
    bool is_button_pressed)
{
    for (int i = 0; i < size_file_menu_header; ++i) {
        if (is_mouse_over_rectangle_shape(file_menu_header[i].rectangle,
            mouse_pos) == true) {
                sfRectangleShape_setFillColor(file_menu_header[i].rectangle,
                    (sfColor) {102, 255, 102, 255});
        } else {
            sfRectangleShape_setFillColor(file_menu_header[i].rectangle,
                sfWhite);
        }
    } gestion_header_file_menu(window, mouse_pos, is_button_pressed);
    for (int i = 0; i < size_edit_menu_header; ++i) {
        if (is_mouse_over_rectangle_shape(edit_menu_header[i].rectangle,
            mouse_pos) == true) {
                sfRectangleShape_setFillColor(edit_menu_header[i].rectangle,
                    (sfColor) {102, 255, 102, 255});
        } else {
            sfRectangleShape_setFillColor(edit_menu_header[i].rectangle,
                sfWhite);
        }
    } gestion_header_edit_menu(window, mouse_pos, is_button_pressed);
}

void interaction_view_and_layer_header(sfRenderWindow *window,
    bool is_button_pressed)
{
    for (int i = 0; i < size_view_menu_header; ++i) {
        if (is_mouse_over_rectangle_shape(view_menu_header[i].rectangle,
            mouse_pos) == true) {
                sfRectangleShape_setFillColor(view_menu_header[i].rectangle,
                    (sfColor) {102, 255, 102, 255});
        } else {
            sfRectangleShape_setFillColor(view_menu_header[i].rectangle,
                sfWhite);
        }
    } gestion_header_view_menu(window, mouse_pos, is_button_pressed);
    for (int i = 0; i < size_layer_menu_header; ++i) {
        if (is_mouse_over_rectangle_shape(layer_menu_header[i].rectangle,
            mouse_pos) == true) {
                sfRectangleShape_setFillColor(layer_menu_header[i].rectangle,
                    (sfColor) {102, 255, 102, 255});
        } else {
            sfRectangleShape_setFillColor(layer_menu_header[i].rectangle,
                sfWhite);
        }
    } gestion_header_layer_menu(window, mouse_pos, is_button_pressed);
}

void management_button_header(sfRenderWindow *window, bool is_button_pressed,
    int *stay_on_icon_header)
{
    for (int i = 0; i < size_button_header; ++i) {
        sfRenderWindow_drawRectangleShape(window, button_header[i].rectangle,
            NULL);
    }
    for (int i = 0; i < size_text_button_header; ++i) {
        sfRenderWindow_drawText(window, text_button_header[i].text, NULL);
    }
    gestion_header_menu(mouse_pos, is_button_pressed, stay_on_icon_header);
    interaction_file_and_edit_header(window, is_button_pressed);
    interaction_view_and_layer_header(window, is_button_pressed);
    for (int i = 0; i < size_help_menu_header; ++i) {
        if (is_mouse_over_rectangle_shape(help_menu_header[i].rectangle,
            mouse_pos) == true) {
            sfRectangleShape_setFillColor(help_menu_header[i].rectangle,
                (sfColor) {102, 255, 102, 255});
        } else {
            sfRectangleShape_setFillColor(help_menu_header[i].rectangle,
                sfWhite);
        }
    } gestion_header_help_menu(window, mouse_pos, is_button_pressed);
}

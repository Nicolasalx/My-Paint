/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_all_data
*/

#include "my.h"
#include "layer.h"
#include "tool.h"

void create_all_data(void)
{
    ini_bg_user_interface();
    ini_draw_img_user_interface();
    init_all_button_selection();
    ini_chromatic_wheel();
    init_all_text_selection_color();
    ini_button_header();
    ini_text_button_header();
    ini_file_menu_header();

    // ? layer
    create_default_layer();
    ini_icon_rectangle();
    ini_icon_sprite();
    ini_size_pen();
    ini_file_text();
    ini_edit_text();
    ini_edit_menu_header();
    ini_view_text();
    ini_edit_menu_header_rectangle_icon();

    // ? tool
    create_all_tool();
    ini_layer_menu_header_rectangle_icon();
    ini_layer_text();
    ini_help_menu_header_rectangle_icon();
    ini_help_text();
}
